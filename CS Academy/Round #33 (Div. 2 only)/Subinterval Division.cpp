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
#define LL long long
/******   END OF HEADER *********/
#define eps 0.00000001
#define SIZE 100009
LL N, X;
double ansAr[SIZE], upto = 0;
struct point
{
    double x, y;
    LL idx;
    point(){}
    point(double x, double y, LL idx)
    {
        this->x = x;
        this->y = y;
        this->idx = idx;
    }
    bool operator < ( const point B ) const
    {
        if ( x == B.x )
        {
            return y < B.y;
        }
        return x < B.x;

    }
};
set<point> setPoint;

double getSqDis(point A, point B)
{
    return (A.x-B.x)*(A.x-B.x) + (A.y-B.y)*(A.y-B.y);
}

double getD(point A, point B)
{
    point lastPoint = point(X, 0, 0);
    if ( getSqDis(A, lastPoint) < getSqDis(B, lastPoint) )
    {
        return -2;
    }
    double minVal = upto, maxVal = X, midVal;
    cout << "minVal = " << minVal << endl;
    cout << "maxVal = " << maxVal << endl;
    while( abs(minVal-maxVal) > eps )
    {
        cout << "minVal = " << minVal << endl;
        cout << "maxVal = " << maxVal << endl;
        midVal = (minVal+maxVal) / 2;
        cout << "midVal = " << midVal << endl;
        point midPoint = point(midVal, 0, 0);
        double aDis = getSqDis(A, midPoint);
        cout << "aDis = " << aDis <<endl;
        double bDis = getSqDis(B, midPoint);
        cout << "bDis = " << bDis << endl;
        double sqDisDif = aDis - bDis;
        cout << "sqDisDif = " << sqDisDif << endl;
        if ( sqDisDif < -eps )
        {
            minVal = midVal;
        }
        else if ( sqDisDif > eps )
        {
            maxVal = midVal;
        }
        else
        {
            return midVal;
        }
    }
    return minVal;
}

int main()
{
    freopen("input.txt", "r", stdin);
    LL a, b, c, d, e, f;
    cin >> N >> X;
    cout << "N = " << N << ", X = " << X << endl;
    for (a = 1; a <= N; a++)
    {
        cout << "a = " << a << endl;
        LL x, y;
        scanf("%lld %lld", &x, &y);
        setPoint.insert( point(x, y, a) );
        cout << "setPoint.size() = " << setPoint.size() << endl;
        ansAr[a] = 0;
    }
    point firP, secP;
    while( setPoint.size() )
    {
        firP = *setPoint.begin();
        cout << "firP" << endl;
        cout << firP.x << " " << firP.y << " " << firP.idx << endl;
        setPoint.erase( setPoint.begin() );
        while( setPoint.size() )
        {
            secP = *setPoint.begin();
            cout << "secP" << endl;
            cout << secP.x << " " << secP.y << " " << secP.idx << endl;
            double myD = getD(firP, secP);
            cout << "myD = " << myD << endl;
            if ( myD < -1 )
            {
                setPoint.erase( setPoint.begin() );
            }
            else
            {
                ansAr[ firP.idx ] = myD - upto;
                upto = myD;
                break;
            }
        }
    }
    ansAr[ firP.idx ] = X-upto;
    for (a = 1; a <= N; a++)
    {
        if ( ansAr[ a ] <= eps )
        {
            ansAr[ a ] = 0;
        }

        printf("%0.9lf\n", ansAr[a]);
    }
    return 0;
}
