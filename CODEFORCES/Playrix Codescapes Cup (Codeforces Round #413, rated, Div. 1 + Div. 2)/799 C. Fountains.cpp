#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
#define SIZE 100009
struct segTree
{
    // This is a range max query segment tree
    long long *segAr, *numAr;
    long long siz;
    segTree(){}
    segTree(long long *numAr, long long siz)
    {
        long long a, b, c, d, e;
        this->siz = siz;
        this->numAr = new long long[siz+9];
        for (a = 0; a < siz; a++)
        {
            this->numAr[a] = numAr[a];
        }
        segAr = new long long[ (siz+9) * 4];
    }

    void build(long long att, long long L, long long R)
    {
        segAr[att] = INT_MIN;
        if (L == R)
        {
            segAr[att] = numAr[L];
            return ;
        }
        long long mid = (L+R)/2;
        build(att * 2, L, mid);
        build(att * 2 + 1, mid+1, R);
    }

    void update(long long att, long long L, long long R, long long pos, long long u)
    {
        if ( L == R )
        {
            segAr[att] = u;
            return ;
        }

        long long mid = (L+R)/2;
        if ( pos <= mid )
        {
            update(att * 2, L, mid, pos, u);
        }
        else
        {
            update(att * 2 + 1, mid + 1, R, pos, u);
        }

        segAr[att] = max(segAr[att * 2], segAr[att * 2 + 1]);
    }

    long long query(long long att, long long L, long long R, long long l, long long r)
    {
        if (l > r)
        {
            return INT_MIN;
        }
        if ( r < L || R < l )
        {
            return INT_MIN;
        }

        if ( l <= L && R <= r )
        {
            return segAr[att];
        }

        long long mid = (L+R)/2;
        long long x = query(att * 2, L, mid, l, r);
        long long y = query(att * 2 + 1, mid + 1, R, l, r);

        return max(x, y);
    }
};
long long n, c, d, bAr[SIZE], pAr[SIZE];
char monAr[SIZE];
long long nullAr[SIZE], ans, coinBuAr[SIZE], diaBuAr[SIZE];
int main()
{
//    freopen("input.txt", "r", stdin);
    long long i, j, k, l, m;

    segTree coinSeg(nullAr, SIZE), diaSeg(nullAr, SIZE), mixSeg(nullAr, SIZE);
    long long remC, remD;

    coinSeg.build(1, 1, SIZE);
    diaSeg.build(1, 1, SIZE);


    cin >> n >> c >> d;
    for (i = 1; i <= n; i++)
    {
        long long posAns = INT_MIN;
        remC = c;
        remD = d;
        scanf("%lld %lld %c", &bAr[i], &pAr[i], &monAr[i]);
        if ( monAr[i] == 'C' )
        {
            if ( pAr[i] <= remC )
            {
                remC -= pAr[i];
                posAns = bAr[i];
            }
        }
        else if ( monAr[i] == 'D' )
        {
            if ( pAr[i] <= remD )
            {
                remD -= pAr[i];
                posAns = bAr[i];
            }
        }
        long long fromCoin = coinSeg.query(1, 1, SIZE, 1, remC);
        if ( fromCoin == 0 )
        {
            fromCoin = INT_MIN;
        }
        ans = max(ans, posAns+fromCoin);

        long long fromDia = diaSeg.query(1,1, SIZE, 1, remD);
        if ( fromDia == 0 )
        {
            fromDia = INT_MIN;
        }
        ans = max(ans, posAns + fromDia);

        long long already;
        if ( monAr[i] == 'C' )
        {
            coinBuAr[ pAr[i] ] = max(coinBuAr[ pAr[i] ], bAr[i] );
            coinSeg.update(1, 1, SIZE, pAr[i], coinBuAr[ pAr[i] ] );
        }
        else if ( monAr[i] == 'D' )
        {
            diaBuAr[ pAr[i] ] = max(diaBuAr[ pAr[i] ], bAr[i]);
            diaSeg.update(1, 1, SIZE, pAr[i], diaBuAr[ pAr[i] ]);
        }
    }

    cout << ans ;





    return 0;
}
