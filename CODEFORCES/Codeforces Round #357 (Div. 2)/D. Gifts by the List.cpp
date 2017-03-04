#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
#define WHITE 0
#define GREY 2
#define BLACK 3
long long n, m, son, father;
long long a, b, c, d, e;
long long fath[SIZE], color[SIZE], shouldGive[SIZE], choice[SIZE];
long long dfs(long long u)
{
    if ( fath[u] == 0 )
    {
        shouldGive[u] = u;
        return u;
    }
    else if ( shouldGive[u] != 0 )
    {
        return shouldGive[u];
    }
    shouldGive[u] = dfs( fath[u] );
    return shouldGive[u];
}
int main()
{
    cin >> n >> m;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &father, &son);
        fath[son] = father;
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &choice[a]);
    }
    for (a = 1; a <= n; a++)
    {

    }
    return 0;
}
