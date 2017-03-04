#include <bits/stdc++.h>
using namespace std;
long long n, m, ans, start, addee;
long long a, b, c, d, e, f;
int main()
{
    cin >> n >> m;
    for (a = 1; a <= min(n, m); a++)
    {
        addee = 0;
        start = ceil((double)a/5) * 5 - a;
        if (start <= max(n, m))
        {
            addee = 1 + (max(n,m)-start)/5;
        }
        if ( a%5 ==0  ) addee = max(n, m)/5;
        //cout << "a = " << a << ", adddee = " << addee << endl;
        ans += addee;
    }
    cout << ans << endl;
    return 0;
}
