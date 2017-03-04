#include <bits/stdc++.h>
using namespace std;
#define SIZE 600009
long long t, ai, cntAr[SIZE], len, ans;
long long a, b, c, d, e, f, g;
char order, s[59];

long long myHash(long long n)
{
    long long a, b, c, d, e, f, r, ret = 0, mul = 1;
    while(n)
    {
        r = n%10;
        n/=10;
        ret = ret + ( (r%2)*mul );
        mul*=2;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> t;
//    cout << t << endl;
    for (a = 1; a <= t; a++)
    {
        getchar();
        scanf("%c", &order);
        scanf("%lld", &ai);
//        cout << "ai = " << ai << " " << myHash(ai) << endl;

//        cout << order << " " << ai << endl;
        if ( order == '+' )
        {
            //scanf("%lld", &ai);
            cntAr[ myHash(ai) ]++;
        }
        else if ( order == '-' )
        {
            //scanf("%lld", &ai);
            cntAr[ myHash(ai) ]--;
        }
        else if ( order == '?' )
        {
            //scanf("%lld", &ai);
            ans = cntAr[ myHash(ai) ];
            printf("%lld\n", ans);
        }
    }
    return 0;
}
