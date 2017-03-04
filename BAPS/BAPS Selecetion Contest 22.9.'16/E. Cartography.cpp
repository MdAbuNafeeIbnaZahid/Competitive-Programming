#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long T, M, K;
long long a, b, c, d, e, f, g, h;
long long ans, sameCol, diffCol, tot;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> M >> K;
//        cout << "M = " << M << ", K = " << K << endl;
        if (M == 0)
        {
            cout << 0 << endl;
            continue;
        }
        else if ( M == 1 )
        {
            cout << K*(K-1) << endl;
            continue;
        }
        else if ( M >= 2 )
        {
            if ( K < 2 )
            {
                cout << 0 << endl;
                continue;
            }
            sameCol = ( (K%MOD)*( (K-1)%MOD )*( (K-1)%MOD ) )%MOD;
            diffCol = ( (K%MOD) * ( (K-1)%MOD ) * ( (K-2)%MOD ) * ( (K-2)%MOD ) ) %MOD;
//            cout << "2X2" << endl;
//            cout << "sameCol = " << sameCol << endl;
//            cout << "diffCol = " << diffCol << endl;
            ans =  (sameCol%MOD + diffCol%MOD)%MOD;

            for (b = 3; b <= M; b++)
            {
                sameCol = (K-1)%MOD;
                diffCol = ( ( (K-2)%MOD ) * ( (K-2)%MOD ) ) % MOD;
                tot = ( sameCol%MOD + diffCol%MOD ) %MOD;
                ans = ( (ans%MOD)*(tot%MOD) ) %MOD;
            }
            cout << ans << endl;
        }

    }
    return 0;
}
