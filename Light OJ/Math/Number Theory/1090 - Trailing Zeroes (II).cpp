#include <bits/stdc++.h>
using namespace std;
int T, n, r, p, q;
int i, j, k, a, b, c2, c5, dividee, ans, addee, divisor;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        c2 = 0;
        c5 = 0;
        scanf("%d %d %d %d", &n, &r, &p, &q);

        dividee = n;
        divisor = 2;
        while(dividee/divisor)
        {
            c2+=dividee/divisor;
            divisor*=2;
        }
        divisor = 5;
        while(dividee/divisor)
        {
            c5+=dividee/divisor;
            divisor*=5;
        }
        //cout << "c2 = " << c2 << ", c5 = " << c5 << endl;

        while(p%2==0)
        {
            p/=2;
            c2+=q;
        }
        while(p%5==0)
        {
            p/=5;
            c5+=q;
        }
        //cout << "c2 = " << c2 << ", c5 = " << c5 << endl;

        dividee = n-r;
        divisor = 2;
        while(dividee/divisor)
        {
            c2-=dividee/divisor;
            divisor*=2;
        }
        divisor = 5;
        while(dividee/divisor)
        {
            c5-=dividee/divisor;
            divisor*=5;
        }
        //cout << "c2 = " << c2 << ", c5 = " << c5 << endl;

        dividee = r;
        divisor = 2;
        while(dividee/divisor)
        {
            c2-=dividee/divisor;
            divisor*=2;
        }
        divisor = 5;
        while(dividee/divisor)
        {
            c5-=dividee/divisor;
            divisor*=5;
        }
        //cout << "c2 = " << c2 << ", c5 = " << c5 << endl;


        ans = min(c2, c5);
        ans = max(ans, 0);
        printf("Case %d: %d\n", i, ans);
    }
    return 0;
}
