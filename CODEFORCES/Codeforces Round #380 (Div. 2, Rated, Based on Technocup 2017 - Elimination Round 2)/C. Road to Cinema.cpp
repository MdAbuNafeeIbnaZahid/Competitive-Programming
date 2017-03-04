#include <bits/stdc++.h>
using namespace std;
#define SIZE
long long n, k, s, t, ci, vi, gi, ans = INT_MAX;
long long a, b, c, d, e, f, g, h, minV, midV, maxV, curT;
vector<long long> gas;
long long timeNeeded(long long fuelCap, long long dis)
{
//    cout << "dis = " << dis << endl;
//    cout << "fuelCap = " << fuelCap << endl;

    long long a, b, c, d, ret = 0;
    if ( dis > fuelCap )
    {
        return INT_MAX;
    }
    ret = 2*dis;
//    cout << "ret = " << ret << endl;
    fuelCap -= dis;
    ret -= min(fuelCap, dis);
//    cout << "ret = " << ret << endl;
    return ret;
}
struct car
{
    long long ci, vi;
    car(){}
    car(long long ci, long long vi)
    {
        this->ci = ci;
        this->vi = vi;
    }
};
vector<car> vecCar;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> k >> s >> t;
    vecCar.push_back( car(INT_MAX, INT_MAX) );
    for (a = 1;  a <= n; a++)
    {
        scanf("%lld %lld", &ci, &vi);
        vecCar.push_back( car(ci, vi) );
    }
    gas.push_back(0);
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &gi);
        gas.push_back( gi );
    }
    gas.push_back( s );
    sort(gas.begin(), gas.end());
    minV = 1;
    maxV = INT_MAX;
    while( minV < maxV )
    {
//        cout << "minV = " << minV << endl;
//        cout << "maxV = " << maxV << endl;
        midV = (minV+maxV)/2;
//        cout << "midV = " << midV << endl;
        curT = 0;
        for (a = 1; a <= k+1; a++)
        {
//            cout << "a = " << a << endl;
            curT += timeNeeded(midV, gas[a]-gas[a-1] );
//            cout << "curT = " << curT << endl;
        }
        if ( curT <= t  )
        {
            maxV = midV;
        }
        else
        {
            minV = midV + 1;
        }
    }
    for (a = 0; a < vecCar.size(); a++)
    {
        if ( vecCar[a].vi >= minV )
        {
            ans = min(ans, vecCar[a].ci );
        }
    }
    if (ans >= INT_MAX)
    {
        ans = -1;
    }
    cout << ans;
    return 0;
}
