#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long T;
char str1[SIZE], str2[SIZE];
long long a, b, c, d, e, f, g, h, i, j;
long long len1, len2, lpsAr[SIZE], ans;
void cmpLps(char *str)
{
    long long a, b, c, d, e, f, g, len = strlen(str), i, j;
    lpsAr[0] = 0;
    i = 1;
    j = 0;
    for (i = 1; i < len; i++)
    {
        while( str[i] != str[j]  )
        {
            j = lpsAr[j-1];
            if (j == 0) break;
        }
        if ( str[i] == str[j] )
        {
            lpsAr[i] = ++j;
        }
        else lpsAr[i] = j;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        //cout << "a = " << a << endl;
        ans = 0;
        scanf("%s", str1);
        scanf("%s", str2);
        //cout << "str1 = " << str1 << endl;
        //cout << "str2 = " << str2 << endl;
        len1 = strlen(str1);
        len2 = strlen(str2);
        if ( len2 > len1 )
        {
            cout << "Case " << a << ": 0" << endl;
            continue;
        }
        memset(lpsAr, 0, sizeof(lpsAr) );
        cmpLps(str2);
        for (b = 0; b < len2; b++)
        {
            //cout << "b = " << b << ", lps = " << lpsAr[b] << endl;
        }
        j = 0;
        for (b = 0; b < len1; b++)
        {
            while(str1[b] != str2[j])
            {
                j = lpsAr[j-1];
                if ( j == 0 ) break;
            }
            if ( str1[b] == str2[j] )
            {
                j++;
            }
            if ( j == len2 )
            {
                //cout << "b = " << b<< endl;
                ans++;
                j  = lpsAr[j-1];
            }
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
