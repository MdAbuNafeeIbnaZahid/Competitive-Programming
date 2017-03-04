#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, m;
long long a, b, c, d, e, f, aAr[SIZE], toDel[SIZE];
string strAr[SIZE], ansStr;
long long ifMatch( string str1, string str2 )
{
    long long a, b, c, d, e, f;
    if ( str1.size() != str2.size() )
    {
        return 0;
    }
    for (a = 0; a < str1.size(); a++)
    {
        if ( str1[a]=='?' || str2[a]=='?' || str1[a]==str2[a] )
        {

        }
        else
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        cin >> strAr[a];
    }
    for (a = 1; a <= m; a++)
    {
        cin >> aAr[a];
        toDel[ aAr[a] ] = 1;
    }
    for (a = 1; a < m; a++)
    {
        if ( strAr[ aAr[a] ].size() != strAr[ aAr[a+1] ].size() )
        {
            cout << "No";
            return 0;
        }
    }
    ansStr = strAr[ aAr[1] ];
    for (a = 1; a <= m; a++)
    {
        for (b = 0; b < ansStr.size(); b++)
        {
            if ( ansStr[b] != strAr[ aAr[a] ][b] )
            {
                ansStr[b] = '?';
            }
        }
    }
    for (a = 1; a <= n; a++)
    {
        if ( toDel[a] )
        {
            continue;
        }
        else
        {
            if ( ifMatch(ansStr, strAr[a]) )
            {
                cout << "No";
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    cout << ansStr;
    return 0;
}
