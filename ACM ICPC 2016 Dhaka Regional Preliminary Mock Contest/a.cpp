#include <bits/stdc++.h>
using namespace std;
long long T, n;
long long a, b, c, d, e, f, g;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (b = 1; b <= T; b++)
    {
        cin >> n;
        cout << min((long long)0, n);
        for (a = min((long long)0, n)+1; a <= max( (long long)0, n ); a++ )
        {
            printf(" %lld", a);
        }
        cout << endl;
    }
    return 0;
}
