#include <bits/stdc++.h>
using namespace std;
long long a, b,  d, e, f, g, mi, ci, m, c, n;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> mi >> ci;
        if (mi > ci)
        {
            m++;
        }
        else if (mi < ci)
        {
            c++;
        }

    }
    if (m>c)
        {
            cout << "Mishka";
        }
        else if (m == c)
        {
            cout << "Friendship is magic!^^";
        }
        else cout << "Chris";
    return 0;
}
