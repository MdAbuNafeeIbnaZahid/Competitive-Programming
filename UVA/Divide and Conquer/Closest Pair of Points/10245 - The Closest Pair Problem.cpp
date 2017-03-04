#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
int N;
double ans, x, y;
int i, j, k;
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
point Px[SIZE], Py[SIZE];
bool cmpX(point a, point b)
{
    if (a.x==b.x) return a.y<b.y;
    return a.x<b.x;
}
bool cmpY(point a, point b)
{
    if (a.y==b.y) return a.x<b.x;
    return a.y<b.y;
}
double getDist(point a, point b)
{
    return sqrt( (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) );
}
double getMinDistInStripe(point *ar, int len, double dis)
{
    double ret = dis;
    int i, j, k;
    for (i = 0; i < len; i++)
    {
        for (j= i+1; j < len && abs(ar[j].y-ar[i].y)<dis; j++)
            ret = min(ret, getDist(ar[i], ar[j]) );
    }
    return ret;
}
double getMinDistBruteForce(point *ar, int len)
{
    double ret = FLT_MAX;
    for (i = 0; i < len; i++)
    {
        for (j = i+1; j < len; j++)
        {
            ret = min(ret, getDist(ar[i], ar[j]) );
        }
    }
    return ret;
}
double getMinDist(point *Px, point *Py, int len)
{
    double ret = FLT_MAX, lDist, rDist;
    int i, j, k, m, mid = (len-1)/2, lIdx = 0, rIdx = 0, n = 0;
    point stripe[len+1], midPoint = Px[mid];
//    cout << "getMinDist called " << endl;
//    cout << "len = " << len << endl;
//    cout << "Px " << endl;
//    for (i = 0; i < len; i++)
//    {
//        cout << Px[i].x << " " << Px[i].y << endl;
//    }
//    cout << "Py " << endl;
//    for (i = 0; i < len; i++)
//    {
//        cout << Py[i].x << " " << Py[i].y << endl;
//    }
//    cout << "midPoint " << midPoint.x << " " << midPoint.y << endl;
    if (len < 5) return getMinDistBruteForce(Px, len);
    point Pyl[mid+1];
    point Pyr[len-mid+1];
    for (i = 0; i < len; i++)
    {
//        cout << "Py[i].x = " << Py[i].x << endl;
//        cout << "midPoint.x = " << midPoint.x << endl;
        if ( Py[i].x < midPoint.x )
        {
            Pyl[lIdx] = Py[i];
            lIdx++;
        }
        else if (Py[i].x > midPoint.x)
        {
            Pyr[rIdx] = Py[i];
            rIdx++;
        }
    }
//    cout << "lIdx = " << lIdx << endl;
//    cout << "rIdx = " << rIdx << endl;
    lDist = getMinDist(Px, Pyl, lIdx);
    rDist = getMinDist(Px+mid+1, Pyr, rIdx);
//    cout << "lDist = " << lDist << endl;
//    cout << "rDist = " << rDist << endl;
    ret = min( lDist, rDist);
    n = 0;
    for (i = 0; i < len; i++)
    {
        if ( abs(Py[i].x-midPoint.x)<ret )
        {
            stripe[n++] = Py[i];
        }
    }
    ret = min( ret, getMinDistInStripe(stripe, n, ret) );
    return ret;
}
int main()
{
    freopen("dataSet.txt", "r", stdin);
    while(1)
    {
        cin >> N;
        if (N==0) break;
        for (i = 0; i < N; i++)
        {
            scanf("%lf %lf", &x, &y);
            Px[i] = point(x, y);
            Py[i] = point(x, y);
        }
        sort(Px, Px+N, cmpX);
        sort(Py, Py+N, cmpY);
        ans = getMinDist(Px, Py, N);
        if (ans >=  10000) cout << "INFINITY" << endl;
        else printf("%.4lf\n", ans);
    }
    return 0;
}
