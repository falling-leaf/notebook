## Elastic Search

### 1. 部署方式

本方案中Elastic Search使用Docker（基于Windows 11操作系统）部署。

本方案中`Elastic Search`，`Kibana`，`IK`均使用8.12.2版本。

> 在安装过程中需注意如下问题：    
> 1. 在下载镜像文件时，可能需要打开代理；但在尝试通过浏览器访问端口时需关闭代理（否则需要额外配置代理文件）   
> 2. 所有容器的版本应当一致（建议先搜索IK是否具备所需版本）   
> 3. 配置过程中可以通过docker ps/docker images等命令查看容器状态和镜像信息    
> 4. 如需访问容器的文件系统，可以直接通过docker desktop的UI操作（在进行文件系统的修改后需要重启对应的docker）   

#### 1.1 Docker基本环境配置

1. 在[Docker官网](https://www.docker.com/)中下载`Docker Desktop`并安装。

2. 配置Hyper-V环境并最终完成WSL2的基本配置（具体可参考[链接](https://docker.easydoc.net/doc/81170005/cCewZWoN/lTKfePfP)）

3. 配置成功后，在命令行中输入`docker --version`命令，若能正常显示版本号，则说明Docker环境配置成功。

4. 输入以下命令，创建一个docker网络，使Elastic Search容器能够互相通信：

```bash

docker network create es-net

```

#### 1.2 Elastic Search安装

1. 输入以下命令，拉取Elastic Search镜像：

```bash
$ docker pull elasticsearch:8.12.2
```

2. 输入以下命令，运行Elastic Search容器（注意：`--name`，`--network`名字可以改变，但需与其他步骤一致）：

```bash

docker run -d \
  --name es \
  -e "ES_JAVA_OPTS=-Xms512m -Xmx1024m" \
  -e "discovery.type=single-node" \
  -e "xpack.security.enabled=true" \
  -v es-data:/usr/share/elasticsearch/data \
  -v es-plugins:/usr/share/elasticsearch/plugins \
  --privileged \
  --network es-net \
  -p 9200:9200 \
  -p 9300:9300 \
  elasticsearch:8.12.2

```

3. 运行成功后，Elastic Search将会在`http://localhost:9200/`提供服务。通过浏览器或`CURL`语句尝试访问可获得JSON格式的响应。

4. 输入以下命令，进入Elastic Search虚拟环境并对Elastic Search的密码进行配置：

```bash

docker exec -it es /bin/bash

bin/elasticsearch-setup-passwords interactive

```

5. 在配置密码后，再次进入`http://localhost:9200/`需要输入用户名和密码才能访问Elastic Search。

#### 1.3 Kibana安装

1. 输入以下命令，拉取Kibana镜像：

```bash

docker pull kibana:8.12.2

```

1. 输入以下命令，运行Kibana容器（注意：`--name`，`--network`名字可以改变，但需与其他步骤一致；`ELASTICSEARCH_PASSWORD`字段要改成在Elastic Search中配置的密码）：   

```bash

docker run -d \
  --name kibana \
  --net es-net \
  -p 5601:5601 \
  -e "ELASTICSEARCH_HOSTS=http://es:9200" \
  -e "ELASTICSEARCH_USERNAME=kibana_system" \
  -e "ELASTICSEARCH_PASSWORD=<your_kibana_system_password>" \
  kibana:8.12.2

```

2. 运行成功后，Kibana将会在`http://localhost:5601/`提供服务。通过浏览器或`CURL`语句尝试访问可获得Kibana的登录页面。

#### 1.4 IK插件安装

1. 进入ES内部

```bash

docker exec -it es /bin/bash

```

2. 下载IK插件

```bash

curl -L -O https://github.com/medcl/elasticsearch-analysis-ik/releases/download/v8.12.2/elasticsearch-analysis-ik-8.12.2.zip

```

3. 安装IK插件

```bash

elasticsearch-plugin install file:///usr/share/elasticsearch/elasticsearch-analysis-ik-8.12.2.zip

```


4. 重启ES

```bash

docker restart es

```

### 2. 基本介绍

#### 2.1 Elastic Search简介

Elastic Search(ES)是一种封装好的搜索引擎，它通过JSON文件格式存储数据，为用户提供搜索、分析、存储、分布式处理等功能。

相比于MySQL数据库，ES不具备基本的ACID特性，但它长于在海量数据中快速搜索、高效存储、分布式处理等功能（这是因为它的索引采用了 **倒排索引** ，这意味着ES能够更高效地完成搜索任务）。

同时，它提供Restful API接口，可以方便地与其他程序进行交互。（具体通过DSL等语法实现）

#### 2.2 Kibana简介

kibana是Elastic Search官方提供的可视化工具，它可以帮助用户快速地检索、分析、过滤和可视化数据。

在其中，可以尝试搜索`dev tools`并使用，以通过快捷命令行的方式对ES进行操作。

#### 2.3 IK插件简介

在ES中，采用了倒排索引作为构建方式，这意味着ES需要一个工具来对文本进行分词，并生成索引。IK插件就是这样一个工具，它能够对中文、英文、数字等文本进行分词，并生成索引。

IK是一种 **分词器** ，其作用是将文本分割成一个个单词，并为每个单词生成一个索引，以便于搜索引擎快速检索。

例如：**计算机程序员** 通过IK分词后，可以生成不同类型的索引：如“计算机”、“程序员”等。

##### 2.3.1 IK分词器基本使用

IK分词器还支持不同粒度的分词，例如在上例中，更细粒度的分词会出现“程序”、“员”等词汇。

具体分词操作举例如下（可在`kibana`的`dev tools`工具中进行尝试）：

```bash
POST /_analyze
{
  "text": "程序员why程序员",
  "analyzer": "ik_smart" // ik_smart是粗粒度的划分
  // "analyzer": "ik_max_word" // ik_max_word是细粒度的划分
}
```

##### 2.3.2 IK自定义词库

同时，IK也支持自定义词库，用户可以根据自己的需求添加、删除、修改词库（例如添加新兴词汇等）

其添加方法如下：

1. 在es文件系统内找到：`/usr/share/elasticsearch/plugins/analysis-ik/IKAnalyzer.cfg.xml`并打开后，可找到用户自定义的词库配置：

```xml

<?xml version="1.0" encoding="UTF-8"?>
<!DOCTYPE properties SYSTEM "http://java.sun.com/dtd/properties.dtd">
<properties>
	<comment>IK Analyzer 扩展配置</comment>
	<!--用户可以在这里配置自己的扩展字典 -->
	<entry key="ext_dict"></entry>
	 <!--用户可以在这里配置自己的扩展停止词字典-->
	<entry key="ext_stopwords"></entry>
	<!--用户可以在这里配置远程扩展字典 -->
	<!-- <entry key="remote_ext_dict">words_location</entry> -->
	<!--用户可以在这里配置远程扩展停止词字典-->
	<!-- <entry key="remote_ext_stopwords">words_location</entry> -->
</properties>


```

2. 在其中的`ext_dict`和`ext_stopwords`标签下，可以添加自定义词库和停止词文件（文件置于与`IKAnalyzer.cfg.xml`同一目录下，需要用户自行新建）。

3. 参考同目录下其他文件的设置方法（例如`extra_stopword.dic`）对自定义词库和停止词文件进行配置，即可完成自定义词库的添加。

#### 2.4 总结

总而言之，我们可以将ES看作一个“巨大的文档”，其中通过不同的构建方式（在下一部分详述）将数据存储在不同的索引中。而使用ES的目的就是希望能够快速对文档中的任意组合的数据进行搜索、分析、过滤、可视化等操作。

### 3. 具体操作：索引库

索引库对应MySQL的表（table），其定义了不同字段的类型、约束条件等。定义约束条件的方式称之为 **mapping** 。

在ES中，mapping有如下的属性：

- type: 字段数据类型，常见的类型有：
    - 字符串
        - text：可以被分词的文本
        - keyword：不能被分词的文本（例如姓名、邮箱等）
    - 数值：long/integer/short/byte/double/float
    - 布尔：boolean
    - 日期：date
    - 对象：object（用于嵌套定义）
    - > 注：mapping没有数组类型，但支持多值字段，例如"score": [1, 2, 3]
- index: 是否创建索引（默认为true）
- analyzer: 分词器
- properties: 该字段的子字段

#### 3.1 创建索引库

通过如下DSL语句，可以创建索引库：

```json

PUT /index_name
{
  "mappings": {
    "properties": {
      "field1": {
        "type": "text",
        "analyzer": "ik_max_word"
      },
      "field2": {
        "type": "keyword"
      },
      "field3": {
        "type": "integer"
      },
      "field4": {
        "type": "date"
      },
      "field5": {
        "type": "object",
        "properties": {
          "subfield1": {
            "type": "text",
            "analyzer": "ik_max_word"
          },
          "subfield2": {
            "type": "integer"
          }
        }
      }
    }
  }
}

```

其中：

- `index_name`表示索引库的名称（自定义）
- `field1`等表示字段的名称（自定义）
- `type`表示字段的数据类型
- `analyzer`表示字段的分词器

同时，例子中还提供了嵌套字段的写法，可以参考。

#### 3.2 查询、删除索引库

由于使用的是Restful API，所以查询、删除索引库的操作也比较简单：

1. 查询索引库：

```json

GET /index_name

```

2. 删除索引库：

```json

DELETE /index_name

```

#### 3.3 索引库的更新

严格来讲，ES不允许对索引库进行更新操作（这与MySQL是一致的）。

但ES仍然提供了“在索引库中添加新的字段”这一操作，具体方法如下：

```json

PUT /index_name/_mapping
{
  "properties": {
    "new_field": {
      "type": "text",
      "analyzer": "ik_max_word"
    }
  }
}

```

**需要注意的是，new_field必须与之前的mapping中的字段名称不同，否则会报错。**

### 4. 具体操作：文档

文档对应MySQL的行（row），其包含了具体的数据。

#### 4.1 插入文档

插入文档的操作如下：

```json

POST /index_name/_doc/doc_id
{
  "field1": "value1",
  "field2": "value2",
  "field3": 3,
  "field4": "2022-01-01T00:00:00Z",
  "field5": {
    "subfield1": "subvalue1",
    "subfield2": 4
  }
}

```

其中：

- `doc_id`表示文档的唯一标识符（自定义）
- `field1`等表示字段的名称
- `value1`等表示字段的值

如果操作成功，返回的json我呢见中会包含如下字段：
```json
  "result": "created"
```

#### 4.2 查询、删除文档

同理，查询、删除文档的操作也比较简单：

1. 查询文档：

```json

GET /index_name/_doc/doc_id

```

2. 删除文档：

```json

DELETE /index_name/_doc/doc_id

```

同样地，删除文档的操作会返回如下字段：

```json
  "result": "deleted"
```

#### 4.3 修改文档

修改文档分为两种方式：

- 全量修改：修改文档的所有字段（即删除旧文档，插入新文档）
- 增量修改：仅修改文档中的部分字段

1. 全量修改：

```json

PUT /index_name/_doc/doc_id
{
  "field1": "new_value1",
  "field2": "new_value2",
  "field3": 4,
  "field4": "2022-01-02T00:00:00Z",
  "field5": {
    "subfield1": "new_subvalue1",
    "subfield2": 5
  }
}

```

上述操作会将`doc_id`对应文档删除，并插入新的文档。

特别地，如果`doc_id`不存在，则不会删除任何文档，而是直接插入新文档。

2. 增量修改：

```json

POST /index_name/_update/doc_id
{
  "doc": {
    "field1": "new_value1",
    "field2": "new_value2"
  }
}

```

上述操作会仅修改`doc_id`对应文档的`field1`和`field2`字段。

上述操作成功后，返回的json中会包含如下字段：

```json
  "result": "updated"
```

### 5. DSL语法

DSL语法对应MySQL的SQL语句，其提供了丰富的查询、分析、过滤、聚合等功能。

#### 5.1 查询语法

查询语法分为如下几种方法：

- 查询所有：查询出所有数据
    - 例如：`match_all`
- 全文检索（full text）查询：利用分词器对用户输入内容进行分词，然后去倒排索引库中进行匹配
    - 例如：`match_query`，`multi_match_query`
- 精确查询：根据精确词条值查找数据，一般查找keyword、数值、日期、boolean等类型字段
    - 例如：`ids`, `range`, `term`
- 地理查询：根据经纬度查询
    - 例如：`geo_distance`, `geo_bounding_box`
- 复合查询：组合上述查询条件
    - 例如：`bool`, `constant_score`, `function_score`

基本语法如下：

```json

GET /index_name/_search
{
  "query": {
    "query_type": {
      "query_body": "query_value"
    }
  }
}

```

其中：

- `query_type`表示查询类型，如`match_all`、`match_query`等
- `query_body`表示查询条件（这个字段并非必须）

举例：对于“查询所有”操作，可以使用如下语句：

```json

GET /index_name/_search
{
  "query": {
    "match_all": {}
  }
}

```

其 **返回值** 格式如下：


