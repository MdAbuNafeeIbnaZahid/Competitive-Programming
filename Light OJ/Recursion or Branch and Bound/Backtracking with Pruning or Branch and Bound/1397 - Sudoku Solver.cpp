#include <bits/stdc++.h>
using namespace std;
#define SIZE 19
int T, i, j, k, a, b, c;
string grid[SIZE];
bool ifGridOk(string *grid, int &row, int &col)
{
    cout << "ifGridOk called " << endl;
    int i, j, k;
    for (row = 0; row < 9; row++)
    {
        for (col = 0; col < 9; col++)
        {
            if (grid[row][col] < '1' || grid[row][col] > '9')
            {
                return false;
            }
        }
    }
    return true;
}
bool ifCanPlace(int row, int col, char num)
{
    int i, j, k;
    for (i = 0; i < 9; i++)
    {
        if ( grid[row][i]==num ) return false;
    }
    for (i = 0; i < 9; i++)
    {
        if ( grid[i][col] == num ) return false;
    }
    for (i = row-(row%3); i < row-(row%3)+3; i++)
    {
        for (j = col-(col%3); j < col-(col%3)+3; j++)
        {
            if (grid[i][j] == num) return false;
        }
    }
    return true;
}
bool solveGrid(string *grid)
{
    cout << "solveGrid called" << endl;
    int row, col, i, j, k;
    if ( ifGridOk(grid, row, col) )
    {
        return true;
    }
    cout << "row = " << row << ", col = " << col << endl;
    for (i = 1; i < 9; i++)
    {
        if(ifCanPlace(row, col, '0'+i) )
        {
            grid[row][col] = '0'+i;
            if ( solveGrid(grid) )
            {
                return true;
            }
            grid[row][col] = '.';
        }
    }
    return false;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    cin >> T;
//    for (i = 1; i <= T; i++)
//    {
//        for (a = 0; a < 9; a++)
//        {
//            cin >> grid[a];
//        }
//        cout << "input taken " << endl;
//        for (a = 0; a < 9; a++)
//        {
//            for (b = 0; b < 9; b++)
//            {
//                cout << grid[a][b];
//            }
//            cout << endl;
//        }
//        cout << endl << endl << endl;
//        if ( !solveGrid(grid) )
//        {
//            cout << "grid can't be solved";
//        }
//        cout << "Case " << i << ":" << endl;
//        for (a = 0; a < 9; a++)
//        {
//            cout << grid[a] << endl;
//        }
//    }
//    return 0;

    while(1)
    {
        int row, col;
        cin >> row >> col;
        for (i = row-(row%3); i < row-(row%3)+3; i++)
        {
            for (j = col-(col%3); j < col-(col%3)+3; j++)
            {
                cout << "(" << i << "," << j << ") " ;
            }
            cout << endl << endl << endl;
        }
    }

}
