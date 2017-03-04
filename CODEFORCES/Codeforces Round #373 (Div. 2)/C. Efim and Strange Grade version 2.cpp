#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, t;
char str[SIZE];
long long a, b, c, d, e, f, g;
long long tCount, decIdx, moreThanFiveIdx, updatedUpto;
vector<long long> vecLL;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> t;
    scanf("%s", str);
    for (a = 0; a< n; a++)
    {
        if ( str[a] == '.' )
        {
            decIdx = a;
            vecLL.push_back( -99 );
        }
        else
        {
            vecLL.push_back( str[a]-'0' );
        }
    }
    for (a = decIdx+1; a < vecLL.size(); a++)
    {
        if ( vecLL[a] >= 5 )
        {
            moreThanFiveIdx = a;
            cout << "moreThanFiveIdx = " << moreThanFiveIdx << endl;
            break;
        }
    }
    if ( a >= n )
    {
        printf("%s", str);
        return 0;
    }
    for (a = moreThanFiveIdx; a < n; a++)
    {
        cout << "pop_back" << endl;
        vecLL.pop_back();
    }
    if ( vecLL[ vecLL.size() - 1 ] == -99 )
    {
        a = moreThanFiveIdx-1;
        for (b = a-1; b >= 0; b--)
        {
            vecLL[b]++;
            if ( vecLL[b] != 10 )
            {
                break;
            }
            else
            {
                vecLL[b] = 0;
            }
        }
        if ( b < 0 ) printf("1");
        for (b = 0; b < vecLL.size(); b++)
        {
            if ( vecLL[b] == -99 )
            {
                if ( b < vecLL.size()-1 ) printf(".");
            }
            else printf("%lld", vecLL[b]);
        }
        return 0;
    }

    for (a = moreThanFiveIdx-1, tCount = 1; a >= 0, tCount < t; a--)
    {
        cout << "a = " << a << endl;
        cout << "tCount = " << tCount << endl;
        if ( vecLL[a] == -99 )
        {
            //continue;
            for (b = a-1; b >= 0; b--)
            {
                vecLL[b]++;
                if ( vecLL[b] != 10 )
                {
                    break;
                }
                else
                {
                    vecLL[b] = 0;
                }
            }
            if ( b < 0 ) printf("1");
            for (b = 0; b < vecLL.size(); b++)
            {
                if ( vecLL[b] == -99 )
                {
                    if ( b < vecLL.size()-1 ) printf(".");
                }
                else printf("%lld", vecLL[b]);
            }
            return 0;
        }

        if ( vecLL[a] == 4 )
        {
            cout << "popped another" << endl;
            vecLL.pop_back();
            tCount++;
        }
        else
        {
            vecLL[a]++;
            for (b = 0; b < vecLL.size(); b++)
            {
                if ( vecLL[b] == -99 )
                {
                    if ( b < vecLL.size()-1 ) printf(".");
                }
                else printf("%lld", vecLL[b]);
            }
            return 0;
        }
        cout << "t = " << t << endl;
        cout << "tCount = " << tCount << endl;
    }


    cout << "came here" << endl;
    vecLL[a]++;
    for (b = 0; b < vecLL.size(); b++)
    {
        if ( vecLL[b] == -99 )
        {
            if ( b < vecLL.size()-1 ) printf(".");
        }
        else printf("%lld", vecLL[b]);
    }
    return 0;


//    for (a = moreThanFiveIdx-1; a >= 0; a--)
//    {
//        if ( vecLL[a] == -99 )
//        {
//            continue;
//        }
//        vecLL[a]++;
//        updatedUpto = a;
//        if (vecLL[a] != 10) break;
//        else
//        {
//            vecLL[a] = 0;
//        }
//    }
    if ( a < 0 )
    {
        printf("1");
        for (b = 0; b < vecLL.size(); b++)
        {
            if ( vecLL[b] == -99 )
            {
                if ( b < vecLL.size()-1 ) printf(".");
            }
            else printf("%lld", vecLL[b]);
        }
        return 0;
    }
    tCount++;
    while( tCount < t )
    {
        //if ( vecLL[] )
    }
    return 0;
}
