#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, aAr[SIZE], consSum[SIZE], per[SIZE];
long long a, b, c, d, e, f, current, before, after, ans;
struct info
{
    long long si, ei, su;
    info(){}
    info(long long si, long long ei, long long su)
    {
        this->si = si;
        this->ei = ei;
        this->su = su;
    }
    const bool operator < ( info B ) const
    {
        if ( su == B.su )
        {
            if ( si == B.si )
            {
                return ei < B.ei;
            }
            return si < B.si;
        }
        return su > B.su;
    }
};
struct seg
{
    long long si, ei;
    seg(){}
    seg(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
    const bool operator - ( seg B ) const
    {
        if ( si == B.si )
        {
            return ei < B.ei;
        }
    }
};
struct ele
{
    long long val;
    ele(){}
    ele(long long val)
    {
        this->val = val;
    }
    const bool operator < ( ele B ) const
    {
        return val > B.val;
    }
};
set<info> setInfo;
map<long long, map<long long, long long> > ifDes;
set<long long> setLL;
set<long long>::iterator setLLIt;
multiset<ele> mulEle;
multiset<ele>::iterator mulEleIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &per[a]);
    }
    for (a = 1; a <= n; a++)
    {
        consSum[a] = consSum[a-1] + aAr[a];
    }
    setInfo.insert( info(1, n, consSum[n]-consSum[0]) );

    setLL.insert(0);
    setLL.insert(n+1);
    mulEle.insert( ele(consSum[n]-consSum[0]) );
    for (a = 1; a < n; a++)
    {
        current = per[a];
        setLLIt = setLL.lower_bound(current);
        after = *setLLIt;
        before = *(--setLLIt);
        mulEleIt = mulEle.find( ele(consSum[after-1] - consSum[before]) );
        mulEle.erase( mulEleIt );
        setLL.insert(current);
        mulEle.insert( ele(consSum[current-1] - consSum[before]) );
        mulEle.insert( ele(consSum[after-1] - consSum[current]) );
        ans = mulEle.begin()->val;
        printf("%lld\n", ans);
    }
    cout << 0;
    return 0;
}
