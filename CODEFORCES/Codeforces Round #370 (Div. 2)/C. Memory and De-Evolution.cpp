#include <bits/stdc++.h>
using namespace std;
long long x, y;
long long ar[9], cnt;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> x >> y;
    ar[0] = ar[1] = ar[2] = y;
    while( ar[0] < x )
    {
        sort(ar, ar+3);
        ar[0] = ar[1] + ar[2] - 1;
        cnt++;
        sort(ar, ar+3);
    }
    cout << cnt << endl;
    return 0;
}
