#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, n, m, u, v, w, q, c, s, t, k, i, j, len;
long long a, b, d, e, f, fuelNeeded;
long long dis[SIZE][SIZE], perQDis[SIZE][SIZE], fuelPrice[SIZE], minCost[SIZE];
long long vis[SIZE][SIZE];
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
struct node
{
    long long idx, cost, oilReserve;
    node(){}
    node(long long idx, long long cost, long long oilReserve)
    {
        this->idx= idx;
        this->cost = cost;
        this->oilReserve = oilReserve;
    }
    bool const operator < (node b) const
    {
        if ( cost == b.cost )
        {
            if ( oilReserve == b.oilReserve )
            {
                return idx < b.idx;
            }
            else return oilReserve < b.oilReserve;
        }
        else return cost < b.cost;
    }
};
node current, nodeArray[SIZE][SIZE], modifiedNextNode;
set<node> setNode;
set<node>::iterator setNodeIt;
edge edgeArray[1009];
query queryArray[SIZE];
vector<edge> vectorEdge, gr[SIZE];
void printANode(node n)
{
    cout << "idx = " << n.idx << ", cost = " << n.cost << ", oilReserve = " << n.oilReserve << endl;
}
void printAEdge(edge e)
{
    cout << "from = " << e.from << ", to = " << e.to << ", weight = " << e.weight << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n >> m;
        for (b = 0; b < n; b++)
        {
            scanf("%lld", &fuelPrice[b]);
            gr[b] = vector<edge>();
        }
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
            //if ( edgeArray[d].weight > c ) continue;
            dis[ edgeArray[d].from ][ edgeArray[d].to ] = min( dis[ edgeArray[d].from ][ edgeArray[d].to ], edgeArray[d].weight );
            dis[ edgeArray[d].to ][ edgeArray[d].from ] = min( dis[ edgeArray[d].to ][ edgeArray[d].from ], edgeArray[d].weight );
        }
        for (k = 0; k < n; k++)
        {
            for (i = 0; i < n; i++)
            {
                for (j = 0; j < n; j++)
                {
                    if ( dis[i][j] > dis[i][k] + dis[k][j] )
                    {
                        //cout << "i = " << i << ", j = " << j << ", updated" << endl;
                        dis[i][j] = dis[i][k] + dis[k][j];
                    }
                }
            }
        }
        for (i = 0; i < n; i++)
        {
            for (j = 0; j < n; j++)
            {
                if ( i!=j && dis[i][j] < INT_MAX )
                {
                    gr[i].push_back( edge(i, j, dis[i][j]) );
                    //cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl;
                }
            }
        }


        for (b = 0; b < q; b++)
        {
            s = queryArray[b].s;
            t = queryArray[b].t;
            c = queryArray[b].c;
            for (d = 0; d < n; d++)
            {
                //minCost[d] = INT_MAX;
                for (e = 0; e <= c; e++)
                {
                    nodeArray[d][e].idx = d;
                    nodeArray[d][e].cost = INT_MAX;
                    nodeArray[d][e].oilReserve = e;
                }
            }
            //nodeArray[s][0].cost = 0;
            setNode = set<node>();
            for (e = 0; e <= c; e++)
            {
                nodeArray[s][e].idx = s;
                nodeArray[s][e].cost = e*fuelPrice[s];
                nodeArray[s][e].oilReserve = e;
                //setNode.insert( nodeArray[s][e] );
            }
            setNode.insert( node(s, 0, 0 ) );
            memset(vis, 0, sizeof(vis));
            while( setNode.size() > 0 )
            {
//                cout << "setNode.size() = " << setNode.size() << endl;
                setNodeIt = setNode.begin();
                current = *setNodeIt;
//                printANode( current );
                setNode.erase( setNodeIt );
                if ( vis[current.idx][current.oilReserve] ) continue;
                vis[current.idx][current.oilReserve] = 1;
                if ( current.oilReserve > c )
                {
                    cout << "current.oilReserve = " << current.oilReserve << endl;
                    continue;
                }
                len = gr[current.idx].size();
                for (d = 0; d < len; d++)
                {
                    if ( gr[current.idx][d].weight > c ) continue;
                    modifiedNextNode.idx = gr[current.idx][d].to;

                    fuelNeeded = gr[current.idx][d].weight - current.oilReserve;
                    if (fuelNeeded <= 0)
                    {
                        modifiedNextNode.cost = current.cost;
                        modifiedNextNode.oilReserve = current.oilReserve - gr[current.idx][d].weight;
                    }
                    else
                    {
                        modifiedNextNode.cost = current.cost + fuelNeeded*fuelPrice[current.idx];
                        modifiedNextNode.oilReserve = 0;
                    }

                    if ( modifiedNextNode < nodeArray[ gr[current.idx][d].to ][modifiedNextNode.oilReserve] )
                    {
                        nodeArray[ gr[current.idx][d].to ][modifiedNextNode.oilReserve] = modifiedNextNode;
                        setNode.insert( modifiedNextNode );
                    }
                    //else if ( modifiedNextNode.oilReserve > nodeArray[ gr[current.idx][d].to ].oilReserve )
                    //{
                        //setNode.insert( modifiedNextNode );
                    //}

                    fuelNeeded = c - current.oilReserve;
                    modifiedNextNode.cost = current.cost + fuelNeeded*fuelPrice[current.idx];
                    modifiedNextNode.oilReserve = c - gr[current.idx][d].weight;
                    if ( modifiedNextNode < nodeArray[ gr[current.idx][d].to ][ modifiedNextNode.oilReserve ] )
                    {
                        nodeArray[ gr[current.idx][d].to ][ modifiedNextNode.oilReserve ] = modifiedNextNode;
                        setNode.insert( modifiedNextNode );
                    }
                    //else if ( modifiedNextNode.oilReserve > nodeArray[ gr[current.idx][d].to ].oilReserve )
                    //{
                        //setNode.insert( modifiedNextNode );
                    //}
                }
            }
            //for (d = 0; d < n; d++)
            //{
                //for ( e = 0; e < n; e++ )
                //{
                    //dis[d][e] = INT_MAX;
                    //if ( d==e ) dis[d][e] = 0;
                //}
            //}
            //for (d = 0; d < m; d++)
            //{
                //if ( edgeArray[d].weight > c ) continue;
                //dis[ edgeArray[d].from ][ edgeArray[d].to ] = edgeArray[d].weight * fuelPrice[ edgeArray[d].from ];
                //dis[ edgeArray[d].to ][ edgeArray[d].from ] = edgeArray[d].weight * fuelPrice[ edgeArray[d].to ];
            //}
            //for (k = 0; k < n; k++)
            //{
                //for (i = 0; i < n; i++)
                //{
                    //for (j = 0; j < n; j++)
                    //{
                        //if ( dis[i][j] > dis[i][k] + dis[k][j] )
                        //{
                            //cout << "i = " << i << ", j = " << j << ", updated" << endl;
                            //dis[i][j] = dis[i][k] + dis[k][j];
                        //}
                    //}
                //}
            //}
            //for (i = 0; i < n; i++)
            //{
                //for (j = 0; j < n; j++)
                //{
                    //cout << "dis[" << i << "][" << j << "] = " << dis[i][j] << endl;
                //}
            //}

            //cout << "s = " << s << ", t = " << t << endl;
            if ( nodeArray[t][0].cost >= INT_MAX )
            {
                printf("impossible\n");
            }
            else printf("%lld\n", nodeArray[t][0].cost);
        }
    }
    return 0;
}
