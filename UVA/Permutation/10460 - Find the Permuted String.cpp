#include <bits/stdc++.h>
using namespace std;
string input, ans, f, l, mid = "s";
long long T, I, len, a, b, c, d, pos[40], cnt;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    while(T--)
    {
        cin >> input;
        len = input.size();
        cin >> I;
        ans = "s";
        I--;
        for (a = len-1; a >= 0; a--)
        {
            pos[a] = I%(a+1);
            I = I/(a+1);
        }
        ans[0] = input[0];
        for (a = 1; a < len; a++)
        {
            f = ans.substr(0, pos[a]);
            mid[0] = input[a];
            l = ans.substr(pos[a], a+1-pos[a]);
            ans = f + mid + l;
        }
        cout << ans << endl;
    }
    return 0;
}
