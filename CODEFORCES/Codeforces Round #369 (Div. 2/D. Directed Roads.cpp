#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define MOD 1000000009
long long n, aAr[SIZE], layer[SIZE], isVisited[SIZE], len, parent[SIZE], head[SIZE];
long long a, b, c, d, e, f, g, h;
struct edge
{
    long long to, idx;
    edge(){}
    edge(long long to, long long idx)
    {
        this->to = to;
        this->idx = idx;
    }
};
vector<edge> gr[SIZE];
vector<long long> cy;
void bfs(long long u)
{
    long long a, b, c, d, e, f, g, h, current, len;
    queue<long long> q;
    for (a = 0; a < SIZE; a++)
    {
        layer[a] = INT_MAX;
    }
    layer[u] = 0;
    q.push(u);
    while( q.size() )
    {
        current = q.front();
        q.pop();
        len = gr[current].size();
        cout << "current = " << current << endl;
        for (a = 0; a < len; a++)
        {
            if ( isVisited[ gr[current][a].idx ] ) continue;
            if ( layer[gr[current][a].to] >= INT_MAX )
            {
                layer[gr[current][a].to] = layer[current]+1;
                q.push(gr[current][a].to);
            }
            else
            {
                cy.push_back( layer[current] - layer[gr[current][a].to] + 1 );
            }
            isVisited[gr[current][a].idx ] = 1;
        }
    }
}
void dfs(long long u, long long v)
{
    if ( color[v] != WHITE )
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        gr[a].push_back( edge(aAr[a], a) );
        gr[ aAr[a] ].push_back( edge(a, a) );
    }
    for (a = 1; a <= n; a++)
    {
        if (  )
    }
    len = cy.size();
    for (a = 0; a < len; a++)
    {
        cout << cy[a] << " ";
    }
    return 0;
}
