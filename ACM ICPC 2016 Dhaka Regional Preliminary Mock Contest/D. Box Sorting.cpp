#include <bits/stdc++.h>
using namespace std;
long long T, N, X;
long long a, b, c, d, e, f, g, ans;
vector<long long> vecLL;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        vecLL = vector<long long>();
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld", &X);
            vecLL.push_back( X );
        }
        sort(vecLL.begin(), vecLL.end());
        d = 0;
        for (c = 1; c <vecLL.size(); c++)
        {
            //cout << "c = " << c << ", " << vecLL[c] << endl;
            if ( vecLL[d] < vecLL[c] )
            {
                //c++;
                d++;
            }
        }
        ans = vecLL.size() - d;
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
