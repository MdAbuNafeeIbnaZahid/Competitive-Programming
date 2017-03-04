#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long a, b, c, d, e, f, g;
long long k, r;
long long ans, tot;
int main()
{
    cin >> k >> r;
    for (a = 1; a <= 19; a++)
    {
        tot = a*k;
        if ( (tot%10==0) || (tot%10==r) )
        {
            cout << a ;
            return 0;
        }
    }
    return 0;
}
