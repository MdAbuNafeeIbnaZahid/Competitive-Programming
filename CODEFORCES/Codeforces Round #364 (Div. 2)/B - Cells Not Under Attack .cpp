#include <bits/stdc++.h>
using  namespace std;
#define SIZE 100009
long long n, m, rowUsed[SIZE], columnUsed[SIZE];
long long a, b, c, d, e, f, g, newRow, newCol, x, y, rem;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    rem = n*n;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &x, &y);

        if ( !rowUsed[x] )
        {
            rem -= (n - columnUsed[0]);
            rowUsed[x] = 1;
        rowUsed[0]++;
        }


        if ( !columnUsed[y] )
        {
            rem -= (n - rowUsed[0]);
            columnUsed[y] = 1;
        columnUsed[0]++;
        }

        printf("%lld ", rem);
    }
    return 0;
}

