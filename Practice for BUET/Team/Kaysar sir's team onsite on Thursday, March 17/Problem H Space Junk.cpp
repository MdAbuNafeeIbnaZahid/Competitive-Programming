#include <bits/stdc++.h>
using namespace std;
double T, x1, y1_, z1, r1, vx1, vy1, vz1;
double x2, y2, z2, r2, vx2, vy2, vz2;
double x0, y0_, z0, r0, vx0, vy0, vz0;
double a, b, c, d, ans;
double i, j, k;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lf %lf %lf %lf %lf %lf %lf", &x1, &y1_, &z1, &r1, &vx1, &vy1, &vz1);
        scanf("%lf %lf %lf %lf %lf %lf %lf", &x2, &y2, &z2, &r2, &vx2, &vy2, &vz2);
        x0 = x1-x2;
        y0_ = y1_-y2;
        z0 = z1-z2;
        r0 = r1+r2;
        vx0 = vx1 - vx2;
        vy0 = vy1 - vy2;
        vz0 = vz1 - vz2;
        a = vx0*vx0 + vy0*vy0 + vz0*vz0;
        b = 2*(x0*vx0 + y0_*vy0 + z0*vz0);
        c = x0*x0 + y0_*y0_ + z0*z0 - r0*r0;
        d = b*b - 4*a*c;
        if (c<=0)
        {
            ans = 0;
        }
        else if (d<0 || a==0)
        {
            cout << "No collision" << endl;
            continue;
        }
        else
        {
            ans = min( (-b+sqrt(d))/(2*a), (-b-sqrt(d))/(2*a) );
            if (ans<0)
            {
                cout << "No collision" << endl;
                continue;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
