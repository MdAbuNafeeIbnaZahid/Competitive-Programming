#include <bits/stdc++.h>
using namespace std;
#define x 1234567
#define y 123456
#define z 1234
long long a, b, c, d, rem;
long long n;
int main()
{
    cin >> n;
    for (a = 0; a <= (n/x); a++)
    {
        for (b = 0; b <= (n/y); b++)
        {
            rem = n - a*x - b*y;
            if (rem < 0) break;
            if (rem % z == 0)
            {
                cout << "YES" ;
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
