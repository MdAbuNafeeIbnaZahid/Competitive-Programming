#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long grundyVal[SIZE];
long long a, b, c, d, e;
long long grundyF(long long n)
{
    set<long long> lowerVal;
    long long a, b, c, d, e, current;
    if ( grundyVal[n] != -1 )
    {
        return grundyVal[n];
    }
    if ( n%2 == 0 ) grundyVal[n] = n/2;
    if ( n%4==1 ) grundyVal[n] = n/4;
    if ( ( (n+1) & n ) == 0 ) grundyVal[n] = 0;
    if (n%16 == 3) grundyVal[n] = (n-3)/8;
    if ( n%16 == 7 ) grundyVal[n] = (n-7)/16;
    if (n%16 == 11) grundyVal[n] = 1+(n-11)/8;
    if ( n%64 == 15 ) grundyVal[n] = (n-15)/32;
    if (n%64 == 31) grundyVal[n] = (n-31)/64;
    if ( n%64 == 47 ) grundyVal[n] =  1+(n-47)/32;
    else
    {
        current = 256;
        while(1)
        {
            if ( n%current == 3*(current/4)-1 )
        }
    }
    if ( grundyVal[n] == -1 )
    {
        grundyVal[n] = 0;
        for (a = 1; a <= n/2; a++)
        {
            lowerVal.insert( grundyF(n-a) );
        }
        for (a = 0; ; a++)
        {
            if ( lowerVal.find(a) == lowerVal.end() )
            {
                grundyVal[n] = a;
                break;
            }
        }
    }
    return grundyVal[n];
}
int main()
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
