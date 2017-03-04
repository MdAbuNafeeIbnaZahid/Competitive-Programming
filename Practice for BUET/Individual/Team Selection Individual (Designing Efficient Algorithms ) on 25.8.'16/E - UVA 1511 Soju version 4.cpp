#include <bits/stdc++.h>
using namespace std;
#define SIZE
#define IC 0
#define PC 1
long long T, n, xi, yi, m;
long long a, b, c, d, e, f, g, h, len, ans, closestPick;
struct coOrd
{
    long long x, y, type;
    coOrd(){}
    coOrd(long long x, long long y, long long type)
    {
        this->x = x;
        this->y = y;
        this->type = type;
    }
    bool const operator < (coOrd b) const
    {
        if ( y == b.y ) return x < b.x;
        return y < b.y;
    }
};
vector<coOrd> coVec;
coOrd closestP;
long long dist(coOrd a, coOrd b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        coVec = vector<coOrd>();
        ans = INT_MAX;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            coVec.push_back( coOrd(xi, yi, IC) );
        }
        cin >> m;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            coVec.push_back( coOrd(xi, yi, PC) );
        }
        len = coVec.size();
        closestP.x = INT_MAX;
        closestP.y = INT_MIN;
        closestPick = INT_MAX;
        for (b = 0; b < len; b++)
        {
            if ( coVec[b].type == PC )
            {
                closestPick = min(closestPick, coVec[b].x+coVec[b].y);
            }
            else if ( coVec[b].type == IC )
            {
                cout << "b = " << b << endl;
                ans = min(ans, closestPick-(coVec[b].x+coVec[b].y) );
            }
        }
        cout << "ans = " << ans << endl;
        closestP.x = INT_MAX;
        closestP.y = INT_MAX;
        closestPick = INT_MAX;
        for (b = len-1; b >= 0; b--)
        {
            if ( coVec[b].type == PC )
            {
                closestPick = min(closestPick, coVec[b].x-coVec[b].y);
            }
            else
            {
                ans = min(ans, closestPick-(coVec[b].x-coVec[b].y) );
            }
        }
        cout << ans ;
        //if ( a < T )
            cout << endl;
    }
    return 0;
}

