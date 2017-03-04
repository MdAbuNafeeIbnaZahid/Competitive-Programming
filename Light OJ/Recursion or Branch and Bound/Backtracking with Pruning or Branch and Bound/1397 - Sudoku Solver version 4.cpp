#include <bits/stdc++.h>
using namespace std;
string grid[19];
int T;
int a, b, c, d, e, f, i, d1, d2;
void printGrid()
{
    int i, j, k;
    for (i = 0; i < 9; i++)
    {
        cout << grid[i] << endl;
    }
}
bool ifSafeToPut(int row, int col, char ch)
{
    int i, j, k;
    for (i = 0; i < 9; i++)
    {
        if ( grid[i][col]==ch ) return false;
    }
    for (i = 0; i < 9; i++)
    {
        if ( grid[row][i]==ch ) return false;
    }
    for (i = row-(row%3); i < row-(row%3)+3; i++)
    {
        for (j = col-(col%3); j < col-(col%3)+3; j++)
        {
            if ( grid[i][j] == ch ) return false;
        }
    }
    return true;
}
bool ifGridOk(int &row, int &col)
{
    int best = 100, cur, i, j, k, r1, c1;
    char ch;
    for (r1 = 0; r1 < 9; r1++)
    {
        for (c1 = 0; c1 < 9; c1++)
        {
            cur = 0;
            if ( grid[r1][c1] == '.' )
            {
                for (ch = '1'; ch <= '9'; ch++)
                {
                    if ( ifSafeToPut(r1, c1, ch) ) cur++;
                }
                if ( cur < best )
                {
                    best = cur;
                    row = r1;
                    col = c1;
                }
            }
        }
    }
    if ( best < 10 ) return false;
    return true;
}
bool solveGrid()
{
    int row, col;
    int i, j, k;
    char ch;
    if ( ifGridOk(row, col) )
    {
        return true;
    }
    cout << "";

    for (ch = '1'; ch <= '9'; ch++)
    {
        if ( ifSafeToPut(row, col, ch) )
        {
            grid[row][col] = ch;
            if ( solveGrid() )
            {
                return true;
            }
            grid[row][col] = '.';
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        for (a = 0; a < 9; a++)
        {
            cin >> grid[a];
        }
        cout << "Case " << i << ":" << endl;
        solveGrid();
        printGrid();
    }
    return 0;
}

