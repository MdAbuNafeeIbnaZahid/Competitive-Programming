#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long T, a, b, L, c;
long long i, j, k, lcm, s, lcmCount, Lcount;
long long gcd(long long a, long long b)
{
    if (a>b) return gcd(b, a);
    if (a==0) return b;
    return gcd(b%a, a);
}
vector<long long> primes;
bool mark[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    primes.push_back(2);
    for (i = 4; i < SIZE; i+=2)
    {
        mark[i] = false;
    }
    for (i = 3; i < SIZE; i++)
    {
        //cout << "i = " << i << endl;
        if ( mark[i] )
        {
            primes.push_back(i);
            for (j = i*i; j<SIZE; j+=(2*i) )
            {
                //cout << "j = " << j << endl;
                mark[j] = false;
            }
        }
    }
    s = primes.size();
    //for (i = 0; i < 30; i++) cout << primes[i] << " ";
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        c = 1;
        cin >> a >> b >> L;
        lcm = (a*b/gcd(a, b));
        if (L%lcm!=0)
        {
            cout << "Case " << i << ": impossible" << endl;
            continue;
        }
        for (j = 0; j < s; j++)
        {
            lcmCount = Lcount = 0;
            while(lcm%primes[j]==0)
            {
                lcm/=primes[j];
                lcmCount++;
            }
            while(L%primes[j]==0)
            {
                L/=primes[j];
                Lcount++;
            }
            if (Lcount>lcmCount)
            {
                for (k = 1; k <= Lcount; k++)
                {
                    c*=primes[j];
                }
            }
        }
        if (L>1) c*= L;
        cout << "Case " << i << ": " << c << endl;
    }
    return 0;
}
