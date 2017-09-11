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

// Generic Pair with stream inserter
template<class Typ1, class Typ2> class Pair
{
public:
    Typ1 first;
    Typ2 second;
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


template<typename typ>
void prVec( vector<typ> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename typ>
void prSet( set<typ> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename T1, typename T2>
void prMap( map<T1, T2> toPr )
{
    for (auto it : toPr)
    {
        cout << " [ " << it.first << " ] = " << it.second << endl;
    }
    cout << endl;
}

template<typename T1>
void prAr(T1 *ar, LL si, LL ei)
{
    long long a, b, c;
    for (a = si; a <= ei; a++)
    {
        cout << "ar [ " << a << " ] = " << ar[a] << endl;
    }
}

template<typename T1>
void prMulSet( multiset<T1> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

template<typename T1>
void prQ( queue<T1> toPr )
{
    while( toPr.size() )
    {
        cout << toPr.front() << " , " << endl;
        toPr.pop();
    }
    cout << endl;
}

template<typename T1>
void prDQ( deque<T1> toPr )
{
    for (auto it : toPr)
    {
        cout << it << " , " << endl;
    }
    cout << endl;
}

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
#define SIZE 509
LL N, S;
LL grid[49][49];
LL dpAr[49][49][SIZE];
LL solAr[49][49][SIZE];
void inputGrid(LL siz)
{
    LL a, b, c, d, e, f, g;
    FOR(a,1,siz+1)
    {
        LL len = siz+1-a;
        FOR(b,1,1+len)
        {
            ILL( grid[a][b] );
        }
    }
    FOR(a,siz+1,2*siz)
    {
        LL len = a-siz+1;
        FOR(b,1,1+len)
        {
            ILL( grid[a][b] );
        }
    }
}

void printGrid(LL siz)
{
    LL a, b, c, d, e;
    FOR(a,1,siz<<1)
    {
        LL len;
        if (a <= siz)
        {
            len = siz+1-a;
        }
        else
        {
            len = a-siz+1;
        }
        FOR(b,1,1+len)
        {
            cout << grid[a][b] << " ";
        }
        cout << endl;
    }
}


LL getLen(LL row, LL siz)
{
    LL len;
    if ( row <= siz )
    {
        len = siz+1-row;
    }
    else
    {
        len = row-siz+1;
    }
    return len;
}

LL isValid( LL r, LL c, LL val )
{
    if ( val < 0 )
    {
        return 0;
    }
    if (r <= 0 || c <= 0 )
    {
        return 0;
    }
    LL len = getLen(r, N);
    if (c > len)
    {
        return 0;
    }
    return 1;
}

LL calcDp(LL r, LL c, LL val)
{
//    if (r <= 0 || c<=0 || val < 0)
//    {
//        return 0;
//    }
    char dir;
    if ( !isValid(r, c, val) )
    {
        return 0;
    }
    if ( dpAr[r][c][val] == -1 )
    {
//        cout << "calculating dpAr " << endl;
//        DBG3(r, c, val);
        LL ret = 0;
        if ( r==(2*N-1) )
        {
            ret = (grid[r][c]==val);
        }
        else if ( r >= N )
        {
            ret = 0;
            ret += calcDp(r+1, c+1, val-grid[r][c] );
            if ( calcDp(r+1, c+1, val-grid[r][c] ) )
            {
                dir = 'R';
            }
            ret += calcDp(r+1, c, val-grid[r][c] );
            if ( calcDp(r+1, c, val-grid[r][c] ) )
            {
                dir = 'L';
            }
        }
        else if (r < N)
        {
            ret = 0;
            ret += calcDp(r+1, c, val-grid[r][c] );
            if ( calcDp(r+1, c, val-grid[r][c] ) )
            {
                dir = 'R';
            }
            ret += calcDp(r+1, c-1, val-grid[r][c] );
            if ( calcDp(r+1, c-1, val-grid[r][c] ) )
            {
                dir = 'L';
            }
        }
        dpAr[r][c][val] = ret;
        solAr[r][c][val] = dir;
    }
    return dpAr[r][c][val];
}

void makeDpAr(LL siz)
{
    LL a, b, c, d, e, f;
    ROF(a,2*siz-1,0)
    {
        LL len;
        if (a <= siz)
        {
            len = siz+1-a;
        }
        else
        {
            len = a-siz+1;
        }
        FOR(b,1,1+len)
        {
            FOR(c,0,SIZE)
            {
                calcDp(a, b, c);
            }
        }
    }
}

LL ans = 0;


void printDpAr(LL siz)
{
    cout << "printing dpAr " << endl;
    LL a, b, c, d, e, f;
    FOR(a,1,2*siz)
    {
        LL len;
        if (a <= siz)
        {
            len = siz+1-a;
        }
        else
        {
            len = a-siz+1;
        }
        FOR(b,1,1+len)
        {
            FOR(c,0,SIZE)
            {
                DBG3(a, b, c);
                DBG( dpAr[a][b][c] );
            }
        }
    }
}


void printSol()
{
    LL a, b, c, d, e;
    LL curCol, curVal, curRow = 1;
    if (ans <= 0)
    {
//        cout << endl;
    }
    else
    {
        FOR(a,1,1+N)
        {
            if ( dpAr[1][a][S] > 0 )
            {
                curCol = a;
                curVal = S;
                break;
            }
        }
        printf("%lld ", curCol-1);
        while(curRow < 2*N-1)
        {
            char curSol = solAr[curRow][curCol][curVal];
            printf("%c", curSol);
            curVal -= grid[curRow][curCol];
            if ( curRow<N && curSol=='L' )
            {
                curCol--;
            }
            else if ( curRow>=N && curSol=='R' )
            {
                curCol++;
            }
            curRow++;
        }
    }
    cout << endl;
}

int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e;
    while(1)
    {
        cin >> N >> S;
//        DBG2(N, S);
        if (N+S==0)
        {
            return 0;
        }
        inputGrid(N);
//        printGrid(N);
//        cout << endl;
        SET(dpAr);
        makeDpAr(N);


//        printDpAr(N);



        ans = 0;
        FOR(a,1,1+N)
        {
            ans += calcDp(1, a, S );
        }
        cout << ans << endl;
        printSol();
    }
    return 0;
}


