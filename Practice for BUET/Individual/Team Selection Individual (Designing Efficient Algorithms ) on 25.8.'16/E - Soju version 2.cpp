#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long T, n, xi, yi, m;
long long a, b, c, d, e, f, g, h, ICar[2*SIZE], PCar[2*SIZE], ans;
struct coOrd
{
    long long x, y;
    coOrd(){}
    coOrd(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
};
bool cmpX(coOrd a, coOrd b)
{
    if ( a.x == b.x ) return a.y < b.y;
    return a.x<b.x;
}
bool cmpY(coOrd a, coOrd b)
{
    if ( a.y == b.y ) return a.x < b.x;
    return a.y < b.y;
}
long long dist(coOrd a, coOrd b)
{
    return abs(a.x-b.x)+abs(a.y-b.y);
}
vector<coOrd> ICpoints, PCpoints;
long long recMinDist(vector<coOrd>ICvec, vector<coOrd>PCvec)
{
    long long a, b, c, d, e, f, g, len, midY, ret = INT_MAX, leftMinDist, rightMinDist;;
    long long appMinDist, midMinDist, lenIC, lenPC;
    vector<coOrd> leftICvec, rightICvec, leftPCvec, rightPCvec, stripICvec, stripPCvec;
    if ( ICvec.size()==0 || PCvec.size()==0 ) return INT_MAX;
    if ( ICvec.size() * PCvec.size() <= 36 )
    {
        lenIC = ICvec.size();
        lenPC = PCvec.size();
        for (a = 0; a < lenIC; a++)
        {
            for (b = 0; b < lenPC; b++)
            {
                ret = min(ret, dist(ICvec[a], PCvec[b]) );
            }
        }
        return ret;
    }
    if ( ICvec.size() == 1 )
    {
        len = PCvec.size();
        for (a = 0; a < len; a++)
        {
            ret = min(ret, dist(ICvec[0], PCvec[a]) );
        }
        return ret;
    }
    if ( PCvec.size() == 1 )
    {
        len = ICvec.size();
        for (a = 0; a < len; a++)
        {
            ret = min(ret, dist(PCvec[0], ICvec[a]));
        }
        return ret;
    }
    len = ICvec.size();
    midY = ICvec[ (len/2)-1 ].y;
    for (a = 0; a < len; a++)
    {
        if ( ICvec[a].y <= midY ) leftICvec.push_back( ICvec[a] );
        else rightICvec.push_back( ICvec[a] );
    }
    len = PCvec.size();
    for (a = 0; a < len; a++)
    {
        if ( PCvec[a].y <= midY ) leftPCvec.push_back( PCvec[a] );
        else rightPCvec.push_back( PCvec[a] );
    }
    leftMinDist = recMinDist(leftICvec, leftPCvec);
    rightMinDist = recMinDist(rightICvec, rightPCvec);
    appMinDist = min(leftMinDist, rightMinDist);
    lenIC = ICvec.size();
    for (a = 0; a < lenIC; a++)
    {
        if ( abs(ICvec[a].y-midY) < appMinDist ) stripICvec.push_back( ICvec[a] );
    }
    lenPC = PCvec.size();
    for (a = 0; a < lenPC; a++)
    {
        if ( abs(PCvec[a].y-midY) < appMinDist ) stripPCvec.push_back( PCvec[a] );
    }
    midMinDist = recMinDist(stripICvec, stripPCvec);
    ret = min(appMinDist, midMinDist);
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ICpoints = vector<coOrd>();
        PCpoints = vector<coOrd>();
        for (b = 0; b < 2*SIZE; b++)
        {
            ICar[b] = INT_MIN;
            PCar[b] = INT_MAX;
        }
        cin >> n;
        for (b = 1; b <= n;b++)
        {
            scanf("%lld %lld", &xi, &yi);
            ICar[yi+SIZE] = max(ICar[yi+SIZE], xi);
        }
        cin >> m;
        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            PCar[yi+SIZE] = min(PCar[yi+SIZE], xi);
        }
        for (b = 0; b < 2*SIZE; b++)
        {
            if ( ICar[b] > INT_MIN ) ICpoints.push_back( coOrd(ICar[b], b-SIZE) );
            if ( PCar[b] < INT_MAX ) PCpoints.push_back( coOrd(PCar[b], b-SIZE) );
        }
        ans = recMinDist(ICpoints, PCpoints);
        cout << ans << endl;
    }
    return 0;
}
