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
LL k;
vector<LL> parVec;
LL ans, len;
LL getSum(vector<LL> vec)
{
    LL ret = 0, a, b, c;
    for (a = 0; a< vec.size(); a++)
    {
        ret += vec[a];
    }
    return ret;
}
LL getMax(vector<LL> vec)
{
    LL ret = INT_MIN,a , b, c, d;
    for (a = 0; a < vec.size(); a++)
    {
        ret = max(ret, vec[a]);
    }
    return ret;
}
vector<LL> genVec()
{
    vector<LL> ret;
    char ch;
    LL cnt = 0;
    while(1)
    {
        ch = getchar();
//        cout << "ch = " << ch << endl;
        cnt++;
        if ( (ch>='a'&&ch<='z' ) || (ch>='A'&&ch<='Z' ) )
        {

        }
        else
        {
            ret.push_back(cnt);
            cnt=0;
        }
        if ( ch == '\n' )
        {
            ret[ ret.size()-1 ]--;
            break;
        }
    }
    return ret;
}
void printVecLL(vector<LL> vec)
{
    LL a, b, c, d;
    cout << endl;
    for (a = 0;a  < vec.size(); a++)
    {
        cout << vec[a] << " ";
    }
    cout << endl;
}
LL getParReq(LL maxParLen, vector<LL> vecLL)
{
    LL ret = 0, curParLen = 0, curNum;
    while( vecLL.size() )
    {
        curNum = vecLL[ vecLL.size() - 1 ];
        vecLL.pop_back();
        if ( curParLen + curNum > maxParLen )
        {
            ret++;
            curParLen = curNum;
        }
        else
        {
            curParLen += curNum;
        }
    }
    if ( curParLen )
    {
        ret++;
    }
    return ret;
}
LL binSearch(LL minVal, LL maxVal)
{
    LL mid = (minVal+maxVal)/2;
    if ( minVal == maxVal )
    {
        return maxVal;
    }
    LL req = getParReq(mid, parVec);
    if ( req <= k )
    {
        return binSearch(minVal, mid);
    }
    else
    {
        return binSearch(mid+1, maxVal);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> k;
    getchar();
    parVec = genVec();
//    printVecLL(parVec);
    LL minVal = getMax(parVec);
//    cout << "minVal = " << minVal << endl;
    LL maxVal = getSum(parVec);
//    cout << "maxVal = " << maxVal << endl;
    LL ans = binSearch(minVal, maxVal);
    cout << ans << endl;
    return 0;
}
