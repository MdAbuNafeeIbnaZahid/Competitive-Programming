#include <bits/stdc++.h>
using namespace std;
#define SIZE 20009
long long T, n, m, u, v, ans, indegreeZero, outdegreeZero, compo, current;
long long len;
long long visited[SIZE], indegree[SIZE], outdegree[SIZE];
vector<long long> gr[SIZE], transGr[SIZE], DAG[SIZE], transDAG[SIZE];
long long a, b, c, d, e;
stack<long long> stak;
void dfs1(long long u)
{
    long long a, b, c, len = gr[u].size();
    if ( visited[u] ) return;
    visited[u] = 1;
    for (a = 0; a < len; a++)
    {
        if ( !visited[ gr[u][a] ] ) dfs1( gr[u][a] );
    }
    stak.push(u);
}
void dfs2(long long u)
{
    long long a, b, c, len = transGr[u].size();
    if ( visited[u] ) return;
    visited[u] = compo;
    for (a = 0; a < len; a++)
    {
        if ( !visited[ transGr[u][a] ] ) dfs2( transGr[u][a] );
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        for (b= 1; b <= n; b++)
        {
            gr[b] = vector<long long>();
            transGr[b] = vector<long long>();
            DAG[b] = vector<long long>();
            transDAG[b] = vector<long long>();
        }
        memset(visited, 0, sizeof(visited));
        memset(indegree, 0, sizeof(indegree));
        memset(outdegree, 0, sizeof(outdegree));;
        ans = indegreeZero = outdegreeZero = compo = 0;
        cin >> n >> m;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &u, &v);
            gr[u].push_back( v );
            transGr[v].push_back( u );
        }
        stak = stack<long long>();
        memset( visited, 0, sizeof(visited) );
        for (b = 1; b <= n; b++)
        {
            dfs1(b);
        }
        memset( visited, 0, sizeof(visited) );
        while( !stak.empty() )
        {
            current = stak.top();
            stak.pop();
            if ( !visited[current] )
            {
                compo++;
                dfs2(current);
            }
        }
        //cout << "compo = " << compo << endl;
        if ( compo <= 1 )
        {
            cout << "Case " << a << ": " << 0 << endl;
            continue;
        }
        for (b = 1; b <= n; b++)
        {
            len = gr[b].size();
            for (c = 0; c < len; c++)
            {
                if ( visited[b] != visited[ gr[b][c] ] )
                {
                    outdegree[ visited[b] ]++;
                    indegree[ visited[ gr[b][c] ] ]++;
                }
            }
        }
        for (b = 1; b <= compo; b++)
        {
            if ( indegree[b]==0 ) indegreeZero++;
            if ( outdegree[b]==0 ) outdegreeZero++;
        }
        ans = max( indegreeZero, outdegreeZero );
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
