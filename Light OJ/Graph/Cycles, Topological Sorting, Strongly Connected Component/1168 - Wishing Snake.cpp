#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, n, k, u, v;
long long a, b, c, d, e;
vector<long long> gr[SIZE];
long long inDegree[SIZE], outDegree[SIZE], visited[SIZE];
set<long long> vertexSet, terminalVertex;
set<long long>::iterator setIt;
void dfs(long long u)
{
    if ( visited[u] ) return;
    visited[u] = 1;
    vector<long long>::iterator it;
    for (it = gr[u].begin(); it != gr[u].end(); it++)
    {
        dfs(*it);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        vertexSet = set<long long>();
        terminalVertex = set<long long>();
        for (b = 0; b < SIZE; b++)
        {
            gr[b] = vector<long long>();
            inDegree[b] = outDegree[b] = visited[b] = 0;
        }
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &k);
            for (c = 1; c <= k; c++)
            {
                scanf("%lld %lld", &u, &v);
                gr[u].push_back( v );
                outDegree[u]++;
                inDegree[v]++;
                vertexSet.insert(u);
                vertexSet.insert(v);
            }
        }
        dfs(0);
        for (setIt = vertexSet.begin(); setIt != vertexSet.end(); setIt++)
        {
            if ( !visited[*setIt] )
            {
                cout << "Case " << a << ": NO" << endl;
                break;
            }
        }
        if (setIt != vertexSet.end()) continue;
        for (setIt = vertexSet.begin(); setIt != vertexSet.end(); setIt++)
        {
            if ( inDegree[*setIt] != outDegree[*setIt] ) terminalVertex.insert( *setIt );
        }
        if ( terminalVertex.size() <= 2 )
        {
            cout << "Case " << a << ": Yes" << endl;
        }
        else cout << "Case " << a << ": NO" << endl;
    }
    return 0;
}
