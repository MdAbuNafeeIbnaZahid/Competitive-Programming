#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long T, M, N, Q, xi, yi, ansPoint[SIZE][SIZE], ansAr[SIZE], number = 0, ans;
char grid[SIZE][SIZE];
bool visited[SIZE][SIZE];
long long a, b, c, d, e, f;
bool ifOk(long long x, long long y)
{
    if (x<0 || x>=M || y<0 || y>=N) return false;
    if ( visited[x][y] ) return false;
    if ( grid[x][y] == '#' ) return false;
    return true;
}
void dfs(long long x, long long y)
{
    if ( !ifOk(x,y) ) return;
    if ( grid[x][y]=='C' ) ans++;
    //cout << "x = " << x << ", y = " << y << endl;
    ansPoint[x][y] = number;
    visited[x][y] = true;
    dfs(x-1, y);
    dfs(x+1, y);
    dfs(x, y-1);
    dfs(x, y+1);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        number = 0;
        memset(ansAr, -1, sizeof(ansAr));
        memset(ansPoint, -1, sizeof(ansPoint));
        cin >> M >> N >> Q;
        for (b = 0; b < M; b++)
        {
            scanf("%s", grid[b]);
        }
        for (b = 0; b < M; b++)
        {
            //printf("%s\n", grid[b]);
        }
        cout << "Case " << a << ":" << endl;
        for (b = 0; b < Q; b++)
        {
            number++;
            memset( visited, false, sizeof(visited) );
            ans = 0;
            scanf("%lld %lld", &xi, &yi);
            //printf("%lld %lld\n", xi, yi);
            if ( ansPoint[xi-1][yi-1] == -1 ) dfs(xi-1, yi-1);
            ansAr[number] = ans;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
