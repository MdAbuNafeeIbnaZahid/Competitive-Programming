#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long n, grid[SIZE][SIZE], ans;
long long a, b, c, d, e, f, g, row, col, sum, toPut, checkSum;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //cout  << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &grid[a][b]);
            if ( grid[a][b] == 0 )
            {
                row = a;
                col = b;
            }
        }
    }
//    cout << "row = " << row << endl;
//    cout << "col = " << col << endl;
    if (n == 1)
    {
        cout << 1;
        return 0;
    }
    if (row==1)
    {
        for (a = 1; a <= n; a++) sum += grid[2][a];
    }
    else
    {
        for (a = 1; a <= n; a++) sum += grid[1][a];
    }
    //cout << "sum = " << sum << endl;
    toPut = sum;
    for (a = 1; a <= n; a++)
    {
        toPut -= grid[row][a];
    }
//    cout << "toPut = " << toPut << endl;
    if (toPut <= 0)
    {
        cout << -1;
        return 0;
    }
    grid[row][col] = toPut;
    for (a = 1; a <= n; a++)
    {
        checkSum = 0;
        for (b = 1; b <= n; b++)
        {
            checkSum += grid[a][b];
        }
        if (checkSum != sum)
        {
            cout << -1;
            return 0;
        }
    }
    for (a = 1; a <= n; a++)
    {
        checkSum = 0;
        for (b = 1; b <= n; b++)
        {
            checkSum += grid[b][a];
        }
        if (checkSum != sum)
        {
            cout << -1;
            return 0;
        }
    }
    checkSum = 0;
    for (b = 1; b <= n; b++)
    {
        checkSum += grid[b][b];
    }
    if (checkSum != sum)
    {
        cout << -1;
        return 0;
    }
    checkSum = 0;
    for (b = 1; b <= n; b++)
    {
        checkSum += grid[b][n-b+1];
    }
    if (checkSum != sum)
    {
        cout << -1;
        return 0;
    }
    cout << toPut;
    return 0;
}
