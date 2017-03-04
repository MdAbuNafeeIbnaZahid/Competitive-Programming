#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, n, m, u, v, w, q, c, s, t, k, i, j;
long long a, b, d, e, f;
long long dis[SIZE][SIZE], perQDis[SIZE][SIZE], fuelPrice[SIZE];
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
struct query
{
    long long c, s, t;
    query(){}
    query(long long c, long long s, long long t)
    {
        this->c = c;
        this->s = s;
        this->t = t;
    }
};
edge edgeArray[SIZE];
query queryArray[SIZE];
vector<edge> vectorEdge;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n >> m;
        for (b = 0; b < n; b++) scanf("%lld", &fuelPrice[b]);
        for (b = 0; b < m; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            edgeArray[b].from = u;
            edgeArray[b].to = v;
            edgeArray[b].weight = w;
        }
        cin >> q;
        for (b = 0; b < q; b++)
        {
            scanf("%lld %lld %lld", &c, &s, &t);
            queryArray[b].c = c;
            queryArray[b].s = s;
            queryArray[b].t = t;
        }
        cout << "Case " << a << ":" << endl;
        for (b = 0; b < q; b++)
        {
            for (d = 0; d < n; d++)
            {
                for ( e = 0; e < n; e++ )
                {
                    dis[d][e] = INT_MAX;
                    if ( d==e ) dis[d][e] = 0;
                }
            }
            for (d = 0; d < m; d++)
            {
                if ( edgeArray[d].weight > c ) continue;
                dis[ edgeArray[d].from ][ edgeArray[d].to ] = edgeArray[d].weight * fuelPrice[ edgeArray[d].from ];
                dis[ edgeArray[d].to ][ edgeArray[d].from ] = edgeArray[d].weight * fuelPrice[ edgeArray[d].to ];
            }
            for (k = 0; k < n; k++)
            {
                for (i = 0; i < n; i++)
                {
                    for (j = 0; j < n; j++)
                    {
                        if ( dis[i][j] > dis[i][k] + dis[k][j] )
                        {
                            cout << "i = " << i << ", j = " << j << ", updated" << endl;
                            dis[i][j] = dis[i][k] + dis[k][j];
                        }
                    }
                }
            }
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl;
                }
            }
            s = queryArray[b].s;
            t = queryArray[b].t;
            cout << "s = " << s << ", t = " << t << endl;
            printf("%lld\n", dis[s][t]);
        }
    }
    return 0;
}
