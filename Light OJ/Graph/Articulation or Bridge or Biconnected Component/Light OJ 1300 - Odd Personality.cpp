#include <bits/stdc++.h>
using namespace std;
#define SIZE 20009
struct edge
{
    long long to, isBridge, idxInTrans;
    edge(){}
    edge(long long to, long long idxInTrans)
    {
        this->to = to;
        this->isBridge = 0;
        this->idxInTrans = idxInTrans;
    }
};
struct DSU
{
    long long parentAr[SIZE];
    DSU(){}
    void init()
    {
        long long a, b, c, d, e, f;
        for (a = 0; a < SIZE; a++)
        {
            parentAr[a] = a;
        }
    }
    long long getParent(long long u)
    {
        if ( parentAr[u] != u )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    void makeSet(long long u, long long v)
    {
//        cout << "making set " << u << " " << v << endl;
        parentAr[ getParent(u) ] = getParent(v);
    }
};
long long T, n, m, u, v;
long long a, b, c, d, e, f, g, h;
long long tim, discoverTime[SIZE], lowTime[SIZE], parentAr[SIZE], isVisited[SIZE];
long long canStart[SIZE], ans, szx, szy;
vector< edge > gr[SIZE];
DSU myDsu;
void dfsFindBridge(long long u)
{
    long long a, b, c, d, e, v;
    if ( isVisited[u] )
    {
        return;
    }
    tim++;
    lowTime[u] = discoverTime[u] = tim;
    isVisited[u] = 1;
    for (a = 0; a < gr[u].size(); a++)
    {
        v = gr[u][a].to;
        if ( parentAr[u] == v )
        {
            continue;
        }
        if ( isVisited[v] )
        {
            lowTime[u] = min(lowTime[u], discoverTime[v]);
        }
        else
        {
            parentAr[v] = u;
            dfsFindBridge(v);
            lowTime[u] = min(lowTime[u], lowTime[v]);
            if ( discoverTime[u] < lowTime[v] /* && parentAr[u] != -1 */ )
            {
               gr[u][a].isBridge = 1;
               gr[ v ][ gr[u][a].idxInTrans ].isBridge = 1;
            }
        }
    }
}
void handleEvenPair(long long u)
{
    long long a, b, c, d, e, f, g, v, x;
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( gr[u][a].isBridge )
        {
            continue;
        }
        v = gr[u][a].to;
        for (b = 0; b < gr[v].size(); b++)
        {
            if ( gr[v][b].isBridge )
            {
                continue;
            }
            x = gr[v][b].to;
            myDsu.makeSet( u, x );
        }
    }
}
void handleCanStart(long long u)
{
    long long a, b, c, d, e, f, v;
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( gr[u][a].isBridge )
        {
            continue;
        }
        v = gr[u][a].to;
        if ( myDsu.getParent(u) == myDsu.getParent(v) )
        {
            canStart[u] = 1;
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        myDsu.init();
        cin >> n >> m;
        for (b = 0; b <= n; b++)
        {
            gr[b] = vector<edge>();
            lowTime[b] = INT_MAX;
            parentAr[b] = -1;
            isVisited[b] = 0;
            canStart[b] = 0;
        }
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &u, &v);
            szx = gr[u].size();
            szy = gr[v].size();
            gr[u].push_back( edge(v, szy) );
            gr[v].push_back( edge(u, szx) );
        }
        for (b = 0; b < n; b++ )
        {
            dfsFindBridge(b);
        }
//        for (b = 0; b < n; b++)
//        {
//            for (c = 0; c < gr[b].size(); c++)
//            {
//                if ( gr[b][c].isBridge && b<gr[b][c].to )
//                {
//                    cout << b << " " << gr[b][c].to << endl;
//                }
//            }
//        }
        for (b = 0; b < n; b++)
        {
            handleEvenPair(b);
        }
        for (b = 0; b < n; b++)
        {
            handleCanStart(b);
            ans += canStart[b];
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
