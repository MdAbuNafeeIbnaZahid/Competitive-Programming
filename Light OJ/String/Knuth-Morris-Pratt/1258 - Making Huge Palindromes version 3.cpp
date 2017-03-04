#include <bits/stdc++.h>
using namespace std;
#define SIZE 2000009
long long T;
long long a, b, c, d, e, f, g, i, j;
long long ans, lpsAr[SIZE], len;
char str[SIZE], revStr[SIZE];
void calLps(char *str)
{
    long long a, b, c, d, e, f, len = strlen(str), i, j;
    lpsAr[0] = 0;
    j = 0;
    for (a = 1; a < len; a++)
    {
        while( j > 0 && str[a] != str[j] )
        {
            //cout  << "j = " << j << endl;
            j = lpsAr[j-1];
        }
        if ( str[a] == str[j] )
        {
            j++;
        }
        lpsAr[a] = j;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%s", str);
        len = strlen(str);
        for (b = 0; b < len;b++)
        {
            revStr[b] = str[len-1-b];
        }
        revStr[len] = 0;
        //cout << revStr << endl;
        calLps( revStr );
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << ", lps = " << lpsAr[b] << endl;
        }
        j = 0;
        for (b = 0; b < len; b++)
        {
            while( j > 0 && str[b] != revStr[j] )
            {
                j = lpsAr[j-1];
            }
            if ( str[b] == revStr[j] )
            {
                j++;
            }
        }
        //cout << "a = " << a << ", j = " << j << endl;
        ans = 2*len-j;
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
