#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
struct edge
{
    long long from, to, weight;
    edge()
    {
    }
    edge(long long from, long long to, long long weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
long long dis[SIZE], busyness[SIZE];
long long T, n, m, source, destination, q, w, queryDest, len;
long long a, b, c, d, e, f;
long long k, i, j;
vector<long long> gr[SIZE];
vector<edge> edgeVector;

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            dis[b] = INT_MAX;
        }
        edgeVector = vector<edge>();
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &busyness[b]);
        }
        //for (b = 1; b <= n; b++)
        //{
            //for (c = 1; c <= n; c++)
            //{
                //if ( b==c ) dis[b][c] = 0;
                //else dis[b][c] = INT_MAX;
            //}
        //}
        cin >> m;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &source, &destination);
            w =  busyness[destination] - busyness[source] ;
            //w = busyness[source] - busyness[destination];
            edgeVector.push_back( edge(source, destination, w*w*w) );
        }
        //for (k = 1; k <= n; k++)
        //{
            //for (i = 1; i <= n; i++)
            //{
                //for (j = 1; j <= n; j++)
                //{
                    //if ( dis[i][k] + dis[k][j] < dis[i][j] )
                    //{
                        //dis[i][j] = dis[i][k] + dis[k][j];
                    //}
                //}
            //}
        //}
        dis[1] = 0;
        len = edgeVector.size();
        for (b = 1; b <= n-1; b++)
        {
            for (c = 0; c < len; c++)
            {
                if ( dis[ edgeVector[c].to ] > dis[ edgeVector[c].from ] + edgeVector[c].weight )
                {
                    dis[ edgeVector[c].to ] = dis[ edgeVector[c].from ] + edgeVector[c].weight;
                }
            }
        }
        for (c = 0; c < len; c++)
        {
            if ( dis[ edgeVector[c].to ] > dis[ edgeVector[c].from ] + edgeVector[c].weight )
            {
                dis[ edgeVector[c].to ] = INT_MAX;
            }
        }
        cout << "Case " << a << ":" << endl;
        cin >> q;
        for ( b = 1; b <= q; b++ )
        {
            scanf("%lld", &queryDest);
            if ( dis[queryDest] < 3 || dis[queryDest] >= INT_MAX/2  )
            {
                printf("?\n");
            }
            else printf("%lld\n", dis[queryDest]);
        }
        //cout << endl;
    }
    return 0;
}

