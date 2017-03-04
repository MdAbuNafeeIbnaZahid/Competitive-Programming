#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000
long long T, N, M, Q, U, V, X, Y;
long long a, b, c, d, e, f, g, h, i;
long long parent[3*SIZE], ifVis[3*SIZE];
vector<long long> gr[3*SIZE];
void dfs(long long u, long long par)
{
//    cout << "dfs called, u = " << u << ", par = " << par << endl;
    long long a, b, c, d, e, f, g, len = gr[u].size();
    if ( parent[u] ) return;
    parent[u] = par;
    for (a = 0; a < len; a++)
    {
        dfs( gr[u][a], par );
    }
    return;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> M >> Q;
        memset(parent, 0, sizeof(parent));
        //memset(ifVis, 0, sizeof(ifVis));
        for (b = 1; b <= N; b++)
        {
            gr[b] = vector<long long>();
            gr[b+SIZE] = vector<long long>();
        }
        for (b = 1; b <= M; b++)
        {
            scanf("%lld %lld", &U, &V);
            gr[U].push_back(V+SIZE);
            gr[V+SIZE].push_back(U);

            gr[V].push_back(U+SIZE);
            gr[U+SIZE].push_back(V);
        }
        for (b = 1; b <= N; b++)
        {
            if ( parent[b] ) continue;
//            cout << "b = " << b << ", dfs called" << endl;
            dfs(b, b);
        }
        cout << "Case " << a << ":" << endl;
        for (b = 1; b <= Q; b++)
        {
            scanf("%lld %lld", &X, &Y);
            if ( parent[X] == parent[Y] )
            {
                printf("Yes\n");
            }
            else printf("No\n");
        }
    }
    return 0;
}
