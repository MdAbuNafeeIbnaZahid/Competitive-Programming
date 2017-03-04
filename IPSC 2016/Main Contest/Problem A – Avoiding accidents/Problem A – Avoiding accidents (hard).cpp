#include <bits/stdc++.h>
using namespace std;
#define SIZE 19
long long t;
long long a, b, c, d, e, firstIdx, secondIdx;
string str[SIZE];
int main()
{
    freopen("a2.in", "r", stdin);
    freopen("a2Output.txt", "w", stdout);
    cin >> t;
    for (a = 1; a <= t; a++)
    {
        for (b = 1; b <= 10; b++)
        {
            cin >> str[b];
        }
        str[15] = "";
        for (b = 1; b <= 10; b++)
        {
            for (c = 1; c <= 10; c++)
            {
                if (b==c) continue;
                if ( str[b][3] == str[c][0] )
                {
                    firstIdx = b;
                    secondIdx = c;
                }
            }
        }
        for (b = 1; b <= 10; b++)
        {
            if ( b!=firstIdx && b!=secondIdx )
            {
                str[15] = str[15] + str[b];
            }
        }
        for (b = 0; b <= 3; b++)
        {
            str[15] = str[15] + str[firstIdx][b];
        }
        for (b = 1; b <= 3; b++)
        {
            str[15] = str[15] + str[secondIdx][b];
        }
        cout << str[15] << endl;
    }
    return 0;
}
