#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
int n, m, max3, max2, share, ans = INF, prevMax2, prevMax3;
int share2, share3;
int main()
{
    cin >> n >> m;
    max2 = n*2;
    max3 = m*3;
    share2 = share3 = share = min( max2, max3 )/6;

    //shifting 2
    while(share2 > 0)
    {
        prevMax2 = max2;
        max2 = max2 + share2*2;
        if (prevMax2 >= max3) share2 = 0;
        else share2 = min(max2, max3)/6 - (prevMax2-1)/6;
    }

    ans = min(ans, max(max2, max3) );


    max2 = n*2;
    max3 = m*3;
    while(share3 > 0)
    {
        prevMax3 = max3;
        max3 = max3 + share3*3;
        if (prevMax3 > max2) share3 = 0;
        else share3 = min(max2, max3)/6 - (prevMax3-1)/6;
    }


    ans = min(ans, max(max2, max3) );
    cout << ans;

    return 0;
}
