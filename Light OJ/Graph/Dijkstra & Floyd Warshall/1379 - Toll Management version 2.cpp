#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
long long T, N, M, s, t, p, u, v, c, idx, cost, highestToll, len, ans;
long long from, to, weight;
long long disFromS[SIZE], disFromT[SIZE];
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
bool cmp(const edge a, const edge b)
{
    if ( a.weight == b.weight )
    {
        if ( a.from == b.from )
        {
            return a.to < b.to;
        }
        else return a.from < b.from;
    }
    else return a.weight < b.weight;
}
struct node
{
    long long idx, cost, highestToll;
    node(){}
    node(long long idx, long long cost, long long highestToll = 0)
    {
        this->idx = idx;
        this->cost = cost;
        this->highestToll = highestToll;
    }
    const bool operator < (const node b) const
    {
        if ( cost == b.cost )
        {
            return idx < b.idx;
        }
        else return cost < b.cost;
    }
};
node nodeAr[SIZE], current, nextPick, modifiedNextPick;
vector<edge> gr[SIZE], transGr[SIZE], vectorEdge;
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
            transGr[b] = vector<edge>();
            disFromS[b] = INT_MAX;
            disFromT[b] = INT_MAX;
        }
        vectorEdge = vector<edge>();
        ans = -1;
        for (b = 0; b < M; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &c);
            gr[u].push_back( edge(u, v, c) );
            transGr[v].push_back( edge(v, u, c) );
            vectorEdge.push_back( edge(u, v, c) );
        }
        setNode = set<node>();
        disFromS[s] = 0;
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
            len = gr[idx].size();
            for (b = 0; b < len; b++)
            {
                //cout << "b = " << b << endl;
                from = gr[idx][b].from;
                to = gr[idx][b].to;
                weight = gr[idx][b].weight;
                if ( disFromS[to] > disFromS[from] + weight )
                {
                    disFromS[to] = disFromS[from] + weight;
                    setNode.insert( node(to, disFromS[to]) );
                }
            }
        }
        //cout << "disFromS ";
        for (b = 1; b <= N; b++)
        {
            //cout << "[" << b << "]" << disFromS[b];
        }
        //cout << endl;

        setNode = set<node>();
        disFromT[t] = 0;
        setNode.insert( node(t, 0, 0) );
        while( setNode.size() > 0 )
        {
            //cout << "inside while loop" << endl;
            setNodeIt = setNode.begin();
            current = *setNodeIt;
            setNode.erase( setNodeIt );
            idx = current.idx;
            cost = current.cost;
            highestToll = current.highestToll;
            len = transGr[idx].size();
            for (b = 0; b < len; b++)
            {
                //cout << "b = " << b << endl;
                from = transGr[idx][b].from;
                to = transGr[idx][b].to;
                weight = transGr[idx][b].weight;
                if ( disFromT[to] > disFromT[from] + weight )
                {
                    disFromT[to] = disFromT[from] + weight;
                    setNode.insert( node(to, disFromT[to]) );
                }
            }
        }
        //cout << "disFromT ";
        for (b = 1; b <= N; b++)
        {
            //cout << "[" << b << "]" << disFromT[b];
        }
        //cout << endl;

        sort(vectorEdge.begin(), vectorEdge.end(), cmp);
        for (b = M-1; b >= 0; b--)
        {
            from = vectorEdge[b].from;
            to = vectorEdge[b].to;
            weight = vectorEdge[b].weight;
            if ( disFromS[from] + weight + disFromT[to] <= p )
            {
                //cout << "disFromS[" << from << "] = " << disFromS[from] << endl;
                //cout << "disFromT[" << to << "] = " << disFromT[to] << endl;
                ans = weight;
                break;
            }
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
