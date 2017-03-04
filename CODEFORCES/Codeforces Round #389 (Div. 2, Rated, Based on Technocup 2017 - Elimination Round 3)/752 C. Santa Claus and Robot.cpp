#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, ans;
char str[SIZE];
long long x, y, d, maxD;
long long a, b, c;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    //cout << "n = " << n << endl;
    scanf("%s", str);
    for (a = 0; a < n; a++)
    {
        if ( str[a] == 'L' )
        {
            x--;
        }
        else if (str[a] == 'R')
        {
            x++;
        }
        else if (str[a] == 'U')
        {
            y++;
        }
        else
        {
            y--;
        }
        d = abs(x) + abs(y);
        maxD = max(maxD, d);
        if ( d < maxD )
        {
            ans++;
            d = 0;
            maxD = 0;
            x = 0;
            y = 0;
            a--;
        }
    }
    ans++;
    cout << ans;
    return 0;
}
