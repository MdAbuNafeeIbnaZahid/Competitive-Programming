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
#define SIZE 10000009
long long n, k, aAr[SIZE], ans;
long long a, b, c, d, e, f, maxVal, minVal, midVal, totalSlices, maxSlice, personPossible[SIZE];
void update(long long joy)
{
    long long a, b, c, d, e, f, leftChild, rightChild;
    for (a = 0; a < SIZE; a++)
    {
        personPossible[a] = (a>=joy);
        leftChild = a/2;
        rightChild = a - leftChild;
        personPossible[a] = max(personPossible[leftChild] + personPossible[rightChild],
                                personPossible[a]);

    }
}
long long ifPossible(long long joy)
{
    long long a, b, c, d, e, f, g, pupilCovered = 0, thisTan;
    for (a = 1; a <= n; a++)
    {
        pupilCovered += personPossible[ aAr[a] ];
    }
    return pupilCovered >= k;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        totalSlices += aAr[a];
        maxSlice = max(maxSlice, aAr[a]);
    }
    if ( totalSlices < k )
    {
        cout << -1;
        return 0;
    }
    minVal = 1;
    maxVal = maxSlice;
    while(minVal < maxVal)
    {
        midVal = (minVal+maxVal+1)/2;
//        cout << "midVal = " << midVal << endl ;
        update(midVal);
//        for (a = 0; a < 15; a++)
//        {
//            cout << "a = " << a << " personPossible  = " << personPossible[a] << endl ;
//        }
        if ( ifPossible(midVal) )
        {
            minVal = midVal;
        }
        else
        {
            maxVal = midVal - 1;
        }
    }
    cout << maxVal;
    return 0;
}

