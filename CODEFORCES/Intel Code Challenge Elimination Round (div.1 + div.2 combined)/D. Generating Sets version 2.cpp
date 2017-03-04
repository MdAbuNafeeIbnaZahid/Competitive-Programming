#include <bits/stdc++.h>
using namespace std;
long long n, yi;
vector<long long> vLL, cop;
long long a, b, c, d, e, flag, len, target, current;
map<long long, long long> occupy;
main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &yi);
        vLL.push_back(yi);
        occupy[yi] = 1;
    }
    sort(vLL.begin(), vLL.end());
    while(1)
    {
        cop = vector<long long>();
        flag = 0;
        len = vLL.size();
        for (a = len-1; a >= 0; a--)
        {
            current = vLL[a];
            target = vLL[a]/2;
            if ( target!=0 && occupy[target]==0  )
            {
                cop.push_back( target );
                occupy[target] = 1;
                occupy[ current ] = 0;
                flag = 1;
            }
            else
            {
                cop.push_back(current);
            }
        }
        sort(cop.begin(), cop.end() );
        vLL = cop;
        if (flag == 0) break;
    }
    len = vLL.size();
    for (a = 0; a < len; a++)
    {
        printf("%lld ", vLL[a]);
    }
    return 0;
}
