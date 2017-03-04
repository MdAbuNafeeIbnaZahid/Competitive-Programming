#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, isGiven[SIZE], pos[SIZE], low, high;
long long a, b, c, d, e, f, g, h, ans = INT_MAX;
string s;
long long getMinWidth()
{
    long long a, b, c, d, e, f, g, ret = INT_MAX, low = INT_MAX, high = INT_MIN;
    for (a = 'a'; a <= 'z'; a++)
    {
        if ( isGiven[a] )
        {
            if( pos[a] == -1 ) return INT_MAX;
            low = min(low, pos[a]);
            high = max(high, pos[a]);
        }
    }
    for (a = 'A'; a <= 'Z'; a++)
    {
        if ( isGiven[a] )
        {
            if( pos[a] == -1 ) return INT_MAX;
            low = min(low, pos[a]);
            high = max(high, pos[a]);
        }
    }
    ret = high - low+1;
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> s;
    //cout << "s = " << s << endl;
    memset(pos, -1, sizeof(pos));
    for (a = 0; a < n; a++)
    {
        //cout << s[a] << endl;
        isGiven[ s[a] ] = 1;
    }
    for (a = 0; a < n; a++)
    {
        //cout << "a = " << a << endl;
        pos[ s[a] ] = a;
        ans = min(ans, getMinWidth());
        //cout << "ans = " << ans << endl;
    }
    cout << ans << endl;
    return 0;
}
