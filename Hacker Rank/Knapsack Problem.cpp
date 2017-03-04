#include <bits/stdc++.h>
using namespace std;
#define SIZE 2009
long long S, N, ar[SIZE][SIZE];
long long i, j, k, siz[SIZE], val[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    memset(ar, 0, sizeof(ar));
    cin >> S >> N;
    for (i = 1; i <= N; i++)
    {
        scanf("%lld %lld", &siz[i], &val[i]);
    }
    for (i = 1; i <= N; i++)
    {
        for (j = 0; j <= S; j++)
        {
            if ( j-siz[i] >= 0 )
                ar[i][ j ] = max( ar[i-1][ j ], ar[i-1][j-siz[i] ] + val[i] );
            else ar[i][j] = ar[i-1][j];
        }
    }
//    for (i = 0; i <= N; i++)
//    {
//        for (j = 0; j <= S; j++)
//        {
//            cout << ar[i][j] << " ";
//        }
//        cout << endl;
//    }
    cout << ar[N][S];
    return 0;
}
