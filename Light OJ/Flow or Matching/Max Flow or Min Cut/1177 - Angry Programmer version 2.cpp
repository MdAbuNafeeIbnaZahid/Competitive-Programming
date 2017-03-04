#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define WHITE 3
#define GREY 4
#define BLACK 5
long long T, M, W, cost, i, j, c, posX, posY, layer[SIZE], ans, addee;
long color[SIZE];
long long a, b, d, e, f, g;
struct edge
{
    long long from, to, cap, revIdx;
    edge(){}
    edge(long long from, long long to, long long cap, long long revIdx)
    {
        this->from = from;
        this->to = to;
        this->cap = cap;
        this->revIdx = revIdx;
    }
};
long long head(long long n)
{
    return n;
}
long long tail(long long n)
{
    if ( n == 1 || n == M ) return n;
    return n+60;
}
vector<edge> graph[SIZE];
void bfs(long long u)
{
    long long a, b, current, len = graph[u].size();
    queue<long long> Q;
    for (a= 1; a <= M; a++)
    {
        layer[head(a)] = layer[tail(a)]= INT_MAX;
    }
    layer[u] = 0;
    Q.push(u);
    while( !Q.empty() )
    {
        //cout << "Q.size() = " << Q.size() << endl;
        current = Q.front();
        if ( current == M ) break;
        Q.pop();
        //cout << "layer[" << current << "] = " << layer[current] << endl;

        len = graph[current].size();
        for (a = 0; a < len; a++)
        {
            if ( layer[ graph[current][a].to ] >= INT_MAX && graph[current][a].cap > 0 )
            {
                layer[ graph[current][a].to ] = layer[current]+1;
                Q.push(graph[current][a].to);
            }
        }
    }
}
long long dfs(long long u, long long minVal)
{
    //cout << "u = " << u << endl;
    long long a, b, c, d, posRet, len = graph[u].size();
    if ( color[u] != WHITE ) return 0;
    if ( u== M ) return minVal;
    //cout << "minVal = " << minVal << endl;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( graph[u][a].cap > 0 && layer[ graph[u][a].to ] == layer[u]+1 )
        {
            posRet = dfs( graph[u][a].to, min(minVal, graph[u][a].cap) );
        }
        if ( posRet > 0 )
        {
            graph[u][a].cap -= posRet;
            graph[ graph[u][a].to ][ graph[u][a].revIdx ].cap += posRet;
            return posRet;
        }
    }
    color[u] = BLACK;
    return 0;
}
void printGraph()
{
    long long a, b, c, d, e, len;
    for (a = 0; a < SIZE; a++)
    {
        if ( graph[a].size() <= 0 ) continue;
        cout << a << ": ";
        len = graph[a].size();
        for (b = 0; b < len; b++)
        {
            cout << "(" << graph[a][b].to << "," << graph[a][b].cap << ") ";
        }
        cout << endl;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        //cin >> M >> W;
        scanf("%lld %lld", &M, &W);
        for (b = 1; b <= M; b++)
        {
            graph[ head(b) ] = vector<edge>();
            graph[ tail(b) ] = vector<edge>();
        }
        for (b = 2; b <= M-1; b++)
        {
            scanf("%lld", &cost);
            //cout << "cost = " << cost << endl;
            graph[tail(b)].push_back( edge(tail(b), head(b), cost, 0) );
            graph[head(b)].push_back( edge(head(b), tail(b), 0, 0) );
        }
        for (b = 1; b <= W; b++)
        {
            scanf("%lld %lld %lld", &i, &j, &c);
            posX = graph[head(i)].size();
            posY = graph[tail(j)].size();
            graph[head(i)].push_back( edge(head(i), tail(j), c, posY) );
            graph[tail(j)].push_back( edge(tail(j), head(i), 0, posX) );

            posX = graph[head(j)].size();
            posY = graph[tail(i)].size();
            graph[head(j)].push_back( edge(head(j), tail(i), c, posY) );
            graph[tail(i)].push_back( edge(tail(i), head(j), 0, posX) );
        }
        //printGraph();
        while(1)
        {
            bfs(1);
            //cout << "layer[M] = " << layer[M] << endl;
            if ( layer[M] >= INT_MAX ) break;
            //cout << "coloring loop will start now" << endl;
            for (b = 1; b <= M; b++)
            {
                color[head(b)] = color[tail(b)] = WHITE;
            }
            //cout << "dfs will be called right now " << endl;
            addee = dfs(1, INT_MAX);
            if (addee <= 0) break;
            //cout << "addee = " << addee << endl;
            ans += addee;
        }
        //cout << "Case " << a << ": " << ans << endl;
        printf("Case : %lld\n", ans);
    }
    return 0;
}
