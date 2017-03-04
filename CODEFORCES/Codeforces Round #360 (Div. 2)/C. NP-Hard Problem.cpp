#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
#define OFFSET 100002
#define WHITE -1
#define GREEN 0
#define RED 1
long long n, m, ui, vi, u, v;
long long a, b, c, d, e, f, g, len, terminateFlag;
long long parent[SIZE], color[SIZE];
vector<long long> gr[SIZE], ansVector[8];

long long getParent(long long u)
{
    if ( parent[u] == u ) return u;
    parent[u] = getParent(parent[u]);
    return parent[u];
}
void makeUnion(long long u, long long v)
{
    parent[ getParent(u) ] = getParent(v);
}
void dfs1(long long col, long long u)
{
    long long a, b, c, d, e, f, g, len = gr[u].size();
    if ( color[u] != WHITE )
    {
        return;
    }
    //if ( terminateFlag == 1 ) return;
    color[u] = col;
    for (a = 0; a < len; a++)
    {
        if ( color[u] == color[ gr[u][a] ] )
        {
            //cout << -1;
            terminateFlag = 1;
            return ;
        }
        dfs1( !col, gr[u][a] );
    }
}
int main()
{
    //freopen( "input.txt", "r", stdin );
    cin >> n >> m;
    for (a = 0; a < SIZE; a++)
    {
        parent[a] = a;
    }
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &u, &v);
        gr[u].push_back(v);
        gr[v].push_back(u);
    }
    memset(color, -1, sizeof(color));
    for (a = 1; a <= n; a++)
    {
        dfs1(GREEN, a);
        //if (terminateFlag) return 0;
    }
    for (a = 1; a <= n; a++)
    {
        if ( gr[a].size() )
        {
            ansVector[ color[a] ].push_back( a );
        }
    }

    if(terminateFlag)
    {
        cout << -1;
        return 0;
    }

    len = ansVector[GREEN].size();
    cout << len << endl;
    for (a = 0; a < len; a++)
    {
        printf("%lld ", ansVector[GREEN][a]);
    }
    cout << endl;

    len = ansVector[RED].size();
    cout << len << endl;
    for (a = 0; a < len; a++)
    {
        printf("%lld ", ansVector[RED][a]);
    }
    cout << endl;

    return 0;
}
