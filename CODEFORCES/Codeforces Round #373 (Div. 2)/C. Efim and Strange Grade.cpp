#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, t;
char str[SIZE];
long long llStr[SIZE];
long long a, b, c, d, e, f, g, h, tCount, firstOc;
long long decIdx = -1;
vector<long long> vLL;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> t;
    scanf("%s", str);

    for (a = 0; a < n; a++)
    {
        if ( str[a] == '.' )
        {
            decIdx = a;
            break;
        }
    }
    for (a  = 0; a < n; a++)
    {
        if ( str[a] != '.' )
        {
            vLL.push_back( str[a]-'0' );
        }
    }
    if ( decIdx == -1 )
    {
        printf("%s");
        return 0;
    }
    for (a = decIdx; a < vLL.size(); a++)
    {
        if ( vLL[a] >= 5 )
        {
            firstOc = a;
            break;
        }
    }

    while(tCount < t)
    {
        if ( firstOc < decIdx )
        {
            break;
        }
        while(firstOc-1 >= 0)
        {
            vLL[ firstOc-1 ]++;
            if ( vLL[ firstOc-1 ] == 10 )
            {
                vLL[ firstOc-1 ] = 0;
                firstOc--;
            }
            else
            {
                break;
            }
        }
        if ( firstOc-1 < 0 )
        {
            vLL.push_back(1);
            decIdx++;
            break;
        }
        tCount++;
    }
    for (a = 0; a < decIdx-1; a++)
    {
        printf("%lld", vLL[a]);
    }
    if ( firstOc >= decIdx )
    {
        printf(".");
        for (a = decIdx; a <= firstOc; a++)
        {
            printf("%lld", vLL[a]);
        }
    }
//    for (a = decIdx; a < n-1; a++)
//    {
//        if ( str[a+1] >= '5' )
//        {
//            break;
//        }
//        if ( a == decIdx )
//        {
//            for (b = decIdx-1; b >= 0; b--)
//            {
//                if ( str[] )
//            }
//        }
//        else
//        {
//
//        }
//    }
    return 0;
}
