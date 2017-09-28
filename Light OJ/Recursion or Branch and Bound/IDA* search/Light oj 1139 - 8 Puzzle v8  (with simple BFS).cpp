
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
#define SIZE
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef Pair<LL, string> PLS;
//map<string, LL> visMap;


void get0RowCol(string str, LL &row, LL &col)
{
    LL a, b, c, d;
    FOR(a,0,str.size())
    {
        if ( str[a]=='0' )
        {
            row = a/3;
            col = a%3;
            break;
        }
    }
}


LL getManDis(string str)
{
    LL ret = 0;
    LL a, b, c, d, e;
    FOR(a,0,str.size())
    {
        LL val = (str[a]-'0'+8)%9;
        if (val==8)
        {
            continue;
        }
        LL row = val/3;
        LL col = val%3;
        LL addee = abs( row-a/3 ) + abs(col - a%3);
        ret += addee;
    }
//    if (ret & 1LL)
//    {
//        cout << "man dis is odd" << endl;
//        exit(-1);
//    }
//    ret >>= 1;
    return ret;
}


string getChild(string str, LL typ)
{
    LL a, b, c, d, e;
    LL row, col;
    get0RowCol(str, row, col);
    LL newRow = row, newCol = col;
    if ( typ == UP )
    {
        newRow--;
    }
    else if ( typ==DOWN )
    {
        newRow++;
    }
    else if ( typ == LEFT )
    {
        newCol--;
    }
    else if ( typ==RIGHT )
    {
        newCol++;
    }

    if ( newRow<0 || newRow>2 || newCol<0 || newCol>2 )
    {
        return str;
    }
    swap( str[newRow*3 + newCol], str[row*3 + col] );
    return str;
}



string inpStr;
LL kase;
//LL prevCut, curCut;

LL aStar()
{
//    cout << "in aStar " << endl;
    LL a, b, c, d, e;
    LL prevCut = 0;
    LL curCut = INT_MAX;
    map<string, LL> gMap, fMap;
    while(1)
    {
        fMap.clear();
        gMap.clear();
        curCut = INT_MAX;
//        visMap.clear();
        set<PLS> setNode;
        setNode.insert( PLS( getManDis(inpStr), inpStr ) );
        fMap[ inpStr ] = getManDis(inpStr);


//        DBG2(prevCut, curCut);

//        cout << "printing setNode initially" << endl;
//        prSet( setNode );

        while( setNode.size() )
        {
            PLS curpls = *setNode.begin();
            setNode.erase( setNode.begin() );

//            DBG(curpls);

            LL curF = curpls.first;
            string curStr = curpls.second;

            if ( curF>fMap[curStr] || curF>curCut )
            {
                continue;
            }

            LL curG = gMap[ curStr ];
            curCut = curF>prevCut ? min(curCut, curF) : curCut ;
            LL curH = getManDis( curpls.second );
//            DBG3(curG, curH, curF);

//            if ( curH + curG != curF )
//            {
//                cout << "curH + curG != curF" << endl;
//                exit(2);
//            }
//            DBG(curH);
            if ( curH == 0 )
            {
                return curF;
            }
            FOR(a,UP,1+RIGHT)
            {
//                DBG(a);
                string childStr = getChild(curStr, a);
//                DBG(childStr);
                if (childStr == curStr)
                {
                    continue;
                }
                LL childH = getManDis(childStr);
//                DBG( childH );
                LL childF = curG + 1 + childH;
//                if ( childH == 0 )
//                {
//                    return childF;
//                }
//                DBG(childF);
                if ( fMap[childStr]!=0 && fMap[childStr]<=childF )
                {
                    continue;
                }
                curCut = childF>prevCut ? min(curCut, childF) : curCut ;
//                DBG(curCut);
                if ( childF > curCut )
                {
                    continue;
                }
                if ( fMap[childStr]==0 || fMap[childStr]>childF )
                {
                    gMap[ childStr ] = curG + 1;
                    fMap[childStr] = childF;
                    setNode.insert( PLS(childF, childStr) );
                }
            }

//            cout << "this node expansion complete " << endl;
//            cout << "printing setNode " << endl;
//            prSet( setNode );
        }
        if ( curCut<=prevCut )
        {
            return INT_MAX;
        }
        prevCut = curCut;
    }

}


map<string, LL> layerMap;
void bfs(string s)
{
//    cout << "in bfs " << endl;
//    DBG(s);
    LL a, b, c, d, e;
    queue<string> Q;
    Q.push( s );
    layerMap[s] = 0;
    while( Q.size() )
    {
        string cur = Q.front();
//        DBG(cur);
        Q.pop();
        LL curLayer = layerMap[cur];
//        DBG(curLayer);
        FOR(a,UP,1+RIGHT)
        {
//            DBG(a);
            string child = getChild(cur, a);
//            DBG(child);
//            if (child == s)
//            {
//                continue;
//            }
//            cout << "printing layerMap " << endl;
//            prMap( layerMap );
            if ( layerMap.find(child)==layerMap.end() || layerMap[child]>curLayer+1 )
            {
//                cout << "inserting this child " << endl;
                layerMap[child] = curLayer+1;
                Q.push(child);
            }

//            cout << "printing layerMap " << endl;
//            prMap( layerMap );
        }
    }
}


int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    LL a, b, c, d, e, f;
    bfs( "123456780" );

//    DBG( layerMap.size() );

    cin >> kase;
//    DBG(kase);
    FOR(a,1,1+kase)
    {
//        DBG(a);
        inpStr.clear();
        FOR(b,0,9)
        {
            LL i;
            ILL(i);
            inpStr.PUB( '0' + i );
        }
//        DBG(inpStr);
        LL ans;
        if ( layerMap.find(inpStr)==layerMap.end() )
        {
            ans = INT_MAX;
        }
        else
        {
            ans = layerMap[inpStr];
        }
//        LL ans = aStar()  ;
//        DBG(ans);
        printf("Case %lld: ", a);
        if (ans >= INT_MAX)
        {
            printf("impossible\n");
        }
        else
        {
            printf("%lld\n", ans);
        }
    }
    return 0;
}






