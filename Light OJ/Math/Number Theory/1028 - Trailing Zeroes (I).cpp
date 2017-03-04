#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
bool mark[1000009];
long long T, N, i, j, k, ans, s, mul, a, b, c, d, e;
vector<long long> v;
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    for (i = 2; i <SIZE ; i++)
    {
        if (mark[i])
        {
            v.push_back(i);
            for (j = i*i; j < 1000009; j+=(2*i) )
            {
                mark[j] = false;
            }
        }
    }
    s = v.size();
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        scanf("%lld", &N);
        if (N==1) printf("Case %lld: %lld\n", i, 0);
        else
        {
            ans = 1;
            for (j = 0; j<s && N!=1; j++)
            {
                if (v[j]*v[j]>N) break;
                mul = 0;
                while(N%v[j]==0)
                {
                    mul++;
                    N/=v[j];
                }
                ans *= (mul+1);
            }
            if (N!=1) ans*=2;
            printf("Case %lld: %lld\n", i, ans-1);
        }
    }
    return 0;
}
