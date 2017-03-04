#include <bits/stdc++.h>
using namespace std;
long long T, n, k, ans;
long long i,j, a, b, c;
double preAns;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lld %lld", &n, &k);
        preAns = 1;
        for (j = 0; j < k; j++)
        {
            preAns = preAns * (n-j) * (n-j) / (j+1);
        }
        ans = round(preAns);
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
