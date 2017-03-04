#include <bits/stdc++.h>
using namespace std;
#define SMALL_DIFF 0.00000000001
double n, l, v1, v2,k, low, high, g, dis, ans, mid;
int main()
{
    cin >> n >> l >> v1 >> v2 >> k;
    g = ceil(n/k);
    //cout << "g = " << g << endl;
    low = 0;
    high = l;
    while(low<high)
    {
        //cout << "low = " << low << endl;
        //cout << "high = " << high << endl;
        mid = (low + high)/2;
        //cout << "mid = " << mid << endl;
        dis = v2*mid + (g-1) * (mid * 2 * v1 * v2) / (v1+v2);
        //cout << "dis = " << dis << endl;
        if ( abs(dis - l) <= SMALL_DIFF ) break;
        if (dis > l)
        {
            high = mid - SMALL_DIFF;
        }
        else if (dis < l )
        {
            low = mid + SMALL_DIFF;
        }
    }
    ans = g * mid + (g-1) * (v2-v1) * mid / (v2+v1);
    //cout << ans << endl;
    printf("%0.10lf", ans);
    return 0;
}
