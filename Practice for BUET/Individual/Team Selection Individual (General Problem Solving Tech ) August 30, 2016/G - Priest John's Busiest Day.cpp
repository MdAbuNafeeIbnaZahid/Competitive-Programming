#include <bits/stdc++.h>
using namespace std;
long long N, Si, Ti;
long long a, b, c, d, e, f, g, h, upto;
struct interval
{
    long long s, e;
    interval(){}
    interval(long long s, long long e)
    {
        this->s = s;
        this->e = e;
    }
};
vector<interval> vecIn;
bool cmp(const interval a, const interval b)
{
    if (a.s==b.s) return a.e<b.e;
    return a.s<b.s;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> N;
        if (N==0) return 0;
        vecIn = vector<interval>();
        upto = 0;
        for (a = 1; a <= N; a++)
        {
            scanf("%lld %lld", &Si, &Ti);
            vecIn.push_back( interval(Si, Ti) );
        }
        sort(vecIn.begin(), vecIn.end(), cmp);
        for (a = 0; a < N; a++)
        {
            upto = max(upto, vecIn[a].s ) + (vecIn[a].e-vecIn[a].s)/2 + 1;
            if (upto > vecIn[a].e) break;
        }
        if (a<N) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
