#include <bits/stdc++.h>
using namespace std;
#define SIZE 19
long long  n, x[SIZE], y[SIZE];
long long a, b, c, d, e;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> x[a] >> y[a];
    }
    for (a = 2; a <= n; a++)
    {
        if( x[a] != x[a-1] ) break;
    }
    if ( a > n )
    {
        cout << "YES" ;
        return 0;
    }
    for (a = 2; a <= n; a++)
    {
        if ( y[a] != y[a-1] ) break;
    }
    if ( a > n )
    {
        cout << "YES";
        return 0;
    }
    cout << "NO";
    return 0;
    return 0;
}
