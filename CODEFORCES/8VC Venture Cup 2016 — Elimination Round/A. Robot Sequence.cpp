#include <bits/stdc++.h>
using namespace std;
int n, vertAr[300], horAr[300], ans = 0, i, j, k, m;
string str;
int main()
{
    cin >> n;
    cin >> str;
    horAr[0] = vertAr[0] = 0;
    for (i = 0; i < str.size(); i++)
    {
        if ( str[i] == 'R' )
        {
            horAr[i+1] = horAr[i] + 1;
            vertAr[i+1] = vertAr[i];
        }
        else if ( str[i] == 'L' )
        {
            horAr[i+1] = horAr[i] - 1;
            vertAr[i+1] = vertAr[i];
        }

        if ( str[i] == 'U' )
        {
            vertAr[i+1] = vertAr[i] + 1;
            horAr[i+1] = horAr[i];
        }
        else if ( str[i] == 'D' )
        {
            vertAr[i+1] = vertAr[i] - 1;
            horAr[i+1] = horAr[i];
        }
    }

    //for (i = 0; i <= n; i++) cout << horAr[i] << " ";
    //cout << endl;
    //for (i = 0; i <= n; i++) cout << vertAr[i] << " ";
    //cout << endl;


    for (i = 0; i < n; i++)
    {
        for (j = i+1; j <= n; j++)
        {
            if ( horAr[i]==horAr[j] && vertAr[i]==vertAr[j] ) ans++;
        }
    }
    cout << ans;
    return 0;
}
