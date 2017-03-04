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
#define SIZE 5009
long long n, m, xe, ye, w, ci, ki, pi, q, gj, rj, aj;
long long layerAr[SIZE][SIZE];
long long a, b, c, d, e, f, lowerVal, midVal, upperVal;
vector<long long> gr[SIZE];
struct store
{
    long long city, totalNumberOfShovels, priceOfEach;
    store(){}
    store(long long city, long long totalNumberOfShovels, long long priceOfEach)
    {
        this->city = city;
        this->totalNumberOfShovels = totalNumberOfShovels;
        this->priceOfEach = priceOfEach;
    }
    bool operator < (const store B) const
    {
        if ( priceOfEach == B.priceOfEach )
        {
            if ( city== B.city )
            {
                return totalNumberOfShovels < B.totalNumberOfShovels;
            }
            return city < B.city;
        }
        return priceOfEach < B.priceOfEach;
    }
};
multiset<store> mulSetStore;
void bfs( long long *layer, long long u )
{
    long long a, b, c, d, e, f, current;
    queue<long long> Q;
    layer[u] = 0;
    Q.push(u);
    while(Q.size() )
    {
        current = Q.front();
        Q.pop();
        for (a = 0; a < gr[current].size(); a++)
        {
            if ( layer[ gr[current][a] ] >= INT_MAX )
            {
                layer[ gr[current][a] ] = layer[current]+1;
                Q.push( gr[current][a] );
            }
        }
    }
}
long long ifPossible(long long city, long long totalOrder, long long maxCost, long long maxTime)
{
    long long a, b, c, d, e, f;
    long long moneyInHand = maxCost, shovelInHand = 0, currentOrder;
    multiset<store>::iterator mulSetStrIt;
    for ( mulSetStrIt = mulSetStore.begin(); mulSetStrIt != mulSetStore.end() &&
        shovelInHand < totalOrder ; mulSetStrIt++)
    {
        if ( layerAr[city][mulSetStrIt->city ] > maxTime )
        {
            continue;
        }
        currentOrder = min(mulSetStrIt->totalNumberOfShovels, totalOrder-shovelInHand );
        if ( currentOrder * mulSetStrIt->priceOfEach > moneyInHand )
        {
            return 0;
        }
        moneyInHand -= currentOrder * mulSetStrIt->priceOfEach;
        shovelInHand += currentOrder;
    }
    return shovelInHand >= totalOrder;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    freopen("output.txt", "w", stdout);
    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            layerAr[a][b] = INT_MAX;
        }
    }
    cin >> n >> m;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &xe, &ye);
        gr[xe].push_back(ye);
        gr[ye].push_back(xe);
    }
    for (a = 1; a <= n; a++)
    {
        bfs(layerAr[a], a);
    }
    cin >> w;
    for (a = 1; a <= w; a++)
    {
        scanf("%lld %lld %lld", &ci, &ki, &pi);
        mulSetStore.insert( store(ci, ki, pi) );
    }
    cin >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld %lld %lld", &gj, &rj, &aj);
        lowerVal = 0;
        upperVal = SIZE+9;
        while( lowerVal < upperVal )
        {
            midVal = (lowerVal+upperVal)/2;
            if ( ifPossible(gj, rj, aj, midVal) )
            {
                upperVal = midVal;
            }
            else
            {
                lowerVal = midVal+1;
            }
        }
        if ( lowerVal > SIZE )
        {
            printf("-1\n");
        }
        else
        {
            printf("%lld\n", lowerVal);
        }
    }
    return 0;
}
