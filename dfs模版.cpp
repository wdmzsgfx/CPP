/*

char graph[Max][Max];

int used[Max][Max];  //标记已经走过的路

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

void DFS(int x, int y)
{
    if(x==goal_x&&y==goal_y)
    {
        return;
    }
    // 遍历四个方向
    for (int i = 0; i != 4; ++i)
    {
        // 更新方向
        int new_x = x + px[i], new_y = y + py[i];

        // 检验方向
        if(new_x > 0 && new_x <= n && new_y > 0 && new_y <= m && used[new_x][new_y] == 0 && !flag&&graph[new_x][new_y]!='#')
        {
            used[new_x][new_y] = 1; // 将该格子设为走过
            DFS(new_x, new_y); // 使用递归寻找路径
        }
    }
}
*/
/*
作者：电线不加ele
链接：https://www.zhihu.com/question/494715545/answer/3223802907
来源：知乎
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

题目描述

萩生响又一次迷了路。

小镇的布局可以视为一个
矩阵

，每个位置要么是可通过的路，要么是建筑。响能在道路上上下左右移动。

现在响的初始位置为
，请帮响找到一条通往学校

的路径。
输入格式

第一行，两个正整数

。

第二行，两个正整数

。

接下来
行，输入小镇的布局。每行输入一个长为

的字符串，# 表示建筑，. 表示空地。
输出格式

仅一行，使用↑ ↓ ← →组合，输出一条响能到达学校的路径。
样例
样例输入

3 5
4 2
.##.#
.#...
...#.

样例输出

↓ ↓ → → ↑ →
*/

#include <bits/stdc++.h>

using namespace std;

const int Max = 110;

char graph[Max][Max];

int used[Max][Max];  //标记已经走过的路

int n, m, goal_x, goal_y;

int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};

vector<string> ans_dir;

void DFS(int x, int y, vector<string> dir)
{
    if (x == goal_x && y == goal_y) // 到达终点的条件
    {
        ans_dir = dir;
        return;
    }
    // 遍历四个方向
    for (int i = 0; i < 4; i++)
    {
        // 更新方向
        int new_x = x + px[i], new_y = y + py[i];

        vector<string> new_dir;

        new_dir = dir;

        if (i == 0) // 将路径载入容器
            new_dir.push_back("↓");
        if (i == 1)
            new_dir.push_back("→");
        if (i == 2)
            new_dir.push_back("↑");
        if (i == 3)
            new_dir.push_back("←");

        // 检验新方向是否可走
        if (new_x > 0 && new_x <= m && new_y > 0 && new_y <= n && used[new_x][new_y] == 0 && graph[new_x][new_y] != '#')
        {
            used[new_x][new_y] = 1;     // 将该格子设为走过
            DFS(new_x, new_y, new_dir); // 递归下去
        }
    }
}

int main()
{
    cin >> n >> m;
    cin>>goal_x;
    cin>>goal_y;

    // 构造地图，注意哪个下表代表是x，哪个下表代表的是y
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> graph[j][i];
    }

    vector<string> dir; // 使用vector容器来存储答案路径

    DFS(1, 1, dir);

    for (int i = 0; i < ans_dir.size(); i++) // 输出结果
    {
        cout << ans_dir[i] << " ";
    }
    cout << endl;

    return 0;
}
