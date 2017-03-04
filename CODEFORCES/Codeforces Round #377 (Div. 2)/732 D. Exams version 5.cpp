#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, m;
long long dAr[SIZE], aAr[SIZE];
long long a, b, c, d, e, f, g, h;
long long lowerVal, higherVal, midVal;
long long ifPossible( long long daysGiven )
{
    long long a, b, c, d, e, f, g, h, currentDate, currentSubject, examGiven = 0;
    long long lastOccur[SIZE], alreadySpent = 0;
    set<long long> setLL;
    set<long long>::iterator setLLIt;
    memset(lastOccur, -1, sizeof(lastOccur));
    for (a = 1; a <= daysGiven; a++)
    {
        lastOccur[ dAr[a] ] = a;
    }
    for (a = 1; a <= m; a++)
    {
        setLL.insert( lastOccur[a] );
    }
    setLLIt = setLL.begin();
    currentDate = *setLLIt;
    if ( currentDate < 1 )
    {
        return 0;
    }
    while( setLL.size() )
    {
        setLLIt = setLL.begin();
        currentDate = *setLLIt;
        currentSubject = dAr[ currentDate ];
        if ( aAr[ currentSubject ] + alreadySpent >= currentDate )
        {
            return 0;
        }
        //examGiven++;
        alreadySpent += ( aAr[currentSubject]+1 );
        setLL.erase( setLLIt );
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &dAr[a]);
    }
    for (a = 1; a <= m; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    lowerVal = 1;
    higherVal = n;
    while( lowerVal < higherVal )
    {
        midVal = (lowerVal+higherVal)/2;
        if ( ifPossible(midVal) )
        {
            higherVal = midVal;
        }
        else lowerVal = midVal + 1;
    }
    if ( ifPossible(lowerVal) )
    {
        cout << lowerVal;
    }
    else
    {
        cout << -1;
    }
    return 0;
}
