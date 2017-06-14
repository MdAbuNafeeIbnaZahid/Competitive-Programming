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
map<LL, LL> dis;
LL X;
void bfs(LL u)
{
    LL a, b, c, d, e, f;
//    cout << "u = " << u << endl;
    dis[u] = 0;
    queue<LL> q;
    q.push(u);
    while(q.size())
    {
        LL cur = q.front();
//        cout << "cur = " << cur <<
        q.pop();
        vector<LL> vec;
        if (cur-1>0)
        {
            vec.push_back(cur-1);
        }
        vec.push_back(cur+1);
        if ( cur%3==0 )
        {
            vec.push_back(cur/3);
        }
        for (a = 0; a < vec.size(); a++)
        {
            if ( dis.find( vec[a] ) == dis.end() )
            {
                dis[ vec[a] ] = dis[cur]+1;
                q.push( vec[a] );
                if ( vec[a] == 1 )
                {
                    cout << dis[ vec[a] ];
                    exit(0);
                }
            }
        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> X;
    if ( X == 1 )
    {
        cout << 0;
        return 0;
    }
    bfs(X);
    cout << dis[1];
    return 0;
}
