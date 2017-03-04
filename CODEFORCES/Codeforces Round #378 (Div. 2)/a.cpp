#include <bits/stdc++.h>
using namespace std;
string str;
long long a, b, c, d, e, f, g, ans = 1, prevIdx = -1;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> str;
    str = str + "A";
    for (a = 0; a < str.size(); a++)
    {
        if ( str[a]=='A' || str[a]=='E' ||   str[a]=='I' || str[a]=='O' || str[a]=='U'
             || str[a]=='Y' )
        {
            ans = max(ans, a-prevIdx);
            prevIdx = a;
        }
    }
    cout << ans;
    return 0;
}
