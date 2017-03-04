#include <bits/stdc++.h>
using namespace std;
long long T, n, x, y, w, D2;
long long a, b, c, d, e, f, len;
struct point
{
    long long x, y;
    point(){}
    point(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
    point operator - (point B)
    {
        point ret;
        ret.x = x - B.x;
        ret.y = y - B.y;
    }
};
bool cmp(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
bool cmpLeftLow(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
bool cmpLeftHigh(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y > B.y;
    }
    return A.x < B.x;
}
bool cmpLowLeft(point A, point B)
{
    if ( A.y == B.y )
    {
        return A.x < B.x;
    }
    return A.y < B.y;
}
bool cmpLowRight(point A, point B)
{
    if ( A.y == B.y )
    {
        return A.x > B.x;
    }
    return A.y < B.y;
}
long long dis(point A, point B)
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}
vector<point> vecPoint, work, conHull;

long long crossPr(point A, point B)
{
    long long ret = A.x*B.y - A.y*B.x;
    return ret;
}


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


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        D2 = 0;
        vecPoint = vector<point>();
        work = vector<point>();
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld %lld", &x, &y, &w);
            vecPoint.push_back( point(x, y) );
            vecPoint.push_back( point(x+w, y) );
            vecPoint.push_back( point(x, y+w) );
            vecPoint.push_back( point(x+w, y+w) );
        }
        len = vecPoint.size();

        sort(vecPoint.begin(), vecPoint.end(), cmpLeftLow);
        work.push_back( vecPoint[0] );
        work.push_back( vecPoint[len-1] );

        sort(vecPoint.begin(), vecPoint.end(), cmpLeftHigh);
        work.push_back( vecPoint[0] );
        work.push_back( vecPoint[len-1] );

        sort(vecPoint.begin(), vecPoint.end(), cmpLowLeft);
        work.push_back( vecPoint[0] );
        work.push_back( vecPoint[len-1] );

        sort(vecPoint.begin(), vecPoint.end(), cmpLowRight);
        work.push_back( vecPoint[0] );
        work.push_back( vecPoint[len-1] );

        len = work.size();
        for (b = 0; b < len; b++)
        {
            for (c = 0; c < len; c++)
            {
               D2 = max(D2,  dis( work[b], work[c] ) );
            }
        }
        cout << D2;
        if (a < T) cout << endl;
    }
    return 0;
}
