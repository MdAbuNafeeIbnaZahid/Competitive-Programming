#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define HOR_DO_NOTHING 1
#define VER_DO_NOTHING 2
#define HOR_FIRE 3
#define VER_FIRE 4
long long R, C, N, grid[SIZE][SIZE], rowCnt[SIZE], colCnt[SIZE], row, col, ans;
long long dp[SIZE][SIZE], sol[SIZE][SIZE], rowMin[SIZE], colMin[SIZE];
long long maxR, maxC;
long long a, b, c, d, e, f, g, h;
vector<char> vecChar;
vector<long long> vecLL;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> R >> C >> N;
        cout << "R = " << R << ", C = " << C << ", N = " << N << endl;
        if (R+C+N==0) break;
        memset(grid, 0, sizeof(grid));
        for (a = 1; a <= R; a++)
        {
            for (b = 1; b <= C; b++)
            {
                dp[a][b] = INT_MAX;
                rowMin[a] = INT_MAX;
                colMin[b] = INT_MAX;
            }
        }
        ans = 0;
        vecChar = vector<char>();
        vecLL = vector<long long>();
        for (a = 1; a <= N; a++)
        {
            scanf("%lld %lld", &row, &col);
            rowMin[row] = min(rowMin[row], col);
            colMin[col] = min(colMin[col], row);
        }
        cout << "rowMin" << endl;
        for (a = 1; a <= R; a++)
        {
            cout << "a = " << rowMin[a] << endl;
        }
        cout << endl;
        for (a = 1; a <= R; a++)
        {
            for (b = 1; b <= C; b++)
            {
                if ( rowMin[a] > b )
                {
                    if ( dp[a][b] > dp[a-1][b] )
                    {
                        dp[a][b] = dp[a-1][b];
                        sol[a][b] = HOR_DO_NOTHING;
                    }
                }
                else
                {
                    if ( dp[a][b] > dp[a-1][b]+1 )
                    {
                        dp[a][b] = dp[a-1][b]+1;
                        sol[a][b] = HOR_FIRE;
                    }
                }

                if ( colMin[b] > a )
                {
                    if ( dp[a][b] > dp[a][b-1] )
                    {
                        dp[a][b] = dp[a][b-1];
                        sol[a][b] = VER_DO_NOTHING;
                    }
                }
                else
                {
                    if ( dp[a][b] > dp[a][b-1]+1 )
                    {
                        dp[a][b] = dp[a][b-1]+1;
                        sol[a][b] = VER_FIRE;
                    }
                }
            }
        }
        cout << "dp" << endl;
        for (a = 1; a <= R; a++)
        {
            for (b = 1; b <= C; b++)
            {
                cout << dp[a][b] << " ";
            }
            cout << endl;
        }
        cout << "sol" << endl;
        for (a = 1; a <= R; a++)
        {
            for (b = 1; b <= C; b++)
            {
                cout << sol[a][b] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
