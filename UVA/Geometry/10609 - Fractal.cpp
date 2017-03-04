#include <bits/stdc++.h>
using namespace std;
#define eps (1e-9)
double X1, Y1, X2, Y2, T;
long long testCases;
struct point
{
    double x, y;
    point(){}
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    const bool operator < (point b) const
    {
        //if ( dist(*this, b) < eps ) return false;
        if ( sqrt( (x-b.x)*(x-b.x) + (y-b.y)*(y-b.y) ) <= eps ) return false;
        if ( abs(x - b.x) <= eps ) return y < b.y+eps;
        return x < b.x+eps;
    }
};
double dist(point a, point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
set<point> setP;
set<point>::iterator setPIt;
void myRec(point a, point b)
{
    point p, q, r, v;
    if (dist(a, b) < T+eps) return;
    setP.insert(a);
    setP.insert(b);
    v.x = (b.x-a.x);
    v.y = (b.y-a.y);
    p.x = a.x + (b.x-a.x)/4;
    p.y = a.y + (b.y-a.y)/4;
    q.x = b.x + (a.x-b.x)/4;
    q.y = b.y + (a.y-b.y)/4;
    r.x = (a.x+b.x)/2 - v.y * sqrt(3)/4;
    r.y = (a.y+b.y)/2 + v.x * sqrt(3)/4;
    myRec(p,r);
    myRec(r,q);
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> X1 >> Y1 >> X2 >> Y2 >> T;
        if (T < 1+eps) return 0;
        testCases++;
        setP = set<point>();
        myRec( point(X1, Y1), point(X2, Y2) );
        cout << "Case " << testCases << ":" << endl;
        cout << setP.size() << endl;
        for (setPIt = setP.begin(); setPIt != setP.end(); setPIt++)
        {
            printf("%0.5lf %0.5lf\n", setPIt->x, setPIt->y);
            //setPIt++;
            //if ( setPIt != setP.end() ) printf("\n");
        }
    }
    return 0;
}
