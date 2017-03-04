#include <bits/stdc++.h>
using namespace std;

#define SIZE 10009


int t, k, n, m, u, v, dist[SIZE], i, j, a, b, c, d, e, f, x, y, z, ans;
int canVisited[SIZE], isVisited[SIZE];
vector<int> g[SIZE];
set<int> cities;
set<int>::iterator it;

void dfs(int u)
{
    if (isVisited[u] == 1) return;
    int i, j, k;
    isVisited[u] = 1;
    for (i = 0; i < g[u].size(); i++)
    {
        dfs( g[u][i] );
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> t;
    for (i = 1; i <= t; i++)
    {
        cities.clear();
        for (j = 0; j < SIZE; j++)
        {
            canVisited[j] = 1;
            g[j].clear();
        }
        cin >> k >> n >> m;
        for (j = 0; j < k; j++)
        {
            cin >> a;
            cities.insert(a);
        }
        for (j = 0; j < m; j++)
        {
            cin >> u >> v;
            g[u].push_back(v);
        }

        for (it = cities.begin(); it != cities.end(); it++)
        {
            for (j = 0; j < SIZE; j++)
            {
                isVisited[j] = 0;
            }
            dfs(*it);
            for (j = 0; j < SIZE; j++)
            {
                if ( !isVisited[j] ) canVisited[j] = 0;
            }
        }

        ans = 0;
        for (j = 1; j <= n; j++)
        {
            ans += canVisited[j];
        }

        cout << "Case " << i << ": " << ans << "\n";
    }



    return 0;
}
