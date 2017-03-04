#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long grundyVal[SIZE], xorVal, num;
long long a, b, c, d, e;
long long T, n;
long long grundyF(long long n)
{
    set<long long> lowerVal;
    long long a, b, c, d, e, current, rem;
    if ( n%2 == 0 ) return n/2;
    if ( n%4==1 ) return  n/4;
    if ( ( (n+1) & n ) == 0 ) return  0;
    current = 16;
    while(1)
    {
         rem = (current/4)-1;
         if (n%current == rem) return 2*(n/current);
         rem = 2*(current/4)-1;
         if (n%current == rem) return n/current;
         rem = 3*(current/4)-1;
         if (n%current == rem) return 1+( n -rem )/(current/2);
         current *= 4;
    }

    return -1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &num);
            xorVal ^= grundyF(num);
        }
        if (xorVal) cout << "Case " << a << ": Alice" << endl;
        else cout << "Case " << a << ": Bob" << endl;
    }
    return 0;
}

int cmain()
{
    memset(grundyVal, -1, sizeof(grundyVal) );
    grundyVal[1] = 0;
    grundyVal[2] = 1;
    for (a = 1; a < SIZE; a++)
    {
        grundyF(a);
        if (  a%64==63) cout << " a = " << a << " -> " << grundyVal[a] << endl << endl;
    }

    return 0;
}
