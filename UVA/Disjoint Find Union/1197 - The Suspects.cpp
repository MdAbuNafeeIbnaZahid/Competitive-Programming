#include <bits/stdc++.h>
using namespace std;
#define SIZE 30009
int n, m, visited[SIZE], ans, k, i, j, pr, cur;
set<int> groups[509];
vector<int> graph[SIZE];
void dfs(int u)
{
    vector<int>::iterator vIt;
    //cout << "dfs with u = " << u << endl;
    visited[u] = 1;
    ans++;
    if ( graph[u].empty() ) return;
    for (vIt = graph[u].begin(); vIt!=graph[u].end(); vIt++)
    {
        //cout << "u = " << u << ", *vIt = " << *vIt << endl;
        if (visited[*vIt]==0) dfs(*vIt);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> n >> m;
        if (n+m==0) return 0;
        //cout << "n = " << n << ", m = " << m << endl;
        memset(visited, 0, sizeof(visited) );
        ans = 0;
        for (i = 0; i < n; i++)
        {
            graph[i] = vector<int>();
        }
        for (i = 1; i <= m; i++)
        {
            cin >> k;
            if ( k >= 1) cin >> pr;
            for (j = 2; j <= k; j++)
            {
                cin >> cur;
                graph[pr].push_back(cur);
                graph[cur].push_back(pr);
                //cout << "edge between " << prev << " & " << cur << endl;
                pr = cur;
            }
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
