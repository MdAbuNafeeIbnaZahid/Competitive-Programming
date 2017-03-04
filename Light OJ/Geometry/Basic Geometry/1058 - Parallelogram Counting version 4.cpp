#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, n, x, y;
long long a, b, c, d, e, f, g, h;
long long xAr[SIZE], yAr[SIZE], ans, cnt, len;
struct point
{
    long long x, y;
    point(){}
    point(long long x, long long y)
    {
        this->x = x;
        this->y = y;
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
vector<point> vecPoint;
map<point, long long> myMap;
map<point, long long>::iterator mapIt;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        myMap = map<point, long long>();
        vecPoint = vector<point>();
        cin >> n;
        //cout << "n = " << n << endl;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld", &xAr[b], &yAr[b]);
        }
        for (b = 1; b <= n; b++)
        {
            for (c = b+1; c <= n; c++)
            {
                //myMap[ point(xAr[b]+xAr[c], yAr[b]+yAr[c]) ] ++;
                vecPoint.push_back( point(xAr[b]+xAr[c], yAr[b]+yAr[c]) );
            }
        }
        sort(vecPoint.begin(), vecPoint.end());
        len = vecPoint.size();
        cnt = 0;
        //cout << "b = 0" << endl;
        //cout << "x = " << vecPoint[0].x << ", y = " << vecPoint[0].y << endl;
        for (b = 1; b < len; b++)
        {
            //cout << "b = " << b << endl;
            //cout << "x = " << vecPoint[b].x << ", y = " << vecPoint[b].y << endl;
            //cout << "cnt = " << cnt << endl;
            //cout << "ans = " << ans << endl;
            if ( vecPoint[b].x == vecPoint[b-1].x && vecPoint[b].y == vecPoint[b-1].y )
            {
                cnt++;
            }
            else
            {
                ans += (cnt*(cnt+1))/2;
                cnt = 0;
            }
            //cout << "cnt = " << cnt << endl;
            //cout << "ans = " << ans << endl;
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
