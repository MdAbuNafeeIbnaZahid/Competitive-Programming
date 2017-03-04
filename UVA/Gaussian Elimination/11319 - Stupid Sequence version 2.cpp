#include <bits/stdc++.h>
using namespace std;
#define SIZE 1509
double N, inputAr[SIZE];
double matrix[SIZE][SIZE];
double a,b,c,d,e,f,g;
double a0, a1, a2, a3, a4, a5, a6, a7, a8;
double maxPivot, el, temp, divisor, multiplier;
double check;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= 7; a++)
    {
        for (b = 0; b <= 6; b++)
        {
            matrix[(int)a][(int)b] = round( pow(a, b) );
            //cout << "matrix[(int)a][(int)b] = " << matrix[(int)a][(int)b] << endl;
        }
    }
    for (a = 1; a <= N; a++)
    {
        for (b = 1; b <= 7; b++)
        {
            scanf("%lf", &inputAr[(int)b]);
        }
        for (b = 1; b <= 7; b++)
        {
            matrix[(int)b][7] = inputAr[(int)b];
        }
        el = 0;
        for (b = 0; b <= 6; b++)
        {
            //cout << "b = " << b << endl;
            //cout << "at first situation of matrix " << endl;
            for (f=1; f <= 7; f++)
            {
                for (g = 0; g < 8; g++)
                {
                    //cout << matrix[(int)f][(int)g] << " ";
                }
                //cout << endl;
            }
            maxPivot = el+1;
            for (c = el+2; c <= 7; c++)
            {
                //cout << "matrix[(int)c][(int)b] = " << matrix[(int)c][(int)b] << endl;
                if ( matrix[(int)c][(int)b] > matrix[(int)maxPivot][(int)b] )
                {
                    maxPivot = c;
                }
            }
            if ( matrix[(int)maxPivot][(int)b] == 0 ) continue;
            el++;
            for ( c = 0; c <= 7; c++ )
            {
                temp = matrix[(int)maxPivot][(int)c];
                matrix[(int)maxPivot][(int)c] = matrix[(int)el][(int)c];
                matrix[(int)el][(int)c] = temp;
            }
            //cout << "row interchange complete " << endl;
            for (f=1; f <= 7; f++)
            {
                for (g = 0; g < 8; g++)
                {
                    //cout << matrix[(int)f][(int)g] << " ";
                }
                //cout << endl;
            }
            divisor = matrix[(int)el][(int)b];
            for (c = 0; c <= 7; c++)
            {
                matrix[(int)el][(int)c] /= divisor;
            }
            //cout << "made a leading one" << endl;
//            for (f=1; f <= 7; f++)
//            {
//                for (g = 0; g < 8; g++)
//                {
//                    cout << matrix[(int)f][(int)g] << " ";
//                }
//                cout << endl;
//            }
            for (c = 1; c <= 7; c++)
            {
                if (c == el) continue;
                multiplier = matrix[(int)c][(int)b];
                for (d = 0; d <= 7; d++)
                {
                    matrix[(int)c][(int)d] -= matrix[(int)el][(int)d]*multiplier;
                }
            }
//            cout << "Now I have deleted from all row " << endl;
//            for (f=1; f <= 7; f++)
//            {
//                for (g = 0; g < 8; g++)
//                {
//                    cout << matrix[(int)f][(int)g] << " ";
//                }
//                cout << endl;
//            }
        }
//        cout << "el = " << el << endl;
        if ( el < 7 )
        {
            printf("This is a smart sequence\n");
            continue;
        }
        for (b = 8; b <= 1500; b++)
        {
            check = 0;
            for (c = 0; c <= 6; c++)
            {
                check += matrix[(int)c+1][7] * pow(b, c);
            }
            if ( abs(check - inputAr[(int)b] ) > 0.001 )
            {
                break;
            }
        }
        if ( b<=1500 )
        {
            printf("This is a smart sequence\n");
            continue;
        }
        for (b = 1; b <= 7; b++)
        {
            cout << matrix[(int)b][7] << " ";
        }
    }

    return 0;

}
