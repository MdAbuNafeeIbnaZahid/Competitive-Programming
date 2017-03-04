#include <bits/stdc++.h>
using namespace std;;
#define SIZE
long long from, h, m;
string str;
char ch;
long long ar[9];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> from;
    cin >> h >> ch >> m;
    //cout << "h = " << h << ", m = " << m;
    if ( from == 12 )
    {
        if ( h <= 12 && h >= 1 )
        {
            cout << h/10 << h%10;
        }
        else
        {
            if ( h%10 == 0 )
            {
                cout << 1 << 0;
            }
            else
            {
                cout << 0 << h%10;
            }
        }
    }
    else
    {
        if (h > 23)
        {
            cout << 0 << h%10;
        }
        else
        {
            cout << h/10 << h%10;
        }
    }
    cout << ":";
    if (m > 59)
    {
        cout << 0 << m%10;
    }
    else
    {
        cout << m/10 << m%10;
    }
    return 0;
}
