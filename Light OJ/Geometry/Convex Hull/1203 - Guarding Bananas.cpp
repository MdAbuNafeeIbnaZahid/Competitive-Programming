#include <bits/stdc++.h>
using namespace std;
#define eps 0.000000001
#define PI 3.1415926535
long long T, n;
double  ans, dp, dn, dm, angle;
long long a, b, c, d, e, f, g, h, len, xi, yi, len2, t;
struct point
{
    long long x, y;
    point(){}
    point(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
    const bool operator < ( const point b ) const
    {
        if ( x==b.x ) return y < b.y;
        return x < b.x;
    }
};
point prev, mid, next;
vector<point> inputVec, conHull;
long long cross(point o, point a, point b)
{
    return (a.x-o.x)*(b.y-o.y) - (a.y-o.y)*(b.x-o.x);
}
double dist(point a, point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        //cout << "a = " << a << endl;
        cin >> n;
        inputVec = vector<point>();
        conHull = vector<point>();
        ans = PI;
        for (b = 0; b < n; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            inputVec.push_back( point(xi, yi) );
        }
        sort(inputVec.begin(), inputVec.end());
        //len = inputVec.size();
        for (b = 0; b < n; b++)
        {
            len = conHull.size();
            while( len>=2 && cross( conHull[len-2], conHull[len-1], inputVec[b] ) <= 0 )
            {
                conHull.pop_back();
                len = conHull.size();
            }
            conHull.push_back( inputVec[b] );
        }
        conHull.pop_back();
        t = conHull.size();
        for (b = n-1; b >= 0; b--)
        {
            len = conHull.size();
            while( len>=t+2 && cross( conHull[len-2], conHull[len-1], inputVec[b] ) <= 0 )
            {
                conHull.pop_back();
                len = conHull.size();
            }
            conHull.push_back( inputVec[b] );
        }
        conHull.pop_back();
        len = conHull.size();
        for (b = 0; b < conHull.size(); b++)
        {
            prev = conHull[ (b-1+len)% len ];
            mid = conHull[b];
            next = conHull[ (b+1)%len ];
            dp = dist(mid, next);
            dm = dist(prev, next);
            dn = dist(prev, mid);
            angle =  ( (double) (dp*dp + dn*dn - dm*dm ) ) / ( 2*dp*dn );
            ans = min(ans, acos(angle) );
        }
        if ( abs(PI-ans) < eps ) ans = 0;
        ans = ans * 180 / PI;
        cout << "Case " << a << ": ";
        printf("%0.8lf\n", ans );
    }
    return 0;
}
