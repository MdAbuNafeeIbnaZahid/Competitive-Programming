
#include <bits/stdc++.h>
//#include <ext/pb_ds/assoc_container.hpp> // Common file
//#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
//#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;
//// Order Statistic Tree
///* Special functions:
//
//		find_by_order(k) --> returns iterator to the kth largest element counting from 0
//		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
//*/
//typedef tree<
//int,
//null_type,
//less<int>,
//rb_tree_tag,
//tree_order_statistics_node_update>
//ordered_set;

// Generic Pair with stream inserter
template<class Typ1, class Typ2> class Pair
{
public:
    Typ1 first;
    Typ2 second;
    Pair(){}
    Pair(Typ1 first, Typ2 second)
    {
        this->first = first;
        this->second = second;
    }
    bool operator < ( const Pair B ) const
    {
        if ( first == B.first )
        {
            return second < B.second;
        }
        return first < B.first;
    }

};
template<class Typ1, class Typ2>
ostream &operator << (ostream &stream, const Pair<Typ1, Typ2> pr)
{
    stream << " (" << pr.first << ", " << pr.second << ") ";
    return stream;
}


// Generic Triple with stream inserter
template<class Typ1, class Typ2, class Typ3> class Triple
{
public:
    Typ1 first;
    Typ2 second;
    Typ3 third;
    Triple(){}
    Triple(Typ1 first, Typ2 second, Typ3 third)
    {
        this->first = first;
        this->second = second;
        this->third = third;
    }
    bool operator < ( const Triple B ) const
    {
        if ( first == B.first )
        {
            if ( second == B.second )
            {
                return third < B.third;
            }
            return second < B.second;
        }
        return first < B.first;
    }

};
template<class Typ1, class Typ2, class Typ3>
ostream &operator << (ostream &stream, const Triple<Typ1, Typ2, Typ3> tr)
{
    stream << " (" << tr.first << ", " << tr.second << ", " << tr.third << ") ";
    return stream;
}


#define LL 			long long
#define PairLL		Pair<long long, long long>
#define TripleLL    Triple<long long, long long, long long>



#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MP              make_pair
#define PUB				push_back
#define POB				pop_back
#define PUF             push_front
#define POF             pop_front


#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)

#define DBG(x) cout<<#x<<" : "<<x<<endl
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define SPRIME 10007
#define BPRIME 1000000007
#define LLMAX ( (unsigned long long) -1LL >> 1LL )


//template<typename typ>
//void prVec( vector<typ> toPr )
//{
//    for (auto it : toPr)
//    {
//        cout << it << " , " << endl;
//    }
//    cout << endl;
//}
//
//template<typename typ>
//void prSet( set<typ> toPr )
//{
//    for (auto it : toPr)
//    {
//        cout << it << " , " << endl;
//    }
//    cout << endl;
//}
//
//template<typename T1, typename T2>
//void prMap( map<T1, T2> toPr )
//{
//    for (auto it : toPr)
//    {
//        cout << " [ " << it.first << " ] = " << it.second << endl;
//    }
//    cout << endl;
//}
//
//template<typename T1>
//void prAr(T1 *ar, LL si, LL ei)
//{
//    long long a, b, c;
//    for (a = si; a <= ei; a++)
//    {
//        cout << "ar [ " << a << " ] = " << ar[a] << endl;
//    }
//}
//
//template<typename T1>
//void prMulSet( multiset<T1> toPr )
//{
//    for (auto it : toPr)
//    {
//        cout << it << " , " << endl;
//    }
//    cout << endl;
//}
//
//template<typename T1>
//void prQ( queue<T1> toPr )
//{
//    while( toPr.size() )
//    {
//        cout << toPr.front() << " , " << endl;
//        toPr.pop();
//    }
//    cout << endl;
//}
//
//template<typename T1>
//void prDQ( deque<T1> toPr )
//{
//    for (auto it : toPr)
//    {
//        cout << it << " , " << endl;
//    }
//    cout << endl;
//}

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

