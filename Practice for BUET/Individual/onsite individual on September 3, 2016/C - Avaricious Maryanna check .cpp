#include <bits/stdc++.h>
using namespace std;
long long a, b, c, d, e, f, g, h, mod;
int main()
{
    mod = 1;
    for (a = 1; a <= 15; a++)
    {
        mod *= 10;
        cout << "a = " << a << " --> ";
        for (b = (mod/10); b < mod; b++)
        {
            if ( (b*b)%mod == b ) cout << b << " ";
        }
        cout << endl;
    }
    return 0;
}
