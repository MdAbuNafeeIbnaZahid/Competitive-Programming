#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, n, x, y, grundyVal[SIZE][SIZE], xorVal, row, col;
long long a, b, c, d, e, f;
long long movR[] = {-2, -2, -3, -1, -1, 1};
long long movC[] = {1, -1, -1, -2, -3, -2};
long long grundyF(long long x, long long y)
{
    long long a, b, c, d, e, row, col;
    set<long long> lowerVal;
    if ( grundyVal[x][y] == -1 )
    {
        for ( a = 0; a < 6; a++ )
        {
            row = x+movR[a];
            col = y+movC[a];
            if (row >= 0 && col >= 0)
            {
                lowerVal.insert( grundyF(row, col) );
            }
        }
        for (a = 0; ; a++)
        {
            if ( lowerVal.find( a ) == lowerVal.end() ) break;
        }
        grundyVal[x][y] = a;
    }
    return grundyVal[x][y];
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(grundyVal, -1, sizeof(grundyVal) );
    for (a = 0; a <= 1000; a++)
    {
        row = a;
        col = 0;
        while(row >= 0)
        {
            grundyF(row, col);
            row--;
            col++;
        }
    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld", &x, &y);
            xorVal ^= grundyF(x, y);
        }
        if (xorVal)  cout << "Case " << a << ": Alice" << endl;
        else cout << "Case " << a << ": Bob" << endl;
    }
    return 0;
}
