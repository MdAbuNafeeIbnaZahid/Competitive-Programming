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
#define SIZE 1000009LL
#define MOD 1000000007LL
#define B 1
#define F 0

LL getInvMod(LL num)
{
    return bigMod(num, MOD-2, MOD);
}

LL N, M;
char toPushAr[SIZE];
string luckySeq, tossedToday;

LL testCase;
LL fAr[SIZE], rAr[SIZE];
LL dpPAr[SIZE];
LL dpQAr[SIZE], ansAr[SIZE];

void makeFailAr(string str, LL *failAr)
{
    LL a, b, c, d, e, f;
    LL len = str.size();
    RESET( failAr );
    LL i = 1;
    LL j = 0;
    for (i = 1; i < len; )
    {
        if ( str[i]==str[j] )
        {
            failAr[i] = j+1;
            i++;
            j++;
        }
        else // no match
        {
            if ( j==0 )
            {
                failAr[i] = 0;
                i++;
            }
            else if ( j>0 )
            {
                j = failAr[ j-1 ];
            }
        }
    }
}

string getStrFromChar(char ch, LL firBitCnt)
{
    LL a, b, c, d, e;
//    cout << "in getStrFromChar" << endl;
//    DBG(ch);
//    DBG(firBitCnt);
    string ret = "";
    LL num = 0;
    if ( ch>= 'a' && ch <= 'z')
    {
        num = ch-'a'+0;
    }
    else
    {
        num = ch-'A'+26;
    }
//    DBG(num);
    ROF(a,firBitCnt-1,-1)
    {
        ret.PUB( toPushAr[ checkBit(num, a) ] );
    }
//    DBG(ret);
    return ret;
}



void makeRematchAr(LL *rematchAr, LL *failAr, string str)
{
    LL a, b, c, d, e;
    LL len = str.size();
    rematchAr[0] = 0;
    for (a = 0; a < len-1;a++)
    {
        char oppositeChar = str[a+1]=='B'? 'F' : 'B';
        LL j = failAr[a];
        while(1)
        {
            if ( oppositeChar == str[j] )
            {
                rematchAr[a] = j;
                break;
            }
            else // no match
            {
                if (j > 0)
                {
                    j = failAr[j-1];
                }
                else // j == 0
                {
                    rematchAr[a] = -1;
                    break;
                }
            }
        }
        rematchAr[a]++;
    }
    ROF(a,len-1,0)
    {
        rematchAr[a] = rematchAr[a-1];
    }
}


string decodeText(LL num, char *st)
{
    LL a, b, c, d, e;
//    cout << "in decodeText " << endl;
//    DBG(num);
//    DBG(st);
    LL len = strlen( st );
    string ret = "";
    for ( a = 0; a < len; a++ )
    {
        string tempStr = getStrFromChar( st[a], 5 );
        FOR(b,0,tempStr.size())
        {
            if ( ret.size()>=num )
            {
                return ret;
            }
            ret.PUB( tempStr[b] );
        }
    }
    return ret;
}


void makeClear()
{

}

LL getStartVal( string text, string pattern )
{
    LL i = 0;
    LL j = 0;
    LL textLen = text.size();
    LL patLen = pattern.size();
    while( i < textLen && j <patLen  )
    {
        if ( text[i]==pattern[j] )
        {
            i++;
            j++;
        }
        else
        {
            if ( j>0 )
            {
                j = fAr[j-1];
            }
            else
            {
                i++;
            }
        }
    }
    return j;
}

void makeDp(LL *pAr, LL *qAr, LL len)
{
    LL a, b, c, d, e;
    cout << "in makeDp" << endl;
    pAr[0] = 0;
    qAr[0] = 1;
    FOR(a,1,1+len)
    {
        DBG(a);
        LL t = rAr[a-1];
        DBG(t);
        pAr[a] = (  (pAr[a-1]<<1LL )%MOD - 2LL - pAr[t] + MOD ) % MOD;
        DBG( pAr[a] );
        DBG(MOD);
        qAr[a] =  (  (qAr[a-1]<<1LL )%MOD - qAr[t] + MOD ) % MOD;
    }
}

void makeAnsAr(LL len)
{
    LL a, b, c, d, e, f;
    ansAr[len] = 0;
    dpPAr[len] = (dpPAr[len] + MOD)%MOD;
    dpQAr[len] = (dpQAr[len] + MOD)%MOD;
    ansAr[0] = ( ( ( -dpPAr[len] + MOD ) % MOD ) * getInvMod( dpQAr[len] ) )%MOD;
    FOR(a,1,1+len)
    {
        ansAr[a] = (dpPAr[a] + (dpQAr[a] * ansAr[0] )%MOD )%MOD;
    }
}

LL solve()
{
    makeClear();
    makeFailAr(luckySeq, fAr);
    cout << "printing fAr" << endl;
    prAr(fAr, 0, luckySeq.size()-1);

    makeRematchAr(rAr, fAr, luckySeq);
    cout << "printing rAr " << endl;
    prAr(rAr, 0, luckySeq.size()-1);

    makeDp(dpPAr, dpQAr, luckySeq.size() );

    cout << "printing dpPAr " << endl;
    prAr( dpPAr, 0, luckySeq.size() );

    cout << "printing dpQAr " << endl;
    prAr( dpQAr, 0, luckySeq.size() );


    makeAnsAr(luckySeq.size());

    cout << "printing ansAr " << endl;
    prAr( ansAr, 0, luckySeq.size() );

    LL target = getStartVal( tossedToday, luckySeq );

    LL ret = ansAr[target];
    return ret;
}



int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    toPushAr[B] = 'B';
    toPushAr[F] = 'F';
    LL a, b, c, d, e,f;
    cin >> testCase;
    FOR(a,1,1+testCase)
    {
        DBG(a);
        char str[SIZE];
        ILL(N);
        scanf("%s", str);
        luckySeq = decodeText(N, str);

        ILL(M);
        scanf("%s", str);
        tossedToday = decodeText(M, str);

        DBG(N);
        DBG(luckySeq);

        DBG(M);
        DBG(tossedToday);

        LL ans = solve();
        printf("%lld\n", ans);
    }
    return 0;
}
