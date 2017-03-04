#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long a, b, c, d, e, f;
long long n, tot, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> b >> d;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &f);
        if ( f <= b ) tot += f;
        if (tot > d)
        {
            ans++;
            tot = 0;
        }
    }
    //cout << "tot = " << tot << endl;

    cout << ans ;
    return 0;
}
