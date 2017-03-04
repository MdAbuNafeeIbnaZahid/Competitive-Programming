#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
#define WHITE 0
#define GREY 1
#define BLACK 2
long long n, m, k;
long long fath, son, aArray[SIZE], color[SIZE], ifChosen[SIZE], len, shouldGive[SIZE];
long long a, b, c, d;
vector<long long> gr[SIZE], revTop, trimmedRevTop;
void dfs(long long u)
{
    long long a, b, c, d, len = gr[u].size();
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( color[ gr[u][a] ] == WHITE )
        {
            dfs( gr[u][a] );
        }
    }
    color[u] = BLACK;
    revTop.push_back(u);
}
void dfs2(long long u, long long x)
{
    long long a, b, c, len = gr[u].size();
    if ( shouldGive[u] != 0 ) return;
    shouldGive[u] = x;
    for (a = 0; a < len; a++)
    {
        dfs2( gr[u][a], x );
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &fath, &son);
        gr[fath].push_back(son);
    }
    for(a = 1; a <= n; a++)
    {
        scanf("%lld", &aArray[a]);
        ifChosen[ aArray[a] ] = 1;
    }
    for (a = 1; a <= n; a++)
    {
        if ( color[a] == WHITE ) dfs(a);
    }
    len = revTop.size();
    for ( a = 0; a < len; a++ )
    {
        if ( ifChosen[ revTop[a] ] )
        {
            trimmedRevTop.push_back( revTop[a] );
        }
    }
    k = trimmedRevTop.size();
    //cout << "k = " << k << endl;
    for (a = 0; a < k; a++)
    {
        dfs2( trimmedRevTop[a], trimmedRevTop[a] );
    }
    for (a = 1; a <= n; a++)
    {
        if ( shouldGive[a] != aArray[a] )
        {
            cout << "-1" ;
            return 0;
        }
    }
    cout << k << endl;
    for (a = 0; a < k ; a++)
    {
        printf("%lld ", trimmedRevTop[a]);
    }
    return 0;
}
