#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n;
char str[SIZE];
long long cntAr[SIZE];
long long ans;
long long a, b, c, d, e, f, g, addee, addee1, addee2;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", str);
    for (a = 0;a < n; a++)
    {
        cntAr[ str[a] ]++;
    }
    if ( n%2 ) // odd
    {
        ans += (n/2) - min( cntAr['b'], cntAr['r'] );
        if ( cntAr['b'] > cntAr['r'] )
        {
            for (a = 0; a < n; a++)
            {
                if ( a%2==0 && str[a] != 'b' )
                {
                    addee++;
                }
                else if( a%2==1 && str[a] != 'r' )
                {
                    addee++;
                }
            }
        }
        else
        {
            for (a = 0; a < n; a++)
            {
                if ( a%2==0 && str[a] != 'r' )
                {
                    addee++;
                }
                else if( a%2==1 && str[a] != 'b' )
                {
                    addee++;
                }
            }
        }
    }
    else
    {
        ans += (n/2) - min( cntAr['b'], cntAr['r'] );
        for (a = 0; a < n; a++)
        {
            if ( a%2==0 && str[a] != 'b' )
            {
                addee1++;
            }
            else if( a%2==1 && str[a] != 'r' )
            {
                addee1++;
            }
        }

        for (a = 0; a < n; a++)
        {
            if ( a%2==0 && str[a] != 'r' )
            {
                addee2++;
            }
            else if( a%2==1 && str[a] != 'b' )
            {
                addee2++;
            }
        }
        addee = min(addee1, addee2);
    }
    ans = ans + addee/2;
    cout << ans;
    return 0;
}
