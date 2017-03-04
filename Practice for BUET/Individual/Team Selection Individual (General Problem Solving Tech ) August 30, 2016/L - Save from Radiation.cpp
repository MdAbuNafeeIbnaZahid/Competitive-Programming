#include <bits/stdc++.h>
using namespace std;
long long T, N;
long long a, b, c, d, e, f, check, ans;
int main()
{   //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        scanf("%lld", &N);
        printf("Case %lld: ", a);
        check = N;
        while(check)
        {
            ans++;
            check /= 2;
        }
        cout << ans << endl;
    }
    return 0;
}
