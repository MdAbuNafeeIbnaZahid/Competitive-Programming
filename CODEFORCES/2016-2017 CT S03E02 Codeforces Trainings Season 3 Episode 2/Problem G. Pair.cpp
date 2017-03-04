#include <bits/stdc++.h>
using namespace std;
#define SIZE 700009
long long a, b, c, d, e, f, g, h, len, current, ans1, ans2;
long long N, K, ni;
long long given[SIZE], isNotPrime[SIZE];
struct inp
{
    long long num, idx;
    inp(){}
    inp(long long num, long long idx)
    {
        this->num = num;
        this->idx = idx;
    }
    const bool operator < (inp B)
    {
        return num < B.num;
    }
};
vector<inp> vec;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N >> K;
    //cout << "N = " << N << ", K = " << K << endl;
    for (a = 1; a <= K; a++)
    {
        scanf("%lld", &ni);
        given[ni] = 1;
        vec.push_back( inp(ni, a) );
    }
    sort(vec.begin(), vec.end());
    len = vec.size();
    for (a = 0; a < len; a++)
    {
        current = vec[a].num;
        //cout << "current = " << current << endl;
        for (b = 2*current; b <= N; b+=current)
        {
            if ( given[b] )
            {
                ans1 = vec[a].idx;
                break;
            }
        }
        if ( b <= N ) break;
    }
    if ( a >= len )
    {
        cout << 0 << " " << 0;
        return 0;
    }
    for (a = 0; a < len; a++)
    {
        if ( vec[a].num % current==0   && vec[a].num != current )
        {
            ans2 = vec[a].idx;
        }
    }

    if ( ans1 > ans2 )
    {
        ans1 = ans1 ^ ans2;
        ans2 = ans1 ^ ans2;
        ans1 = ans1 ^ ans2;
    }
    cout << ans1 << " " << ans2 ;

    return 0;
}
