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
#define SIZE 1009
#define W ('W')
#define L ('L')
#define D ('D')
LL n, k;
LL dp[SIZE][3*SIZE], sol[SIZE][SIZE];
char str[SIZE];
LL getDp(LL row, LL col)
{
//    cout << "in getDp row = " << row << ", col = " << col << endl;
    if ( col <= -k || col>=k )
    {
        return 0;
    }
//    cout << "returning " << dp[row][col+SIZE] << " from getDp" << endl;
    return dp[row][col+SIZE];
}
LL assignDp(LL row, LL col, LL val, char ch)
{
    dp[row][col+SIZE] = val;
    sol[row][col+SIZE] = ch;
}
LL setDp(LL row, LL col)
{
    LL a, b, c, d, e, f;
    char curChar = str[row];
//    cout << "in setDp row = " << row << ", col = " << col << ", curChar = " << curChar << endl;
    if ( curChar==W || curChar=='?' )
    {
        if ( getDp(row-1, col-1) )
        {
            assignDp(row, col, 1, W);
//            dp[row][col] = 1,
//            sol[row][col] = W;
        }
    }
    if ( curChar==L || curChar=='?' )
    {
        if ( getDp(row-1, col+1) )
        {
            assignDp(row, col, 1, L);
//            dp[row][col] = 1,
//            sol[row][col] = L;
        }
    }
    if ( curChar==D || curChar=='?' )
    {
        if ( getDp(row-1, col) )
        {
            assignDp(row, col, 1, D);
//            dp[row][col] = 1,
//            sol[row][col] = D;
        }
    }
}
void printSol(LL row, LL col)
{
    vector<char> vecChar;
    LL a, b, c, d, e;
    while( row!=0 || col-SIZE != 0 )
    {
        char toPrin = sol[row][col];
//        printf("%c", toPrin);
        vecChar.push_back( toPrin );
        row--;
        if ( toPrin == W )
        {
            col--;
        }
        else if ( toPrin == L )
        {
            col++;
        }
        else if ( toPrin == D )
        {

        }
    }
    reverse(vecChar.begin(), vecChar.end());
    for (a = 0; a < vecChar.size(); a++)
    {
        printf("%c", vecChar[a]);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n >> k;
    scanf("%s", str+1);
    // W-L
    dp[0][0+SIZE] = 1;
    for (a = 1; a <= n-1; a++)
    {
        for (b = 1-k; b <= k-1; b++)
        {
            setDp(a,b);
        }
    }
    setDp(n, -k);
    setDp(n, k);

//    for (a = 0; a <= n; a++)
//    {
//        for (b = -k; b <= k; b++)
//        {
//            cout << dp[a][b+SIZE] << " ";
//        }
//        cout << endl;
//    }
//
//    cout << endl << endl;
//    cout << "sol" << endl;
//    for (a = 0; a <= n; a++)
//    {
//        for (b = -k; b <= k; b++)
//        {
//            char toP = (char)sol[a][b+SIZE];
//            if ( toP == 0 )
//            {
//                cout << "0 " ;
//            }
//            else
//            {
//                cout << (char)sol[a][b+SIZE] << " ";
//            }
//
//        }
//        cout << endl;
//    }

    if ( dp[n][-k+SIZE] )
    {
//        cout << "W-L=k" << endl;
        printSol(n, -k+SIZE);
        return 0;
    }
    else if ( dp[n][k+SIZE] )
    {
//        cout << "W-L=k" << endl;
        printSol(n, k+SIZE);
        return 0;
    }

    cout << "NO";
    return 0;
}
