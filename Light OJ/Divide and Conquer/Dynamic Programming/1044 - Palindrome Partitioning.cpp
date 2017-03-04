#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T;
long long len, dp[SIZE];
char str[SIZE];
bool isPalin[SIZE][SIZE];
void printIsPalin()
{
    long long a, b, c, d, e, f;
    for ( a = 0; a <= len; a++ )
    {
        for ( b = 0; b <= len; b++ )
        {
            cout << isPalin[a][b] << " ";
        }
        cout << endl;
    }
}
void myClear()
{
    long long a, b, c, d, e;
    for ( a = 1; a <= len+5; a++ )
    {
        dp[a] = INT_MAX;
        for (b = 1; b <= len+5; b++)
        {
            isPalin[a][b] = false;
        }
    }

}
void calcIsPalin()
{
    long long a, b, c, d,e, f;
    for ( a = 1; a <= len; a++ )
    {
        for ( b = 1; b <= len; b++ )
        {
            isPalin[a][b] = (a>=b);
        }
    }
//    printIsPalin();
//    cout << endl << "____________" << endl;;
    for ( a = len-1; a >= 1; a-- )
    {
        long long row = 1, col = len-a+1;
        for ( b = 1; b <= len; b++ )
        {
            isPalin[row][col] = ( str[row] == str[col] ) && isPalin[row+1][col-1];
            row++;
            col++;
        }
    }
}
void calcDp()
{
    long long a, b, c, d, e, f;
    dp[0] = 0;
    dp[1] = 1;
    for ( a = 2; a <= len; a++ )
    {
        dp[a] = dp[a-1] + 1;
        for ( b = 1; b <= a; b++ )
        {
            if ( isPalin[b][a] )
            {
                dp[a] = min(dp[a], dp[b-1]+1 );
            }
        }
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
    for ( a = 1;  a <= T; a++ )
    {
        scanf("%s", str+1);
        len = strlen(str+1);
        myClear();
//        memset(isPalin, 0, sizeof(isPalin) );
//        memset(dp, -1, sizeof(dp) );
        calcIsPalin();
//        printIsPalin();
        calcDp();
        long long ans = dp[ len ];
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
