#include <bits/stdc++.h>
using namespace std;
string n, ansStr;
long long a, b, c, d, e, f, len;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    ansStr = n;
    len = ansStr.size();
    for (a = len-1; a >= 0; a--)
    {
        ansStr += n[a];
    }
    cout << ansStr;
    return 0;
}
