#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long a, b, c, d, e, f, g;
long long t, s, x;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t >> s >> x;
    x = x-t;
    if ( x < 0 )
    {
        cout << "NO";
    }
    else if ( x%s==0 ) cout << "YES";
    else if ( x%s==1 && x>s ) cout << "YES";
    else cout << "NO";
    return 0;
}
