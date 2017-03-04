#include <bits/stdc++.h>
using namespace std;
#define SIZE 2009
long long testCases, ar[SIZE], incr[SIZE], decr[SIZE], n;
long long a, b, c, d, e, idx, ans;
struct seq
{
    long long s, e, len;
    seq(){}
    seq(long long s, long long e)
    {
        this->s = s;
        this->e = e;
    }
};
//seqAr[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    while(testCases--)
    {
        cin >> n;
        //cout << "n = " << n << endl;
        for (a = 1; a <= n; a++)
        {
            scanf("%lld", &ar[a]);
        }
        for (a = 1; a <= n; a++)
        {
            incr[a] = 1;
            decr[a] = 1;
        }
        ans = 0;
        for (a = n-1; a >= 1; a--)
        {
            for (b = n; b > a; b--)
            {
                if (ar[b] < ar[a])
                {
                    incr[a] = max( incr[a], incr[b]+1 );
                }
                else if ( ar[b] > ar[a] )
                {
                    decr[a] = max( decr[a], decr[b]+1 );
                }
            }
            //cout << "ar[" << a << "] = " << ar[a] << ", incr =" << incr[a] << ", decr = "
            //<< decr[a] << endl;
            //ans = max(ans, incr[a]+decr[a]-1);
        }
        for (a = 1; a <= n; a++) ans = max(ans, incr[a]+decr[a]-1);
        cout << ans ;
        //if (testCases)
            cout << endl;
    }
    return 0;
}
