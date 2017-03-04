#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long testCases;
long long a,b, c, d, e, f, g;
long long N, W, H, Xi, Yi;
long long xCnt[SIZE], yCnt[SIZE];
long long x1, y1, x2, y2, ansX, ansY, ans, posAns, posX, posY;
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
vector<point> vecP;
binSearch(long long x, long long y, long long xSign, long long ySign)
{
    long long a, b, c, d, e, f, g, h, len;
    long long lowerVal = 1, upperVal = INT_MAX, midVal;
    long long newX, newY, xTree, yTree;
    while(lowerVal < upperVal)
    {
        midVal = (lowerVal+upperVal)/2;
        newX = x + midVal*xSign;
        newY = y + midVal*ySign;
        xTree = xCnt[] - xCnt[];
        yTree = yCnt
        if ( newX <0 || newX > W || newY < 0 || newY > H )
        {

        }
        else if ()
    }
}
int main()
{
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        ans = 0;
        vecP = vector<point>();
        memset(xCnt, 0, sizeof(xCnt) );
        memset(yCnt, 0, sizeof(yCnt) );
        cin >> N >> W >> H;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lld", &Xi, &Yi);;
            xCnt[Xi]++;
            yCnt[Yi]++;
            vecP.push_back( point(Xi, Yi) );
        }
        for (b = 1; b < SIZE; b++)
        {
            xCnt[b] += xCnt[b-1];
            yCnt[b] += yCnt[b-1];
        }
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < c; c++)
            {
                x1 = vecP[b].x;
                y1 = vecP[b].y;
                x2 = vecP[c].x;
                y2 = vecP[c].y;
            }
        }
    }
    return 0;
}
