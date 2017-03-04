#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long N, inputAr[SIZE];
long long a,b, c, d, e, f;
long long lisUpto[SIZE], ldsUpto[SIZE], ans;
set<long long> lisSet, ldsSet;
set<long long>::iterator setLLIt;
int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf("%lld", &N) != EOF )
    {
        //cout << "N = " << N <<endl;
        ans = INT_MIN;
        lisSet = set<long long>();
        ldsSet = set<long long>();
        memset(lisUpto, 0, sizeof(lisUpto));
        memset(ldsUpto, 0, sizeof(ldsUpto));
        for (a = 1; a <= N; a++)
        {
            scanf("%lld", &inputAr[a] );
        }
        for (a = 1; a<=N; a++)
        {
            //cout << inputAr[a] << " ";
        }
        //cout << endl;
        lisUpto[1] = 1;
        lisSet.insert( inputAr[1] );
        for (a = 2; a <= N; a++)
        {
            //cout << "a = " <<a << endl;
            setLLIt = lisSet.lower_bound( inputAr[a] );
            if ( setLLIt == lisSet.end() )
            {
                lisSet.insert( inputAr[a] );
                lisUpto[a] = lisSet.size();
            }
            else
            {
                //cout << " will not increase lis " << endl;
                lisUpto[a] = distance( lisSet.begin(), setLLIt ) + 1;
                lisSet.erase( setLLIt );
                lisSet.insert( inputAr[a] );
            }
        }
        //cout << "lis done" << endl;
        ldsUpto[N] = 1;
        ldsSet.insert( inputAr[N] );
        for (a = N-1; a>=1; a--)
        {
            setLLIt = ldsSet.lower_bound( inputAr[a] );
            if ( setLLIt == ldsSet.end() )
            {
                ldsSet.insert( inputAr[a] );
                ldsUpto[a] = ldsSet.size();
            }
            else
            {
                ldsUpto[a] =  distance(ldsSet.begin(), setLLIt)  +1;
                ldsSet.erase( setLLIt );
                ldsSet.insert( inputAr[a] );
            }
        }
        for (a = 1; a <= N; a++)
        {
            ans = max( ans, 1+ 2*min(lisUpto[a]-1, ldsUpto[a]-1) );
        }
        cout << ans << endl;
    }
    return 0;
}
