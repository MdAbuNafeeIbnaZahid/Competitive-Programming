#include <iostream>

//#include <bits/stdc++.h>
using namespace std;

#define SIZE 105

int N, M, K;
int notVisited[SIZE][SIZE];
int i, j, a, b, c, x, y, z, R, C;
int ans = 0, maxAns = 0;


void dfs(int i, int j)
{
    if (notVisited[i][j] == 0) return;
    if (i < 1 || i > N || j < 1 || j > M) return;
    ans++;
    notVisited[i][j] = 0;
    dfs(i+1, j);
    dfs(i-1, j);
    dfs(i, j+1);
    dfs(i, j-1);
}

int main()
{


    cin >> N >> M >> K;

    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            notVisited[i][j] = 0;
        }
    }

    for (i = 1; i <= K; i++)
    {
        cin >> R >> C;
        notVisited[R][C] = 1;
    }


    for (i = 1; i <= N; i++)
    {
        for (j = 1; j <= M; j++)
        {
            ans = 0;
            dfs(i, j);
            if (ans > maxAns) maxAns = ans;
        }
    }

    cout << maxAns;


    return 0;
}
