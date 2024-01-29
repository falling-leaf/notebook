//这是为演奏曲目打造的排序程序，将所有数据整合后以不同的排序方式输出进入markdown
//经过提前测验，string类型可以存放汉字（这可真是tql）
//考虑到本程序只有自己会用到，因此不用class了，直接用struct以求方便
//by why
#include <bits/stdc++.h>
using namespace std;
struct music//曲目的结构
{
    string name;//曲目名称
    string author;//曲目作者
    string sort;//曲目类型(animation/classical/popular/game)
    string src;//曲目来源
    string rank;//难度(A/SR/SSR/UR)
    string clear;//完成与否(y/n)
};
music sets[1000];
int main()
{
    freopen("database.txt", "r", stdin);
    string temp;
    int i = 0;
    cin >> temp;
    while (temp != "-")
    {
        sets[i].name = temp;
        cin >> sets[i].author;
        cin >> sets[i].sort;
        cin >> sets[i].src;
        cin >> sets[i].rank;
        cin >> sets[i].clear;
        i++;
        cin >> temp;
    }
    fclose(stdin);
    freopen("", "w", stdout);
    
}