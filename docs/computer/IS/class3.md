# class 3/2024.3.12
### (续): enigma
算法：（不好变更）
- 机器的物理架构
- 三个齿轮

密钥：（容易变更）
- 齿轮的初始位置
- 齿轮的排序方式


### 对称密钥加密算法
通过密钥生成多个子密钥，形成费耶斯特结构（多层加密）

### DES
data encryption standard

一个密钥为56位

往往需要通过穷举来进行破解，并没有在密码学意义上破解了算法

因此提出triple DES, 将DES做三次（第一次加密，第二次解密，第三次加密，每次用不同的密钥）

加密解密相结合是为了与普通DES兼容（即k2=k3）


### 公钥密码学
- 有两个密钥：public key和private key

一个人掌握一个公钥密码环，而私钥为个人所有。

利用想象中的30000bit量子计算机，可以破解RSA算法

- diffie-hellman algorithm
对素数p与整数g：

如果$gmodp,g^2modp,...,g^{p-1}modp$为从1到p-1的各不相同的整数

则g为p的原根（primitive root）

那么对于任意的A

有：$A = g^amodp$

则令a为A的离散对数



1