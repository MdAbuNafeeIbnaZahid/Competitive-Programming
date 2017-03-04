#include <bits/stdc++.h>
using namespace std;
long long T;
double AB, AC, BC, rat, ans;
long long a, b, c, d, e, f;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> AB >> AC >> BC >> rat;
        ans = sqrt(rat/(rat+1)) * AB;
        printf("Case %lld: %0.10lf\n", a, ans);
    }
    return 0;
}
