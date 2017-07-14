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


#define LL 			long long
#define PairLL		pair<long long, long long>


#define RESET(a) 		memset(a,0,sizeof(a))
#define SET(a) 			memset(a,-1,sizeof(a))
#define SORT(v)         sort(v.begin(),v.end())
#define REV(v)          reverse(v.begin(),v.end())
#define MP              make_pair
#define PB				push_back

#define FOR(i,a,b) for(i=(a);i<(b);i++)
#define ROF(i,a,b) for(i=(a);i>(b);i--)

#define DBG(x) cout<<#x<<" : "<<x<<endl

#define PI (2.0*acos(0.0)) //#define PI acos(-1.0)

void printVecLL(vector<LL> vecToPr)
{
    LL a, b, c, d, e;
    for ( a= 0; a < vecToPr.size(); a++)
    {
        printf("%lld ", vecToPr[a]);
    }
    printf("\n");
}


void printMapLLLL( map<LL, LL> mapToPr )
{
    LL a, b, c, d, e;
    map<LL, LL>::iterator mapIt;
    cout << endl;
    for (mapIt = mapToPr.begin(); mapIt != mapToPr.end(); mapIt++)
    {
        cout << "[" << mapIt->first << "] = " << mapIt->second << endl;
    }
    cout << endl;
}


/******   END OF HEADER *********/
#define SIZE 1009
char firL[SIZE], secL[SIZE], str[SIZE], ansStr[SIZE], mapStr[SIZE];
LL len;

char getToPutChar(char ch)
{
//    cout << "hello" << endl;
//    DBG(ch);
    char toPut;
    if ( 'a'<=ch && ch<='z' )
    {
        toPut = mapStr[ ch ];
    }
    else if ( 'A'<=ch && ch<='Z' )
    {
//        cout << " 'A' <= ch <= 'Z' " << endl;
        toPut = mapStr[ ch-'A'+'a' ]-'a'+'A';
    }
    else
    {
//        cout << "in else" << endl;
        toPut = ch;
    }
    return toPut;
}

int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    scanf("%s", firL+1);
    scanf("%s", secL+1);
    scanf("%s", str+1);
    len = strlen(str+1);
//    DBG(len);
    FOR(a,1,27)
    {
        mapStr[ firL[a] ] = secL[a];
    }
    FOR(a,1,1+len)
    {
//        DBG(a);
        char toPut;
//        if ( 'a' <= str[a] <= 'z' )
//        {
//            toPut = mapStr[ str[a] ];
//        }
//        else if ( 'A' <= str[a] <= 'Z' )
//        {
//            toPut = mapStr[ str[a]-'A'+'a' ]-'a'+'A';
//        }
//        else
//        {
//            toPut = str[a];
//        }
        toPut = getToPutChar( str[a] );
        ansStr[a] = toPut;
        printf("%c", ansStr[a]);
    }

    return 0;
}

