#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long K;
char str[SIZE];
long long a, b, c, d, e, f, g, h, len;
long long posAr[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    memset(posAr, -1, sizeof(posAr) );
    cin >> K;
    scanf("%s", str);
    len = strlen(str);
    for (a = 0; a < len; a++)
    {
        if ( str[a] == '1' )
        {
            posAr[a%K] = a;
            if ( posAr[(a-1+K)%K] != -1 )
            {
                cout << posAr[(a-1+K)%K]+1 << " " << a+1;
                return 0;
            }
        }
    }
    cout << 0 << " " << 0;
    return 0;
}
