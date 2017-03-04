#include <bits/stdc++.h>
using namespace std;
long long b, d, s;
long long ans;
long long calc(long long p, long long q, long long r)
{
    long long ret = 0;
    long long maxM = max(max(p, q), r);
    ret += (maxM-p);
    ret += (maxM-q);
    ret += (maxM-r);

    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> b >> d >> s;



    ans = calc(b-1, d, s-1);
//    cout << "ans = " << ans << endl;
    ans = min(ans, calc(b-1, d-1, s-1) );
    ans = min(ans, calc(b-1, d-1, s-1-1) );

    ans = min(ans, calc(b-1, d-1, s-1 ) );
    ans = min(ans, calc(b-1, d-1-1, s-1 ) );
    ans = min(ans, calc(b-1, d-1-1, s-1-1 ) );

    ans = min(ans, calc(b-1-1, d-1, s-1) );
    ans = min(ans, calc(b-1-1, d-1-1, s-1) );
    ans = min(ans, calc(b-1-1, d-1-1, s-1-1) );

    cout << ans ;

    return 0;
}
