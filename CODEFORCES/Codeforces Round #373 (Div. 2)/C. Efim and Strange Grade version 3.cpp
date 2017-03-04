#include <bits/stdc++.h>
using namespace std;
#define DOT -9999
#define SIZE 200009
long long n, t;
char str[SIZE];
long long a, b, c, d, e, f, g;
vector<long long> vLL;
long long decIdx, ge5Idx, len;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> t;
    scanf("%s", str);
    for (a = 0;a < n; a++)
    {
        if ( str[a] == '.' )
        {
            decIdx = a;
            vLL.push_back(DOT);
        }
        else
        {
            vLL.push_back( str[a] - '0' );
        }
    }
    for (a = decIdx+1; a < n; a++)
    {
        if ( vLL[a] >= 5 )
        {
            ge5Idx = a;
            break;
        }
    }
//    cout << "ge5Idx = " << ge5Idx << endl;
    if ( ge5Idx == 0 )
    {
        printf("%s", str);
        return 0;
    }
    for (a = ge5Idx+1; a < n; a++)
    {
//        cout << "initial pop" << endl;
        vLL.pop_back();
    }
    for (a = 1; a <= t; a++)
    {
        len = vLL.size();
        if ( vLL[len-1] >= 4 )
        {
            vLL.pop_back();
        }
        else
        {
            break;
        }
    }

    len = vLL.size();
    if ( vLL[len-1] == DOT )
    {
        vLL.pop_back();
        for (a = decIdx-1; a >= 0; a--)
        {
            vLL[a]++;
            if ( vLL[a] != 10 )
            {
                break;
            }
            else
            {
                vLL[a] = 0;
            }
        }
        if (a<0)
        {
            printf("1");
        }
        for (b = 0; b < vLL.size(); b++)
        {
            printf("%lld", vLL[b]);
        }
        return 0;
    }
    else
    {
        vLL[ len-1 ]++;
        for (b = 0; b < vLL.size(); b++)
        {
            if ( vLL[b] == DOT ) printf(".");
            else printf("%lld", vLL[b]);
        }
        return 0;
    }

    return 0;
}
