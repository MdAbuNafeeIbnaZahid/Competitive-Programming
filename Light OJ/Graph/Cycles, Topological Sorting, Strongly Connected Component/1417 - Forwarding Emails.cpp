#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
#define ALREADY_UNION 91
#define WHITE 92
#define GREY 93
#define BLACK 94
long long T, N, u, v, startNode, current, maxAns, maxSource;
long long parent[SIZE], total[SIZE], visited[SIZE], color[SIZE], ans = 0;
long long redundantToCallFrom[SIZE];
long long a, b, c, d, e, f, g;
vector<long long> gr[SIZE], DAG[SIZE];
stack<long long> stak;
long long getParent( long long n )
{
    if ( parent[n] != n ) parent[n] = getParent( parent[n] );
    return parent[n];
}
long long makeUnion(long long a, long long b)
{
    if ( getParent(a) == getParent(b) ) return ALREADY_UNION;
    if ( a>b ) return makeUnion(b, a);
    total[ getParent(a) ] += total[ getParent(b) ];
    parent[ getParent(b) ] = getParent(a);
    return 1;
}
long long dfs1(long from, long long to)
{
    long long stat;
    color[to] = GREY;
    if ( color[ gr[to][0] ] == WHITE ) stat = dfs1(to, gr[to][0] );
    if ( color[ gr[to][0] ] == GREY )
    {
        startNode = gr[to][0];
    }
    if ( startNode== to )
    {
        startNode = -1;
    }
    if ( startNode != -1  )
    {
        makeUnion(to, startNode);
    }
    color[to] = BLACK;
    return 1;
}
long long dfs2(long long u)
{
    long long a, b, c, len = DAG[u].size();
    ans += total[ getParent(u) ];
    visited[u] = 1;
    redundantToCallFrom[u] = 1;
    for ( a= 0; a < len; a++ )
    {
        if ( !visited[ DAG[u][a] ] ) dfs2( DAG[u][a] );
    }
}
long long dfs3(long long u)
{
    long long a, b, c, len = DAG[u].size();
    color[u] = GREY;
    for ( a= 0; a < len; a++ )
    {
        if ( color[ DAG[u][a] ] ==WHITE ) dfs3( DAG[u][a] );
    }
    color[u] = BLACK;
    //stak.push(u);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        stak = stack<long long>();
        for (b = 0; b < SIZE; b++)
        {
            parent[b] = b;
            total[b] = 1;
            color[b] = WHITE;
            gr[b] = vector<long long>();
            DAG[b] = vector<long long>();
        }
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lld", &u, &v);
            gr[u].push_back(v);
        }
        for (b = 1; b <= N; b++)
        {
            startNode = -1;
            if ( color[b]==WHITE ) dfs1(b, b);
        }
        for (b = 1; b <= N; b++)
        {
            if ( getParent(b) != getParent( gr[b][0] ) )
            {
                DAG[ getParent(b) ].push_back( getParent( gr[b][0] ) );
            }
        }
        for (b = 1; b <= N; b++)
        {
            color[b] =WHITE;
        }
        for (b = 1; b <= N; b++)
        {
            if (color[b] == WHITE) dfs3(b);
            stak.push(b);
        }
        memset(redundantToCallFrom, 0, sizeof(redundantToCallFrom));
        maxAns = -1;
        while(!stak.empty())
        {
            current = stak.top();
            stak.pop();
            if ( redundantToCallFrom[current] ) continue;
            memset( visited, 0, sizeof(visited) );
            ans = 0;
            dfs2(current);
            if (ans > maxAns)
            {
                maxAns = ans;
                maxSource = current;
            }
            else if (ans == maxAns && current < maxSource) maxSource = current;
        }
        cout << "Case " << a << ": " << maxSource << endl;
    }
    return 0;
}
