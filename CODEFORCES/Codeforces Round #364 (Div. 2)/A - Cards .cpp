#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
long long n, ar[SIZE], isGiven[SIZE];
long long a, b, c, d, e, f, g, sum = 0, rem, perHead;;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> ar[a];
        sum += ar[a];
    }
    perHead = sum / (n/2);
    for (a = 1; a <= n/2; a++)
    {
        for (b = 1; b <= n; b++)
        {
            if ( !isGiven[b] )
            {
                cout << b << " ";
                isGiven[b] = 1;
                rem = perHead - ar[b];
                break;
            }
        }
        for (b = b+1; b <= n; b++)
        {
            if ( !isGiven[b] && ar[b] == rem )
            {
                cout << b << endl;
                isGiven[b] = 1;
                break;
            }
        }
    }
    return 0;
}
