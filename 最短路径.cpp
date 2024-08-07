#include<bits/stdc++.h>
 
using namespace std;
const int maxn = 105;
const int INF = 0x3f3f3f3f;
int dis[maxn][maxn];
///dis[i][j]表示 i到j的最短距离
void init() {
    for (int i = 1; i < maxn; i++) {
        for (int j = 1; j < maxn; j++)
            dis[i][j] = INF;
        dis[i][i] = 0;
    }
} 
int main() {
    init();
    int n, m, s, e, c;
    scanf("%d %d", &n, &m);
    while (m--) {
        scanf("%d %d %d", &s, &e, &c);
        dis[s][e] = min(dis[s][e], c);//可能存在重边
        // 无向边  dis[e][s]=min(dis[e][s], c);
    }
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
                //这个过程中，dis[i][j]的值都是i到j的路径不断优化的结果
    return 0;
}

