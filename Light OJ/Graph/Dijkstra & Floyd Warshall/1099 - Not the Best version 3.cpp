#include <bits/stdc++.h>
using namespace std;
#define SIZE 5009
struct node
{
    long long idx, shortest, secondShortest;
    node(){}
    node(long long idx, long long shortest, long long secondShortest)
    {
        this->idx = idx;
        this->shortest = shortest;
        this->secondShortest = secondShortest;
    }
    const bool operator < (const node b) const
    {
        if ( shortest == b.shortest )
        {
            if ( secondShortest == b.secondShortest )
            {
                return idx < b.idx;
            }
            else return secondShortest < b.secondShortest;
        }
        else return shortest < b.shortest;
    }
};
struct edge
{
    long long from, to, weight;
    edge(){}
    edge(long long from, long long to, long long weight )
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
long long T, N, R, u, v, w, len, from, to, weight, idx, shortest, secondShortest;
long long a, b, c, d, e, f, g;
node nodeAr[SIZE], current;
vector<edge> gr[SIZE];
vector<edge>::iterator vectorEdgeIt;
set<node> nodeSet;
set<node>::iterator nodeSetIt;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> R;
        for (b = 1; b <= N; b++)
        {
            nodeAr[b].idx = b;
            nodeAr[b].shortest = INT_MAX;
            nodeAr[b].secondShortest = INT_MAX;
            gr[b] = vector<edge>();
        }
        nodeSet = set<node>();
        nodeAr[1].shortest = 0;
        for (b = 1; b <= R; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            gr[u].push_back( edge(u, v, w) );
            gr[v].push_back( edge(v, u, w) );
        }
        nodeSet.insert( nodeAr[1] );
        while( nodeSet.size() > 0 )
        {
            nodeSetIt = nodeSet.begin();
            current = *nodeSetIt;
            idx = current.idx;
            nodeSet.erase( nodeSetIt );
            len = gr[ current.idx ].size();
            for (b = 0; b < len; b++)
            {
                from = gr[current.idx][b].from;
                to = gr[current.idx][b].to;
                weight = gr[current.idx][b].weight;
                if ( nodeAr[to].shortest > nodeAr[idx].shortest + weight )
                {
                    nodeAr[to].secondShortest = nodeAr[to].shortest;
                    nodeAr[to].shortest = nodeAr[idx].shortest + weight;
                    nodeSet.insert( node(to, nodeAr[to].shortest, nodeAr[to].secondShortest) );
                }
                if ( nodeAr[to].shortest < nodeAr[idx].shortest + weight
                    && nodeAr[to].secondShortest > nodeAr[idx].shortest + weight )
                {
                    nodeAr[to].secondShortest = nodeAr[idx].shortest + weight;
                    nodeSet.insert( node(to, nodeAr[to].shortest, nodeAr[to].secondShortest) );
                }
                if ( nodeAr[to].secondShortest > nodeAr[idx].secondShortest + weight )
                {
                    nodeAr[to].secondShortest = nodeAr[idx].secondShortest + weight;
                    nodeSet.insert( node(to, nodeAr[to].shortest, nodeAr[to].secondShortest) );
                }
            }
        }
        cout << "Case " << a << ": " << nodeAr[N].secondShortest << endl;
    }
    return 0;
}
