#include<bits/stdc++.h>
using namespace std;
#define SIZE 19
long long R, C;
long long a, b, d, e, f, g, h, i;
char input[SIZE][SIZE];
long long copyInp[SIZE][SIZE];
long long ans, flipCount, bit, cleared;
long long movR[] = {0, 0, 0, -1, 1};
long long movC[] = {0, -1, 1, 0, 0};

void slaveFlip(long long row, long long col)
{
    if ( row < 0 || row >= R || col < 0 || col >= C )
    {
        //cout << "Invalid masterFlip" << endl;
        return;
    }
    if ( copyInp[row][col] == '.' )
    {
        copyInp[row][col] = 'X';
    }
    else
    {
        copyInp[row][col] = '.';
    }
}

void masterFlip(long long row, long long col)
{
    long long a, b, c, d, e, f, g;
    if ( row < 0 || row >= R || col < 0 || col >= C )
    {
        cout << "Invalid masterFlip" << endl;
        return;
    }
    for (a =0; a < 5; a++)
    {
        slaveFlip(row+movR[a], col+movC[a]);
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> R >> C;
        if ( R+C == 0 ) return 0;
        ans = INT_MAX;
        for (a = 0; a < R; a++)
        {
            scanf("%s", input[a]);
        }
        for (a = 0; a < (1<<C); a++ )
        {
            flipCount = 0;
            for (b = 0; b < R; b++)
            {
                for (d = 0; d < C; d++)
                {
                    copyInp[b][d] = input[b][d];
                }
            }
            for (b = 0; b < C; b++)
            {
                bit = (a>>b) & 1;
                if ( bit )
                {
                    flipCount++;
                    masterFlip(0, b);
                }
            }
            for (b = 1; b < R; b++)
            {
                for (d = 0; d < C; d++)
                {
                    if ( copyInp[b-1][d] == 'X' )
                    {
                        flipCount++;
                        masterFlip(b, d);
                    }
                }
            }
            cleared = 1;
            for (b = 0; b < R; b++)
            {
                for (d = 0; d < C; d++)
                {
                    if ( copyInp[b][d] == 'X' ) cleared = 0;
                }
            }
            if ( cleared == 1 )
            {
                ans = min(ans, flipCount);
            }
        }
        if (ans < INT_MAX)
        {
            cout << "You have to tap " << ans << " tiles." << endl;
        }
        else
        {
            cout << "Damaged billboard." << endl;
        }
    }
    return 0;
}
