#include <bits/stdc++.h>
using namespace std;
#define SIZE 300009
long long n, q, type, xi, ti, ifRead[SIZE], ans, idx;
long long a, b, c, d, e, f, g;
struct noti
{
    long long x, idx;
    noti(){}
    noti(long long x, long long idx)
    {
        this->x = x;
        this->idx = idx;
    }
};
noti current;
queue<noti> bucket[SIZE], Q;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &type);
        if (type == 1)
        {
            scanf("%lld", &xi);
            ans++;
            //unRead[xi]++;
            idx++;
            bucket[xi].push( noti(xi, idx) );
            Q.push( noti(xi, idx) );
        }
        else if (type == 2)
        {
            scanf("%lld", &xi);
            while( !bucket[xi].empty() )
            {
                current = bucket[xi].front();
                bucket[xi].pop();
                if ( !ifRead[ current.idx ] )
                {
                    ans--;
                    ifRead[ current.idx ] = 1;
                }
            }
            //ans -= unRead[xi];
            //startIdx[xi] += unRead[xi];
            //unRead[xi] = 0;
            //bucket[xi] = vector<long long>();
        }
        else if (type == 3)
        {
            scanf("%lld", &ti);
            while( Q.size() && Q.front().idx <= ti )
            {
                current = Q.front();
                Q.pop();
                if( !ifRead[current.idx] )
                {
                    ifRead[current.idx] = 1;
                    ans--;
                }
            }
//            if (ti > upto)
//            {
//                for (b = upto; b < ti; b++)
//                {
//                    current = v[b];
//                    if ( /*bucket[current].size() &&*/ bucket[current][ startIdx[current] ] <= ti )
//                    {
//                        unRead[ current ] -- ;
//                        ans -- ;
//                        //bucket[current].erase( bucket[current].begin() );
//                        startIdx[current]++;
//                    }
//                }
//                upto = ti;
//            }
        }
        printf("%lld\n", ans);
    }
    return 0;
}
