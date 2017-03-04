#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long m;
long long a, b, c, d, e, f, g, h, i, j;
long long ans, lowerVal, higherVal, mid, ways;
int main()
{
    cin >> m;
    lowerVal = 1;
    higherVal = ((long long)1<<61);
    while( lowerVal < higherVal )
    {
        ways = 0;
        mid = (lowerVal+higherVal)/2;
        for (a = 2; a*a*a <= mid; a++)
        {
            ways += mid / (a*a*a);
        }
        if ( ways < m )
        {
            lowerVal = mid+1;
        }
        else higherVal = mid;
    }
    //cout << lowerVal << " " << higherVal << endl;
    ways = 0;
    for (a = 2; a*a*a <= lowerVal; a++)
    {
        ways += lowerVal / (a*a*a);
    }
    if(ways != m) cout << -1;
    else cout << lowerVal;
    return 0;
}
