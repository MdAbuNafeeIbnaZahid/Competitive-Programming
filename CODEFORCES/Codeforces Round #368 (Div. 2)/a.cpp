#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long a,b, c, d, e, f, g, h, ifCol;
long long n, m;
char grid[SIZE][SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= m; b++)
        {
            cin >> grid[a][b];
            if ( grid[a][b] == 'C' || grid[a][b] == 'M' || grid[a][b]=='Y' ) ifCol = 1;
        }
    }
    if (ifCol) cout << "#Color";
    else cout << "#Black&White";
    return 0;
}
