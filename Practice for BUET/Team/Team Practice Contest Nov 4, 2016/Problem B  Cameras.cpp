#include <bits/stdc++.h>
using namespace std;
long long n, a, b, c, d;
char inputStr[100];
long long ifOk( char* str )
{
    long long indices[] = {0, 1, 2, 3, 5, 6, 7};
    long long a, b, c;
    if ( strlen(str) != 8 )
    {
        return 0;
    }
    if ( str[0] != str[1] )
    {
        return 0;
    }
    //cout << "before loop" << endl;
    for (a = 0; a < 7; a++)
    {
        if ( str[ indices[a] ] < '1' || str[ indices[a] ] > '9' )
        {
            return 0;
        }
    }
    if ( str[4] < 'A' || str[4] > 'Z' )
    {
        return 0;
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    //cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        //cout << "a = " << a << endl;
        //cin >> inputStr;
        scanf("%s", inputStr);
        if ( ifOk(inputStr) )
        {
            cout << inputStr << endl;
        }
    }
    return 0;
}
