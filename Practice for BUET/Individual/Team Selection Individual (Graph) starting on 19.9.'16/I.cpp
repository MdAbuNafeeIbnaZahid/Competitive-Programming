#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long R, C, N, grid[SIZE][SIZE], rowCnt[SIZE], colCnt[SIZE], row, col, ans;
long long maxR, maxC;
long long a, b, c, d, e, f, g, h;
vector<char> vecChar;
vector<long long> vecLL;
int main()
{
    while(1)
    {
        cin >> R >> C >> N;
        if (R+C+N==0) break;
        memset(grid, 0, sizeof(grid));
        memset(rowCnt, 0, sizeof(rowCnt));
        memset(colCnt, 0, sizeof(colCnt));
        ans = 0;
        vecChar = vector<char>();
        vecLL = vector<long long>();
        for (a = 1; a <= N; a++)
        {
            scanf("%lld", &row, &col);
            if ( grid[row][col] == 0 )
            {
                grid[row][col] = 1;
                rowCnt[row]++;
                colCnt[col]++;
            }
        }
        while(1)
        {
            maxR = 0;
            for (a = 1; a <= R; a++)
            {
                if ( rowCnt[a] > rowCnt[maxR] )
                {
                    maxR = a;
                }
            }
            maxC = 0;
            for (a = 1; a <= C; a++)
            {
                if ( colCnt[a] > colCnt[maxC] )
                {
                    maxC = a;
                }
            }
            if ( maxR==0 && maxC==0 ) break;
            ans++;
            if ( rowCnt[maxR] > colCnt[maxC] )
            {

            }
            else
            {

            }
        }
    }
    return 0;
}
