#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n;
char str[SIZE];
long long a, b, c, d, e, f, g, rEv, bEv;
long long cntAr[SIZE], ans;
int main()
{
    freopen( "input.txt", "r", stdin );
    cin >> n;
    scanf("%s", str);
    for (a = 0; a < n-1; a++)
    {
        if ( str[a] == str[a+1] )
        {
            cntAr[ str[a] ]++;
            a+=1;
        }
    }
    ans = max( cntAr[ (int)'b' ], cntAr[ (int)'r' ] );
    cout << ans ;
    return 0;
}
