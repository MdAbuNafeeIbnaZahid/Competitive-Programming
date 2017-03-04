#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
char str[SIZE];
long long a,b, c, d, e, f, g, len, cntAr[SIZE], myCount, si = -1;
vector<char> vChar;
vector<long long> vLL;
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%s", str);
    len = strlen(str);
    //cout << "len = " << len << endl;
    for (a = 0; a+25 < len; a++)
    {
        for (b = 'A'; b <='Z'; b++)
        {
            cntAr[b] = 0;
        }
        myCount = 0;
        for (b = a; b <= a+25 && b < len; b++)
        {
            cntAr[ str[b] ]++;
        }
        for (b = 'A'; b <= 'Z'; b++)
        {
            if ( cntAr[b] > 1 ) break;
        }
        if ( b > 'Z' )
        {
            si = a;
            break;
        }
    }
    if ( si == -1 )
    {
        cout << -1;
        return 0;
    }
    else
    {
        for (a = 'A'; a <= 'Z'; a++)
        {
            cntAr[a] = 0;
        }
        for (a = si;a < si+26; a++)
        {
            cntAr[ str[a] ]++;
            if ( str[a] == '?' ) vLL.push_back(a);
        }
        for (a = 'A'; a <= 'Z'; a++)
        {
            if ( cntAr[a] == 0 ) vChar.push_back( (char)a );
        }
        for (a = 0; a < vLL.size(); a++)
        {
            str[ vLL[a] ] = vChar[a];
        }
        for (a = 0;a < si; a++)
        {
            if ( str[a] == '?' ) str[a] = 'A';
        }
        for (a = si+26; a < len; a++)
        {
            if ( str[a] == '?' ) str[a] = 'A';
        }
    }
    cout << str;
    return 0;
}
