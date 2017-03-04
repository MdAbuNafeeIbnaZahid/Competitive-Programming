#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
string bus[SIZE];
long long n;
long long a, b, c, d, e, f;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> bus[a];
    }
    for (a = 1; a <= n; a++)
    {
        if ( bus[a][0]== 'O' && bus[a][1]=='O' )
        {
            bus[a][0] = '+';
            bus[a][1] = '+';
            break;
        }
        if ( bus[a][3]== 'O' && bus[a][4]=='O' )
        {
            bus[a][3] = '+';
            bus[a][4] = '+';
            break;
        }
    }
    if (a > n)
    {
        cout << "NO";
    }
    else
    {
        cout << "YES" << endl;
        for (a = 1; a <= n; a++)
        {
            cout << bus[a] << endl;
        }
    }
    return 0;
}
