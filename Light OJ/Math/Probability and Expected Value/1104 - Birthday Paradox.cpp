#include <bits/stdc++.h>
using namespace std;
long long T, n;
long long a, b, c, d, e, f, g;
double prob;
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        prob = 1;
        scanf("%lld", &n);
        for (b = 2; b <= n; b++)
        {
            prob *= ( (double)(n-b+1)/n );
            if ( prob <= 0.5 ) break;
        }
        cout << "Case " << a << ": " <<  (b-1) << endl;
    }
    return 0;
}
