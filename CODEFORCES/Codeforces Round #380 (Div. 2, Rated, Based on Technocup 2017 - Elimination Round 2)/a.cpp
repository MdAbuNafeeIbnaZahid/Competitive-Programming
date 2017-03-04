#include <bits/stdc++.h>
using namespace std;
#define SIZE 999
long long n;
string str, ansStr;
long long a, b, c, d, e, f, g;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    //gets(str);
    //strcpy(ansStr);
    cin >> str;
    for (a = 0;a  < n; a++)
    {
        if ( str[a] == 'o' )
        {
            b = a;
            while ( b+1 < n && b+2 < n && str[b+1]=='g' && str[b+2]=='o' )
            {
                b += 2;
            }
            if ( b != a )
            {
                ansStr += "***";
                a = b;
                continue;
            }
            else
            {
                ansStr += "o";
            }
        }
        else
        {
            ansStr += str[a];
        }
    }
    cout << ansStr;
    return 0;
}
