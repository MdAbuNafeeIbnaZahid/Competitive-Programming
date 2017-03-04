#include <bits/stdc++.h>
using namespace std;
long long T, N;
long long a,b, c, d, e, f, ans, low, high;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> N;
        //cout << "N = " << N << endl;
        //high = (N+1)/2;
        for (b = 1; b <= N; b++)
        {
            //cout << "b = " << b << endl;
            //low = b;
            //high = ((N-b)/2.0);
            low = max(N-b-(N/2), b);
            high = min(N-b-low, N/2);
            //cout << "low = " << low << endl;
            //cout << "high = " << high << endl;
            if (  high < low )
            {
                //break;
                continue;
            }
            ans +=  ( (high-low+2)/2 );
            //cout << "ans = " << ans << endl;
        }
        cout << ans;// << endl;
        if (a < T) cout << endl;
    }
    return 0;
}
