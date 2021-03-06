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
#define DBG2(x, y) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y)<<endl
#define DBG3(x, y, z) cout<<#x<<" : "<<(x)<<", "<<#y<<" : "<<(y) << ", " << #z << " : " << (z) <<endl
#define DBG4(a,b,c,d) cout<<#a<<" : "<<(a)<<", "<<#b<<" : "<<(b)<<", "<<#c<<" : "<<(c)<<", "<<#d<<": "<<(d)<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)
#define SPRIME 10007
#define BPRIME 1000000007


void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


void printSetLL(set<long long> setLLToPr)
{
    long long a, b, c;
    set<long long>::iterator setLLIt;
    for (setLLIt = setLLToPr.begin(); setLLIt != setLLToPr.end(); setLLIt++)
    {
        cout << *setLLIt << " ";
    }
    cout << endl;
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


void printLLArray( LL *ar, LL si, LL ei )
{
    LL a, b, c, d, e;
    FOR(a, si, ei+1)
    {
        printf("ar[ %lld ] = %lld\n\n", a, ar[a]);
    }
}


void  printSetPair( set<PairLL> givenSetPair )
{
    for ( auto it : givenSetPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
    }
    cout << endl;
}

void printVecPair( vector<PairLL> givenVecPair )
{
    for ( auto it : givenVecPair )
    {
        cout << "(" << it.first << ", " << it.second << ")" << endl;
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
#define SIZE 100009
#define LOSE 0
#define WIN 1
LL n, k;
char str[SIZE];
struct Trie
{
    LL maxNode, root, numNode;
    LL **nodeAr, *stateAr;

    Trie(LL maxNode)
    {
        LL a, b, c, d, e;
        this->maxNode = maxNode;
        root = 0;
        numNode = 0;
        nodeAr = new LL*[maxNode];
        stateAr = new LL[maxNode];
        FOR(a,0,maxNode)
        {
            nodeAr[a] = new LL[29];
            FOR(b,0,29)
            {
                nodeAr[a][b] = -1;
            }
        }
//        SET(nodeAr); // HERE I am setting the whole 2d array at once
        SET( stateAr );
    }

    void ins(char *st) // 1 based string indexing
    {
//        cout << "in ins function " << endl;
        LL a, b, c, d, e;
        LL len = strlen( st+1 );
//        DBG( len );
        LL now = root;
        FOR(a,1,1+len)
        {
//            DBG( st[a] );
            if ( nodeAr[ now ][ st[a]-'a' ] == -1 )
            {
                nodeAr[ now ][ st[a] - 'a' ] = ++numNode;
            }
            now = nodeAr[ now ][st[a]-'a'  ];
        }
//        cout << "at end of ins function " << endl;
//        DBG( numNode );
    }

    void printNodeAr()
    {
        LL a, b, c, d, e;
        FOR(a,0,10)
        {
            FOR(b,0,10)
            {
                cout << nodeAr[a][b] << " ";
            }
            cout << endl;
        }
    }

    LL getState(LL n, LL leafState)
    {
        LL a, b, c, d, e;
        LL childCnt = 0;
        FOR(a,'a',1+'z')
        {
            LL ch = a-'a';
            if ( nodeAr[n][ch] != -1 )
            {
                childCnt++;
            }
        }

        if ( childCnt==0 ) // it is a leaf node
        {
            stateAr[n] = leafState;
        }
        else
        {
            stateAr[n] = 0;
            FOR(a,'a',1+'z')
            {
                LL ch = a-'a';
                if ( nodeAr[n][ ch ] != -1 )
                {
                    if ( stateAr[ nodeAr[n][ch] ] == 0 )
                    {
                        stateAr[n] = 1;
                        break;
                    }
                }
            }
        }

        return stateAr[n];
    }

    void makeStateAr(LL leafState)
    {
//        cout << "in makeStateAr " << endl;
        LL a, b, c, d, e;
        ROF(a,numNode,-1)
        {
//            DBG( a );
            getState(a, leafState);
//            DBG( stateAr[a] );
        }
    }
};
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    cin >> n >> k;
//    DBG2( n, k );
    Trie tr(SIZE);
//    cout << "trie constructed " << endl;

//    tr.printNodeAr();

    FOR(a,1,1+n)
    {
//        DBG( a );
        scanf("%s", str+1);
//        DBG( str+1 );
        tr.ins( str );
    }
//    cout << "input taken and inserted all strings" << endl;
    tr.makeStateAr(0);
//    cout << "stateAr is made " << endl;
    LL looseLeaf = tr.stateAr[0];

    tr.makeStateAr(1);
    LL winLeaf = tr.stateAr[0];

    LL winner = 0;
//    if ( looseLeaf == LOSE )
//    {
//        winner = 2;
//    }
    if ( looseLeaf == WIN )
    {
        if ( winLeaf == WIN )
        {
            if ( k>=2 )
            {
                winner = 1;
            }
        }
        else if ( winLeaf == LOSE )
        {
            if (k&1LL)
            {
                winner = 1;
            }
        }
    }











//    if ( !tr.stateAr[0] ) // first person is looser
//    {
//        winner = 2; // 2nd person is always winner;
//    }
//    else // second person is looser
//    {
//        winner = (k)%2;
//    }

    if ( winner )
    {
        cout << "First" << endl;
    }
    else
    {
        cout << "Second" << endl;
    }
    return 0;
}