void ILL4(LL &u, LL &v, LL &w, LL &x)
{
    LL a, b, c, d, e;
    scanf("%lld %lld %lld %lld", &u, &v, &w, &x);
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

LL getLcm(LL u, LL v)
{
    LL g = getGcd(u, v);
    return (u/g) * v;
}

template<typename T1, typename T2>
T1 aMin(T1 &u, T2 v)
{
    if ( v < u )
    {
        u = v;
    }
    return u;
}


template<typename T1, typename T2>
T1 aMax(T1 &u, T2 v)
{
    if ( v > u )
    {
        u = v;
    }
    return u;
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


// __builtin_popcountll = long long

LL checkBit(LL num, LL pos)
{
    return (num>>pos) & 1LL;
}

LL setBit(LL num , LL pos)
{
    return num | (1LL<<pos);
}

LL resetBit(LL num, LL pos)
{
    return num & ( ~( 1LL<<pos ) );
}




/******   END OF HEADER *********/
#define SIZE 109
LL T;
LL m, n;

LL dpAr[SIZE][SIZE][SIZE];

LL grid[SIZE][SIZE];
LL cumSumAr[SIZE][SIZE];

LL kase;

void makeCumSumAr()
{
    LL a, b, c, d, e;
    RESET( cumSumAr );
    FOR(a,0,SIZE)
    {
        FOR(b,1,SIZE)
        {
            cumSumAr[a][b] = cumSumAr[a][b-1] + grid[a][b];
        }
    }
}


//LL getDp(LL i, LL j, LL k)
//{
//    LL a, b, c, d, e;
//    if (i<1 || j<1 || k<1 || i>m || j>n || k>n || j>=k)
//    {
//        return INT_MIN;
//    }
//    if ( dpAr[i][j][k] == -1 )
//    {
//        LL posDp;
//        cout << "calculating dp " << endl;
//        DBG3(i, j, k);
//
//        cout << "left left" << endl;
//        posDp = getDp(i, j-1,k) + grid[i][j] ;
//        DBG( posDp );
//        aMax(dpAr[i][j][k], posDp );
//
//        posDp = getDp(i, j,k-1) + grid[i][k] ;
//        DBG( posDp );
//        aMax(dpAr[i][j][k], posDp );
//
//        FOR(a,1,j)
//        {
//            aMax( dpAr[i][j][k], getDp(i-1, a, k) + cumSumAr[i][j] - cumSumAr[i][a-1] + grid[i][k] );
//        }
//        FOR(a,1,k)
//        {
//            aMax(dpAr[i][j][k], getDp(i-1,j,a)+grid[i][j]+cumSumAr[i][k]-cumSumAr[i][a-1] );
//        }
//
//        cout << "up up" << endl;
//        posDp = getDp(i-1,j,k)+grid[i][j]+grid[i][k];
//        DBG( posDp );
//        aMax(dpAr[i][j][k], posDp);
//    }
//    return dpAr[i][j][k];
//}

void init()
{
    SET(dpAr);
    RESET(grid);
    RESET( cumSumAr );
}

void printGrid(LL x, LL y)
{
    LL a, b, c, d;
    FOR(a,1,1+x)
    {
        FOR(b,1,1+y)
        {
            cout << grid[a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

void printDpGrid(LL i)
{
    LL a, b, c, d;
    FOR(a,1,1+m)
    {
        FOR(b,1,1+n)
        {
            cout << dpAr[i][a][b] << " ";
        }
        cout << endl;
    }
    cout << endl;
}


LL getDp2(LL i, LL j, LL k)
{
    LL a, b, c, d, e;
    if (i<1 || j<1 || k<1 || i>m || j>n || k>n || j>=k)
    {
        return INT_MIN;
    }
    if ( dpAr[i][j][k] == -1 )
    {
        if (i == 1)
        {
            if (j==1&&k==2)
            {
                dpAr[i][j][k] = grid[1][1] + grid[1][2];
            }
            else
            {
                dpAr[i][j][k] = getDp2(i, j, k-1) + grid[1][k];
            }
        }
        else if (i > 1)
        {
            // first consider the top
            FOR(a,1,n)
            {
                FOR(b,a+1,1+n)
                {
                    aMax(dpAr[i][a][b], getDp2(i-1,a,b) + grid[i][a]
                           + grid[i][b] );
                }
            }
            // move left path
            FOR(a,1,n)
            {
                FOR(b,a+1,1+n)
                {
                    aMax(dpAr[i][a][b], getDp2(i,a-1,b) + grid[i][a] );
                }
            }
            // move right path
            FOR(a,1,n)
            {
                FOR(b,a+1,1+n)
                {
                    aMax(dpAr[i][a][b], getDp2(i,a,b-1) + grid[i][b]);
                }
            }
        }
    }
    return dpAr[i][j][k];
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e;
    cin >> kase;
//    DBG(kase);
    FOR(a,1,1+kase)
    {
        init();
        cin >> m >> n;
//        DBG2(m, n);
        FOR(b,1,1+m)
        {
            FOR(c,1,1+n)
            {
                ILL( grid[b][c] );
            }
        }
//        cout << "printing grid " << endl;
//        printGrid(m, n);

        makeCumSumAr();
        // make dpAr for second row
//        cout << "printing cumSumAr " << endl;
//        FOR(b,1,1+m)
//        {
//            FOR(c,1,1+n)
//            {
//                cout << cumSumAr[b][c] << " ";
//            }
//            cout << endl;
//        }


//        FOR(b,1,n)  // j
//        {
//            FOR(c,b+1,1+n) // k
//            {
//                // iterate over transition point
//                FOR(d,b+1,1+c)
//                {
//                    LL posDp = cumSumAr[2][b]+cumSumAr[1][d]+cumSumAr[2][c]-cumSumAr[2][d-1];
//                    aMax(dpAr[2][b][c], posDp);
//                }
//            }
//        }
//        cout << endl;
//
//        cout << "printing dp[2]" << endl;
//        FOR(b,1,1+n)
//        {
//            FOR(c,1,1+n)
//            {
//                cout << dpAr[2][b][c] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//
//
//        FOR(b,3,m) // i
//        {
//            FOR(c,1,n) // j
//            {
//                FOR(d,c+1,1+n)
//                {
//                    getDp(b, c, d);
////                    DBG3(b, c, d);
////                    DBG( getDp(b, c, d) );
//                }
//            }
//
//            cout << "printing dpGrid " << b << endl;
//            printDpGrid(b);
//            cout << endl;
//
//
//        }
//        LL ans = 0;
//        FOR(b,1,n)
//        {
//            aMax(ans, dpAr[m-1][b][n]+cumSumAr[m][n]-cumSumAr[m][b-1]);
//        }
////        cout << ans;
//        if ( m==2 )
//        {
//            ans = cumSumAr[1][n] + cumSumAr[2][n];
//        }
        FOR(b,1,1+m)
        {
            FOR(c,1,1+n)
            {
                FOR(d,c+1,1+n)
                {
                    getDp2(b, c, d);
                }
            }
        }
        LL ans = getDp2(m, n-1, n);
        printf("Case %lld: %lld\n", a, ans);
    }
    return 0;
}



