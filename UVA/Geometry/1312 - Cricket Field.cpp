#include <bits/stdc++.h>
using namespace std;
long long testCases, N, W, H, xi, yi;
long long a, b, c, d, e, f, g, h, len, ans, ansX, ansY, maxX, minX, maxY, minY;
struct point
{
    long long x, y;
    point(){}
    point(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
};
bool cmpX(point a, point b)
{
    if ( a.x == b.x ) return a.y < b.y;
    return a.x < b.x;
}
bool cmpY(point a, point b)
{
    if ( a.y == b.y ) return a.x < b.x;
    return a.y < b.y;
}
vector<point> vecPointX, vecPointY, strip;
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        cin >> N >> W >> H;
        ans = 0;
        ansX = 0;
        ansY = 0;
        vecPointX = vector<point>();
        vecPointY = vector<point>();
        vecPointX.push_back( point(0, 0) );
        vecPointX.push_back( point(W, 0) );
        vecPointX.push_back( point(0, H) );
        vecPointX.push_back( point(W, H) );
        vecPointY.push_back( point(0, 0) );
        vecPointY.push_back( point(W, 0) );
        vecPointY.push_back( point(0, H) );
        vecPointY.push_back( point(W, H) );
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            vecPointX.push_back( point(xi, yi) );
            vecPointY.push_back( point(xi, yi) );
        }
        sort( vecPointX.begin(), vecPointX.end(), cmpX );
        sort( vecPointY.begin(), vecPointY.end(), cmpY );
        for (b = 0; b < vecPointX.size(); b++)
        {
            minY = 0;
            maxY = H;
            for (c = b+1; c < vecPointX.size(); c++)
            {
                if ( min(maxY-minY, vecPointX[c].x-vecPointX[b].x) > ans )
                {
                    ans = min(maxY-minY, vecPointX[c].x-vecPointX[b].x);
                    ansX = vecPointX[b].x;
                    ansY = minY;
                }
                if ( vecPointX[c].x > vecPointX[b].x )
                {
                    if ( vecPointX[c].y < vecPointX[b].y )
                    {
                        minY = max( minY, vecPointX[c].y );
                    }
                    else if ( vecPointX[c].y == vecPointX[b].y )
                    {
                        if ( maxY-vecPointX[c].y > vecPointX[c].y-minY )
                        {
                            minY = vecPointX[c].y;
                        }
                        else maxY = vecPointX[c].y;
                    }
                    else if ( vecPointX[c].y > vecPointX[b].y )
                    {
                        maxY = min(maxY, vecPointX[c].y);
                    }
                }
            }
        }
        for (b = 0; b < vecPointY.size(); b++)
        {
            minX = 0;
            maxX = W;
            for (c = b+1; c < vecPointY.size(); c++)
            {
                if ( min(maxX-minX, vecPointY[c].y-vecPointY[b].y) > ans )
                {
                    ans = min(maxX-minX, vecPointY[c].y-vecPointY[b].y);
                    ansX = minX;
                    ansY = vecPointY[b].y;
                }
                if ( vecPointY[c].y > vecPointY[b].y )
                {
                    if ( vecPointY[c].x < vecPointY[b].x )
                    {
                        minX = max( minX, vecPointY[c].x );
                    }
                    else if ( vecPointY[c].x == vecPointY[b].x )
                    {
                        if ( maxX-vecPointY[c].x > vecPointY[c].x-minX )
                        {
                            minX = vecPointY[c].x;
                        }
                        else maxX = vecPointY[c].x;
                    }
                    else if ( vecPointY[c].x > vecPointY[b].x )
                    {
                        maxX = min(maxX, vecPointY[c].x);
                    }
                }
            }
        }
        cout << ansX << " " << ansY << " " << ans << endl;
        if (a < testCases) cout << endl;
    }
    return 0;
}

