#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define WHITE 2
#define GREY 3
#define BLACK 4
long long T, n, s, t, c, u, v, cap, ans;
long long a, b, d, e, f, g;
long long matrix[SIZE][SIZE], layer[SIZE], color[SIZE];

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
void bfs(long long source)
{
    long long a, b, d, e, f, current;
    queue<long long> Q;
    for (a = 1; a <= n; a++)
    {
        layer[a] = INT_MAX;
    }
    layer[source] = 0;
    Q.push( source );
    while( !Q.empty() )
    {
        current = Q.front();
        Q.pop();
        for (a = 1; a <= n; a++)
        {
            if ( matrix[current][a] > 0 && layer[a] >= INT_MAX )
            {
                layer[a] = layer[current] + 1;
                Q.push(a);
            }
        }
    }
}
long long dfs(long long u, long long minVal)
{
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    long long a, b, d, e, f, posRet;
    if ( u == t ) return minVal;
    for (a = 1; a <= n; a++)
    {
        if ( matrix[u][a] > 0 )
        {
            posRet = dfs(a, min(minVal, matrix[u][a]) );
            if ( posRet > 0 )
            {
                matrix[u][a] -= posRet;
                matrix[a][u] += posRet;
                return posRet;
            }
        }
    }
    color[u] = BLACK;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        //Q = queue<long long>();
        ans = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            for (d = 1; d <= n; d++)
            {
                matrix[b][d] = 0;
            }
        }
        for (b = 1; b <= n; b++)
        {
            layer[b] = INT_MAX;
        }
        cin >> s >> t >> c;
        for (b = 1; b <= c; b++)
        {
            scanf("%lld %lld %lld", &u, &v, &cap);
            matrix[u][v] += cap;
            matrix[v][u] += cap;
        }
        while(1)
        {
            bfs(s);
            if ( layer[t] >= INT_MAX ) break;
            for ( b = 1; b <= n; b++ )
            {
                color[b] = WHITE;
            }
            ans += dfs(s, INT_MAX);
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
