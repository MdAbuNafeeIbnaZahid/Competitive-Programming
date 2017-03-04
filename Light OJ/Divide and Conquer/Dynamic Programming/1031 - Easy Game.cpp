#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, N;
long long inpAr[SIZE], conSum[SIZE], dp[SIZE][SIZE];

void printDp()
{
    long long a, b , c, d;
    for ( a = 0; a <= N; a++ )
    {
        for ( b = 0; b <= N; b++ )
        {
            cout << dp[a][b] << " ";
        }
        cout << endl;
    }
    cout << "____________" << endl;
}

void calcDp()
{
    long long a, b, c, d, e, f;
    for ( a = 0; a <= N+4; a++ )
    {
        for (b = 0; b <= N+4; b++)
        {
            dp[ a ][ b ] = a>b ? 0 : INT_MIN;
//            if ( a > b )
        }
    }
//    printDp();


    for ( a = N; a >= 1; a-- )
    {
//        cout << "a = " << a << endl;
        long long row = 1, col = N - a + 1;
        for ( b = 1; b <= N; b++ )
        {
            for ( c = row; c <= col; c++ )
            {
                dp[row][col] = max( dp[row][col], conSum[c]-conSum[row-1]-dp[c+1][col] );
                dp[row][col] = max( dp[row][col], conSum[col]-conSum[c-1]-dp[row][c-1] );
            }
            row++;
            col++;
        }
//        printDp();
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
    for ( a = 1; a <= T; a++ )
    {
        cin >> N;
        for ( b = 1; b <= N; b++ )
        {
            scanf("%lld", &inpAr[b] );
            conSum[b] = conSum[b-1] + inpAr[b];
        }
        calcDp();
//        printDp();
        long long ans = dp[1][N];
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
