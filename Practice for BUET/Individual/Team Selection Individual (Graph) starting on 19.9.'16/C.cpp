#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
struct edge
{
    long long idx, from, to, weight;
    edge(){}
    edge(long long idx,long long from, long long to, long long weight)
    {
        this->idx = idx;
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
struct node
{
    long long u, w;
    node(){}
    node(long long u, long long w)
    {
        this->u = u;
        this->w = w;
    }
    const bool operator < ( node B ) const
    {
        if ( w == B.w )
        {
            return u < B.u;
        }
        return w < B.w;
    }
};
vector<edge> vecEd, gr[SIZE];
long long n, m, L, a, b, s;
long long c, d, e, f, g, h, i;
long long dis[1009][SIZE][SIZE], parent[1009][SIZE][SIZE];
long long iniCost, finalCost, tempCost, innerTempCost;
void dijkstra(long long grNo, long long source, long long *disAr, long long *parentAr)
{
    long long a, b, c, d, e, f, len, current;
    set<node> setNode;
    set<node>::iterator setNodeIt;
    for (a = 0; a <= n; a++)
    {
        disAr[a] = L;
    }
    disAr[source] = 0;
    parentAr[source] = 0;
    setNode.insert( node(source, 0) );
    while( setNode.size() )
    {
        setNodeIt = setNode.begin();
        current = setNodeIt->u;
        setNode.erase( setNodeIt );
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( gr[current][a].idx == grNo ) continue;
            if ( disAr[ gr[current][a].to ] > disAr[current] + gr[current][a].weight )
            {
                disAr[ gr[current][a].to ] = disAr[current] + gr[current][a].weight;
                parentAr[ gr[current][a].to ] = current;
                setNode.insert( node(gr[current][a].to, disAr[ gr[current][a].to ]) );
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf("%lld %lld %lld", &n, &m, &L) == 3 )
    {
        cout << "n = " << n << ", m = " << m << ", L = " << L << endl;
        vecEd = vector<edge>();
        iniCost = 0;
        finalCost = 0;
        for (c = 0; c <= m; c++)
        {
            gr[c] = vector<edge>();
            for (d = 0; d <= n; d++)
            {
                for (e = 0; e <= n; e++)
                {
                    dis[c][d][e] = L;
                    parent[c][d][e] = -1;
                }
            }
        }
        for (c = 1; c <= m; c++)
        {
            scanf("%lld %lld %lld", &a, &b, &s);
            gr[a].push_back( edge(c, a, b, s) );
            gr[b].push_back( edge(c, b, a, s) );
            vecEd.push_back( edge(c, a, b, s) );
        }
        for (c = 1; c <= n; c++)
        {
            dijkstra(0, c, dis[0][c], parent[0][c]);
            for (d = 1; d <= m; d++)
            {
                if ( parent[0][c][ vecEd[d-1].from] == vecEd[d-1].to ||
                    parent[0][c][ vecEd[d-1].to ] == vecEd[d-1].from )
                {
                    cout << "edge " << d << " part of shortest path from " << c << endl;
                    dijkstra(d, c, dis[d][c], parent[d][c]);
                }
                else
                {
                    for (e = 1; e <= n; e++)
                    {
                        dis[d][c][e] = dis[0][c][e];
                    }
                }
            }
        }

        for (c = 0; c <= m; c++)
        {
            cout << "c = " << c << endl;
            tempCost = 0;
            for (d = 1; d <= n; d++)
            {
                cout << "d = " << d << endl;
                innerTempCost = 0;
                for (e = 1; e <= n; e++)
                {
                    cout << " dis[c][d][" << e << "] = " << dis[c][d][e] << endl;
                    innerTempCost += dis[c][d][e];
                }
                cout << "innerTempCost = " << innerTempCost << endl;
                tempCost += innerTempCost;
            }
            cout << "tempCost = " << tempCost << endl;
            if ( c == 0 )
            {
                iniCost = tempCost;
            }
            finalCost = max(finalCost, tempCost);
        }
        cout << iniCost << " " << finalCost << endl;
    }
    return 0;
}
