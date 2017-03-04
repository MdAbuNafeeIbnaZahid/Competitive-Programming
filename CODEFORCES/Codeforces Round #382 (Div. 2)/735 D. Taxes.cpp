#include <bits/stdc++.h>
using namespace std;
long long n, ans;
bool isPrime(long long num)
{
    long long a, b, c, d, e, upto = sqrt(num+1);
    for (a = 2; a <= upto; a++)
    {
        if ( num%a == 0 )
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    cin >> n;
    if ( isPrime(n) )
    {
        cout << 1;
        return 0;
    }
    if ( n%2 == 0 || isPrime(n-2) )
    {
        cout << 2;
        return 0;
    }
    cout << 3;
    return 0;
}
