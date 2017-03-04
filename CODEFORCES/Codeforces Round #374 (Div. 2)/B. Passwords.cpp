#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, k;
string strAr[SIZE], pass;
long long a, b, c, d, e, f, worst, best, passLen, small, same;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        cin >> strAr[a];
    }
    cin >> pass;
    passLen = pass.size();
    for (a = 1; a <= n; a++)
    {
        if ( strAr[a].size() < passLen )
        {
            small++;
        }
        else if ( strAr[a].size() == passLen )
        {
            same++;
        }
    }
    best = small + (small/k ) * 5 + 1;
    worst = (small+same-1) + ( (small+same-1)/k ) * 5 + 1;
    cout << best << " " << worst ;
    return 0;
}
