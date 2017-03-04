#include <bits/stdc++.h>
using namespace std;
long long T, N, A, B, siz, ans;
long long i, j, k;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        //cout << "i = " << i << endl;
        siz = 0;
        ans = 0;
        cin >> N;
        //cout << "N = " << N << endl;
        for (j = 1; j < N; j++)
        {
            scanf("%lld %lld", &A, &B);
            siz = siz + A - B;
            ans = max(ans, siz);
        }
        printf("Case %lld: %lld\n", i, ans);
    }
    return 0;
}
