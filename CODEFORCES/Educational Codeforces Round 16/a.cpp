#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long a, b, d, e, f, g, h, i;
string str;
long long r, c;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> str;
    r = str[0] - 'a';
    c = str[1] - '1';
    r = r%7;
    c = c%7;
    if (r==0 && c==0)
    {
        cout << 3;
    }
    else if (r==0 || c==0)
    {
        cout << 5;
    }
    else cout << 8;
    return 0;
}
