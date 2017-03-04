#include <bits/stdc++.h>
using namespace std;
#define eps 0.0000000001
#define PI 3.14159265359
long long T;
double x1, y11, r1, x2, y2, r2, d, ans, s, trABC, lenComChord;
double theta1, theta2, area1, area2, sector1, sector2, triangle1, triangle2;
double segment1, segment2;
long long a, b, c, e, f;
double myDis(double x1, double y1, double x2, double y2)
{
    return sqrt( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );
}
double myASin(double dob)
{
    double ret;
    dob = max(dob, -1.0);
    dob = min(dob, 1.0);
    //cout << "dob = " << dob << endl;
    ret = asin(dob);
    //cout << "ret = " << ret << endl;
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T;a++)
    {
        cin >> x1 >> y11 >> r1 >> x2 >> y2 >> r2;
        d = myDis(x1, y11, x2, y2);
        cout << "d = " << d << endl;
        if ( myDis(x1, y11, x2, y2) + eps > r1 + r2 )
        {
            cout << "Case " << a << ": 0" << endl;
            continue;
        }
        else if ( myDis(x1, y11, x2, y2) <= abs(r1-r2) + eps )
        {
            ans = PI*min(r1,r2)*min(r1,r2);
            printf("Case %lld: %0.10lf\n", a, ans);
            continue;
        }
        //cout << "no special case" << endl;
        s = (r1+r2+d)/2;
        trABC = sqrt( s*(s-r1)*(s-r2)*(s-d) );
        cout << "trABC = " << trABC << endl;
        lenComChord = 4*trABC/d;
        cout << "lenComChord = " << lenComChord << endl;
        theta1 = 2*myASin( (lenComChord/(2*r1) ) );
        cout << "theta1 = " << theta1 << endl;
        theta2 = 2*myASin( (lenComChord/(2*r2) ) );
        cout << "theta2 = " << theta2 << endl;
        sector1 = (PI*r1*r1*theta1/(2*PI));
        cout << "sector1 = " << sector1 << endl;
        sector2 = (PI*r2*r2*theta2/(2*PI));
        cout << "sector2 = " << sector2 << endl;
        s = (r1+r1+lenComChord)/2;
        cout << "s for triangle1 = " << s << endl;
        triangle1 = sqrt( abs( s*(s-r1)*(s-r1)*(s-lenComChord) ) );
        cout << "triangle1 = " << triangle1 << endl;
        s = (r2+r2+lenComChord)/2;
        triangle2 = sqrt( abs( s*(s-r2)*(s-r2)*(s-lenComChord) ) );
        cout << "triangle2 = " << triangle2 << endl;
        segment1 = sector1 - triangle1;
        segment2 = sector2 - triangle2;
        ans = segment1+segment2;
        printf("Case %lld: %0.10lf\n", a, ans);
    }
    return 0;
}
