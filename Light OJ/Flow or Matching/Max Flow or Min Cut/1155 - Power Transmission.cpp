#include <bits/stdc++.h>
using namespace std;
#define SIZE 309
#define DHAKA 305
#define BARISHAL 0
#define WHITE 5
#define GREY 6
#define BLACK 7
long long T, N, cap[SIZE], M, i, j, C, posX, posY, B, D, startOrEnd, ans;
long long layer[SIZE], color[SIZE];
long long a, b, d, e, f, g, h;
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
vector<edge> gr[SIZE];
long long head(long long n)
{
    return n;
}
long long mid(long long n)
{
    return n+100;
}
long long tail(long long n)
{
    return n+200;
}
void bfs(long long u)
{
    long long a, b, c, d, current, len;
    queue<long long> Q;
    for (b = 1; b <= N; b++)
    {
        layer[head(b)] = INT_MAX;
        layer[mid(b)] = INT_MAX;
        layer[tail(b)] = INT_MAX;
    }
    layer[BARISHAL] = 0;
    layer[DHAKA] = INT_MAX;
    Q.push(BARISHAL);
    while( !Q.empty() )
    {
        current = Q.front();
        //cout << "layer[" << current << "] = " << layer[current] << endl;
        Q.pop();
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( layer[ gr[current][a].to ] >= INT_MAX && gr[current][a].cap > 0 )
            {
                layer[ gr[current][a].to ] = layer[current]+1;
                Q.push( gr[current][a].to );
            }
        }
    }
}
long long dfs(long long u, long long minVal)
{
    long long a, b, c, d, current, len, posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( u == DHAKA ) return minVal;
    len = gr[u].size();
    for ( a = 0; a < len; a++ )
    {
        if ( gr[u][a].cap > 0 )
        {
            posRet = dfs( gr[u][a].to, min(minVal, gr[u][a].cap) );
            if ( posRet > 0 )
            {
                gr[u][a].cap -= posRet;
                gr[ gr[u][a].to ][ gr[u][a].revIdx ].cap += posRet;
                return posRet;
            }
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
        len = gr[a].size();
        if (len <= 0) continue;
        cout << a << " : ";
        for (b = 0; b < len; b++)
        {
            cout << "(" << gr[a][b].to << "," << gr[a][b].cap << ") ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            gr[ head(b) ] = vector<edge>();
            gr[ mid(b) ] = vector<edge>();
            gr[ tail(b) ] = vector<edge>();
        }
        gr[BARISHAL] = vector<edge>();
        gr[DHAKA] = vector<edge>();
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &cap[b]);

            gr[ head(b) ].push_back( edge(head(b), mid(b), cap[b], 0) );
            gr[ mid(b) ].push_back( edge(mid(b), head(b), 0, 0) );

            gr[ mid(b) ].push_back( edge(mid(b), tail(b), cap[b], 0) );
            gr[ tail(b) ].push_back( edge(tail(b), mid(b), 0, 0) );
        }
        cin >> M;
        for (b = 1; b <= M; b++)
        {
            scanf("%lld %lld %lld", &i, &j, &C);
            posX = gr[head(j)].size();
            posY = gr[tail(i)].size();
            gr[tail(i)].push_back( edge(tail(i), head(j), C, posX) );
            gr[head(j)].push_back( edge(head(j), tail(i), 0, posY) );
        }
        cin >> B >> D;
        for (b = 1; b <= B; b++)
        {
            scanf("%lld", &startOrEnd);
            posX = gr[head(startOrEnd)].size();
            posY = gr[BARISHAL].size();
            gr[BARISHAL].push_back(edge(0, head(startOrEnd), INT_MAX, posX));
            gr[head(startOrEnd)].push_back(edge(head(startOrEnd), BARISHAL, 0, posY));
        }
        for (b = 1; b <= D; b++)
        {
            scanf("%lld", &startOrEnd);
            posX = gr[DHAKA].size();
            posY = gr[tail(startOrEnd)].size();
            gr[tail(startOrEnd)].push_back(edge(tail(startOrEnd), DHAKA, INT_MAX, posX));
            gr[DHAKA].push_back( edge(DHAKA, tail(startOrEnd), 0, posY) );
        }
        //printGraph();
        while(1)
        {
            //cout << "inside while " << endl;
            bfs(BARISHAL);
            //cout << "layer[DHAKA] = " << layer[DHAKA] << endl;
            if ( layer[DHAKA] >= INT_MAX ) break;
            for (b = 1; b <= N; b++)
            {
                color[head(b)] = WHITE;
                color[mid(b)] = WHITE;
                color[tail(b)] = WHITE;
            }
            color[BARISHAL] = WHITE;
            color[DHAKA] = WHITE;
            ans += dfs(BARISHAL, INT_MAX);
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
