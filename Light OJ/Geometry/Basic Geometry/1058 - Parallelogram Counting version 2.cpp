#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define eps 0.000000001
long long T, n;
long long a, b, c, d, e, f, g, len, ans;
double x, y;
struct point
{
    double x, y;
    point(){}
    point(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};
struct lineSegment
{
    double len, midX, midY;
    lineSegment(){}
    lineSegment(point A, point B)
    {
        len = sqrt( (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y) );
        midX = (A.x + B.x)/2;
        midY = (A.y + B.y)/2;
    }
    const bool operator < (lineSegment B) const
    {
        if ( abs(len-B.len) <= eps )
        {
            if ( abs(midX-B.midX) <= eps )
            {
                return midY < B.midY + eps;
            }
            return midX < B.midX + eps;
        }
        return len < B.len+eps;
    }
};
vector<point> vecPoint;
vector<lineSegment> vecLine;
map<lineSegment, long long> myMap;
map<lineSegment, long long>::iterator mapIt;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        vecPoint = vector<point>();
        vecLine = vector<lineSegment>();
        myMap = map<lineSegment, long long>();
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lf %lf", &x, &y);
            vecPoint.push_back( point(x, y) );
        }
        for (b = 0; b < n; b++)
        {
            for (c = b+1; c < n; c++)
            {
                vecLine.push_back( lineSegment( vecPoint[b], vecPoint[c] ) );
            }
        }
        len = vecLine.size();
        for (b = 0; b < len; b++)
        {
            cout << "b = " << b << endl;
            cout << "len = " << vecLine[b].len << endl;
            cout << "midX = " << vecLine[b].midX << endl;
            cout << "midY = " << vecLine[b].midY << endl;
            myMap[ vecLine[b] ]++;
        }
        for (mapIt = myMap.begin(); mapIt !=myMap.end(); mapIt++)
        {
            ans += ( mapIt->second * (mapIt->second-1) );
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
