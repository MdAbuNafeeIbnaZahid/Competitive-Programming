#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, d;
string odd = "I hate", even = "I love";
int main()
{
    cin >> n;
    for (a = 1; a <= n-1; a++)
    {
        if ( a%2==0 )
        {
            cout << even;
        }
        else
        {
            cout << odd ;
        }
        cout << " that ";
    }
    if (n%2) cout << odd;
    else cout << even;
    cout << " it";
    return 0;
}
