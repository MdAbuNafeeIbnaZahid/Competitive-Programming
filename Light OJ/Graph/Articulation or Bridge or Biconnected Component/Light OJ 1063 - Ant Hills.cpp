#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, n, m, a, b;
long long tim, discoverTime[SIZE], lowTime[SIZE], isVisited[SIZE], parentAr[SIZE], ans;
long long isArticulationPoint[SIZE];
long long c, d, e, f, g, h;
vector<long long> gr[SIZE];
void dfsFindArticulationPoint(long long u)
{
    long long a, b, c, d, e, f, g, childrenCount = 0, v;
    if ( isVisited[u] )
    {
        return;
    }
    tim++;
    lowTime[u] = discoverTime[u] = tim;
    isVisited[u] = 1;
    for (a = 0; a < gr[u].size(); a++)
    {
        v = gr[u][a];
        if ( v == parentAr[u] )
        {
            continue;
        }
        if ( isVisited[v] )
        {
            lowTime[u] = min(lowTime[u], discoverTime[v]);
        }
        else
        {
            parentAr[v] = u;
            dfsFindArticulationPoint(v);
            lowTime[u] = min( lowTime[u], lowTime[v] );
            if ( discoverTime[u] <= lowTime[v] && parentAr[u] != 0 )
            {
                isArticulationPoint[u] = 1;
            }
            childrenCount++;
        }
    }
    if ( childrenCount > 1 && parentAr[u]==0 )
    {
        isArticulationPoint[u] = 1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (c = 1; c <= T; c++)
    {
        cin >> n >> m;
        ans = 0;
        for (d = 1; d <= n; d++)
        {
            gr[d] = vector<long long>();
            lowTime[d] = INT_MAX;
            isArticulationPoint[d] = 0;
            isVisited[d] = 0;
        }
        for (d = 1; d <= m; d++)
        {
            scanf("%lld %lld", &a, &b);
            gr[a].push_back( b );
            gr[b].push_back( a );
        }
        for (d = 1; d <= n; d++)
        {
            dfsFindArticulationPoint(d);
        }
        for (d = 1; d <= n; d++)
        {
            ans += isArticulationPoint[d];
        }
        cout << "Case " << c << ": " << ans << endl;
    }
    return 0;
}
