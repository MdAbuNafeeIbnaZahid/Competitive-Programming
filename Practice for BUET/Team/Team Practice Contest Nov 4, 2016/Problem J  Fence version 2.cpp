#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
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
long long n, xi, yi, a, b, difX, difY;
long long i, j, k, p, q, r;
bool cmpPoint(point A, point B)
{
    if ( A.x == B.x )
    {
        return A.y < B.y;
    }
    return A.x < B.x;
}
vector<point> vecPoint, conHull;
long long crossPr(point A, point B)
{
    long long ret = A.x*B.y - A.y*B.x;
    return ret;
}
vector<point> findConHull(vector<point> givenPoints)
{
    long long a, b, c, d, e, f, t, len = givenPoints.size(), siz;
    vector<point> ret;
    sort(givenPoints.begin(), givenPoints.end());
    for (a = 0;a < len; a++)
    {
        siz = ret.size();
        while( siz >= 2 && crossPr(ret[siz-1]-ret[siz-2], givenPoints[a]-ret[siz-2]) <= 0 )
        {
            ret.pop_back();
            siz = ret.size();
        }
        ret.push_back( givenPoints[a] );
    }
    ret.pop_back();
    t = ret.size();
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
//    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> n;
        if (n==0) return 0;
        vecPoint = vector<point>();
        a = b = 0;;
        for (p = 1; p <= n; p++)
        {
            scanf("%lld %lld", &xi, &yi);
            vecPoint.push_back( point(xi, yi) );

        }
        sort(vecPoint.begin(), vecPoint.end(), cmpPoint);
        conHull = findConHull(vecPoint);
        for (p = 0; p < conHull.size(); p++)
        {
            //cout << "p = " << p << endl;
            difX = abs( conHull[p].x - conHull[ (p+1)%conHull.size() ].x );
            //cout << "difX = " << difX << endl;
            difY = abs( conHull[p].y - conHull[ (p+1)%conHull.size() ].y );
            //cout << "difY = " << difY << endl;
            b += min(difX, difY);
            a += (difX+difY- 2*min(difX, difY) );
        }
        //if (a+b==0)
        //{
            //a = 2;
        //}
        cout << a << " " << b << endl;
    }
    return 0;
}
