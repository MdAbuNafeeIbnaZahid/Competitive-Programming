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
typedef vector<long long> VL;



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
//    long long a, b, c;
//    for (a = 0; a < toPr.size(); a++)
//    {
//        long long it = toPr[a];
//        cout << "toPr [ " << a << " ] = " << it << " , " << endl;
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
// void * memcpy ( void * destination, const void * source, size_t num );

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
#define SIZE 4
#define MAX_MOVE 35

#define DOWN 1
#define LEFT 2
#define RIGHT 3
#define UP 4

LL kase;

VL ansVec;
char chAr[999];

void get0RowCol(VL v, LL &row, LL &col)
{
    LL a, b, c, d;
    FOR(a,0,v.size())
    {
        if ( v[a]==0 )
        {
            row = a/SIZE;
            col = a%SIZE;
            return;
        }
    }
}

LL getInvCnt(VL v)
{
    LL a, b, c, d, e;
    LL ret = 0;
    FOR(a,0,v.size())
    {
        if ( v[a]==0 )
        {
            continue;
        }
        FOR(b,a+1,v.size())
        {
            if ( v[b]==0 )
            {
                continue;
            }
            ret += (v[a]>v[b]);
        }
    }
    return ret;
}

bool isSolvable( VL v )
{
    LL a, b, c, d;
    LL invCnt = getInvCnt(v);
    if (SIZE&1LL) // odd sized
    {
        return !(invCnt&1LL);
    }
    else // even sized
    {
        LL zeroRow, zeroCol;
        get0RowCol(v, zeroRow, zeroCol);
        return ( (invCnt+zeroRow) &1LL);
    }
}

LL getTotManDis( VL v )
{
    LL ret = 0;
    LL a, b, c, d;
    FOR(a,0,v.size())
    {
        if ( v[a]==0 )
        {
            continue;
        }
        LL exPos = (v[a]-1)%(SIZE*SIZE);
        LL addee = abs( exPos/SIZE - a/SIZE ) + abs(exPos%SIZE - a%SIZE);
        ret += addee;
    }
    return ret;
}

VL getChild(VL v, LL typ)
{
    LL a, b, c, d, e;
    LL zeroRow, zeroCol;
    VL ret = v;;
    get0RowCol(v, zeroRow, zeroCol);
    LL newRow = zeroRow;
    LL newCol = zeroCol;
    if (typ==UP)
    {
        newRow--;
    }
    else if (typ == DOWN)
    {
        newRow++;
    }
    else if (typ==LEFT)
    {
        newCol--;
    }
    else if (typ==RIGHT)
    {
        newCol++;
    }

    if ( newRow<0 || newRow>=SIZE || newCol<0 || newCol>=SIZE ) // invalid operation
    {
        return ret;
    }

    swap( ret[zeroRow*SIZE+zeroCol], ret[newRow*SIZE+newCol] );
    return ret;
}

LL getH(VL v)
{
    LL ret = getTotManDis(v);
    return ret;
}


bool dfs(LL dep, LL prun, VL v)
{
//    cout << "in dfs " << endl;
//    DBG2(dep, prun);
//
//    cout << "printing v " << endl;
//    prVec(v);

    LL a, b, c, d, e;
    LL hVal = getH(v);
    LL fVal = dep+hVal;
    if (fVal>prun)
    {
        return false;
    }
    if ( hVal==0 )
    {
        return true;
    }
    FOR(a,DOWN, UP+1)
    {
        VL child = getChild(v, a);
        LL childHval = getH( child );
        if ( childHval+dep+1 > prun )
        {
            continue;
        }
        if ( child == v )
        {
            continue;
        }
        bool res = dfs(dep+1, prun, child);
        if (res)
        {
            ansVec.push_back( a );
            return true;
        }
    }
    return false;
}

void printAns( VL v )
{
    LL a, b, c;
    REV(v);
    FOR(a,0,v.size())
    {
        LL it = v[a];
        printf("%c", chAr[it]);
    }
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    chAr[UP] = 'U';
    chAr[DOWN] = 'D';
    chAr[LEFT] = 'L';
    chAr[RIGHT] = 'R';
    LL a, b, c, d, e, f;
    cin >> kase;
//    DBG(kase);
    FOR(a,1,kase+1)
    {
//        DBG(a);
        VL inp;
        ansVec.clear();
        FOR(b,1,1+SIZE*SIZE)
        {
            LL i;
            ILL(i);
            inp.push_back(i);
        }

//        cout << "printing inpVec " << endl;
//        prVec(inp);

        printf("Case %lld: ", a);

        if ( !isSolvable(inp) )
        {
            printf("This puzzle is not solvable.\n");
        }
        else
        {
            bool res = false;
            FOR(b,0,MAX_MOVE+1)
            {
                res = res || dfs(0, b, inp);
                if ( res )
                {
//                    cout << b << endl;
                    printAns(ansVec);
                    printf("\n");
                    break;
                }
            }

            if ( !res )
            {
                printf("This puzzle is not solvable.\n");
            }
        }
    }


    return 0;
}


