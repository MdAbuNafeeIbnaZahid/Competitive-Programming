#include <bits/stdc++.h>
using namespace std;
long long getZeros(long long n)
{
    long long ret = 0, div = 5;
    while(n/div)
    {
        ret+=(n/div);
        div*=5;
    }
    return ret;
}
long long T, Q, low, high, zeros, i, j, mid;
long long maxL = 1;

int main()
{
    freopen("input.txt", "r", stdin);
    maxL = (unsigned)(~maxL) >> 1;
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lld", &Q);
        low = 1;
        high = maxL/5;
        while(low <= high)
        {
            mid = (low+high)/2;
            //cout << "low = " << low << ", mid = " << mid << ", high = " << high << endl;
            zeros = getZeros(mid*5);
            if (zeros > Q)
            {
                high = mid-1;
            }
            else if (zeros == Q) break;
            else if (zeros < Q)
            {
                low = mid+1;
            }
        }
        if (getZeros(5*mid)==Q)
        {
            printf("Case %lld: %lld\n", i, mid*5);
        }
        else
        {
            printf("Case %lld: impossible\n", i);
        }
    }
    return 0;
}
