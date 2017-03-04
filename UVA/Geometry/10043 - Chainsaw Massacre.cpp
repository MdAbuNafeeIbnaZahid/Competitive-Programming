#include <bits/stdc++.h>
using namespace std;
long long testCases, l, w, k;
long long a,b, c, d, e, f, g, x, y, dx, dy, ans, len, maxX, minX, maxY, minY;
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
vector<point> vecPoint;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        vecPoint = vector<point>();
        ans = 0;
        cin >> l >> w;
        while(1)
        {
            scanf("%lld", &k);
            if (k ==0) break;
            else if (k == 1)
            {
                scanf("%lld %lld", &x, &y);
                vecPoint.push_back( point(x, y) );
            }
            else
            {
                scanf("%lld %lld %lld %lld", &x, &y, &dx, &dy);
                for (b = 0; b < k; b++)
                {
                    vecPoint.push_back ( point(x+b*dx, y+b*dy) );
                }
            }
        }
        vecPoint.push_back( point(0, 0) );
        vecPoint.push_back( point(l, 0) );
        vecPoint.push_back( point(0, w) );
        vecPoint.push_back( point(l, w) );
        sort( vecPoint.begin(), vecPoint.end(), cmpX );
        len = vecPoint.size();
        for (b = 0; b < len; b++)
        {
            minY = 0;
            maxY = w;
            for (c = b+1; c < len; c++)
            {
                ans = max(ans, (vecPoint[c].x-vecPoint[b].x)*(maxY-minY));
                if ( vecPoint[c].x == vecPoint[b].x ) continue;
                else
                {
                    if (vecPoint[c].y < vecPoint[b].y)
                    {
                        minY = max(minY, vecPoint[c].y);
                    }
                    else //if ( vecPoint[c].y > vecPoint[b].y )
                    {
                        maxY = min(maxY, vecPoint[c].y);
                    }
                }
            }
        }
        sort(vecPoint.begin(), vecPoint.end(), cmpY);
        for (b = 0; b < len; b++)
        {
            minX = 0;
            maxX = l;
            for (c = b+1; c < len; c++)
            {
                ans = max(ans, (vecPoint[c].y-vecPoint[b].y)*(maxX-minX) );
                if ( vecPoint[c].y == vecPoint[b].y ) continue;
                else
                {
                    if ( vecPoint[c].x < vecPoint[b].x )
                    {
                        minX = max(minX, vecPoint[c].x);
                    }
                    else
                    {
                        maxX = min(maxX, vecPoint[c].x);
                    }
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
