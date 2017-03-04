#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, p[SIZE], weight[SIZE];
long long a, b, c, d, e, f, g, h;
double ansAr[SIZE];
vector<long long> children[SIZE];
long long dfsWeight(long long u)
{
    long long a, b, c, d, e, f, len = children[u].size();
    weight[u] = 1;
    for (a = 0;  a < len; a++)
    {
        weight[u] += dfsWeight( children[u][a] );
    }
    return weight[u];
}
void dfsET(long long u)
{
    long long a, b, c, d, e, len = children[u].size();
    for (a = 0; a < len; a++)
    {
        ansAr[ children[u][a] ] = ansAr[u]+1+ (double)(weight[u]-weight[ children[u][a] ]-1)/2;
        dfsET( children[u][a] );
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //memset(ansAr, -1, sizeof(ansAr) );
    cin >> n;
    for (a = 2; a <= n; a++)
    {
        scanf("%lld", &p[a]);
        children[ p[a] ].push_back(a);
    }
    dfsWeight(1);
    ansAr[1] = 1;
    dfsET(1);
    for (a = 1; a  <= n; a++)
    {
        printf("%lf ", ansAr[a] );
    }
    return 0;
}
