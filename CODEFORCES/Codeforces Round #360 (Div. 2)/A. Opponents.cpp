#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, d, a, b, c, e, f, g, ans, ifWin[SIZE];
string input[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> d;
    for (a = 1; a <= d; a++)
    {
        cin >> input[a];
    }

    for (a = 1; a <= d; a++)
    {
        for (b = 0; b < n; b++)
        {
            if ( input[a][b] == '0' ) break;
        }
        if (b < n)
        {
            ifWin[a] = 1;
        }
    }
    for (a = 1; a <= d; a++)
    {
        if ( ifWin[a] )
        {
            ifWin[a] += ifWin[a-1];
        }
    }
    for (a = 1; a <= d; a++)
    {
        ans = max(ans, ifWin[a]);
    }
    cout << ans ;
    return 0;
}
