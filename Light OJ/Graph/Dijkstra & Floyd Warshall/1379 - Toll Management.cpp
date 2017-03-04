#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
long long T, N, M, s, t, p, u, v, c, idx, cost, highestToll, len;
long long i, j, k, a, b;
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
    long long idx, cost, highestToll;
    node(){}
    node(long long idx, long long cost, long long highestToll)
    {
        this->idx = idx;
        this->cost = cost;
        this->highestToll = highestToll;
    }
    const bool operator < (const node b) const
    {
        if ( highestToll == b.highestToll )
        {
            if ( cost == b.cost )
            {
                return idx<b.idx;
            }
            else return cost < b.cost;
        }
        else return highestToll > b.highestToll;
    }
};
node nodeAr[SIZE], current, nextPick, modifiedNextPick;
vector<edge> gr[SIZE];
set<node> setNode;
set<node>::iterator setNodeIt;
void printANode(node n)
{
    cout << "idx = " << n.idx << ", cost = " << n.cost << ", highestToll = " << highestToll << endl;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> M >> s >> t >> p;
        for (b = 0; b <= N; b++)
        {
            nodeAr[b].idx = b;
            nodeAr[b].cost = INT_MAX;
            nodeAr[b].highestToll = -1;
            gr[b] = vector<edge>();
        }
        for (b = 0; b < M; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &c);
            gr[u].push_back( edge(u, v, c) );
        }
        setNode = set<node>();
        nodeAr[s].cost = 0;
        setNode.insert( node(s, 0, 0) );
        while( setNode.size() > 0 )
        {
            //cout << "inside while loop" << endl;
            setNodeIt = setNode.begin();
            current = *setNodeIt;
            setNode.erase( setNodeIt );
            idx = current.idx;
            cost = current.cost;
            highestToll = current.highestToll;
            if ( cost > p )
            {
                //cout << "cost > p" << endl;
                continue;
            }
            len = gr[idx].size();
            for (b = 0; b < len; b++)
            {
                //cout << "b = " << b << endl;
                u = gr[idx][b].from;
                v = gr[idx][b].to;
                c = gr[idx][b].weight;
                if ( c+cost > p )
                {
                    //cout << "c+cost > p" << endl;
                    continue;
                }
                nextPick = nodeAr[v];
                modifiedNextPick = node(v, c+cost, max(highestToll, c) );
                if ( modifiedNextPick.highestToll > nextPick.highestToll )
                {
                    nodeAr[v] = modifiedNextPick;
                    setNode.insert( modifiedNextPick );
                    //cout << "inserted" << endl;
                    if ( nextPick.cost < modifiedNextPick.cost )
                    {
                        //setNode.insert( nextPick );
                        //cout << "inserted" << endl;
                    }
                }
                else if ( modifiedNextPick.cost < nextPick.cost )
                {
                    setNode.insert( modifiedNextPick );
                    //cout << "inserted" << endl;
                }
            }
        }
        cout << "Case " << a << ": " << nodeAr[t].highestToll << endl;;
    }
    return 0;
}
