#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define WHITE 1
#define GREY 2
#define BLACK 3
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
long long T, n, m, x, y, t, stripLen, totalEdges, outDegree;
long long a, b, c, d, e, f, g, h, i, j;
set<long long> startSet;
vector<edge> gr[SIZE], edgeVector;
long long color[SIZE], dis[SIZE], visited[SIZE], predecessor[SIZE];
set<long long>::iterator setIt;
vector<long long> vertexVector;
stack<long long> stak;
long long dfs1(long long from, long long to)
{
    vector<edge>::iterator vectorEdgeIteraator;
    long long a, b, c, d, e, len = gr[to].size();
    if ( visited[to] )
    {
        if ( dis[to] <= INT_MIN+99 )
        {
            cout << "from = " << from << endl;
            dis[from] = INT_MIN;
            return 1;
        }
        return 0;
    }
    visited[to] = 1;
    if ( dis[to] <= INT_MIN )
    {
        cout << "from = " << from << endl;
        dis[from] = INT_MIN;
        return 1;
    }
    for (a = 0; a < len; a++)
    {
        if ( dfs1(to, gr[to][a].to ) == 1 )
        {
            cout << "to = " << to << endl;
            dis[to] = INT_MIN;
            return 1;
        }
    }
    return 0;
}

long long dfs2(long long u)
{
    long long a, b, c, d, e, len = gr[u].size();
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    for (a = 0; a < len; a++) dfs2( gr[u][a].to );
    color[u] = BLACK;
    vertexVector.push_back( u );
}

long long dfsForFindingNegativeCycle(long long u)
{
    cout << "u = " << u << endl;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( color[ predecessor[u] ] == WHITE )
    {
        dfsForFindingNegativeCycle( predecessor[u] );
    }
    else if ( color[ predecessor[u] ] == GREY )
    {
        cout << "predecessor[u] = " << predecessor[u] << " dis marked as INT_MIN" << endl;
        dis[ predecessor[u] ] = INT_MIN;
    }
    color[u] = BLACK;
}

void printALongLongVector(vector<long long> vec)
{
    long long a, b, c, len = vec.size();
    for (a = 0; a < len; a++)
    {
        cout << vec[a] << " ";
    }
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            gr[b] = vector<edge>();
            color[b] = WHITE;
            dis[b] = INT_MAX;
            visited[b] = 0;
            predecessor[b] = -1;
        }
        edgeVector = vector<edge>();
        startSet = set<long long>();
        stak = stack<long long>();
        cin >> n >> m;
        for (c = 0; c < m; c++)
        {
            scanf("%lld %lld %lld", &x, &y, &t);
            gr[x].push_back( edge(x, y, t) );
            edgeVector.push_back( edge(x, y, t) );
        }
        for ( d = 0; d < n; d++ )
        {
            cout << "d = " << d << endl;
            vertexVector = vector<long long>();
            dfs2(d);
            printALongLongVector( vertexVector );
            stripLen = vertexVector.size();
            if ( !stripLen ) continue;
            for (c = 0; c < stripLen; c++)
            {
                dis[ vertexVector[c] ] = INT_MAX;
                color[ vertexVector[c] ] = WHITE;
            }
            dis[ vertexVector[stripLen-1] ] = 0;
            //totalEdges = 0;
            //for (b = 0; b < stripLen; b++)
            //{
                //totalEdges += gr[ vertexVector[b] ].size();
            //}
            for (b = 0; b < stripLen-1; b++)
            {
                for (c = 0; c < stripLen; c++)
                {
                    x = vertexVector[c];
                    outDegree = gr[x].size();
                    for (e = 0; e < outDegree; e++)
                    {
                        y = gr[x][e].to;
                        t = gr[x][e].weight;
                        if ( dis[y] > dis[x] + t )
                        {
                            dis[y] = dis[x] + t;
                            predecessor[y] = x;
                        }
                    }
                    //y = edgeVector[c].to;
                    //t = edgeVector[c].weight;

                }
                //cout << "step " << b+1 << endl;
                for (c = 0; c < stripLen; c++)
                {
                    //cout << vertexVector[c] << "[" << dis[ vertexVector[c] ] << "] ";
                }
                //cout << endl << endl;

            }
            //for (c = 0; c < m; c++)
            //{
                //x = edgeVector[c].from;
                //y = edgeVector[c].to;
                //t = edgeVector[c].weight;
                //if ( dis[y] > dis[x] + t )
                //{
                    //dis[y] = INT_MIN;
                //}
            //}
            for (c = 0; c < stripLen; c++)
            {
                x = vertexVector[c];
                outDegree = gr[x].size();
                for (e = 0; e < outDegree; e++)
                {
                    y = gr[x][e].to;
                    t = gr[x][e].weight;
                    if ( dis[y] > dis[x] + t )
                    {
                        //cout << "y = " << y << endl;
                        //dis[y] = INT_MIN;
                        dis[y] = dis[x] + t;
                        predecessor[y] = x;
                        cout << y <<" updated at last iteration " << endl;
                    }
                }
                //y = edgeVector[c].to;
                //t = edgeVector[c].weight;
            }

            //cout << "step " << stripLen << endl;
            for (c = 0; c < stripLen; c++)
            {
                cout << vertexVector[c] << "[" << predecessor[ vertexVector[c] ] << "] " << endl;
            }


            for (c = 0; c < stripLen; c++)
            {
                dfsForFindingNegativeCycle( vertexVector[c] );
            }

            //cout << endl << endl;

            for (c = stripLen-1; c >= 0; c--)
            {
                dfs1( vertexVector[c], vertexVector[c] );
            }
        }

        for (b = 0; b < n; b++)
        {
            if ( dis[b] <= INT_MIN+5 ) startSet.insert( b );
        }
        cout << "Case " << a << ": ";
        if ( startSet.size() )
        {
            for ( setIt = startSet.begin(); setIt != startSet.end(); setIt++ )
            {
                printf("%lld ", *setIt);
            }
        }
        else cout << "impossible";
        cout << endl;
    }
    return 0;
}
