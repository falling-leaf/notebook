//这是为演奏曲目打造的排序程序，将所有数据整合后以不同的排序方式输出进入markdown
//经过提前测验，string类型可以存放汉字（这可真是tql）
//考虑到本程序只有自己会用到，因此不用class了，直接用struct以求方便
//by why
//wok屎山代码，先不管了，直接暴力循环生成出来一份吧
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
    bool visit;
};
music sets[1000];
int total;

void outputrank(string sort, string rank)
{
    string color;
    if (rank == "UR")
        color = "red";
    else if (rank == "SSR")
        color = "orange";
    else if (rank == "SR")
        color = "purple";
    else color = "green";
    for (int j = 0; j < total; j++)
    {
        if (sets[j].sort == sort && sets[j].rank == rank && sets[j].visit == false)
        {
            cout << "- <font color = " << color << ">";
            cout << "[" << sets[j].clear << "] " << rank << " " << sets[j].name << " " << sets[j].author;
            cout << "</font>" << endl;
            cout << endl;
            sets[j].visit = true;
        }
    }
}

void outputsort(string sort)
{
    if (sort == "animation")
        cout << "### 动漫" << endl;
    else if (sort == "classical")
        cout << "### 古典" << endl;
    else if (sort == "popular")
        cout << "### 流行" << endl;
    else if (sort == "game")
        cout << "### 游戏" << endl;
    outputrank(sort, "UR");
    outputrank(sort, "SSR");
    outputrank(sort, "SR");
    outputrank(sort, "A");
}

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
    freopen("PLAY.md", "w", stdout);
    total = i;
    cout << "# 演奏！" << endl;
    cout << "## 目录（按分类/难度排序）" << endl;
    outputsort("animation");
    outputsort("classical");
    outputsort("game");
    outputsort("popular");
    // cout << "### 动漫" << endl;
    // cout << endl;
    // for (int j = 0; j < i; j++)
    //     sets[j].visit = false;
    // for (int j = 0; j < i; j++)
    // {
    //     if (sets[j].sort == "animation" && sets[j].rank == "UR" && sets[j].visit == false)
    //     {
    //         cout << "- <font color = red>";
    //         cout << "[" << sets[j].clear << "] " << "UR " << sets[j].name << " " << sets[j].author;
    //         cout << "</font>" << endl;
    //         cout << endl;
    //         sets[j].visit = true;
    //     }
    // }
    // for (int j = 0; j < i; j++)
    // {
    //     if (sets[j].sort == "animation" && sets[j].rank == "SSR" && sets[j].visit == false)
    //     {
    //         cout << "- <font color = orange>";
    //         cout << "[" << sets[j].clear << "] " << "SSR " << sets[j].name << " " << sets[j].author;
    //         cout << "</font>" << endl;
    //         cout << endl;
    //         sets[j].visit = true;
    //     }
    // }
    // for (int j = 0; j < i; j++)
    // {
    //     if (sets[j].sort == "animation" && sets[j].rank == "SR" && sets[j].visit == false)
    //     {
    //         cout << "- <font color = purple>";
    //         cout << "[" << sets[j].clear << "] " << "SR " << sets[j].name << " " << sets[j].author;
    //         cout << "</font>" << endl;
    //         cout << endl;
    //         sets[j].visit = true;
    //     }
    // }
    // for (int j = 0; j < i; j++)
    // {
    //     if (sets[j].sort == "animation" && sets[j].rank == "A" && sets[j].visit == false)
    //     {
    //         cout << "- <font color = green>";
    //         cout << "[" << sets[j].clear << "] " << "A " << sets[j].name << " " << sets[j].author;
    //         cout << "</font>" << endl;
    //         cout << endl;
    //         sets[j].visit = true;
    //     }
    // }
    fclose(stdout);
}