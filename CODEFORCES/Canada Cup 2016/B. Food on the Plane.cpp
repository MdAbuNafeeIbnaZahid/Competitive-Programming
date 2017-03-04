#include <bits/stdc++.h>
using namespace std;
long long n;
char s;
long long rowBefore, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> s;
    //cout << n << " " << s << endl;
    rowBefore = (ceil(n/4.0)-1);
    //cout << "rowBefore = " << rowBefore << endl;
    ans += rowBefore * 16;
    if (n%4==1 || n%4==3)
    {
        ans += 1;
    }
    else
    {
        ans += 8;
    }
    if ( s == 'e' ) ans += 1;
    if ( s == 'd' ) ans += 2;
    if ( s == 'a' ) ans += 3;
    if ( s == 'b' ) ans += 4;
    if ( s == 'c' ) ans += 5;

    cout << ans << endl;

    return 0;
}
