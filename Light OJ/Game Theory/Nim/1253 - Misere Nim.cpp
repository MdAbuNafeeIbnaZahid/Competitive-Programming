#include <bits/stdc++.h>
using namespace std;
long long T, k, xorVal, n, greaterThanOneFlag;
long long a, b, c, d, e;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        greaterThanOneFlag = 0;
        cin >> k;
        for (b = 1; b <= k; b++)
        {
            scanf("%lld", &n);
            if (n>1) greaterThanOneFlag = 1;
            xorVal ^= n;
        }
        cout << "Case " << a << ": " ;
        if ( greaterThanOneFlag )
        {
            if ( xorVal ) cout << "Alice";
            else cout << "Bob";
        }
        else
        {
            if ( !xorVal ) cout << "Alice";
            else cout << "Bob";
        }
        cout << endl;
    }
    return 0;
}
