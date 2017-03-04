#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
bool mark[1000009];
long long T, N, i, j, k, ans, s, mul, a, b, c, d, e;
vector<long long> v;
vector<long long> pf[SIZE];
long long getDiv(vector<long long> v)
{
    int s = v.size(), i, j, ret = 1;
    if (s==0) return 1;
    for (i = 0; i < s; i++) ret *= (v[i]+1);
    ret--;
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    for (i = 2; i <= sqrt(SIZE+1) ; i++)
    {
        if (mark[i])
        {
            a = 1;
            b = i;
            for (j = 2*i; j < 1000009; j+=i )
            {
                mark[j] = false;
                if (b*i==j)
                {
                    a++;
                    b*=i;
                }
                pf[j].push_back(a);
                if (j==24)
                {
                    cout << "i = " << i << ", a = " << a << endl;
                }
            }
        }
    }
    //for (i = 2; i < 1000009; i++)
    //{
        //if ( mark[i] ) v.push_back(i);
    //}
    //s = v.size();
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lld", &N);
        if (N==1) printf("Case %lld: %lld\n", i, 0);
        else
        {
            ans = getDiv(pf[N]);
            printf("Case %lld: %lld\n", i, ans);
        }
    }
    return 0;
}
