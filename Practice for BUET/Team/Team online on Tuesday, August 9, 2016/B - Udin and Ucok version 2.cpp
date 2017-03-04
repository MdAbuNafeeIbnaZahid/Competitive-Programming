#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long T, N, ans, grundVal[SIZE];
long long a, b, c, d, e, f;
long long recF(long long n)
{
    long long n1, n2, ret = 0;
    if (n <= 0) return 0;
    if (n <= 3) return 1;
    n1 = (n-3)/2;
    n2 = n - 3 - n1;
    return 1+recF(n1)+recF(n2);
}
long long grundFunc(long long n)
{
    set<long long> lowerGrundVal;
    long long a, b, c, d, e, f, g;
    if ( grundVal[n] != -1 ) return grundVal[n];
    lowerGrundVal.insert( grundFunc(n-2) );
    for (a = 0; a <= (n-3)/2; a++)
    {
        lowerGrundVal.insert( grundFunc(a) ^ grundFunc(n-3-a) );;
    }
    for (a = 0; a < INT_MAX; a++)
    {
        if ( lowerGrundVal.find(a) == lowerGrundVal.end() ) break;
    }
    grundVal[n] = a;
    return grundVal[n];
}
int main()
{
    memset(grundVal, -1, sizeof(grundVal));
    grundVal[0] = 0;
    grundVal[1] = 1;
    grundVal[2] = 1;
    for (a = 3; a < 1009; a++)
    {
        if ( grundFunc(a) == 0 ) cout << a << endl;
    }
}
