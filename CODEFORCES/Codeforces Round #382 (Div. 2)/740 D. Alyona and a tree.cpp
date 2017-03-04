#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
struct edge
{
    long long v, w;
    edge(){}
    edge(long long v, long long w)
    {
        this->v = v;
        this->w = w;
    }
};
long long n, aAr[SIZE];
long long a, b, c, d, e, f, g, pi, wi, parentAr[SIZE], depthAr[SIZE], wAr[SIZE], ansSumAr[SIZE];
long long distantControllerAr[SIZE];
vector<edge> gr[SIZE];
edge sparseTable[SIZE][29];
void dfsGetDepth(long long u)
{
    long long a, b, c, d, e, f, g;
    for (a = 0; a < gr[u].size(); a++)
    {
        depthAr[ gr[u][a].v ] = depthAr[u] + 1;
        dfsGetDepth( gr[u][a].v );
    }
}
void buildSparseTable()
{
    long long a, b, c, d, e, f;
    for (b = 2; b <= n; b++)
    {
        sparseTable[b][0] = edge( parentAr[b], wAr[b] );
    }
    for (a = 1; a <= 20; a++)
    {
        for (b = 1; b <= n; b++)
        {
            sparseTable[b][a].v = sparseTable[ sparseTable[b][a-1].v ][ a-1 ].v;
            sparseTable[b][a].w = sparseTable[b][a-1].w + sparseTable[ sparseTable[b][a-1].v ][ a-1 ].w;
        }
    }
}
long long getDistantController(long long u)
{
    long long a, b, c, d, e, f, g, uptoDist = 0, uptoParent = u;
    for (a = 20; a >= 0; a--)
    {
        if ( uptoDist + sparseTable[uptoParent][a].w <= aAr[u] )
        {
            uptoDist += sparseTable[uptoParent][a].w;
            uptoParent = sparseTable[uptoParent][a].v;
        }
    }
    return uptoParent;
}
void prepareAnsSum(long long u)
{
    long long a, b, c, d, e, f;
    for (a = 0; a < gr[u].size(); a++)
    {
        prepareAnsSum( gr[u][a].v );
        ansSumAr[u] += ansSumAr[ gr[u][a].v ];
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
//    cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 2; a <= n; a++)
    {
        scanf("%lld %lld", &pi, &wi);
        parentAr[a] = pi;
        wAr[a] = wi;
        gr[ pi ].push_back( edge(a, wi) );
    }
    dfsGetDepth(1);
//    for (a = 1; a <= n; a++)
//    {
//        cout << "a = " << a << ", depth = " << depthAr[a] << endl;
//    }
    buildSparseTable();
    for (a = 2; a <= n; a++)
    {
        distantControllerAr[ a ] = getDistantController(a);
        ansSumAr[ parentAr[ a ] ]++;
        ansSumAr[ parentAr[ distantControllerAr[ a ] ] ]--;
    }
    prepareAnsSum(1);
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", ansSumAr[a]);
    }
    return 0;
}
