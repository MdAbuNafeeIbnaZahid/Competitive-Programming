#include <bits/stdc++.h>
using namespace std;
long long T, N;
long long X, Y, Z;
long long a,b, c, d, e, f, ans, low, high, ans2;
int main()
{
    //freopen("input.txt", "r", stdin);
    //cin >> T;
    for (a = 10000; a <= 10000; a++)
    {
        //cout << "a = " << a << endl;
        ans = 0;
        N = a;
        //cin >> N;
        //cout << "N = " << N << endl;
        //high = (N+1)/2;
        for (b = 1; b <= N; b++)
        {
            //cout << "b = " << b << endl;
            //low = b;
            //high = ((N-b)/2.0);
            low = max(N-b-(N/2), b);
            high = N-b-low;
            //cout << "low = " << low << endl;
            //cout << "high = " << high << endl;
            if (  high < low )
            {
                break;
            }
            ans +=  ( (high-low+2)/2 );
            //cout << "ans = " << ans << endl;
        }
        //cout << ans << endl;
        //if (a < T) cout << endl;

        ans2 = 0;
        for (X = 1; X <= N; X++)
        {
            for (Y = X; Y <= N; Y++)
            {
                for (Z = Y; Z <= N; Z++)
                {
                    if ( X+Y+Z == N && Z <= X+Y )
                    {
                        ans2++;
                    }
                }
            }
        }

        //cout << "ans = " << ans << ", ans2 = " << ans2 << endl;

        if (ans != ans2)
        {
            cout << "a = " <<a << endl;
            cout << "ans != ans2" << endl;
        }
    }
    return 0;
}
