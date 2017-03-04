#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, k, l, a, b, c, d, e, f, A[SIZE], x, ans, finalF;

long long gcd(long long a, long long b)
{
    // a<b
    //cout << "a = " << a << ", " << "b = " << b << endl;
    if ( a == 0 ) return b;
    return gcd(b%a, a);
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &A[a]);
    }
    for (a = 1; a <= n; a++)
    {
        //cout << A[a] << " ";
    }
    //cout << endl;
    x = A[1];
    for (a = 2; a <= n; a++)
    {
        //cout << "a = " << a << endl;
        //cout << "x = " << x << endl;
        //cout << "x = " << x << endl;
        //cout << "A[a] = " << A[a] << endl;
        x = gcd( min(x, A[a]), max(x, A[a]) );
        //cout << "x = " << x << endl;
    }
    //cout << "x = " << x << endl;
    for (a = 2; a <= sqrt(x+1); a++)
    {
        if ( x%a == 0 )
        {
            l = (k/a)*a;
            cout << l;
            return 0;
        }
    }

    cout << (k/x)*x;
    return 0;
}
