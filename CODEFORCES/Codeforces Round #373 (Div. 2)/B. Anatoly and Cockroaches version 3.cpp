#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long a, b, c, d, e, f;
long long n;
char str[SIZE];
long long ans, shouldB, shouldR;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", str);
    ans = INT_MAX;
    shouldB = 0;
    shouldR = 0;
//    cout << "br" << endl;
    for (a = 0; a < n; a++)  // br seq
    {
        if ( a%2 == 0 )
        {
            if ( str[a] != 'b' )
            {
                shouldB++;
            }
        }
        else
        {
            if ( str[a] != 'r' )
            {
                shouldR++;
            }
        }
    }
//    cout << "shouldB = " << shouldB << endl;
//    cout << "shouldR = " << shouldR << endl;
    ans = min(ans, max(shouldB, shouldR) );
    shouldB = 0;
    shouldR = 0;
    for (a = 0; a < n; a++)  // rb seq
    {
        if ( a%2 == 1 )
        {
            if ( str[a] != 'b' )
            {
                shouldB++;
            }
        }
        else
        {
            if ( str[a] != 'r' )
            {
                shouldR++;
            }
        }
    }
    ans = min(ans, max(shouldB, shouldR) );
    cout << ans;
    return 0;
}
