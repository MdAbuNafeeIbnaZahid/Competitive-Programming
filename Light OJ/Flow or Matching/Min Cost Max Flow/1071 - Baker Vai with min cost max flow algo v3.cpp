/***** This solution is getting Memory Limit Exceed in Light OJ. However I have tested it
with many test cases from uDebug. It is giving correct answer.  *******/



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
#define MAX_PPL 20



struct Edge
{
    LL to, cap, cost, revIdx;
    Edge(){}
    Edge(LL to, LL cap, LL cost, LL revIdx)
    :to(to), cap(cap), cost(cost), revIdx(revIdx)
    {
//        this->to = to;
//        this->cap = cap;
//        this->cost = cost;
    }

    void print()
    {
        DBG4(to, cap, cost, revIdx);
    }
};


//ostream & operator<<(ostream &out, const Edge edge)
//{
//    DBG4()
//}

struct Graph
{
    LL maxNode;
    vector<Edge> *gr;
    LL *disAr;

    // node, index
    PairLL *parentAr;
    Graph(LL num)
    {
        maxNode = num;
        gr = new vector<Edge>[num+9];
        disAr = new LL[num+9];
        parentAr = new PairLL[num+9];
    }

    ~Graph()
    {
//        cout << "in destructor " << endl;
        LL a, b, c, d;
        FOR(a,0,maxNode)
        {
            gr[a].clear();
        }
    }

//    void print()
//    {
//        LL a, b, c, d, e;
//        FOR(a,0,maxNode)
//        {
//            if ( gr[a].size() == 0 )
//            {
//                continue;
//            }
//            cout << "from = " << a << endl;
//            for (auto it : gr[a])
//            {
//                // to, cap, cost, revIdx
//                DBG4(it.to, it.cap, it.cost, it.revIdx);
//            }
//        }
//    }

    void addEdge(LL u, LL v, LL cap, LL cost)
    {
        LL uIdx = gr[u].size();
        LL vIdx = gr[v].size();

        gr[ u ].PUB( Edge(v, cap, cost, vIdx) );
        gr[ v ].PUB( Edge(u, 0, -cost, uIdx) );
    }

    bool dijkstra(LL s, LL t)
    {
//        cout << "in dijkstra " << endl;
//        DBG2(s, t);
        LL a, b, c, d;
        FOR(a,0,maxNode)
        {
            disAr[a] = INT_MAX;
        }
        disAr[s] = 0;
        set< PairLL > setPair;
        setPair.insert( PairLL(0, s) );
        while( setPair.size() )
        {
            PairLL curPair = *(setPair.begin() );
//            DBG(curPair);
            setPair.erase( setPair.begin() );
            LL curDis = curPair.first;
            LL curNode = curPair.second;
            if ( curDis > disAr[curNode] )
            {
                continue;
            }
            FOR(a,0,gr[curNode].size())
            {
                Edge it = gr[curNode][a];
//                it.print();
                if ( it.cap <= 0 )
                {
                    continue;
                }
                LL nexNode = it.to;
                LL nexDis = it.cost + curDis;
//                DBG2(nexNode, nexDis);
                if ( nexDis >= disAr[ nexNode ] )
                {
                    continue;
                }
                disAr[nexNode] = nexDis;
                parentAr[nexNode] = PairLL(curNode, a);
                setPair.insert( PairLL(nexDis, nexNode) );
            }
        }
//        DBG(disAr[t]);
        return disAr[t] < INT_MAX;
    }

    LL augment(LL s, LL t)
    {
        LL a, b, c, d;
        LL curNode = t;
        LL maxFlow = INT_MAX;
        while( curNode != s )
        {
            LL curParent = parentAr[curNode].first;
            LL curIdx = parentAr[curNode].second;
            Edge curEdge = gr[curParent][curIdx];
            aMin(maxFlow, curEdge.cap);
            curNode = curParent;
        }
        // maxFlow is calculated
        curNode = t;
        while(curNode != s)
        {
            LL curParent = parentAr[curNode].first;
            LL curIdx = parentAr[curNode].second;

            gr[curParent][curIdx].cap -= maxFlow;
            LL revIdx = gr[curParent][curIdx].revIdx;
            gr[curNode][revIdx].cap += maxFlow;
            curNode = curParent;
        }
        return maxFlow;
    }


    void sendMaxFlow(LL s, LL t, LL &costRet, LL &flowRet)
    {
//        cout << "in sendMaxFlow " << endl;
//        DBG2(s, t);

        costRet = 0;
        flowRet = 0;
        while( dijkstra(s, t) )
        {
//            cout << "in while loop after dijkstra " << endl;
            LL perUnitCost = disAr[t];
            LL flow = augment(s, t);
//            cout << "augmenting done " << endl;
//
//            cout << "printing graph " << endl;
//            this->print();

//            DBG( flow );
            costRet += (flow * perUnitCost);
            flowRet += flow;
        }
    }



};

LL kase;
LL m, n;
LL grid[SIZE][SIZE];

LL getLinAdd(LL u, LL v)
{
    LL ret = u*n + v;
    return ret;
}

void makeGraph(Graph &giv)
{
    LL a, b, c, d, e;
    FOR(a,1,1+m)
    {
        FOR(b,1,1+n)
        {
            LL curLin = getLinAdd(a, b);
            LL extra = 0;
            if ( (a==m&&b==n)  || (a==1&&b==1) )
            {
                extra = 1;
            }
            giv.addEdge(2*curLin,  2*curLin+1, 1+extra, 20-grid[a][b]);
            giv.addEdge(2*curLin+1, 2*getLinAdd(a+1,b), 1, 0 );
            giv.addEdge(2*curLin+1, 2*getLinAdd(a,b+1), 1, 0);
        }
    }
}

void printGrid(LL u, LL v)
{
    LL a, b, c, d, e;
    FOR(a,1,1+u)
    {
        FOR(b,1,1+v)
        {
            cout << grid[a][b] << " ";
        }
        cout << endl;
    }
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
//        DBG(a);
        cin >> m >> n;
        Graph graph(SIZE*SIZE*2);
//        cout << "graph is constructed " << endl;

//        DBG2(m, n);
        FOR(b,1,1+m)
        {
            FOR(c,1,1+n)
            {
                ILL( grid[b][c] );
            }
        }

//        printGrid(m, n);

        makeGraph(graph);

//        cout << "graph is made " << endl;
//
//        cout << "printing graph " << endl;
//        graph.print();

        LL cost;
        LL flow;
        graph.sendMaxFlow( 2*getLinAdd(1,1), 2*getLinAdd(m,n)+1, cost, flow);
//        DBG2(cost, flow);
        cost = 2*(m+n-1)*MAX_PPL - cost;
        cost -= ( grid[1][1] + grid[m][n] );
        cout << "Case " << a << ": " << cost << endl;
    }
    return 0;
}


