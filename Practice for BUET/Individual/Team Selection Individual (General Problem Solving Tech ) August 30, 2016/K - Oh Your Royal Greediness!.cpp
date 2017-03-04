#include <bits/stdc++.h>
using namespace std;
long long N, S, E;
long long a, b, c, d, e, f, g, testCases, len, ans, current;
struct pivot
{
    long long idx, change;
    pivot(){}
    pivot(long long idx, long long change)
    {
        this->idx = idx;
        this->change = change;
    }
};
vector<pivot> vecPiv;
bool cmp(pivot a, pivot b)
{
    if ( a.idx == b.idx )
    {
        return a.change < b.change;
    }
    return a.idx < b.idx;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> N;
        if (N==-1) return 0;
        testCases++;
        vecPiv = vector<pivot>();
        ans = 0;
        current = 0;
        for (a = 1; a <= N; a++)
        {
            scanf("%lld %lld", &S, &E);
            vecPiv.push_back( pivot(S, +1) );
            vecPiv.push_back( pivot(E+1, -1) );
        }
        sort(vecPiv.begin(), vecPiv.end(), cmp);
        len = vecPiv.size();
        for (a = 0; a< len; a++)
        {
            current += vecPiv[a].change;
            ans = max(ans, current);
        }
        cout << "Case " << testCases << ": " << ans << endl;
    }
    return 0;
}
