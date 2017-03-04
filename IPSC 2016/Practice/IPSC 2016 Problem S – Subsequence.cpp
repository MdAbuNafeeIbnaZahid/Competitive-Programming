#include <bits/stdc++.h>
using namespace std;
long long T, a, b, c, d;
string s1, s2;
long long len1, len2, cur2, cur1;
int main()
{
    freopen("s1.in", "r", stdin);
    freopen("output.txt", "w", stdout);
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> s1 >> s2;
        len1 = s1.size();
        len2 = s2.size();
        cur2 = 0;
        for (cur1 = 0; cur1 < len1; cur1++)
        {
            if (cur2 >= len2) break;
            if ( s1[cur1] == s2[cur2] )
            {
                cur2++;
            }
        }
        if (cur2 >= len2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
