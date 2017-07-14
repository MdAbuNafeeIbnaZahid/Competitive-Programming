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


#define LL 			long long
#define PairLL		pair<long long, long long>


#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MP              make_pair
#define PUB				push_back
#define POB				pop_back

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)

#define DBG(x) cout<<#x<<" : "<<x<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


void printMapLLLL( map<LL, LL> mapToPr )
{
    LL a, b, c, d, e;
    map<LL, LL>::iterator mapIt;
    cout << endl;
    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
    {
        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
    }
    cout << endl;
}


/******   END OF HEADER *********/
#define SIZE 200009
LL n, aAr[SIZE];
LL removedUpto, lastRemoved, ans;
LL myMinIdx(LL *ar, LL xIdx, LL yIdx)
{
    if ( xIdx == INT_MAX || yIdx == INT_MAX )
    {
        return (xIdx+yIdx-INT_MAX);
    }
    if ( *(ar+xIdx) <= *(ar+yIdx) )
    {
        return xIdx;
    }
    return yIdx;
}


struct BIT
{
    LL siz, *treeAr;
    BIT(){}
    BIT(LL siz)
    {
        this->siz = siz;
        treeAr = new LL[siz+9];
        RESET(treeAr);
    }

    LL read(LL idx)
    {
        LL ret = 0;
        while( idx > 0 )
        {
            ret += treeAr[idx];
            idx -= ( idx & -idx );
        }
        return ret;
    }

    void update(LL idx, LL val)
    {
        while( idx <= siz )
        {
            treeAr[idx] += val;
            idx += ( idx & -idx );
        }
    }
};


struct segTree
{
    // This is a range min query segment tree
    // It saves the idx rather than value
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

    void init(long long *numAr, long long siz)
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
//        segAr[att] = INT_MAX;
        if (L == R)
        {
            segAr[att] = L;
            return ;
        }
        long long mid = (L+R)/2;
        build(att * 2, L, mid);
        build(att * 2 + 1, mid+1, R);
//        segAr[att] = min( segAr[att*2], segAr[att*2+1] );
        segAr[att] = myMinIdx( numAr, segAr[att*2], segAr[att*2+1] );
    }

    void update(long long att, long long L, long long R, long long pos, long long u)
    {
        if ( L == R )
        {
            segAr[att] = pos;
            numAr[pos] = u;
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

        segAr[att] = myMinIdx(numAr, segAr[att * 2], segAr[att * 2 + 1]);
    }

    long long query(long long att, long long L, long long R, long long l, long long r)
    {
        if (l > r)
        {
            return INT_MAX;
        }
        if ( r < L || R < l )
        {
            return INT_MAX;
        }

        if ( l <= L && R <= r )
        {
            return segAr[att];
        }

        long long mid = (L+R)/2;
        long long x = query(att * 2, L, mid, l, r);
        long long y = query(att * 2 + 1, mid + 1, R, l, r);

        return myMinIdx(numAr, x, y);
    }
};

segTree myMinSeg;
BIT myBit(SIZE);


void handleRemove(LL idx)
{
    LL a, b, c, d;
    if ( idx > n )
    {
        idx -= n;
    }
    myMinSeg.update(1, 1, 2*n, idx, INT_MAX);
    myMinSeg.update(1, 1, 2*n, idx+n, INT_MAX);
    myBit.update(idx, 1);
    myBit.update(idx+n, 1);
    lastRemoved = idx;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n;
//    DBG(n);
    FOR(a,1,1+n)
    {
        scanf("%lld", &aAr[a]);
        aAr[a+n] = aAr[a];
    }
    myMinSeg.init(aAr, 2*n+1);
    myMinSeg.build(1, 1, 2*n);
    while( removedUpto < n )
    {
//        DBG(removedUpto);
        LL idxToRemove = myMinSeg.query(1, 1, 2*n, lastRemoved+1, lastRemoved+n);
//        DBG(idxToRemove);
        LL addee = idxToRemove-lastRemoved;
//        DBG(addee);
        LL alreadyRemovedInRange = myBit.read(idxToRemove) - myBit.read(lastRemoved);
//        DBG(alreadyRemovedInRange);
        addee -= alreadyRemovedInRange;
//        DBG(addee);
        ans += addee;
//        DBG(ans);
        handleRemove(idxToRemove);
        removedUpto++;
    }
    cout << ans;
    return 0;
}


