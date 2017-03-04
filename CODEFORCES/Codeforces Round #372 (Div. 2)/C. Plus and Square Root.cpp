#include <bits/stdc++.h>
using namespace std;
long long n, level, cur;
long long a, b, c, d, e, f, g, h;
int main()
{
    cin >> n;
    cur = 2;
    level = 1;
    for (level = 1; level <= n; level++)
    {
        //cout << "level = " << level << " --> ";
        for (a = 1; ; a++)
        {
            if ( ( (a*(level+1))*(a*(level+1))-cur )%level == 0 )
            {
                cout << ( (a*(level+1))*(a*(level+1))-cur )/level;
                cur = a*(level+1);
                break;
            }
        }
        cout << endl;
    }
    return 0;
}
