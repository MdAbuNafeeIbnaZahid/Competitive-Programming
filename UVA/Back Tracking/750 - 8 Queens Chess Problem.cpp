#include <bits/stdc++.h>
using namespace std;
int T, ri, ci;
int a, b, c, d, e, f, serial, i;
int ifRowFilled[100], ifColFilled[100], ifDiag1Filled[100], ifDiag2Filled[100];
bool ifOk(int row, int col)
{
    if ( ifRowFilled[row] || ifColFilled[col] || ifDiag1Filled[50+row+col]
        || ifDiag2Filled[50+row-col] ) return false;
    return true;
}
void printAllSolution(int col, int tot)
{
    int i, j, k, row;
    if (col == ci)
    {
        printAllSolution(col+1, tot);
    }
    if ( col > tot )
    {
        //cout << (++serial) << "      ";
        printf("%2d      ", (++serial));
        for (i = 1; i <= 8; i++) printf("%d ", ifColFilled[i]);
        printf("\n");
        return;
    }
    for (row = 1; row <= 8; row++)
    {
        if ( ifOk(row, col) )
        {
            ifRowFilled[row] = col;
            ifColFilled[col] = row;
            ifDiag1Filled[50+row+col] = 1;
            ifDiag2Filled[50+row-col] = 1;

            printAllSolution(col+1, tot);

            ifRowFilled[row] = 0;
            ifColFilled[col] = 0;
            ifDiag1Filled[50+row+col] = 0;
            ifDiag2Filled[50+row-col] = 0;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        serial = 0;
        memset(ifRowFilled, 0, sizeof(ifRowFilled));
        memset(ifColFilled, 0, sizeof(ifColFilled));
        memset(ifDiag1Filled, 0, sizeof(ifDiag1Filled));
        memset(ifDiag2Filled, 0, sizeof(ifDiag2Filled));
        cin >> ri >> ci;
        //cout << "SOLN       COLUMN" << endl;
        //cout << " #      1 2 3 4 5 6 7 8" << endl << endl;
        printf("SOLN       COLUMN\n");
        printf(" #      1 2 3 4 5 6 7 8\n\n");

        ifRowFilled[ri] = ci;
        ifColFilled[ci] = ri;
        ifDiag1Filled[50+ri+ci] = 1;
        ifDiag2Filled[50+ri-ci] = 1;

        printAllSolution(1, 8);

        if ( i < T ) cout << endl;
    }
    return 0;
}
