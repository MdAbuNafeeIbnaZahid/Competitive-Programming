#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
char s[SIZE], grid[SIZE][SIZE];
long long leftIdx, rightIdx, idx[SIZE], midIdx, more, row, lastPut;
long long a, b, c, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    memset(idx, -1, sizeof(idx) );
    cin >> s;
    for (a = 0; a < 27; a++)
    {
        if ( idx[ s[a] ] == -1 )
        {
            idx[ s[a] ] = a;
        }
        else
        {
            leftIdx = idx[ s[a] ];
            rightIdx = a;
        }
    }
    if ( rightIdx-leftIdx <= 1 )
    {
        cout << "Impossible";
        return 0;
    }
    else if ( rightIdx-leftIdx == 26 )
    {
        for (a = 0; a <= 12; a++)
        {
            cout << s[a];
        }
        cout << endl;
        for (a = 25; a >= 13; a--)
        {
            cout << s[a];
        }
        return 0;
    }
    else
    {
        rightIdx--;
        more = 26-(rightIdx-leftIdx+1);
        midIdx = (leftIdx+rightIdx)/2;
        for (a = leftIdx; a <= midIdx; a++)
        {
            grid[0][midIdx-a] = s[a];
        }
        for (a = midIdx+1; a <= rightIdx; a++)
        {
            grid[1][a-midIdx-1] = s[a];
            lastPut = a-midIdx-1;
        }
        for (a = 1; a <= more; a++)
        {
            if ( lastPut+a > 12 )
            {
                break;
            }
            grid[1][ (lastPut+a) ] = s[(rightIdx+a+1)%27];
        }
        for ( b = a ; b <= more; b++)
        {
            grid[0][ 12 - (b-a) ] = s[(rightIdx+b+1)%27];
        }
    }
    for (a = 0; a <= 12; a++)
    {
        cout << grid[0][a];
    }
    cout << endl;
    for (a = 0; a <= 12; a++)
    {
        cout << grid[1][a];
    }
    return 0;
}
