#include <bits/stdc++.h>
using namespace std;
long long T, n, x, y, w, D2;
long long a, b, c, d, e, f, len, lowerVal, upperVal, midVal, maxDis;
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
        return ret;
    }
    const bool operator < (point B) const
    {
        if ( x == B.x )
        {
            return y < B.y;
        }
        return x < B.x;
    }
};

long long dis(point A, point B)
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}
vector<point> vecPoint, work, conHull;
set<point> inputSet;
set<point>::iterator setPointIt;
long long crossPr(point A, point B)
{
    long long ret = A.x*B.y - A.y*B.x;
    //cout << "ret = " << ret << endl;
    return ret;
}
vector<point> findConHull(vector<point> givenPoints)
{
    long long a, b, c, d, e, f, t, len = givenPoints.size(), siz;
    vector<point> ret;
    sort(givenPoints.begin(), givenPoints.end());
    //cout << "building lower hull" << endl;
    for (a = 0;a < len; a++)
    {
        //cout << "a = " << a << ", x = " << givenPoints[a].x << ", y = " << givenPoints[a].y << endl;
        siz = ret.size();
        while( siz >= 2 && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            //cout << "popped" << endl;
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    //cout << "lower hull" << endl;
    for (b = 0; b < ret.size(); b++)
    {
        //cout << "b = " << b << ", x = " << ret[b].x << ", y = " << ret[b].y << endl;
    }
    ret.pop_back();
    t = ret.size();

    //cout << "building upper hull" << endl;
    len = givenPoints.size();
    for (a = len-1; a >= 0; a--)
    {
        siz = ret.size();
        while( siz >= 2+t && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    //cout << "upper hull " << endl;
    for (b = t; b < ret.size(); b++)
    {
        //cout << "b = " << b << ", x = " << ret[b].x << ", y = " << ret[b].y << endl;
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
        //cout << "a = " << a << endl;
        D2 = 0;
        inputSet = set<point>();
        vecPoint = vector<point>();
        work = vector<point>();
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld %lld", &x, &y, &w);
            inputSet.insert( point(x, y) );
            inputSet.insert( point(x+w, y) );
            inputSet.insert( point(x, y+w) );
            inputSet.insert( point(x+w, y+w) );
        }
        for (setPointIt = inputSet.begin(); setPointIt != inputSet.end(); setPointIt++)
        {
            vecPoint.push_back( *setPointIt );
        }
        //cout << "input points are" << endl;
        len = vecPoint.size();
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << ", x = " << vecPoint[b].x << ", y = " << vecPoint[b].y << endl;
        }
        conHull = findConHull(vecPoint);
        //cout << "conHull is ready!";
        len = conHull.size();
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << ", x = " << conHull[b].x << ", y = " << conHull[b].y << endl;
        }
        for (b = 0; b < len; b++)
        {
            lowerVal = 1;
            upperVal = len-1;
            while( lowerVal < upperVal )
            {
                midVal = (lowerVal + upperVal)/2;
                if ( dis(conHull[b], conHull[ (b+midVal)%len ]) >
                    dis(conHull[b], conHull[ (b+midVal+1)%len ]) )
                {
                    upperVal = midVal;
                }
                else
                {
                    lowerVal = midVal + 1;
                }
            }
            D2 = max(D2, dis(conHull[b], conHull[ (b+lowerVal)%len ]) );
        }
        cout << D2 << endl;
    }
    return 0;
}
