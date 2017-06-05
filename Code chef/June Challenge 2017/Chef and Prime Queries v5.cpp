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
/******   END OF HEADER *********/
#define SIZE 1000009
long long N, Q, aAr[SIZE], L[SIZE], R[SIZE], X[SIZE], Y[SIZE];
// X-Y prime range
// L-R idx range
long long isPrime[SIZE];
vector<long long> vecPrime;
struct myQ
{
    long long pr, idx, expo;
    myQ(){}
    myQ(long long pr, long long idx, long long expo)
    {
        this->pr = pr;
        this->idx = idx;
        this->expo = expo;
    }
    bool operator < (const myQ B) const
    {
        if ( pr == B.pr )
        {
            if ( idx == B.idx )
            {
                return expo <  B.expo;
            }
            return idx < B.idx;
        }
        return pr < B.pr;
    }
};

void siv(long long siz)
{
    memset(isPrime, -1, sizeof(isPrime));
    isPrime[1] = 0;
    long long a, b, c, d;
    for (a = 2; a < SIZE; a++)
    {
        if ( isPrime[a] )
        {
            vecPrime.push_back( a );
            for (b = a*a; b < SIZE; b+=a)
            {
                isPrime[b] = 0;
            }
        }
    }

}
set<myQ> primeExpoSet, quSet;
map<long long, map<long long, long long> > ansMap;

void printSetMyQ(set<myQ> toPr)
{
    set<myQ>::iterator setMyQIt = toPr.begin();
    for ( ; setMyQIt != toPr.end(); setMyQIt++ )
    {
        cout << "pr = " << setMyQIt->pr << ", idx = " << setMyQIt->idx <<
        ", expo = " << setMyQIt->expo << endl;
    }
}

void handlePrEx(long long idx)
{
    long long val = aAr[idx], a, b, c, d, e;
    for ( a = 0; a < vecPrime.size() & val > 1; a++)
    {
        if ( isPrime[ val ] )
        {
            primeExpoSet.insert( myQ(val, idx, 1) );
            val = 1;
            break;
        }
        long long expo = 0;
        while( val % vecPrime[a] == 0 )
        {
            val /= vecPrime[a];
            expo++;
        }
        if ( expo > 0 )
        {
            primeExpoSet.insert( myQ(vecPrime[a], idx, expo) );
        }
    }
}
struct bit
{
    long long siz;
    long long treeAr[SIZE];
    bit(long long siz)
    {
        this->siz = siz;
        long long a, b, c;
        for ( a = 0; a <= siz; a++)
        {
            treeAr[a] = 0;
        }
    }

    long long read(long long idx)
    {
        long long ret = 0;
        while(idx > 0)
        {
            ret += treeAr[idx];
            idx -= (idx & -idx);
        }
        return ret;
    }

    void update(long long idx, long long val)
    {
        while(idx <= siz )
        {
            treeAr[idx] += val;
            idx += (idx & -idx);
        }
    }
};
int main()
{
//    freopen("input.txt", "r", stdin);
    siv( SIZE );
    long long a, b, c, d, e, f;
    cin >> N;
    for ( a= 1; a <= N; a++)
    {
//        cout << "a = " << a << endl;
        scanf("%lld", &aAr[a]);
        handlePrEx( a );
//        cout << "primeExpoSet.size() = " << primeExpoSet.size() << endl;
    }
//    printSetMyQ( primeExpoSet );
    cin >> Q;
    for ( a = 1; a <= Q; a++ )
    {
        scanf("%lld %lld %lld %lld", &L[a], &R[a], &X[a], &Y[a]);
        L[a]--;
        X[a]--;
        quSet.insert( myQ(X[a], L[a], 0) );
        quSet.insert( myQ(X[a], R[a], 0) );
        quSet.insert( myQ(Y[a], L[a], 0) );
        quSet.insert( myQ(Y[a], R[a], 0) );

    }
    bit myBit(N+5);
//    printSetMyQ( quSet );
    while( quSet.size() )
    {
        set<myQ>::iterator setMyQIt = quSet.begin();
        quSet.erase( setMyQIt );
        long long curPr = setMyQIt->pr;
        while( primeExpoSet.size() )
        {
            if ( primeExpoSet.begin()->pr > curPr )
            {
                break;
            }
            myBit.update( primeExpoSet.begin()->idx, primeExpoSet.begin()->expo );
            primeExpoSet.erase( primeExpoSet.begin() );
        }
        long long readVal = myBit.read( setMyQIt->idx );
//        cout << "readVal = " << readVal << endl;
        ansMap[setMyQIt->idx][setMyQIt->pr] = readVal;
    }
    for (a = 1; a <= Q; a++)
    {
        long long ans = (ansMap[ R[a] ][ Y[a] ] - ansMap[ L[a] ][ Y[a] ] )
                        - (ansMap[ R[a] ][ X[a] ] - ansMap[ L[a] ][ X[a] ] );
        printf("%lld\n", ans);
    }
    return 0;
}
