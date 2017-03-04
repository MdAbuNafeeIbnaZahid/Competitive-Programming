#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
int T, N, i, j, k, m, a, c, s, mul, current;
bool mark[SIZE];
map<int, int> pf[SIZE];
vector<int> primes;
map<int, int>::iterator it, b, e;
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    primes.push_back(2);
    for (i = 4; i <= 100; i+=2)
    {
        mark[i] = false;
    }
    for (i = 3; i <= 100; i++)
    {
        if (mark[i])
        {
            primes.push_back(i);
            for (j = i*i; j <= 100; j+=(2*i) )
            {
                mark[j] = false;
            }
        }
    }
    s = primes.size();
    for (i = 2; i <= 100; i++)
    {
        current = i;
        for (j = 0; j < s; j++)
        {
            if (primes[j]*primes[j]>current) break;
            mul = 0;
            while( current%primes[j]==0 )
            {
                mul++;
                current/=primes[j];
            }
            pf[i][ primes[j] ] = mul;
        }
        if (current!=1) pf[i][current] = 1;
    }
    for (i = 2; i <= 99; i++)
    {
        for (it = pf[i].begin(); it!=pf[i].end(); it++)
        {
            pf[i+1][it->first] += pf[i][it->first];
        }
    }
    scanf("%d", &T);
    for (i = 1; i <= T; i++)
    {
        scanf("%d", &N);
        printf("Case %d: %d = ", i, N);
        b = pf[N].begin();
        e = pf[N].end();
        for (it=b; it!=e; it++)
        {
            if (it!=b) printf(" * ");
            printf("%d (%d)", it->first, it->second);
        }
        printf("\n");
    }
    return 0;
}
