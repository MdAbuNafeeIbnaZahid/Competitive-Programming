#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, k, ci[SIZE], id[SIZE], cumCi[SIZE], ifCapital[SIZE], ans;
long long a, b, c, d, e;
int main()
{
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        cin >> ci[a];
        cumCi[a] = ci[a];
    }
    for (a = 1; a <= k; a++)
    {
        cin >> id[a];
        ifCapital[ id[a] ] = 1;
    }
    for (a = 1; a <= n; a++)
    {
        cumCi[a] += cumCi[a-1];
    }
    for (a = 1; a <= n; a++)
    {

    }
    return 0;
}
