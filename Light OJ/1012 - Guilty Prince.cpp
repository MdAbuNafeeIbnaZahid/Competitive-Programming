#include <bits/stdc++.h>
using namespace std;

int t, i, j, k, w, h, ans;
char ar[25][25];


void count(int row, int column)
{
    if (row < 0 || row >= h || column < 0 || column >= w) return;
    if (ar[row][column] == '#' || ar[row][column] == 'X') return;
    ans++;
    ar[row][column] = 'X';

    count(row-1, column);
    count(row+1, column);
    count(row, column-1);
    count(column, column+1);

}

int main()
{

    scanf("%d", &t);

    for (i = 1; i <= t; i++)
    {
        ans = 1;

        scanf("%d %d", &w, &h);
        for (j = 0; j < h; j++)
        {
            scanf("%s", ar[j]);
        }

        for (j =  0; j < h; j++)
        {
            for (k = 0; k < w; k++)
            {
                if (ar[j][k] == '@') break;
            }

            if (k < w) break;
        }


        count(j, k);

        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
