#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, N, M, a, b, ans, current;
long long i, j, k,x, y, z;
vector<long long> gr[SIZE], transGr[SIZE]; //compo[SIZE];
long long visited[SIZE], compo[SIZE];
stack<long long> stak;
void dfs1(long long u)
{
    long long len, i, j, k;
    visited[u] = 1;
    len = gr[u].size();
    for (i = 0; i < len; i++)
    {
        if ( !visited[ gr[u][i] ] ) dfs1( gr[u][i] );
    }
    stak.push(u);
}
void dfs2(long long u)
{
    long long len, i, j, k, n;
    visited[u] = 1;
    compo[u] = n;
    len = gr[u].size();
    for (i = 0; i < len; i++)
    {
        if ( !visited[ gr[u][i] ] ) dfs2( gr[u][i]  );
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ans = 0;
        stak = stack<long long>();
        memset(visited, 0, sizeof(visited));
        memset(compo, -1, sizeof(compo));
        for (j = 0; j < SIZE; j++)
        {
            gr[j] = vector<long long>();
            transGr[j] = vector<long long>();
        }
        cin >> N >> M;
        for (j = 1; j <= M; j++)
        {
            scanf("%lld %lld", &a, &b);
            gr[a].push_back(b);
            transGr[b].push_back(a);
        }
        for (j = 1; j <= N; j++)
        {
            if ( !visited[j] ) dfs1(j);
        }
        memset(visited, 0, sizeof(visited));
        while( !stak.empty() )
        {
            current = stak.top();
            //cout << "current = " << current << endl;
            stak.pop();
            if ( !visited[current] )
            {
                ans++;
                dfs2(current);
            }
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
