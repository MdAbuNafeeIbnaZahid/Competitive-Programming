#include <bits/stdc++.h>
using namespace std;
#define SIZE 69
long long T, dp[SIZE][SIZE], len;
char str[SIZE];
void printDp()
{
    long long a, b, c, d, e;
    for ( a = 0; a <= len; a++ )
    {
        for (b = 0; b <= len; b++)
        {
            cout << dp[a][b] << " ";
        }
        cout << endl;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
//    cout << "T = " << T << endl;
    for ( a = 1;  a <= T; a++)
    {
//        cout << "a = " << a << endl;
        scanf("%s", str+1);
//        cout << "str+1 = " << str+1 << endl;
        len = strlen(str+1);
//        cout << "len = " << len << endl;
        for ( b = len; b >= 1; b-- )
        {
//            cout << "b = " << b << endl;
            long long col = len - b + 1;
            long long row = 1;
//            cout << "row = " << row << endl;
//            cout << "col = " << col << endl;
            for ( c = 0; c < b; c++ )
            {
//                cout << "row = " << row << endl;
//                cout << "col = " << col << endl;
                if ( str[row] == str[col] )
                {
                    dp[row][col] = dp[row+1][col] + dp[row][col-1] + 1;
                }
                else
                {
                    dp[row][col] = dp[row+1][col] + dp[row][col-1] - dp[row+1][col-1];
                }
                row++;
                col++;
            }
        }
//        for ( b = 0; b <= len; b++ )
//        {
//            for (c = 0; c <= len; c++)
//            {
//                cout << dp[b][c] << " ";
//            }
//            cout << endl;
//        }
        cout << "Case " << a << ": " << dp[1][len] << endl;
    }
    return 0;
}
