#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long T, charCount[SIZE], len, a, b, c, ans;
string str;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = INT_MAX;
        memset(charCount, 0, sizeof(charCount));
        cin >> str;
        len = str.size();
        for (b = 0; b < len; b++)
        {
            charCount[ str[b] ]++;
        }
        for (b = 'a'; b <= 'z'; b++)
        {
            ans = min(ans, charCount[b] );
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
