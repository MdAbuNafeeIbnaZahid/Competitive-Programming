#include <bits/stdc++.h>
using namespace std;
long long i, j, ans;
long long a, b, c,d, e, f, current, currentAns;
int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf("%lld %lld", &i, &j) != EOF )
    {
        ans = INT_MIN;
        for (a = min(i, j); a <= max(i, j); a++)
        {
            current = a;
            currentAns = 1;
            while( current != 1 )
            {
                if (current%2)
                {
                    current = 3*current+1;
                }
                else current/=2;
                currentAns++;
            }
            ans = max(ans, currentAns);
        }
        printf("%lld %lld %lld\n", i, j, ans);
    }
    return 0;
}
