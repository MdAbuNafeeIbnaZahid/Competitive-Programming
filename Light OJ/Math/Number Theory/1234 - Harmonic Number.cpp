#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000009
int T, n, i, j, k,  idx;
double Har[1000009], put, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    Har[0] = 0;
    idx = 0;
    put = 0;
    for (i = 1; i < SIZE; i++)
    {
        put += ( (double)1/i );
        //cout << "i = " << i << ", put = " << put << endl;
        if ( i%100==0 )
        {
            Har[i/100] = put;
        }
    }
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%d", &n);
        //cout << "n = " << n << endl;
        ans = Har[n/100];
        //cout << "ans = " << ans << endl;
        for (j = n-(n%100)+1; j <= n; j++)
        {
            ans += ( (double)1/j );
        }
        //cout << "ans = " << ans << endl;
        printf("Case %d: %0.10lf\n", i, ans);
    }
    return 0;
}
