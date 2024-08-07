/*

char graph[Max][Max];

int used[Max][Max];  //����Ѿ��߹���·

int px[] = {-1, 0, 1, 0};
int py[] = {0, -1, 0, 1};

void DFS(int x, int y)
{
    if(x==goal_x&&y==goal_y)
    {
        return;
    }
    // �����ĸ�����
    for (int i = 0; i != 4; ++i)
    {
        // ���·���
        int new_x = x + px[i], new_y = y + py[i];

        // ���鷽��
        if(new_x > 0 && new_x <= n && new_y > 0 && new_y <= m && used[new_x][new_y] == 0 && !flag&&graph[new_x][new_y]!='#')
        {
            used[new_x][new_y] = 1; // ���ø�����Ϊ�߹�
            DFS(new_x, new_y); // ʹ�õݹ�Ѱ��·��
        }
    }
}
*/
/*
���ߣ����߲���ele
���ӣ�https://www.zhihu.com/question/494715545/answer/3223802907
��Դ��֪��
����Ȩ���������С���ҵת������ϵ���߻����Ȩ������ҵת����ע��������

��Ŀ����

�c������һ������·��

С��Ĳ��ֿ�����Ϊһ��
����

��ÿ��λ��Ҫô�ǿ�ͨ����·��Ҫô�ǽ����������ڵ�·�����������ƶ���

������ĳ�ʼλ��Ϊ
��������ҵ�һ��ͨ��ѧУ

��·����
�����ʽ

��һ�У�����������

��

�ڶ��У�����������

��

������
�У�����С��Ĳ��֡�ÿ������һ����Ϊ

���ַ�����# ��ʾ������. ��ʾ�յء�
�����ʽ

��һ�У�ʹ�á� �� �� ����ϣ����һ�����ܵ���ѧУ��·����
����
��������

3 5
4 2
.##.#
.#...
...#.

�������

�� �� �� �� �� ��
*/

#include <bits/stdc++.h>

using namespace std;

const int Max = 110;

char graph[Max][Max];

int used[Max][Max];  //����Ѿ��߹���·

int n, m, goal_x, goal_y;

int px[] = {0, 1, 0, -1};
int py[] = {1, 0, -1, 0};

vector<string> ans_dir;

void DFS(int x, int y, vector<string> dir)
{
    if (x == goal_x && y == goal_y) // �����յ������
    {
        ans_dir = dir;
        return;
    }
    // �����ĸ�����
    for (int i = 0; i < 4; i++)
    {
        // ���·���
        int new_x = x + px[i], new_y = y + py[i];

        vector<string> new_dir;

        new_dir = dir;

        if (i == 0) // ��·����������
            new_dir.push_back("��");
        if (i == 1)
            new_dir.push_back("��");
        if (i == 2)
            new_dir.push_back("��");
        if (i == 3)
            new_dir.push_back("��");

        // �����·����Ƿ����
        if (new_x > 0 && new_x <= m && new_y > 0 && new_y <= n && used[new_x][new_y] == 0 && graph[new_x][new_y] != '#')
        {
            used[new_x][new_y] = 1;     // ���ø�����Ϊ�߹�
            DFS(new_x, new_y, new_dir); // �ݹ���ȥ
        }
    }
}

int main()
{
    cin >> n >> m;
    cin>>goal_x;
    cin>>goal_y;

    // �����ͼ��ע���ĸ��±������x���ĸ��±�������y
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cin >> graph[j][i];
    }

    vector<string> dir; // ʹ��vector�������洢��·��

    DFS(1, 1, dir);

    for (int i = 0; i < ans_dir.size(); i++) // ������
    {
        cout << ans_dir[i] << " ";
    }
    cout << endl;

    return 0;
}
