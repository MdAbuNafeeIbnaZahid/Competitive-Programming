#include <bits/stdc++.h>
using namespace std;

int t, n, u, v, i, j, k, ans[10];

vector<int> vertices[20009];
int visited[20009];


void dfs(int v, int type)
{
    if (visited[v] != 0) return;
    visited[v] = 1;
    if (vertices[v].empty())
    {
        return;
    }

    ans[type%2]++;

    vector<int>::iterator it;
    for (it = vertices[v].begin(); it != vertices[v].end(); it++)
    {
        dfs(*it, type+1 );
    }
}


int main()
{
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        ans[3] = 0;
        for (j = 0; j < 20009; j++)
        {
            visited[j] = 0;
            vertices[j].clear();
        }


        scanf("%d", &n);
        for (j = 1; j <= n; j++)
        {
            scanf("%d %d", &u, &v);

            vertices[u].push_back(v);
            vertices[v].push_back(u);
        }

        for (j = 1; j <= 20000; j++)
        {
            ans[0] = 0;
            ans[1] = 0;

            dfs(j, 1);

            ans[3] += max(ans[0], ans[1]);
        }

        printf("Case %d: %d\n", i, ans[3]);
    }

    return 0;
}
