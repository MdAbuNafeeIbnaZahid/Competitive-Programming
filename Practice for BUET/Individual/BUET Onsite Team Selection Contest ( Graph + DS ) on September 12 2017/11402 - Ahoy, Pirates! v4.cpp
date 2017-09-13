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
#define SIZE 1000009
#define TOGGLE 2
#define ONE 1
#define ZERO 0
#define NONE 3


LL kase;
LL M;

string str;

LL binAr[SIZE];

string conStr(LL num)
{
    LL a, b, c, d, e;
    char s[59];
    string ret;
    FOR(a,0,num)
    {
        LL T;
        ILL(T);
        scanf("%s", s);
        LL len = strlen(s);
        FOR(b,0,T)
        {
            FOR(c,0,len)
            {
                ret += s[c];
            }
        }
    }
    return ret;
}

LL conBinAr(LL num)
{
    LL a, b, c, d, e, f;
    char s[59];
    LL siz = 0;
    FOR(a,0,num)
    {
        LL T;
        ILL(T);
        scanf("%s", s);
        LL len = strlen(s);
        FOR(b,0,T)
        {
            FOR(c,0,len)
            {
               binAr[siz++] = (s[c]-'0');
            }
        }
    }
    return siz;
}


vector<LL> transVec(vector<LL> inV)
{
    LL a, b, c, d, e;
    LL pre = NONE;
    for (auto it : inV)
    {
        if (pre == NONE)
        {
            pre = it;
        }
        else if (it == ZERO || it == ONE)
        {
            pre = it;
        }
        else if ( (pre==ZERO || pre==ONE) || it==TOGGLE)
        {
            pre ^= 1;
        }
        else if ( pre==TOGGLE && it==TOGGLE )
        {
            pre = NONE;
        }
    }
    vector<LL> ret;
    ret.push_back( pre );
    return ret;
}

struct segTree
{
    LL siz;
    LL *treeAr;
    vector<LL> *lazyAr;
    segTree(){}
    segTree(LL siz)
    {
        LL a, b, c, d;
        this->siz = siz;
        treeAr = new LL[siz+9];
        lazyAr = new vector<LL>[siz+9];
    }
    void build(LL att, LL L, LL R, LL *feed)
    {
//        cout << "in build " << endl;
//        DBG3(att, L, R);
        treeAr[att] = 0;
        lazyAr[att] = vector<LL>();
        if (L==R)
        {
            treeAr[att] = feed[L-1];
            return;
        }
        LL mid = (L+R)/2;
        build(att*2, L, mid, feed);
        build(att*2+1, mid+1, R, feed);
        treeAr[att] = treeAr[att*2] + treeAr[att*2+1];
    }
    void propagate(LL att, LL L, LL R)
    {
//        lazyAr[att] = transVec( lazyAr[att] );
        for (auto it : lazyAr[att])
        {

//            if (it == NONE)
//            {
//                continue;
//            }

            if ( it == ZERO )
            {
                treeAr[att] = 0;
            }
            else if ( it == ONE)
            {
                treeAr[att] = (R-L+1);
            }
            else if ( it == TOGGLE )
            {
                treeAr[att] = (R-L+1 - treeAr[att]);
            }

            if ( L < R ) // not a leaf node
            {
                lazyAr[att*2].PUB(it);
                lazyAr[att*2+1].PUB(it);
            }
        }
        lazyAr[att] = vector<LL>();
    }
    void update(LL att, LL L, LL R, LL lef, LL r, LL typ)
    {
        propagate(att, L, R);
        if (r<L || R<lef) return;
//        propagate(att, L, R);
        if (lef<=L && R<=r)
        {
            lazyAr[att].PUB( typ );
            propagate(att, L, R);
            return;
        }
        // partial overlap
        LL mid = (L+R)/2;
        update(att*2, L, mid, lef, r, typ);
        update(att*2+1, mid+1, R, lef, r, typ);
        treeAr[att] = treeAr[att*2] + treeAr[att*2+1];
    }
    LL query(LL att, LL L, LL R, LL lef, LL r)
    {
//        cout << "in start of query" << endl;
//        DBG3(att, L, R);
//        DBG2(lef, r);


        if ( r<L || R<lef )
        {
//            cout << "returning 0 " << endl;
            return 0;
        }
        propagate(att, L, R);
        if ( lef<=L && R<=r )
        {
            return treeAr[att];
        }
        // partial overlap
        LL mid = (L+R)/2;
        LL x = query(att*2, L, mid, lef, r);
        LL y = query(att*2+1, mid+1, R, lef, r);
        return x+y;
    }
    void print()
    {
        LL a, b, c, d, e;
        cout << "printing treeAr " << endl;
        prAr(treeAr, 1, 50);
        cout << "printing lazeAr " << endl;
        FOR(a,1,siz)
        {
            if ( lazyAr[a].size() )
            {
                DBG(a);
                prVec(lazyAr[a]);
            }
        }
    }
};


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e;
    segTree seg( (SIZE+9)<<2LL );
    cin >> kase;
//    DBG(kase);
    FOR(a,1,1+kase)
    {
//        cout << "Case " << a << ":" << endl;
//        cin >> M;
        printf("Case %lld:\n", a);
        ILL(M);
//        DBG(M);
//        str = conStr(M);
//        DBG(str);
        LL len = conBinAr(M);
//        DBG(len);

//        cout << "segTree constructed " << endl;
        seg.build(1, 1, len, binAr);
//        cout << "segTree built " << endl;
//        seg.print();
        LL Q;
//        cin >> Q;
        ILL(Q);
//        DBG(Q);
        LL quesCnt = 0;
        FOR(b,1,1+Q)
        {
            // F -> 1
            // E -> 0
            // I -> inv
            // S -> query
//            DBG(b);
            char ch;
            LL u, v;
            getchar();
            scanf("%c", &ch);
            ILL2(u, v);
//            DBG3(ch, u, v);
            u++;
            v++;
            if (ch == 'F')
            {
                seg.update(1, 1, len, u, v, ONE);
            }
            else if (ch == 'E')
            {
                seg.update(1, 1, len, u, v, ZERO);
            }
            else if ( ch == 'I' )
            {
                seg.update(1, 1, len, u, v, TOGGLE);
            }
            else if ( ch == 'S' )
            {
                LL ans = seg.query(1, 1, len, u, v);
                printf("Q%lld: %lld\n", ++quesCnt, ans);
            }
//            seg.print();
        }
    }
    return 0;
}



