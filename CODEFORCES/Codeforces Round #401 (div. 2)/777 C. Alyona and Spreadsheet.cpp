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
#define SIZE 100009
long long n, m, k;
vector<long long> grid[SIZE], nonDecLen[SIZE];

struct range
{
    long long si, ei;
    range(){}
    range(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
    bool operator < ( const range B ) const
    {
        if ( si == B.si )
        {
            return ei < B.ei;
        }
        return si < B.si;
    }
};
map<range, long long> ifNonDec;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b , c, d, e, f;
    cin >> n >> m;
//    cout << "n = " << n << endl ;
//    cout << "m = " << m << endl ;
    for ( a = 0; a < n; a++ )
    {
        for ( b = 0; b < m; b++ )
        {
            long long num;
            scanf("%lld", &num);
            grid[ a ].push_back( num );
            nonDecLen[ a ].push_back( 0 );
        }
    }
//    cout << "printing grid " << endl;
//    for ( a = 0; a< n; a++ )
//    {
//        for (b = 0; b < m; b++)
//        {
//            cout << grid[a][b] << " ";
//        }
//        cout << endl;
//    }
//    for (  )
    for ( a = 0; a < m; a++ )
    {
        nonDecLen[0][a] = 1;
        for ( b = 1; b < n; b++ )
        {
            if ( grid[b][a] >= grid[b-1][a] )
            {
                nonDecLen[b][a] = nonDecLen[b-1][a] + 1;
            }
            else
            {
                nonDecLen[b][a] = 1;
            }
        }
    }
//    cout << "printing nonDecLen " << endl;
//    for ( a = 0; a < n; a++ )
//    {
//        for ( b = 0; b < m; b++ )
//        {
//            cout << nonDecLen[a][b] << " ";
//        }
//        cout << endl;
//    }
    cin >> k;
    if ( m < n ) // less column
    {
//        cout << "m < n" << endl;
        long long li, ri;
        for ( a = 1; a <= k; a++ )
        {
//            cout << "a = " << a << endl;
            scanf("%lld %lld", &li, &ri);
            li--;
            ri--;
//            cout << "li = " << li << ", ri = " << ri << endl;
            long long flag = 0;
            for ( b = 0; b < m; b++ )
            {
                flag = flag || ( (nonDecLen[ri][b] - nonDecLen[li][b]) == (ri-li) );
            }
            if ( flag )
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    else  // less row
    {
        //for ( a = 0; a < m; a++ )
        //{
            for ( b = 0; b < n; b++ )
            {
                for ( c = b; c < n; c++ )
                {
                    long long flag = 0;
                    for ( a = 0; a < m; a++ )
                    {
                        flag = flag ||  ( nonDecLen[c][a]-nonDecLen[b][a] == c-b );
//                        if ( nonDecLen[c][m]-nonDecLen[b][m] == c-b )
//                        {
//                            ifNonDec[ range(b, c) ] = 1;
//                            cout << "b = " << b << ", c = " << c << endl;
//                        }
                    }
                    if ( flag )
                    {
                        ifNonDec[ range(b, c) ] = 1;
//                        cout << "b = " << b << ", c = " << c << endl;
                    }
                }
            }
        //}
        for ( a = 1;  a<= k; a++ )
        {
            long long li, ri;
            scanf("%lld %lld", &li, &ri);
            li--;
            ri--;
            if ( ifNonDec[ range(li, ri) ] )
            {
                printf("Yes\n");
            }
            else
            {
                printf("No\n");
            }
        }
    }
    return 0;
}

