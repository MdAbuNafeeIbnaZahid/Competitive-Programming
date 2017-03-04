#include <bits/stdc++.h>
using namespace std;
#define SIZE 39
long long T, dpsl[SIZE][SIZE], dpus[SIZE][SIZE];
string str1, str2;
int main()
{
//    freopen("input.txt", "r", stdin);
    long long a, b, c, d, e, f;
    cin >> T;
//    cout << "T = " << T << endl;
    getchar();
    for ( a = 1; a <= T; a++ )
    {
        getline(cin, str1);
        getline(cin, str2);
        str1 =  "0" + str1;
        str2 =  "0" + str2;
//        cout << "str1 = " << str1 << endl;
//        cout << "str2 = " << str2 << endl;
        for (b = 0; b < SIZE; b++)
        {
            for (c = 0; c < SIZE ; c++)
            {
                dpsl[b][c] = INT_MAX;
                if ( b == 0 || c == 0 )
                {
                    dpsl[b][c] = b+c;
                    dpus[b][c] = 1;
                }
            }
        }
        for (b = 1; b < str1.size(); b++)
        {
            for ( c = 1; c < str2.size(); c++ )
            {
                if ( str1[b] == str2[c] )
                {
                    dpsl[b][c] = min(dpsl[b][c], 1+dpsl[b-1][c-1]);
                    dpus[b][c] = dpus[b-1][c-1];
                }
                else
                {
                    dpsl[b][c] = min(dpsl[b][c], 1+dpsl[b-1][c]);
                    dpsl[b][c] = min(dpsl[b][c], 1+dpsl[b][c-1]);
                    if ( dpsl[b-1][c] == dpsl[b][c-1] )
                    {
                        dpus[b][c] = dpus[b-1][c] + dpus[b][c-1];
                    }
                    else if ( dpsl[b][c] == 1+dpsl[b-1][c] )
                    {
                        dpus[b][c] = dpus[b-1][c] ;
                    }
                    else if ( dpsl[b][c] == 1+dpsl[b][c-1] )
                    {
                        dpus[b][c] = dpus[b][c-1];
                    }
                }
            }
        }
        long long n, m;
        n = str1.size()-1;
        m = str2.size() - 1;
        cout << "Case " << a << ": " << dpsl[n][m] << " " << dpus[n][m] << endl;
    }
    return 0;
}
