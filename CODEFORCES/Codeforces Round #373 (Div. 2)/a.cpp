#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long a, b, c, d, e, f, g, aAr[SIZE];
long long n;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    if ( n == 1 )
    {
        if ( aAr[1] == 0 )
        {
            cout << "UP";
            return 0;
        }
        else if ( aAr[1] == 15 )
        {
            cout << "DOWN";
            return 0;
        }
        else
        {
            cout << -1;
            return 0;
        }
    }
    else
    {
        if ( aAr[n] == 0 )
        {
            cout << "UP";
            return 0;
        }
        else if ( aAr[n] == 15 )
        {
            cout << "DOWN";
            return 0;
        }
        else
        {
            if ( aAr[n] - aAr[n-1] == 1 )
            {
                cout << "UP";
                return 0;
            }
            else
            {
                cout << "DOWN";
                return 0;
            }
        }
    }
    return 0;
}
