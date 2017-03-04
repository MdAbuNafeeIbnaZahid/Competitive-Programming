#include <bits/stdc++.h>
using namespace std;
#define SIZE 59
long long T, N, M, ar[SIZE][SIZE], Mi[SIZE], minimum[SIZE], bMin, bMinCop, p;
long long current, ans;
long long a, b, c, d, e, f, g;
vector<long long> prime, power;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for  (a = 1; a <= T; a++)
    {
        ans = 1;
        prime = vector<long long>();
        power = vector<long long>();
        bMin = 0;
        memset(ar, 0, sizeof(ar));
        memset(Mi, 0, sizeof(Mi));
        memset(minimum, 0, sizeof(minimum));
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &Mi[b]);
            for (c = 1; c <= Mi[b]; c++)
            {
                scanf("%lld", &ar[b][c]);
            }
        }
        for (b = 1; b <= N; b++)
        {
            minimum[b] = INT_MAX;
            for (c = 1; c <= Mi[b]; c++)
            {
                minimum[b] = min(minimum[b], ar[b][c]);
            }
        }
        for (b = 1; b <= N; b++)
        {
            bMin += minimum[b];
        }
        bMinCop = bMin;
        for (b = 2; b <= sqrt(bMinCop+9); b++)
        {
            p = 0;
            while(bMinCop%b==0)
            {
                bMinCop /= b;
                p++;
            }
            if (p>0)
            {
                prime.push_back( b );
                power.push_back( p );
            }
        }
        if (bMinCop>1)
        {
            prime.push_back( bMinCop );
            power.push_back( 1 );
        }
        for (b = 1; b <= N; b++)
        {
            bMinCop = bMin - minimum[b];
            for (c = 1; c <= Mi[b]; c++)
            {
                current = bMinCop + ar[b][c];
                for (d = 0; d < prime.size(); d++)
                {
                    p = 0;
                    while( current % prime[d] == 0 )
                    {
                        current /= prime[d];
                        p++;
                    }
                    power[d] = min(p, power[d]);
                }
            }
        }
        for (b = 0; b < prime.size(); b++)
        {
            for (c = 0; c < power[b]; c++)
            {
                ans *= prime[b];
            }
        }
        printf("Case #%lld: %lld\n", a, ans);
    }
    return 0;
}
