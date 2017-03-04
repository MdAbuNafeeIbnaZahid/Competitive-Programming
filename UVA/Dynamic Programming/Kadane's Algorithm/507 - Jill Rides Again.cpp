#include <bits/stdc++.h>
using namespace std;
#define SIZE 20009
long long b, s, r, ar[SIZE];
long long bucketSum, tankSum, bs, be, ts, te;
long long a, c, d, e;
long long i, j;
long long prevBucketSum, prevBs, prevBe;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> b;
    memset(ar, 0, sizeof(ar));
    for (r = 1; r <= b; r++)
    {
        bucketSum = tankSum = INT_MIN;
        bs = be = ts = te = 0;
        prevBucketSum = prevBe = prevBs = 0;
        cin >> s;
        for (a = 0; a < s-1; a++)
        {
            scanf("%lld", &ar[a]);
        }
        for (a = 0; a < s-1; a++)
        {
            prevBucketSum = bucketSum;
            prevBs = bs;
            prevBe = be;
            if ( bucketSum+ar[a] >= ar[a] )
            {
                //cout << "bucketSum+ar[a] = " << bucketSum+ar[a] << endl;

                bucketSum = bucketSum+ar[a];
            }
            else
            {
                bucketSum = ar[a];
                bs = a+1;
            }
            be = a+2;
            if ( bucketSum > tankSum )
            {
                tankSum = bucketSum;
                ts = bs;
                te = be;
            }
            else if ( bucketSum==tankSum && (be-bs)>(te-ts) )
            {
                ts = bs;
                te = be;
            }
            else if ( bucketSum==tankSum && (be-bs)==(te-ts) && bs<ts )
            {
                ts = bs;
                te = be;
            }
        }
        if ( tankSum > 0 )
        {
            printf("The nicest part of route %lld is between stops %lld and %lld\n", r, ts, te);
        }
        else printf("Route %lld has no nice parts\n", r);
    }
    return 0;
}
