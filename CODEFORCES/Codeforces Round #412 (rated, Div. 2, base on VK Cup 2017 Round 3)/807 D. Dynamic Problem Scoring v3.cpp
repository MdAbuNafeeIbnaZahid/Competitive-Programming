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
#define MAX_VAL 1000000007
#define SIZE 129
LL n, aAr[SIZE][9];
LL sucCnt[9];
LL getMaxPointVal(double rat)
{
    if ( rat <= (1.0 / 32) )
    {
        return 3000;
    }
    else if (rat <= (1.0 / 16) )
    {
        return 2500;
    }
    else if (rat <= (1.0 / 8) )
    {
        return 2000;
    }
    else if (rat <= (1.0 / 4) )
    {
        return 1500;
    }
    else if (rat <= (1.0 / 2) )
    {
        return 1000;
    }
    else
    {
        return 500;
    }
//    else if (rat <= (1.0 / 1) )
//    {
//        return 500;
//    }

}
bool isPos(LL num)
{
    LL a, b, c, d, e, f, vasPoint = 0, petPoint = 0;
    double rat;
//    cout << "isPos...  num = " << num << endl;
    for (a = 1; a <= 5; a++)
    {
//        cout << "a = " << a << endl;

        if ( aAr[1][a] == 250 || aAr[1][a]<aAr[2][a] )
        {
            // will make a wrong sub
            rat = ( ( 1.0 * sucCnt[a] ) / ( n + num ) );
        }
        else
        {
            // will make a correct sub
            rat = ( ( 1.0 * (sucCnt[a] + num ) ) / ( n + num ) );
        }

//        cout << "rat = " << rat << endl;
        LL maxPointVal = getMaxPointVal(rat);

        vasPoint += (maxPointVal/250) * ( 250 - aAr[1][a] );
        petPoint += (maxPointVal/250) * ( 250 - aAr[2][a] );

//        vasPoint += round( maxPointVal * ( ( 250 - aAr[1][a] ) / (250.0) ) );
//        petPoint += round( maxPointVal * ( ( 250 - aAr[2][a] ) / (250.0) ) );
    }
//    cout << "vasPoint = " << vasPoint << endl;
//    cout << "petPoint = " << petPoint << endl;
    return vasPoint > petPoint;
}
LL binSearch(LL low, LL high)
{
    LL mid = (low+high)/2;;
    if ( low==high )
    {
        if ( isPos(low) )
        {
            return low;
        }
        else
        {
            return -1;
        }
    }
    else if ( low>high )
    {
        return -1;
    }

    if ( isPos(mid) )
    {
        return binSearch(low, mid);
    }
    else
    {
        return binSearch(mid+1, high);
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        scanf("%lld %lld %lld %lld %lld", &aAr[a][1], &aAr[a][2], &aAr[a][3]
        , &aAr[a][4], &aAr[a][5]);
        for (b = 1; b <= 5; b++)
        {
            if ( aAr[a][b] == -1 )
            {
                aAr[a][b] = 250;
            }
            sucCnt[b] += ( aAr[a][b] != 250 );
        }
//        for (b= 1; b <= 5; b++)
//        {
//            cout << "b = " << b << ", sucCnt = " << sucCnt[b] << endl;
//        }
    }

//    for (a = 1; a <= 5; a++)
//    {
//        cout << "a = " << a << ", sucCnt = " << sucCnt[a] << endl;
//    }
//    cout << endl;

//    isPos(2);

    for (a = 0; a < 39*n; a++)
    {
        if ( isPos(a) )
        {
            cout << a;
            return 0;
        }
    }

    cout << -1;
    return 0;


    LL ans = binSearch(0, MAX_VAL);
    cout << ans;
    return 0;
}


