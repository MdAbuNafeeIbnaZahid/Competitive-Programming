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
#define PB				push_back

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


/******   END OF HEADER *********/
#define SIZE (100009*32)

LL q, typ, pi, li;

LL getBit(LL num, LL bitPos)
{
    return ( ( num>>bitPos) & 1LL );
}

struct Trie
{
    LL maxNumNode, maxBranch;
    LL **node;
    LL root, numNode;
    LL *numCnt;

    Trie(){}

    Trie(LL maxNumNode, LL maxBranch)
    {
        LL a, b, c, d;
        this->maxNumNode = maxNumNode;
        this->maxBranch = maxBranch;
        node = new LL*[maxNumNode+9];
        for (a= 0; a <= maxNumNode; a++)
        {
            node[a] = new LL[ maxBranch + 1  ];
        }
        numCnt = new LL[maxNumNode];
    }

    void init()
    {
        LL a, b, c, d, e;
//        cout << "init method of trie" << endl;
        root = numNode = 0;
        for (a = 0; a <= maxNumNode; a++)
        {
            for (b = 0; b <= maxBranch; b++)
            {
                node[a][b] = 0;
            }
            numCnt[a] = 0;
        }
    }

    void update(LL num, LL val)
    {
//        cout << "in update" << endl;
        LL a, b, c, d, e;
        LL now = root;
//        DBG(now);
        for (a = 28; a >= 0; a--)
        {
//            DBG(a);
            LL curBit = getBit(num, a);
            if ( node[now][ curBit ] == 0 )
            {
                node[now][ curBit ] = ++numNode;
            }
//            DBG(numNode);
            now = node[now][ curBit ];
            numCnt[ now ] += val;
        }
    }

    LL query(LL pers, LL lead)
    {
//        cout << "in query" << endl;
//        DBG(pers);
//        DBG(lead);
        LL a, b, c, d, e, ret = 0, now = 0;
        LL q = pers ^ lead;
//        DBG(q);
        for (a = 28; a >= 0; a--)
        {
//            DBG(a);
            LL curBitQ = getBit(q, a);
//            DBG(curBitQ);
            LL curBitPers = getBit(pers, a);
//            DBG(curBitPers);
            LL curBitLead = getBit(lead, a);
//            DBG(curBitLead);
            LL opBitQ = curBitQ ^ 1;
//            DBG(opBitQ);

//            cout << "now before update " << endl;
//            DBG(now);
            if ( curBitLead )
            {
                ret += numCnt[ node[now][ opBitQ ] ];
            }
//            DBG(ret);

            now = node[ now ][ curBitQ ];
//            cout << "now after update " << endl;
//            DBG(now);
        }

        return ret;
    }
};




int main()
{
//    cout << "start of main method" << endl;
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    Trie myTrie(SIZE, 2);
    myTrie.init();
    LL a, b, c, d, e;
    cin >> q;
//    DBG(q);
    for (a = 1; a <= q; a++)
    {
//        DBG(a);
        scanf("%lld %lld", &typ, &pi);
//        DBG(typ);
//        DBG(pi);
        if ( typ == 1 )
        {
            myTrie.update(pi, 1);
        }
        else if ( typ ==2 )
        {
            myTrie.update(pi, -1);
        }
        else if ( typ == 3 )
        {
            scanf("%lld", &li);
//            DBG(li);
            myTrie.update(pi^li, 0);
            LL ans = myTrie.query(pi, li);
            printf("%lld\n", ans);
        }

//        cout << "printing numCnt ar of trie" << endl;
//        for (b = 0; b <= myTrie.numNode; b++)
//        {
//            DBG(b);
//            DBG( myTrie.numCnt[b] );
//        }
    }
    return 0;
}



