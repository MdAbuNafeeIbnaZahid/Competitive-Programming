#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
long long T, R, C, rowXor[SIZE], colXor[SIZE], lose = 1, num;;
long long a, b,  d, e, f;
vector<long long> grid[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        lose = 1;
        cin >> R >> C;
        for (b = 0; b < R; b++)
        {
            grid[b] = vector<long long>();
            for (d = 0; d < C; d++)
            {
                scanf("%lld", &num);
                grid[b].push_back( num );
            }
        }
        memset(rowXor, 0, sizeof(rowXor) );
        memset(colXor, 0, sizeof(colXor) );
        for (b = 0; b < R; b++)
        {
            rowXor[b] = 0;
            for (d = 0; d < C; d++)
            {
                rowXor[b] ^= grid[b][d];
            }
        }
        for (b = 0; b < C; b++)
        {
            colXor[b] = 0;
            for (d = 0; d < R; d++)
            {
                colXor[b] ^= grid[d][b];
            }
        }
        for (b = 0; b < R-1; b++)
        {
            if ( rowXor[b] ) lose = 0;
        }
        for (b = 0; b < C-1; b++)
        {
            if (colXor[b] ) lose = 0;
        }
        if (lose)
        {
            cout << "Case " << a << ": lose" << endl;
        }
        else
        {
            cout << "Case " << a << ": win" << endl;
        }
    }
    return 0;
}
