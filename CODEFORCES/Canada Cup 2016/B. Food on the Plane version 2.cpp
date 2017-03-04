#include <bits/stdc++.h>
using namespace std;
long long n, rowsBefore, ans;
char s;
int main()
{
    cin >> n >> s;
    if (n%4==3 || n%4==0)
    {
        n -= 2;
    }
    rowsBefore = (n/4)*2 + (n%2==0);
    ans = rowsBefore * 6 + n;
    if ( s == 'e' ) ans += 1;
    if ( s == 'd' ) ans += 2;
    if ( s == 'a' ) ans += 3;
    if ( s == 'b' ) ans += 4;
    if ( s == 'c' ) ans += 5;

    cout << ans;

    return 0;
}
