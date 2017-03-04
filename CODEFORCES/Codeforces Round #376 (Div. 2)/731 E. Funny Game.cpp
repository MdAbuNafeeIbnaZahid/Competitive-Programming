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
#define SIZE 200009
long long n, aAr[SIZE];
long long a, b, c, d, e, f, g;
long long cumSum[SIZE], ans;
struct moves
{
    long long key,idx;
    moves(){}
    moves(long long key, long long idx)
    {
        this->key = key;
        this->idx = idx;
    }
    bool operator < (const moves B) const
    {
        if ( key == B.key )
        {
            return idx < B.idx;
        }
        return key > B.key;
    }
};
moves current;
set<moves> setMoves;

void printSetMoves(set<moves> toPrint)
{
    set<moves>::iterator setMovesIt;
    for (setMovesIt = toPrint.begin(); setMovesIt != toPrint.end(); setMovesIt++)
    {
        cout << setMovesIt->key << " " << setMovesIt->idx << endl;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (a=1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        cumSum[a] = cumSum[a-1] + aAr[a];
    }
//    for (a = 1; a <= n; a++)
//    {
//        cout << "a = " << a << ", cumSum[a] = " << cumSum[a] << endl;
//    }
    setMoves.insert( moves(cumSum[n], n) );

//    printSetMoves(setMoves);

    for (a = n-1; a > 1; a--)
    {
//        cout << "a = " << a << endl;
        current = *setMoves.begin();
        setMoves.insert( moves(cumSum[a] - current.key, a) );
//        printSetMoves(setMoves);
    }
    current = *setMoves.begin();
    ans = current.key;
    cout << ans;
    return 0;
}

