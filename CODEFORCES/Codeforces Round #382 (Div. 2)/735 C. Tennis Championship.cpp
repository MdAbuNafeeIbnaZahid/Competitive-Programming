#include <bits/stdc++.h>
using namespace std;
#define SIZE 99999
long long n;
long long a, b, c, d, e, fibAr[SIZE];
int main()
{
    cin >> n;
    fibAr[0] = 1;
    fibAr[1]  = 1;
    for (a = 2; a < SIZE; a++)
    {
        fibAr[a] = fibAr[a-1] + fibAr[a-2];
        if ( fibAr[a] > n )
        {
            cout << a-2;
            return 0;
        }
    }
    return 0;
}
