#include <bits/stdc++.h>
using namespace std;
char gen;
int n, a, b, ans = 0, i, j, k, mAr[400], fAr[400];

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        cin >> gen >> a >> b;
        if (gen == 'M')
        {
            for (j = a; j <= b; j++)
            {
                mAr[j]++;
            }
        }
        if (gen == 'F')
        {
            for (j = a; j <= b; j++)
            {
                fAr[j]++;
            }
        }
    }
    for (i = 1; i <= 366; i++)
    {
        ans = max(ans,  2*min( mAr[i], fAr[i] ) );
    }
    cout << ans;
    return 0;
}
