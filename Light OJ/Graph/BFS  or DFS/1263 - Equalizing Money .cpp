#include <bits/stdc++.h>
using namespace std;

#define SIZE 1009

int t, n, m, i, j, k, a, b, c, d, e, f, money[SIZE], u, v, isVisited[SIZE] = {0};
int totalMoney = 0, moneyPerHead;
vector<int> g[SIZE];
vector<int> moneyVector;


void dfs(int u)
{
    if (isVisited[u]) return;
    int i, j, k;
    isVisited[u] = 1;
    moneyVector.push_back( money[u] );
    for (i = 0; i < g[u].size(); i++)
    {
        dfs( g[u][i] );
    }
}


int main()
{
    //freopen( "input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> t;
    for (i = 1; i <= t; i++)
    {
        for (j = 1; j < SIZE; j++)
        {
            g[j].clear();
            isVisited[j] = 0;
        }
        totalMoney = 0;

        cin >> n >> m;

        for (j = 1; j <= n; j++)
        {
            cin >> money[j];
        }

        for (j = 1; j <= m; j++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        for (j = 1; j <= n; j++)
        {
            totalMoney += money[j];
        }
        moneyPerHead = totalMoney / n;
//        cout << "\n At first moneyPerHead = " << moneyPerHead << "\n";
        if (moneyPerHead * n != totalMoney)
        {
            cout << "Case " << i <<": No\n";
            continue;
        }

        for (j = 1; j <= n; j++)
        {
            moneyVector.clear();
            if (isVisited[j] == 0)
            {
                dfs(j);
                totalMoney = accumulate( moneyVector.begin(), moneyVector.end(), 0 );
                if ( (double)totalMoney/moneyVector.size() != moneyPerHead )
                {
                    break;
                }
            }
        }
        if (j <= n)
        {
            cout << "Case " << i <<": No\n";
        }
        else
        {
            cout << "Case " << i <<": Yes\n";
        }
    }


    return 0;
}
