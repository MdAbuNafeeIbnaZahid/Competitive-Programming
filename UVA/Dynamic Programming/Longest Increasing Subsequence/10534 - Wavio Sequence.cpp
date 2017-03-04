#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long N, ar[SIZE], LIS[SIZE], LDS[SIZE], cur;
long long a, b, c, d, e;
set<long long> sLIS, sLDS;
int main()
{
    while(cin >> N)
    {
        memset(LIS, -1, sizeof(LIS));
        memset(LDS, -1, sizeof(LDS));
        sLIS = set<long long>();
        sLDS = set<long long>();
        for (a = 1; a <= N; a++) scanf("%lld", &ar[a]);
        LIS[1] = 1;
        LDS[1] = 1;
        sLIS.insert( ar[a] );
        sLDS.insert( ar[a] );
        for (a = 2; a <= N; a++)
        {
            cur = ar[a];
            //if ( cur[] )
        }
    }
    return 0;
}
