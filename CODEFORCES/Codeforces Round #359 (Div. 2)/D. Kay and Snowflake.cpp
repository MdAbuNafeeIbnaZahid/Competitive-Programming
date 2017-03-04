#include <bits/stdc++.h>
using namespace std;
#define SIZE 300009
long long n, q, p[SIZE], v[SIZE];
long long a, b, c, d, e, f, g;
long long cent[SIZE], maxChildWeight[SIZE], sizeOfSubTree[SIZE], heavyChild[SIZE];
vector<long long> gr[SIZE];
long long dfs1(long long u)
{
    long long a, b, c, d, len = gr[u].size();
    sizeOfSubTree[u] = 1;
    maxChildWeight[u] = 0;
    for (a = 0; a < len; a++)
    {
        dfs1( gr[u][a] );
        sizeOfSubTree[u] += sizeOfSubTree[ gr[u][a] ];
        maxChildWeight[u] = max( maxChildWeight[u], sizeOfSubTree[ gr[u][a] ] );
    }
    return 0;
}
long long dfs2(long long u)
{
    long long a, b, c, d, e, len = gr[u].size(), ret;
    //if ( cent[u] != 0 ) return cent[u];
    if ( sizeOfSubTree[u] <= 1 )
    {
        cent[u] = u;
        return u;
    }
    for (a = 0; a < len; a++)
    {
        dfs2( gr[u][a] );
    }
    for (a = 0; a < len; a++)
    {
        if ( sizeOfSubTree[ gr[u][a] ] ==  maxChildWeight[u]  )
        {
            heavyChild[u] = gr[u][a];
        }
    }
    ret = cent[ heavyChild[u] ];
    while( ret != u )
    {
        if (  2*max(maxChildWeight[ret], sizeOfSubTree[u]-sizeOfSubTree[ret]) <= sizeOfSubTree[u]  )
        {
            break;
        }
        ret = p[ret];
    }
    cent[u] = ret;
    return cent[u];
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    //cout << "n = " << n << endl;
//    cout << "q = " << q << endl;
    for (a = 2; a <= n; a++)
    {
        scanf("%lld", &p[a]);
        gr[ p[a] ].push_back( a );
    }
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &v[a]);
    }
//    cout << "input taken" << endl;
    dfs1(1);
//    cout << "dfs1 complete " << endl;
    dfs2(1);
//    cout << "dfs2 complete" << endl;
    for (a = 1; a <= q; a++)
    {
        //cout << a << endl;
        printf("%lld\n", cent[ v[a] ]);
    }
    return 0;
}
