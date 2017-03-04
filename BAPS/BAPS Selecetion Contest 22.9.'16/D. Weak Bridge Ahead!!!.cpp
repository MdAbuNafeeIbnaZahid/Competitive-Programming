#include <bits/stdc++.h>
using namespace std;
long long T, N, M, num;
long long a, b, c, d, e, f, g, ans, lastN, lastM;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> N >> M;
//        cout << "N = " << N << endl;
//        cout << "M = " << M << endl;
        for (b = 1; b < N; b++)
        {
            scanf("%lld", &num);
//            cout << "num = " << num << endl;
            ans += num;
        }
        scanf("%lld", &num);
        lastN = num;
//        cout << "lastN = " << lastN << endl;
        for (b = 1; b < M; b++)
        {
            scanf("%lld", &num);
            ans += num;
        }
        scanf("%lld", &num);
        lastM = num;
//        cout << "lastM = " << lastM << endl;
        ans += min(lastN,lastM);
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
