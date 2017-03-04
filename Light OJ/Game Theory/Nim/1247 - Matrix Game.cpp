#include <bits/stdc++.h>
using namespace std;
long long m, n, xorVal, cell, T, pile;
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (b = 1; b <= T; b++)
    {
        xorVal = 0;
        cin >> m >> n;
        for (a = 1; a <= m; a++)
        {
            pile = 0;
            for (c = 1; c <= n; c++)
            {
                scanf("%lld", &cell);
                pile += cell;
            }
            xorVal ^= pile;
        }
        cout << "Case " << b << ": ";
        if (xorVal) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    }

    return 0;
}
