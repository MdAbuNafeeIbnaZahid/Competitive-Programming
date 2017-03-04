#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, ans = -1, calc;
int main()
{
    cin >> n >> m;
    ans = max(ans, 2*n);
    ans = max(ans, 3*m);
    calc = 6*((n+m)/4);
    if ( (n+m)%4==1 ) calc += 2;
    if ( (n+m)%4==2 ) calc += 3;
    if ( (n+m)%4==3 ) calc += 4;
    ans = max(ans, calc);
    cout << ans;
    return 0;
}
