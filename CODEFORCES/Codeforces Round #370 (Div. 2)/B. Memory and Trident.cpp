#include <bits/stdc++.h>
using namespace std;
string s;
long long cntU, cntR, len, ans;
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> s;
    len = s.size();
    for (a = 0; a < len; a++)
    {
        if ( s[a] == 'U' )
        {
            cntU++;
        }
        else if ( s[a] == 'D' )
        {
            cntU--;
        }
        else if ( s[a] == 'R' )
        {
            cntR++;
        }
        else
        {
            cntR--;
        }
    }
    if ( (abs(cntU) + abs(cntR) )%2 ) cout << -1;
    else cout << (abs(cntU) + abs(cntR) )/2;
    return 0;
}
