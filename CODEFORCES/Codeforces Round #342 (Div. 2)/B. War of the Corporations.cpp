#include <bits/stdc++.h>
using namespace std;

string s1, s2;

int ans = 0, pos = 0, idx = 0;

int main()
{
    cin >> s1 >> s2;

    while(idx < s1.size())
    {
        idx = s1.find(s2, idx);
        if (idx == string::npos) break;
        ans++;
        idx += s2.size();
    }


    cout << ans;
    return 0;
}
