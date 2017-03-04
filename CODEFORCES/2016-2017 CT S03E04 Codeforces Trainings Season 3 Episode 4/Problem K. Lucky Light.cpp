#include <bits/stdc++.h>
using namespace std;
#define eps 0.00001
long long testCases, n;
double xl, yl, xi, yi, ui, vi, sx, ex, pos1, pos2;
double t, upto;
long long a, b, c, d, e, f, g, len, cnt, ans;
struct shadow
{
    double sx, ex;
    shadow(){}
    shadow(double sx, double ex)
    {
        this->sx = sx;
        this->ex = ex;
    }
};
vector<shadow> vecSha;
double AtoB(double xl, double yl, double xi, double yi)
{
    double t, ret;
    t = yl / (yl - yi);
    ret = xl + (xi-xl) * t;
    return ret;
}
bool cmpF(shadow A, shadow B)
{
    if ( abs(A.sx- B.sx) <= eps )
    {
        return A.ex < B.ex + eps;
    }
    return A.sx < B.sx+eps;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> testCases;
    //cout << "testCases = " << testCases << endl;
    for (a = 1; a <= testCases; a++)
    {
        cnt = 0;
        vecSha = vector<shadow>();
        cin >> n;
        //cout << "n = " << n << endl;
        cin >> xl >> yl;
        for (b = 1; b <= n; b++)
        {
            scanf("%lf %lf %lf %lf", &xi, &yi, &ui, &vi);
            pos1 = AtoB(xl, yl, xi, yi);
            pos2 = AtoB(xl, yl, ui, vi);
            sx = min(pos1, pos2);
            ex = max(pos1,pos2);
            vecSha.push_back( shadow(sx, ex) );
        }
        len = vecSha.size();
        sort(vecSha.begin(), vecSha.end(), cmpF);
        cnt = 1;
        if (len == 0)
        {
            cout << 1 << endl;
            continue;
        }
        if ( len > 0 )
        {
            upto = vecSha[0].ex;
        }
        for (b = 1; b < len; b++)
        {
            if ( vecSha[b].sx > upto + eps )
            {
                cnt++;
            }
            upto = max(upto, vecSha[b].ex);
        }
        ans = cnt+1;
        cout << ans << endl;
    }
    return 0;
}
