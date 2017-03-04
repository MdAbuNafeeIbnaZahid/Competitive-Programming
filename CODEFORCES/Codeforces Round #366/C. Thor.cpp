#include <bits/stdc++.h>
using namespace std;
#define SIZE 300009
long long unRead[SIZE];
long long n, q, ans, type, xi, ti, upto, current, idx;
long long a, b, c, d, e, f;
vector<long long> v, bucket[SIZE], startIdx[SIZE];
vector<long long>::iterator vecIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &type);
        if (type == 1)
        {
            scanf("%lld", &xi);
            ans++;
            unRead[xi]++;
            idx++;
            bucket[xi].push_back( idx );
            v.push_back( xi );
        }
        else if (type == 2)
        {
            scanf("%lld", &xi);
            ans -= unRead[xi];
            unRead[xi] = 0;
            bucket[xi] = vector<long long>();
        }
        else if (type == 3)
        {
            scanf("%lld", &ti);
            if (ti > upto)
            {
                for (b = upto; b < ti; b++)
                {
                    current = v[b];
                    if ( bucket[current].size() && bucket[current][0] <= ti )
                    {
                        unRead[ current ] -- ;
                        ans -- ;
                        bucket[current].erase( bucket[current].begin() );
                    }
                }
                upto = ti;
            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
