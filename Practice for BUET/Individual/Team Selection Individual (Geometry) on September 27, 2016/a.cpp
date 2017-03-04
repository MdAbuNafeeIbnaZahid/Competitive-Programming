#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
long long N, XA, YA, XB, YB, XC, YC;
long long a, b, c, d, e, f;
double angA, angB, angC;
double myACos(double val)
{
    val = min(1.0, val);
    val = max(-1.0, val);
    return acos(val);
}
struct point
{
    double x, y;
    point(){}
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    point operator - (point B)
    {
        point ret;
        ret.x = x - B.x;
        ret.y = y - B.y;
        return ret;
    }
};
struct straightLine
{
    double a, b, c;
    straightLine(){}
    straightLine(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    straightLine(point A, point B)
    {
        double dx, dy;
        dx = A.x-B.x;
        dy = A.y-B.y;
        a = dy;
        b = dx;
        c = a*A.x + b*A.y;
    }
};
point A, B, C, D, E, F, bA, cA, cB, aB, aC, bC;
straightLine AaB, AaC, BbA, BbC, CcA, CcB;
double dotProduct( point A, point B )
{
    return A.x*B.x + A.y*B.y;
}
double lenOfVec(point A)
{
    return sqrt(A.x*A.x + A.y*A.y);
}
double angleBetweenTwoVectors(point A, point B)
{
    double dotPr;
    cout << "A.x = " << A.x << endl;
    cout << "A.y = " << A.y << endl;
    cout << "B.x = " << B.x << endl;
    cout << "B.y = " << B.y << endl;
    dotPr = dotProduct(A, B);
    cout << "dotPr = " << dotPr << endl;
    double cosAng = dotProduct(A,B) / ( lenOfVec(A) * lenOfVec(B) );
    return myACos( cosAng );
}
point rot(point C, point P, double ang)
{
    point ret;
    ret.x = C.x + (P.x-C.x) * cos(ang) - (P.y-C.y) * sin(ang);
    ret.y = C.y + (P.x-C.x) * sin(ang) + (P.y-C.y) * cos(ang);
    return ret;
}
point interSecOfTwoLines(straightLine S1, straightLine S2)
{
    point ret;
    double a1, a2, b1, b2, c1, c2;
    a1 = S1.a;
    b1 = S1.b;
    c1 = S1.c;
    a2 = S2.a;
    b2 = S2.b;
    c2 = S2.c;
    ret.x = (c1*b2 - c2*b1) / (a1*b2 - a2*b1);
    ret.y = (c1*a2 - c2*a1) / (a2*b1 - a1*b2);
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        scanf("%lld %lld %lld %lld %lld %lld", &XA, &YA, &XB, &YB, &XC, &YC);
        A = point(XA, YA);
        B = point(XB, YB);
        C = point(XC, YC);
        angA = angleBetweenTwoVectors( B-A, C-A );
        cout << "angA = " << angA*180/PI << endl;
        angB = angleBetweenTwoVectors( C-B, A-B );
        cout << "angB = " << angB*180/PI << endl;
        angC = angleBetweenTwoVectors( A-C, B-C );
        cout << "angC = " << angC*180/PI << endl;
        bA = rot(B, A, -angB/3);
        cA = rot(C, A, angC/3);
        cB = rot(C, B, -angC/3);
        aB = rot(A, B, angA/3);
        aC = rot(A, C, -angA/3);
        bC = rot(B, C, angB/3);
        cout << "bC.x = " << bC.x << endl;
        cout << "bC.y = " << bC.y << endl;
        BbC = straightLine(B, bC);
        cout << "BbC.a = " << BbC.a << endl;
        cout << "BbC.b = " << BbC.b << endl;
        cout << "BbC.c = " << BbC.c << endl;
        CcB = straightLine(C, cB);
        D = interSecOfTwoLines(BbC, CcB);
        printf("%lf %lf\n", D.x, D.y);
    }
    return 0;
}
