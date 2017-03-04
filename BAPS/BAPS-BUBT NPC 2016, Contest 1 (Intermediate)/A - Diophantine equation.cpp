#include <bits/stdc++.h>
using namespace std;
long long MAXN=1000000000;
long long T, n;
long long a, b, c, d, e=0, f, g, h, i, j;
long long rem, previous, idx, ans;
map<long long, long long> cntMap;
map<long long, long long>::iterator mapIt;
int main()
{
//    for (d = 0;  d*d*d*d <= MAXN; d++)
//    {
//        for (b = 0; b*b + d*d*d*d <= MAXN; b++)
//        {    e++;
//            cntMap[b*b + d*d*d*d]++;
//        }
//    }
//    cout<<e<<endl;
    cin >> T;
//    for (mapIt = cntMap.begin(); mapIt != cntMap.end(); mapIt++)
//    {
//        idx = mapIt->first;
//        cntMap[idx] += previous;
//        previous = cntMap[idx];
//    }
    for (i = 1; i <= T; i++)
    {
        ans = 0;
        scanf("%lld", &n);
        for (d = 0; d*d*d*d <= n; d++)
        {
            for (c = 0; c*c*c + d*d*d*d <= n; c++)
            {
                rem = n-c*c*c - d*d*d*d;
                ans += (sqrt(rem)+1);
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
