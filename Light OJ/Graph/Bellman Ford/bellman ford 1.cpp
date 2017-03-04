#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
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
long long dis[109];
long long a, b, c, d, e;
long long u, v, w;
long long n, m;
edge edgeArray[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    for (a = 0; a < SIZE; a++) dis[a] = INT_MAX;
    cin >> n >> m;
    for (a = 1; a <= m; a++)
    {
        cin >> u >>  v >> w;
        edgeArray[a].from = u;
        edgeArray[a].to = v;
        edgeArray[a].weight = w;
    }
    dis[1] = 0;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            if ( dis[ edgeArray[b].to ] > dis[ edgeArray[b].from ] + edgeArray[b].weight )
            {
                dis[ edgeArray[b].to ] = dis[ edgeArray[b].from ] + edgeArray[b].weight;
            }
        }
        cout << "step = " << a << "";
        for (c = 1; c <= n; c++) cout << c << "[" << dis[c] << "] ";
        cout << endl;
    }
    return 0;
}
