#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
char str[SIZE][SIZE], ch;
long long n, pAr[SIZE], cnt, len;
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        cin >> pAr[a];
    }
    getchar();
    for (a = 1; a <= n; a++)
    {
        gets( str[a] );
    }
    for (a = 1; a <= n; a++)
    {
        //cout << "a = " << a << endl;
        //cout << str[a] << endl;
        cnt = 0;
        len = strlen( str[a] );
        for (b = 0; b < len; b++)
        {
            ch = str[a][b];
            if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'y' )
            {
                //cout << "b = " << b << endl;
                cnt++;
            }
        }
        //cout << "cnt = " << cnt << endl;
        if (cnt != pAr[a])
        {
            break;
        }
    }
    if (a <= n) cout << "NO";
    else cout << "YES";
    return 0;
}
