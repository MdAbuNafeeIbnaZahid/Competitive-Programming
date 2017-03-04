#include <bits/stdc++.h>
using namespace std;
string str;
long long a, b, c, d, e, f, len, startIdx = -1, endIdx;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> str;
    len = str.size();

    for (a =0; a < len; a++)
    {
        if ( str[a] != 'a' )
        {
            startIdx = a;
            break;
        }
    }
    if ( startIdx == -1 )
    {
        str[len-1] = 'z';
        cout << str;
        return 0;
    }
    for (a = startIdx+1; a < len; a++)
    {
        if ( str[a] == 'a' )
        {
            break;
        }
    }
    endIdx = a-1;
    for (a = startIdx; a <= endIdx; a++)
    {
        str[a]--;
    }
    cout << str;
    return 0;
}
