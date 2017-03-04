#include <bits/stdc++.h>
using namespace std;
long long n, x, dist = 0, di;
long long rem, a, b, c, d, e, f, g, h;
char ch;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> x;
    rem = x;
    for (a = 1; a <= n; a++)
    {
        cin >> ch >> di;
        if (ch == '+')
        {
            rem += di;
        }
        else if (ch == '-')
        {
            if ( rem >= di )
            {
                rem -= di;
            }
            else dist++;
        }
    }
    cout << rem << " " << dist << endl;
    return 0;
}
