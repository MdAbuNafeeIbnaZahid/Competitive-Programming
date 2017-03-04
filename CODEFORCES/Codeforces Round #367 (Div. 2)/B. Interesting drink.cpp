#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, xi, q, mi, ways[SIZE];
long long a, b, c, d, e;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &xi);
        ways[xi]++;
    }
    for (a = 1; a < SIZE; a++)
    {
        ways[a] += ways[a-1];
    }
    cin >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &mi);        printf("%lld\n", ways[ min( (int)mi, SIZE-1) ]);
    }
    return 0;
}
