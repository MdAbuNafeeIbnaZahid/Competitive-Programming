#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
struct edge
{
    long long from, to, isBridge, idxInTrans;
    edge(){}
    edge(long long from, long long to, long long idxInTrans)
    {
        this->from = from;
        this->to = to;
        this->isBridge = 0;
        this->idxInTrans = idxInTrans;
    }
};
long long T, n, m, u, v;
vector<edge> gr[SIZE];
vector<long long> decomposedGr[SIZE];
long long a,b, c, d, e, f, g, ans, tim, szx, szy, leavesCount;
long long parentAr[SIZE], lowTime[SIZE], discoverTime[SIZE], isVisited[SIZE];
long long compoIdx[SIZE];
void dfsFindBridge(long long u)
{
    long long a, b, c, d, e, f, v;
    if ( isVisited[u] )
    {
        return;
    }
    tim++;
    lowTime[u] = discoverTime[u] = tim;
    isVisited[u] = 1;
    for (a = 0; a < gr[u].size(); a++ )
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
            if ( discoverTime[u] < lowTime[v] )
            {
                gr[u][a].isBridge = 1;
                gr[v][ gr[u][a].idxInTrans ].isBridge = 1;
            }
        }
    }
}
void dfsDecompose(long long u, long long idx)
{
//    cout << "u = " << u << ", idx = " << idx << endl;
    long long a, b, c, d, e, f, v;
    if ( compoIdx[u] != -1 )
    {
        return;
    }
    compoIdx[u] = idx;
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( gr[u][a].isBridge )
        {
            continue;
        }
        v = gr[u][a].to;
        dfsDecompose(v, idx);
    }
}
void buildDecomposedGr()
{
    long long a, b, c, d, e, f, g, h, v;
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < gr[a].size(); b++)
        {
            if ( gr[a][b].isBridge == 0 )
            {
                continue;
            }
            v = gr[a][b].to;
            decomposedGr[ compoIdx[a] ].push_back( compoIdx[v] );
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
//        cout << "a = " << a << endl;
        cin >> n >> m;
        leavesCount = 0;
        for (b = 0; b < n; b++)
        {
            gr[b] = vector<edge>();
            decomposedGr[b] = vector<long long>();
            lowTime[b] = INT_MAX;
            isVisited[b] = 0;
            compoIdx[b] = -1;
        }
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &u, &v);
            szx = gr[u].size();
            szy = gr[v].size();
            gr[u].push_back( edge(u, v, szy) );
            gr[v].push_back( edge(v, u, szx) );
        }
        dfsFindBridge(0);
        for (b = 0; b < n; b++)
        {
//            cout << "b = " << b << endl;
            dfsDecompose(b, b);
        }
//        for (b = 0; b < n; b++)
//        {
//            cout << "b = " << b << ", compoIdx = " << compoIdx[b] << endl;
//        }
        buildDecomposedGr();
        for (b = 0; b < n; b++)
        {
            leavesCount += (decomposedGr[b].size()==1);
        }
        ans = leavesCount/2 + leavesCount%2;
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
