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

#define FOR(i,a,b) for(i=a;i<=b;i++)
#define ROF(i,a,b) for(i=a;i>=b;i--)

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
#define SIZE
LL A, B, L, R;
vector<char> vec;
set<char> setChar;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> A >> B >> L >> R;
    LL a, b, c, d, e;
    R = min(R, L+3*(A+B));
    vec.push_back( 'a' );
    for(a = 1; a <= A; a++)
    {
        vec.push_back( a+'a'-1 );
    }
//    cout << "first a characters pushed " << endl;
//    DBG( vec.size() );
    for (a = 1; a <= B; a++)
    {
        vec.push_back( vec[A] );
    }
//    cout << "first B characters pushed" << endl;
//    DBG( vec.size() );
    for (a = A+B; a >= B+1; a--)
    {
        setChar.insert( vec[a] );
    }
    for ( a = A+B+1; a <= 2*A+B; a++)
    {
        char ch;
        for (ch = 'a'; ch <= 'z'; ch++)
        {
            if ( setChar.find(ch) == setChar.end() )
            {
                vec.push_back( ch );
                setChar.insert( ch );
                break;
            }
        }
    }
    for (a = 1; a <= B; a++)
    {
        vec.push_back( vec[2*A+B] );
    }

//    cout << " vec.size() =  " << vec.size() << endl;

    for (a = 0; a < vec.size(); a++)
    {
//        DBG(a);
//        cout << vec[a] << endl;
    }

    set<char> ansSet;
    for (a = L; a <= R; a++)
    {
//        DBG(a);
        LL curIdx = a%( 2*(A+B) );
        if ( curIdx == 0 )
        {
            curIdx = 2*(A+B);
        }
//        DBG(curIdx);
        ansSet.insert( vec[curIdx] );
    }
    set<char>::iterator setLLit;
    for (setLLit = ansSet.begin(); setLLit != ansSet.end(); setLLit++)
    {
//        DBG( *setLLit );
    }
//    for (  )
    cout << ansSet.size();
    return 0;
}
