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
struct eat
{
    long long eater;
    char ch;
    eat(){}
    eat(long long eater, char ch)
    {
        this->eater = eater;
        this->ch = ch;
    }
};
long long n, k, ai, bi;
vector<long long> aVec, bVec, workVec;
long long a, b, c, d, e, f, g, h, nextBig, smallSum, maxMons, ifEaten, doubleMons;
vector<eat> eatVec;
long long maxOfAVec(vector<long long> vec)
{
    long long a, b, c, ret = INT_MIN;
    for (a = 0; a < vec.size(); a++)
    {
        ret = max(ret, vec[a]);
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ai);
        aVec.push_back( ai );
    }
    cin >> k;
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &bi);
        bVec.push_back( bi );
    }
    while( bVec.size() )
    {
        workVec = vector<long long>();
        smallSum = 0;
        nextBig = bVec[ bVec.size()-1 ];
        //cout << "nextBig = " << nextBig << endl;
        //cout << "aVec.size() = " << aVec.size() << endl;
        bVec.pop_back();
        while( smallSum < nextBig )
        {
            if ( aVec.size() == 0 )
            {
                cout << "NO";
                return 0;
            }
            smallSum += aVec[ aVec.size()-1 ];
            workVec.push_back( aVec[aVec.size()-1] );
            aVec.pop_back();
        }
        //cout << "smallSum = " << smallSum << endl;
        if ( smallSum > nextBig )
        {
            cout << "NO";
            return 0;
        }
        reverse( workVec.begin(), workVec.end() );
        while(1)
        {
            maxMons = maxOfAVec( workVec );
            if ( maxMons == nextBig )
            {
                break;
            }
            ifEaten = 0;
            for (a = 0; a < workVec.size(); a++)
            {
                if ( workVec[a] == maxMons )
                {
                    if ( a > 0  && workVec[a-1] < workVec[a] )
                    {
                        doubleMons = workVec[a-1]+workVec[a];
                        eatVec.push_back( eat(aVec.size()+a+1, 'L') );
                        ifEaten = 1;
                        workVec.erase( workVec.begin()+a-1, workVec.begin()+a+1 );
                        workVec.insert( workVec.begin()+a-1,  doubleMons);
                        break;
                    }
                    if ( a < workVec.size()-1 &&  workVec[a+1] < workVec[a] )
                    {
                        doubleMons = workVec[a]+workVec[a+1];
                        eatVec.push_back( eat(aVec.size()+a+1, 'R') );
                        ifEaten = 1;
                        workVec.erase( workVec.begin()+a, workVec.begin()+a+2 );
                        workVec.insert( workVec.begin()+a,  doubleMons);
                        break;
                    }
                }
            }
            if ( !ifEaten )
            {
                cout << "NO";
                return 0;
            }
        }
    }
    if ( aVec.size() )
    {
        cout << "NO";
        return 0;
    }
    cout << "YES" << endl;
    for (a = 0; a < eatVec.size(); a++)
    {
        printf("%lld %c\n", eatVec[a].eater, eatVec[a].ch);
    }
    return 0;
}
