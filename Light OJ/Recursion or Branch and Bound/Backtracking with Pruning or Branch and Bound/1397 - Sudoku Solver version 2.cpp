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
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if ( grid[row][col] == '.' ) return false;
        }
    }
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
