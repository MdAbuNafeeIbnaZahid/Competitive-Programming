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
#define SIZE 509
#define MAX_NODE 250009
long long k, M, nAr[SIZE];
char sAr[SIZE][SIZE];
long long a, b, c, d, e, f, ans, currentIdx, current;
long long node[MAX_NODE][29], countNode[MAX_NODE], parentNode[MAX_NODE];
long long depthOfNode[MAX_NODE];
long long root, nnode, parent;
void initializeTrie()
{
    long long a, b, c;
    nnode = 0;
    memset(countNode, 0, sizeof(countNode) );
    memset( parentNode, -1, sizeof(parentNode) );
    memset(depthOfNode, 0, sizeof(depthOfNode) );
    for (a = 0; a < 27; a++)
    {
        node[0][a] = -1;
    }
}
void insertInTrie(char *str, long long rep)
{
    long long a, b, c, d, e, f, g, len = strlen(str), now = 0, rem = rep;
    countNode[ now ] += rep;
    //cout << "now = " << now << ", countNode[now]" << countNode[now] << endl;
    for (a = 0; a < len; a++)
    {
        if ( node[now][ str[a]-'A' ] == -1 )
        {
            node[now][ str[a]-'A' ] = ++nnode;
            parentNode[ nnode ] = now;
            depthOfNode[ nnode ] = a+1;
            for (b = 0; b < 27; b++)
            {
                node[ nnode ][b] = -1;
            }
        }
        now = node[now][ str[a]-'A' ];
        countNode[ now ] += rep;
        //cout << "now = " << now << ", countNode[now]" << countNode[now] << endl;
    }
}
struct DNA
{
    long long idx, len;
    DNA(){}
    DNA(long long idx, long long len)
    {
        this->idx = idx;
        this->len = len;
    }
    bool operator < (const DNA B) const
    {
        if ( len == B.len )
        {
            return idx < B.idx;
        }
        return len < B.len;
    }
};
set<DNA> setDNA;
set<DNA>::iterator setDNAIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> k >> M;
        if (k+M==0)
        {
            return 0;
        }
        setDNA = set<DNA>();
        ans = 0;
        initializeTrie();
        for (a = 1; a <= k; a++)
        {
            scanf("%lld", &nAr[a]);
            scanf("%s", sAr[a]);
            if ( strlen( sAr[a] ) < M )
            {
                continue;
            }
            insertInTrie( sAr[a], nAr[a] );
        }
        for (a = nnode; a >= 1; a--)
        {
            //cout << "a = " << a<< endl;
            if ( depthOfNode[a] < M || countNode[a]<=0 )
            {
                continue;
            }
            ans++;
            //cout << "ans is increased" << endl;
            current = a;
            while( current != 0 )
            {
                //cout << "current = " << current << endl;
                countNode[current]--;
                current = parentNode[current];
            }
        }
        cout << ans << endl;
    }
    return 0;
}
