#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long T;
double a, b, c, d, s, ans, tr, baseOfTr, areaOfTr, areaOfRectangle;
long long i, j, k;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> a >> b >> c >> d;
        baseOfTr = max(a,c) - min(a,c);
        s = (baseOfTr+b+d)/2;
        areaOfTr = sqrt(s*(s-baseOfTr)*(s-b)*(s-d));
        areaOfRectangle = ( (areaOfTr * min(a,c) * 2) / baseOfTr );
        ans = areaOfTr + areaOfRectangle;
        //cout << "Case " << i << ": " << ans << endl;
        printf("Case %lld: %0.10lf\n", i, ans);
    }
    return 0;
}
