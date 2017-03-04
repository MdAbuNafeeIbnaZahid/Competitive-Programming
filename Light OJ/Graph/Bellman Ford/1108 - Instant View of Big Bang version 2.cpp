#include <bits/stdc++.h>
using namespace std;
#define SIZE 2009
#define WHITE 2
#define GREY 3
#define BLACK 4
struct edge
{
    long long from, to, weight;
    edge(){}
    edge(long long from, long long to, long long weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
long long T, n, m, x, y, t, current;
long long a, b, c, d, e, f;
long long parent[SIZE], dis[SIZE], color[SIZE];
vector<edge> gr[SIZE], transGr[SIZE], edgeVector;
stack<long long> stak;
set<long long> startSystem;
set<long long>::iterator setLongLongIt;
long long getParent(long long u)
{
    if ( parent[u] != u ) parent[u] = getParent( parent[u] );
    return parent[u];
}
void makeUnion(long long u, long long v)
{
    parent[ getParent(u) ] = getParent(v);
}
void dfsForTopSort(long long u)
{
    long long a, b, c, d, len = gr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for(a = 0; a < len; a++)
    {
        if ( color[ gr[u][a].to ] == WHITE )
        {
            dfsForTopSort( gr[u][a].to );
        }
    }
    color[u] = BLACK;
    stak.push( u );
    return;
}
void dfsForSCC(long long prev, long long cur)
{
    long long a, b, c, d, len = transGr[cur].size();
    if ( color[ cur ] != WHITE ) return;
    makeUnion( prev, cur );
    color[cur] = GREY;
    for (a= 0; a < len; a++)
    {
        if ( color[ transGr[cur][a].to ] == WHITE ) dfsForSCC( cur, transGr[cur][a].to );
    }
    color[cur] = BLACK;
}
void dfsForFinalAns(long long u)
{
    long long a, b, c, d, e, len = transGr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    startSystem.insert( u );
    for (a = 0; a < len; a++)
    {
        dfsForFinalAns( transGr[u][a].to );
    }
    color[u] = BLACK;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        stak = stack<long long>();
        edgeVector = vector<edge>();
        startSystem = set<long long>();
        cin >> n >> m;
        for (b = 0; b <= n; b++)
        {
            gr[b] = vector<edge>();
            transGr[b] = vector<edge>();
            parent[b] = b;
            dis[b] = INT_MAX;
            color[b] = WHITE;
        }
        for (b = 0; b < m; b++)
        {
            scanf("%lld %lld %lld", &x, &y, &t);
            gr[x].push_back( edge(x, y, t) );
            transGr[y].push_back( edge(y, x, -t) );
            edgeVector.push_back( edge(x, y, t) );
        }
        for (b = 0; b < n; b++)
        {
            if ( color[b] == WHITE ) dfsForTopSort( b );
        }
        for (b = 0; b <= n; b++)
        {
            color[b] = WHITE;
        }
        while( !stak.empty() )
        {
            current = stak.top();
            stak.pop();
            if ( color[current] == WHITE )
            {
                dfsForSCC( current, current );
            }
        }
        for (b = 0; b < n-1; b++)
        {
            for (c = 0; c < m; c++)
            {
                x = edgeVector[c].from;
                y = edgeVector[c].to;
                t = edgeVector[c].weight;
                if ( getParent(x) != getParent(y) ) continue;
                if ( dis[y] > dis[x] + t )
                {
                    dis[y] = dis[x] + t;
                }
            }
        }
        for (b = 0; b <= n; b++) color[b] = WHITE;
        for (c = 0; c < m; c++)
        {
            x = edgeVector[c].from;
            y = edgeVector[c].to;
            t = edgeVector[c].weight;
            if ( getParent(x) != getParent(y) ) continue;
            if ( dis[y] > dis[x] + t )
            {
                dis[y] = dis[x] + t;
                //startSystem.insert( y );
                dfsForFinalAns( y );
            }
        }
        cout << "Case " << a << ": ";
        if ( startSystem.size() <= 0 ) cout << "impossible";
        else
        {
            for (setLongLongIt = startSystem.begin(); setLongLongIt != startSystem.end(); setLongLongIt++ )
            {
                printf( "%lld ", *setLongLongIt );
            }
        }
        if ( a < T ) cout << endl;
    }
    return 0;
}
