#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, n, k, u, v;
long long a, b, c, d, e, f;
long long current, outDegree, possible;
vector<long long > graph[SIZE], DAG[SIZE], transGraph[SIZE];
long long parent[SIZE], color[SIZE];
set<long long> vertexSet, DAGVertexSet;
set<long long>::iterator vertexSetIt, DAGVertexSetIt;
stack<long long> topStack;
long long getParent(long long u)
{
    if ( parent[u] == u ) return u;
    parent[u] = getParent( parent[u] );
    return parent[u];
}
void makeUnion(long long u, long long v)
{
    parent[ getParent(u) ] = getParent(v);
}
void dfs1(long long u)
{
    int i, j, k, len = graph[u].size();
    vector<long long>::iterator itVec;
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for (i = 0; i < len; i++)
    {
        dfs1( graph[u][i] );
    }
    color[u] = BLACK;
    topStack.push(u);
}
void dfs2(long long u)
{
    int i, j, k, len = transGraph[u].size();
    vector<long long>::iterator itVec;
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for (i = 0; i < len; i++)
    {
        if ( color[ transGraph[u][i] ] != WHITE ) continue;
        //cout << "making union" << endl;
        makeUnion(u, transGraph[u][i] );
        dfs2( transGraph[u][i] );
    }
    color[u] = BLACK;
}
void dfs3(long long u)
{
    color[u] = GREY;
    if ( DAG[u].size() == 1 ) dfs3( DAG[u][0] );
    if ( DAG[u].size() > 1 ) possible = 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        possible = 1;
        vertexSet = set<long long>();
        DAGVertexSet =set<long long>();
        for (b = 0; b < SIZE; b++)
        {
            parent[b] = b;
            graph[b] = vector<long long>();
            transGraph[b] = vector<long long>();
            DAG[b] = vector<long long>();
            color[b] = WHITE;
        }
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &k);
            for (c = 1; c <= k; c++)
            {
                scanf("%lld %lld", &u, &v);
                graph[u].push_back(v);
                transGraph[v].push_back(u);
                vertexSet.insert(u);
                vertexSet.insert(v);
            }
        }
        for (vertexSetIt = vertexSet.begin(); vertexSetIt != vertexSet.end(); vertexSetIt++)
        {
            dfs1( *vertexSetIt );
        }
        for (b = 0; b < SIZE; b++)
        {
            color[b] = WHITE;
        }
        while( !topStack.empty() )
        {
            current = topStack.top();
            //cout << "current = " << current << endl;
            topStack.pop();
            dfs2( current );
        }
        for (b = 0; b < SIZE; b++)
        {
            color[b] = WHITE;
            outDegree = graph[b].size();
            for (c = 0; c < outDegree; c++)
            {
                u = b;
                v = graph[b][c];
                DAGVertexSet.insert( getParent(u) );
                DAGVertexSet.insert( getParent(v) );
                if ( getParent(u) != getParent(v) )
                {
                    //cout << "u = " << u << ", v = " << v << endl;

                    DAG[ getParent(u) ].push_back( getParent(v) );
                }
            }
        }
        dfs3( getParent(0) );
        //cout << "DAGVertexSet.size() = " << DAGVertexSet.size() << endl;
        for ( DAGVertexSetIt = DAGVertexSet.begin(); DAGVertexSetIt != DAGVertexSet.end(); DAGVertexSetIt++ )
        {
            //cout << "*DAGVertexSetIt = " << *DAGVertexSetIt << endl;
            if ( color[ *DAGVertexSetIt ] == WHITE ) possible = 0;
        }
        if ( possible == 0 )
        {
            cout << "Case " << a << ": NO" << endl;
        }
        else cout << "Case " << a << ": YES" << endl;
    }
    return 0;
}
