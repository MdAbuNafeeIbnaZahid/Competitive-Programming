#include <bits/stdc++.h>
using namespace std;
string sAr[2020];
int n, i, j, k, ans = 0, choc;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> sAr[i];
    }
    for (i = 0; i < n; i++)
    {
        //cout << sAr[i];
    }
    for (i = 0; i < n; i++)
    {
        choc = 0;
        for (j = 0; j < n; j++)
        {
            if ( sAr[i][j]=='C' ) choc++;
        }
        ans += (choc * (choc-1) ) /2;
    }
    for (i = 0; i < n; i++)
    {
        choc = 0;
        for (j = 0; j < n; j++)
        {
            if ( sAr[j][i]=='C' ) choc++;
        }
        ans += (choc * (choc-1) ) /2;
    }
    cout << ans;
    return 0;
}
