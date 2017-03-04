#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long l1, r1, l2, r2, k, s, e, ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> l1 >> r1 >> l2 >> r2 >> k;
    s = max(l1, l2);
    e = min(r1, r2);
    ans = e-s+1;
    if ( s <= k && k <= e ) ans--;
    if ( ans <= 0 ) ans = 0;
    cout << ans;
    return 0;
}
