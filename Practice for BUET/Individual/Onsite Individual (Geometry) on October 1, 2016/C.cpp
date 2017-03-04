#include <bits/stdc++.h>
using namespace std;
long long N, n;
double x, y;
double totX, totY, avgX, avgY, ans;
long long a, b, c, d, e, f, len;
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
struct line
{
    double a, b, c;
    line(){}
    line(double a, double b, double c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    line(point P, point Q)
    {
        double dy = P.y - Q.y, dx = P.x - Q.x;
        a = -dy;
        b = dx;
        c = a * P.x + b * P.y;
    }
};
double crossPr(point A, point B)
{
    double ret = A.x*B.y - A.y*B.x;
    return ret;
}
vector<point> vecPoint, conHull;
bool cmp(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
line L;
vector<point> findConHull(vector<point> givenPoints)
{
    long long a, b, c, d, e, f, t, len = givenPoints.size(), siz;
    vector<point> ret;
    sort(givenPoints.begin(), givenPoints.end(), cmp);
    for (a = 0; a < len; a++)
    {
        siz = ret.size();
        while(siz >= 2 && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    t = ret.size();
    for (a = len-1; a >= 0; a--)
    {
        siz = ret.size();
        while(siz >= 2+t && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    return ret;
}
double dis(line L, point P)
{
    double up, down;
    up = L.a * P.x + L.b * P.y - L.c;
    down = sqrt( L.a * L.a + L.b * L.b );
    return abs( up/down );
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        vecPoint = vector<point>();
        ans = 80009;
        totX = 0;
        totY = 0;
        cin >> n;
        //cout << "n = " << n << endl;
        for (b = 0; b < n; b++)
        {
            scanf("%lf %lf", &x, &y);
            vecPoint.push_back( point(x, y) );
            totX += x;
            totY += y;
        }
        avgX = totX/n;
        //cout << "avgX = " << avgX << endl;
        avgY = totY/n;
        //cout << "avgY = " << avgY << endl;
        conHull = findConHull(vecPoint);
        //cout << "conHull Found" << endl;
        len = conHull.size();
        //cout << "conHull.size() = " << conHull.size() << endl;
        //cout << (conHull.size() <= 1) << endl ;
        if ( conHull.size() <= 1 )
        {
            //cout << "zero will be printed" << endl;
            printf("Case #%lld: 0.000\n", a);
            continue;
        }
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << endl;
            //cout << "ans = " << ans << endl;
            //cout << "x = " << conHull[b].x << ", y = " << conHull[b].y << endl;
            L = line( conHull[b%len], conHull[(b+1)%len] );
            //cout << "L.a = " << L.a << ", L.b = " << L.b << ", L.c = " << L.c << endl;
            //cout << "dis = " << dis(L, point(avgX, avgY) ) << endl;
            ans = min(ans, dis(L, point(avgX, avgY) ) );
            //cout << "ans = " << ans << endl;
        }
        printf("Case #%lld: %0.3lf\n", a, ans);
    }
    return 0;
}
