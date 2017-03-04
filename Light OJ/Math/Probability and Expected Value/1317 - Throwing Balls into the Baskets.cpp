#include <bits/stdc++.h>
using namespace std;
long long T, N, M, K, a, b, c;
double P, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {

        cin >> N >> M >> K >> P;
        ans = N*K*P;
        printf("Case %lld: %0.8lf\n", a, ans);
    }
    return 0;
}
