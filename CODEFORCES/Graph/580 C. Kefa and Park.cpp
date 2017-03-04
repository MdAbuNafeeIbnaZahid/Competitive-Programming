#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
#define WHITE 0
#define GRAY 1
#define BLACK 2
long long n, m, aAr[SIZE], xi, yi, ans, color[SIZE];
vector<long long> gr[SIZE];
long long a, b, c, d, e, f, g, h;
void dfs(long long u, long long cost)
{
    //cout << "dfs called for u = " << u << endl;
    long long a, b, c, d, e, len, nextCost;
    if ( color[u] != WHITE ) return;
    color[u] = GRAY;
    len = gr[u].size();
    if ( aAr[u] ) nextCost = cost+1;
    else nextCost = 0;
    if ( nextCost > m )
    {
        color[u] = BLACK;
        return;
    }
    for (a = 0; a < len; a++)
    {
        if ( color[ gr[u][a] ] == WHITE ) break;
    }
    if ( a >= len )
    {
        //cout << "u = " << u << endl;
        ans++;
    }
    for (a = 0; a < len; a++)
    {
        dfs( gr[u][a], nextCost );
    }
    color[u] = BLACK;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 1; a <= n-1; a++)
    {
        scanf("%lld %lld", &xi, &yi);
        gr[xi].push_back(yi);
        gr[yi].push_back(xi);
    }
    dfs(1, 0);
    cout << ans ;
    return 0;
}
