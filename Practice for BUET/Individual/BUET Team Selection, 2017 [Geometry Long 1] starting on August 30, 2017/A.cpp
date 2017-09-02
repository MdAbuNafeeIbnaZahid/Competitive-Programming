#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
//typedef tree<
//int,
//null_type,
//less<int>,
//rb_tree_tag,
//tree_order_statistics_node_update>
//ordered_set;
//

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
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define SPRIME 10007
#define BPRIME 1000000007


//void printVecLL(vector<LL> vecToPr)
//{
//    LL a, b, c, d, e;
//    for ( a= 0; a < vecToPr.size(); a++)
//    {
//        printf("%lld ", vecToPr[a]);
//    }
//    printf("\n");
//}
//
//
//void printSetLL(set<long long> setLLToPr)
//{
//    long long a, b, c;
//    set<long long>::iterator setLLIt;
//    for (setLLIt = setLLToPr.begin(); setLLIt != setLLToPr.end(); setLLIt++)
//    {
//        cout << *setLLIt << " ";
//    }
//    cout << endl;
//}
//
//
//
//void printMapLLLL( map<LL, LL> mapToPr )
//{
//    LL a, b, c, d, e;
//    map<LL, LL>::iterator mapIt;
//    cout << endl;
//    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
//    {
//        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
//    }
//    cout << endl;
//}
//
//
//void printLLArray( LL *ar, LL si, LL ei )
//{
//    LL a, b, c, d, e;
//    FOR(a, si, ei+1)
//    {
//        printf("ar[ %lld ] = %lld\n\n", a, ar[a]);
//    }
//}
//
//
//void  printSetPair( set<PairLL> givenSetPair )
//{
//    for ( auto it : givenSetPair )
//    {
//        cout << "(" << it.first << ", " << it.second << ")" << endl;
//    }
//    cout << endl;
//}
//
//void printVecPair( vector<PairLL> givenVecPair )
//{
//    for ( auto it : givenVecPair )
//    {
//        cout << "(" << it.first << ", " << it.second << ")" << endl;
//    }
//    cout << endl;
//}
//


void ILL(LL &u)
{
    LL a, b, c, d;
    scanf("%lld", &u);
}

void ILL2(LL &u, LL &v)
{
    LL a, b, c, d, e;
    scanf("%lld %lld", &u, &v);
}

void ILL3(LL &u, LL &v, LL &w)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld", &u, &v, &w);
}



LL dirR[] = {1, -1, 0, 0};
LL dirC[] = {0, 0, 1, -1};


LL bigMod(LL a, LL b, LL M)
{
    if ( b == 0 ) return 1%M;
    LL x = bigMod(a, b/2, M);
    x = (x*x)%M;
    if ( b&1LL )
    {
        x = (x*a)%M;
    }
    return x;
}

LL getGcd(LL u, LL v)
{
    if ( u > v )
    {
        swap(u, v);
    }
    if ( u == 0 )
    {
        return v;
    }
    return getGcd(v%u, u);
}


struct DSU
{
    LL *parentAr, *countAr;
    LL siz;
    DSU(LL siz)
    {
        LL a, b, c,d ;
        this->siz = siz;
        parentAr = new LL[siz];
        countAr = new LL[siz];
        FOR(a,0,siz)
        {
            parentAr[a] = a;
            countAr[a] = 1;
        }
    }
    LL getParent( LL u )
    {
        LL ret;
        if ( parentAr[u] != u )
        {
            parentAr[u] = getParent( parentAr[u] );
        }
        return parentAr[u];
    }
    void makePair(LL u, LL v)
    {
        if ( getParent(u) == getParent(v) )
        {
            return ;
        }
        countAr[ getParent(v) ] += countAr[ getParent(u) ];
        parentAr[ getParent(u) ] = getParent( v );
    }
    LL getCount( LL u )
    {
        return countAr[ getParent(u) ];
    }
};


struct BIT
{
    LL *treeAr;
    LL siz;
    BIT(){}
    BIT(LL siz)
    {
        this->siz = siz;
        treeAr = new long long[siz+9];
        RESET( treeAr);
    }
    long long read(long long idx)
    {
        long long sum = 0;
        while(idx > 0)
        {
            sum += treeAr[ idx ];
            idx -= (idx & -idx);
        }
        return sum;
    }
    void update(long long idx, long long val)
    {
        while(idx<=siz)
        {
            treeAr[idx] += val;
            idx += (idx & -idx);
        }
    }
};


struct Triple
{
    LL u, v, w;
    Triple(){}
    Triple(long long u, long long v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
    bool operator < (const Triple B) const
    {
        if ( u == B.u )
        {
            if ( v == B.v )
            {
                return w < B.w;
            }
            return v < B.v;
        }
        return u < B.u;
    }
};



/******   END OF HEADER *********/
#define SIZE
#define eps (1e-9)


/******  Monotone Convex Hull Algo by Nafee *****/
struct point
{
    long long x, y;
    point(){}
    point(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
    point operator - (point B)
    {
        point ret;
        ret.x = x - B.x;
        ret.y = y - B.y;
        return ret;
    }
    const bool operator < (point B) const
    {
        if ( x == B.x )
        {
            return y < B.y;
        }
        return x < B.x;
    }
};
bool cmpPoint(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
long long crossPr(point A, point B)
{
    long long ret = A.x*B.y - A.y*B.x;
    return ret;
}
vector<point> findConHull(vector<point> givenPoints)
{
    long long a, b, c, d, e, f, t, len = givenPoints.size(), siz;
    vector<point> ret;
    sort(givenPoints.begin(), givenPoints.end());
    for (a = 0;a < len; a++)
    {
        siz = ret.size();
        while( siz >= 2 && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    t = ret.size();
    len = givenPoints.size();
    for (a = len-1; a >= 0; a--)
    {
        siz = ret.size();
        while( siz >= 2+t && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    return ret;
}


LL T, n, d;

vector<point> givenPoints, convexPoints;
double ans;


double getDis(point A, point B)
{
    LL u, v, x, y;
    LL a, b, c;
    u = A.x;
    v = A.y;
    x = B.x;
    y = B.y;
//    DBG( d );
//    DBG4(u, v, x, y);
//    if ( abs(u-x)==d && abs(v-y)==d )
//    {
////        cout << " should be circular " << endl;
//        return PI*d/2.0;
//    }
//    cout << "non circular segment " << endl;
    return sqrt( (u-x)*(u-x) + (v-y)*(v-y) );
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c,e, f;
    cin >> T;
    FOR(a,1,1+T)
    {
        cin >> n >> d;
        givenPoints = vector<point>();
        ans = 0;
        FOR(b,1,1+n)
        {
            LL xi, yi;
            ILL2(xi, yi);
            givenPoints.push_back( point(xi, yi) );
//            givenPoints.PUB( point(xi+d, yi) );
//            givenPoints.PUB( point(xi-d, yi) );
//            givenPoints.PUB( point(xi, yi+d) );
//            givenPoints.PUB( point(xi, yi-d) );
        }
        convexPoints = findConHull( givenPoints );
        LL siz = convexPoints.size();
//        DBG( siz );
        for (b = 0; b < convexPoints.size(); b++)
        {
//            cout << convexPoints[b].x << ", " << convexPoints[b].y << endl;
            double addee = getDis( convexPoints[b], convexPoints[ (b+1)%siz ] );
            ans += addee;
        }
        ans += 2 * PI * d;
        printf("Case %lld: %0.9lf\n", a, ans);
    }
}

