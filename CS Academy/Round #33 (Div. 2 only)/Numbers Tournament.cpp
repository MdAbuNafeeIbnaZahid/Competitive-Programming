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
#define LL long long
/******   END OF HEADER *********/
#define SIZE 109
LL N;
vector<LL> vecAr[SIZE];
LL pointAr[SIZE];
LL getRes(vector<LL> fv, vector<LL> sv)
{
    LL a, b, c, d, e, f;
    LL minC = INT_MAX, maxC = INT_MIN;
    set<LL> setLL;
    setLL.insert( fv.begin(), fv.end() );
    for (a = 0; a < sv.size(); a++)
    {
        if ( setLL.find( sv[a] ) == setLL.end() )
        {

        }
        else
        {
            minC = min(minC, sv[a]);
            maxC = max(maxC, sv[a]);
        }
    }
    LL cntA = 0, cntB = 0;
    for (a = 0; a < sv.size(); a++)
    {
        cntA += ( ( fv[a] < minC || fv[a] > maxC ) );
        cntB += ( ( sv[a] < minC || sv[a] > maxC ) );
//        if ( sv[a] < minC || sv[a] > maxC )
//        {
//
//        }
    }
    if ( cntA > cntB )
    {
        return 1;
    }
    else if ( cntA == cntB )
    {
        return 0;
    }
    else
    {
        return 2;
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> N;
//    cout << "N = " << N << endl;
    for (a = 1; a <= N; a++)
    {
        for (b = 1;  b<= N; b++)
        {
            LL num;
            scanf("%lld", &num);
            vecAr[a].push_back( num );
        }
        sort(vecAr[a].begin(), vecAr[a].end());
    }
//    cout << "input taken" << endl;
//    cout << "input taken" << endl;
//    cout << "input taken" << endl;
    for (a = 1; a <= N; a++)
    {
        for (b = a+1; b <= N; b++)
        {
            LL res = getRes( vecAr[a], vecAr[b] );
//            cout << "got res" << endl;
            if ( res == 1 )
            {
                pointAr[a] += 2;
            }
            else if ( res == 2 )
            {
                pointAr[b] += 2;
            }
            else if ( res == 0 )
            {
                pointAr[a]++;
                pointAr[b]++;
            }
        }
    }
//    cout << "point calculated " << endl;
    vector< pair<LL, LL> > setP;
    for (a = 1; a <= N; a++)
    {
        setP.push_back( make_pair( -pointAr[a], a ) );
    }
    sort(setP.begin(), setP.end());
    for (a = 0; a < setP.size(); a++)
    {
        printf("%lld\n", setP[a].second);
    }
    return 0;
}
