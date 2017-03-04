#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
#define MOD 1000000007
#define WHITE 0
#define GRAY 1
#define BLACK 2
long long n, aAr[SIZE], color[SIZE], cnt, len, notCy, ans = 1;
long long a, b, c, d, e, f, g, h;
vector<long long> gr[SIZE], transGr[SIZE], topSorted, cy;
void dfs1(long long u)
{
    long long a, b, c, d, e;
    if ( color[u] != WHITE ) return;
    color[u] = GRAY;
    dfs1( aAr[u] );
    color[u] = BLACK;
    topSorted.push_back(u);
}
void dfs2(long long u)
{
    long long a, b, c, d, e, f, len = transGr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GRAY;
    for (a = 0; a < len; a++)
    {
        dfs2( transGr[u][a] );
    }
    cnt++;
    color[u] = BLACK;
}
long long myPow(long long n)
{
    long long a, b, c, d, e, f, ret = 1;
    for (a = 1; a <= n; a++)
    {
        ret =  ( (ret%MOD)*2 ) %MOD;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <=n; a++)
    {
        scanf("%lld", &aAr[a]);
        gr[a].push_back( aAr[a] );
        transGr[ aAr[a] ].push_back(a);
    }
    for (a = 1; a <= n; a++)
    {
        dfs1(a);
    }
    memset(color, 0, sizeof(color));
    for (a = n-1; a >= 0;a--)
    {
        cnt=0;
        dfs2( topSorted[a] );
        if (cnt >= 2) cy.push_back(cnt);
    }
    notCy = n;
    len = cy.size();
    for (a = 0;a  < len; a++)
    {
        notCy -= cy[a];
        ans = ( (ans%MOD)*( (myPow(cy[a])-2+MOD )%MOD ) )%MOD;
    }
    ans = ( (ans%MOD)*(myPow(notCy)%MOD) )%MOD;
    cout << ans;
    return 0;
}
