#include <bits/stdc++.h>
using namespace std;
long long testCases, N, W, H, xi, yi;
long long a, b, c, d, e, f, g, h, len, ans, ansX, ansY;
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
    freopen("output.txt", "w", stdout);
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
        cout << "sorted x " << endl;
        for (b = 0; b < vecPointX.size(); b++)
        {
            cout << "(" << vecPointX[b].x << "," << vecPointX[b].y << ") ";
        }
        cout << endl;
        cout << "sorted y";
        for (b = 0; b < vecPointY.size(); b++)
        {
            cout << "(" << vecPointY[b].x << "," << vecPointY[b].y << ") ";
        }
        cout << endl;
        cout << "vecPointX.size() = " << vecPointX.size() << endl;
        cout << "vecPointY.size() = " << vecPointY.size() << endl;
        for (b = 0; b < vecPointX.size(); b++)
        {
            cout << endl;
            cout << "b = " << b << endl;
            cout << "b.x = " << vecPointX[b].x << endl;
            cout << "b.y = " << vecPointX[b].y << endl;
            for (c = b+1; c < vecPointX.size(); c++)
            {
                cout << endl;
                cout << "c = " << c << endl;
                cout << "c.x = " << vecPointX[c].x << endl;
                cout << "c.y = " << vecPointX[c].y << endl;
                strip = vector<point>();
                for (d = 0; d < vecPointY.size(); d++)
                {
                    if ( vecPointX[b].x < vecPointY[d].x &&
                        vecPointY[d].x < vecPointX[c].x  )
                    {
                        strip.push_back( vecPointY[d] );
                    }
                }
                if ( strip.size() == 0 )
                {
                    ans = max(ans, min(H, vecPointX[c].x-vecPointX[b].x) );
                }
                for (d = 0; d < strip.size(); d++)
                {
                    cout << "d = " << d << endl;
                    cout << "d.x = " << strip[d].x << endl;
                    cout << "d.y = " << strip[d].y << endl;
                    if ( d == 0 )
                    {
                        ans = max(ans, min(vecPointX[c].x-vecPointX[b].x, strip[d].y) );
                    }
                    else
                    {
                        ans = max(ans, min(vecPointX[c].x-vecPointX[b].x, strip[d].y-strip[d-1].y) );
                    }
                    if ( d == strip.size()-1 )
                    {
                        ans = max(ans, min(vecPointX[c].x-vecPointX[b].x, H-strip[d].y) );
                    }
                    else
                    {
                        ans = max(ans, min(vecPointX[c].x-vecPointX[b].x, strip[d+1].y-strip[d].y) );
                    }
                    cout << "ans = " << ans << endl;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
