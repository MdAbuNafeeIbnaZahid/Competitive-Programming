#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265359
long long N, n;
double x, y, w, h, phi;
double diag, boardSpace, totalSpace, ans;
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
double crossPr(point A, point B)
{
    return A.x*B.y - A.y*B.x;
}
bool cmp(point A, point B)
{
    if ( A.x == B.x ) return A.y < B.y;
    return A.x < B.x;
}
vector<point> vecPoint, conHull, corPoint;
point rot(point C, point P, double ang)
{
    point ret;
    ret.x = C.x + (P.x-C.x) * cos(ang) - (P.y-C.y) * sin(ang);
    ret.y = C.y + (P.x-C.x) * sin(ang) + (P.y-C.y) * cos(ang);
    return ret;
}
vector<point> findCorPoint(point midPoint, double w, double h, double ang)
{
    vector<point> ret;
    double u, v;
    u = midPoint.x+w; v = midPoint.y+h;
    ret.push_back( rot(midPoint, point(u,v), -ang) );
    u = midPoint.x+w; v = midPoint.y-h;
    ret.push_back( rot(midPoint, point(u,v), -ang) );
    u = midPoint.x-w; v = midPoint.y+h;
    ret.push_back( rot(midPoint, point(u,v), -ang) );
    u = midPoint.x-w; v = midPoint.y-h;
    ret.push_back( rot(midPoint, point(u,v), -ang) );
    return ret;
}
vector<point> findConHull(vector<point> givenPoints)
{
    vector<point> ret;
    long long a, b, c, d, e, f, t, len = givenPoints.size();
    sort(givenPoints.begin(), givenPoints.end(), cmp);
    for ( a = 0; a < givenPoints.size(); a++ )
    {
        len = ret.size();
        while( ret.size() >= 2
              && crossPr(ret[len-1]-ret[len-2], givenPoints[a]-ret[len-2]) <= 0 )
        {
            ret.pop_back();
            len = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    t = ret.size();
    for (a = givenPoints.size()-1; a >= 0; a--)
    {
        len = ret.size();
        while( ret.size() >= 2+t
              && crossPr(ret[len-1]-ret[len-2], givenPoints[a]-ret[len-2]) <= 0 )
        {
            ret.pop_back();
            len = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    return ret;
}
double dis(point A, point B)
{
    return sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
}
double triangleArea(point A, point B, point C)
{
    double ret, s, AB, BC, CA;
    AB = dis(A, B);
    BC = dis(B, C);
    CA = dis(C, A);
    s = (AB + BC + CA)/2;
    ret = sqrt( s*(s-AB)*(s-BC)*(s-CA) );
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        vecPoint = vector<point>();
        conHull = vector<point>();
        boardSpace = 0;
        totalSpace = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lf %lf %lf %lf %lf", &x, &y, &w, &h, &phi);
            boardSpace += (w*h);
            corPoint = findCorPoint(point(x, y), w/2, h/2, phi*PI/180);
            for (c = 0; c < 4; c++)
            {
                vecPoint.push_back( corPoint[c] );
            }
        }
        //cout << "boardSpace = " << boardSpace << endl;
        //cout << "vecPoint.size() = " << vecPoint.size() << endl;
        for (b = 0; b < vecPoint.size(); b++)
        {
            //cout << "b = " << b << ", x = " << vecPoint[b].x << ", y = " <<vecPoint[b].y << endl;
        }
        conHull = findConHull(vecPoint);
        len = conHull.size();
        //cout << "conHull.size() = " << conHull.size() << endl;
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << ", x = " << conHull[b].x << ", y = " << conHull[b].y << endl;
        }
        for (b = 2; b < len; b++)
        {
            totalSpace += triangleArea(conHull[0], conHull[b-1], conHull[b]);
        }
        ans = (boardSpace / totalSpace)*100;
        //cout << "ans = " << ans << endl;
        printf("%0.1lf %%\n", ans);
    }
    return 0;
}
