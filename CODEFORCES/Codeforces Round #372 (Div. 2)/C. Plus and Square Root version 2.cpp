#include <bits/stdc++.h>
using namespace std;
long long n;
long long a, b, c, d, e, f, g, h, cur = 2;
int main()
{
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        if (a == 1) cout << 2 << endl;
        else cout << a*(a+1)*(a+1) - (a-1) << endl;
    }
    return 0;
}
