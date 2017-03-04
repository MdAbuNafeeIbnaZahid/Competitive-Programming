#include <bits/stdc++.h>
using namespace std;
#define SIZE 9909
#define WHITE 2
#define GREY 3
#define BLACK 4
long long T, N, R, P, A, B, I, E, current, netLoss;
long long a, b, c, d, e, f, g, h;
long long parent[SIZE], dis[SIZE], color[SIZE];
struct edge
{
    long long from, to, income, expense, weight;
    edge(){}
    edge(long long from, long long to, long long income = 0, long long expense = 0)
    {
        this->from = from;
        this->to = to;
        this->income = income;
        this->expense = expense;
        weight = -(income - P*expense);
    }
};
vector<edge> edgeVector, gr[SIZE], transGr[SIZE];
stack<long long> stakForTopSort;
long long getParent(long long u)
{
    if ( parent[u] != u ) parent[u] = getParent( parent[u] );
    return parent[u];
}
void makeUnion(long long u, long long v)
{
    parent[ getParent(u) ] = getParent(v);
}
void dfsForTopSort(long long u)
{
    long long a, b, c, d, e, len = gr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( color[ gr[u][a].to ] == WHITE ) dfsForTopSort( gr[u][a].to );
    }
    color[u] = BLACK;
    stakForTopSort.push( u );
}
void dfsForSCC(long long prev, long long cur)
{
    long long a, b, c, d, e, f, len = transGr[cur].size();
    if ( color[cur] != WHITE ) return;
    color[cur] = GREY;
    makeUnion(prev, cur);
    //cout << "cur = " << cur << endl;
    for (a = 0; a < len; a++)
    {
        if ( color[ transGr[cur][a].to ] == WHITE )
        {
            dfsForSCC( cur, transGr[cur][a].to );
        }
    }
    color[cur] = BLACK;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> R >> P;
        for (b = 0; b <= N; b++)
        {
            parent[b] = b;
            dis[b] = INT_MAX;
            color[b] = WHITE;
            gr[b] = vector<edge>();
            transGr[b] = vector<edge>();
        }
        edgeVector = vector<edge>();
        stakForTopSort = stack<long long>();
        for (b = 0; b < R; b++)
        {
            scanf("%lld %lld %lld %lld", &A, &B, &I, &E);
            edgeVector.push_back( edge(A, B, I, E) );
            gr[A].push_back( edge(A, B, I, E) );
            transGr[B].push_back( edge(B, A) );
        }
        for (b = 0; b < N; b++) if ( color[b] == WHITE ) dfsForTopSort( b );
        for (b = 0; b < N; b++) color[b] = WHITE;
        //cout << "stakForTopSort.size() = " << stakForTopSort.size() << endl;
        while( !stakForTopSort.empty() )
        {
            current = stakForTopSort.top();
            stakForTopSort.pop();
            if ( color[ current ] == WHITE )
            {
                //cout << "current = " << current << endl;
                dfsForSCC( current, current );
            }
        }
        for (b = 0; b < N-1; b++)
        {
            for (c = 0; c < R; c++)
            {
                A = edgeVector[c].from;
                B = edgeVector[c].to;
                netLoss = edgeVector[c].weight;
                if ( getParent(A) != getParent(B) ) continue;
                if ( dis[A] > dis[B] + netLoss )
                {
                    dis[A] = dis[B] + netLoss;
                }
            }
        }
        for (c = 0; c < R; c++)
        {
            A = edgeVector[c].from;
            B = edgeVector[c].to;
            netLoss = edgeVector[c].weight;
            if ( getParent(A) != getParent(B) ) continue;
            if ( dis[A] > dis[B] + netLoss )
            {
                dis[A] = dis[B] + netLoss;
                break;
            }
        }
        cout << "Case " << a << ": ";
        if ( c<R ) cout << "YES";
        else cout << "NO";
        cout << endl;
    }
    return 0;
}
