#include <bits/stdc++.h>
using namespace std;
#define SIZE 20009
long long T, n, m, k, d, u, v, w, idx, dis, prop, len;
long long a, b, c,  e, f, g;
long long distanceAr[SIZE];
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
struct node
{
    long long idx, dis, prop;
    node(){}
    node(long long idx, long long dis, long long prop)
    {
        this->idx = idx;
        this->dis = dis;
        this->prop = prop;
    }
    const bool operator < (const node b) const
    {
        if ( dis == b.dis )
        {
            return idx<b.idx;
        }
        return dis < b.dis;
    }
};
set<node> setNode;
set<node>::iterator setNodeIt;
node current;
vector<edge> gr[SIZE], propGr[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for ( a = 1; a <= T; a++ )
    {
        cin >> n >> m >> k >> d;
        for (b = 0; b < n; b++)
        {
            distanceAr[b] = INT_MAX;
            gr[b] = vector<edge>();
            propGr[b] = vector<edge>();
        }
        setNode = set<node>();
        distanceAr[0] = 0;
        for (b = 0; b < m; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            gr[u].push_back( edge(u, v, w) );
        }
        for (b = 0; b < k; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            propGr[u].push_back( edge(u, v, w) );
        }
        setNode.insert( node(0, 0, 0) );
        while( setNode.size() > 0 )
        {
            setNodeIt = setNode.begin();
            current = *setNodeIt;
            setNode.erase( setNodeIt );
            idx = current.idx;
            dis = current.dis;
            prop = current.prop;
            len = gr[idx].size();
            for (b = 0; b < len; b++)
            {
                u = gr[idx][b].from;
                v = gr[idx][b].to;
                w = gr[idx][b].weight;
                if ( distanceAr[v] > distanceAr[u]+w )
                {
                    distanceAr[v] = distanceAr[u]+w;
                    setNode.insert( node(v, distanceAr[v], prop) );
                }
            }
            if (prop >= d) continue;
            len = propGr[idx].size();
            for (b = 0; b < len; b++)
            {
                u = propGr[idx][b].from;
                v = propGr[idx][b].to;
                w = propGr[idx][b].weight;
                if ( distanceAr[v] > distanceAr[u]+w )
                {
                    distanceAr[v] = distanceAr[u]+w;
                    setNode.insert( node(v, distanceAr[v], prop+1) );
                }
            }
        }
        cout << "Case " << a << ": ";
        if ( distanceAr[n-1] >= INT_MAX ) cout << "Impossible" << endl;
        else cout << distanceAr[n-1] << endl;
        //if (a < T)
        //cout << endl;
    }
    return 0;
}
