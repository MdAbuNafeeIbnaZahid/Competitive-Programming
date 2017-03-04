#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, k, a, m, x[SIZE];
long long b, c, d, e, f, possibleAc, sub, add, startIdx, endIdx;
set<long long> shotSet;
set<long long>::iterator setLLIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> k >> a;
    cin >> m;
    for (b = 1; b <= m; b++)
    {
        scanf("%lld", &x[b]);
    }
    shotSet.insert(0);
    shotSet.insert(n+1);
    possibleAc = n/(a+1) + (n%(a+1))/a;
    for (b = 1; b <= m; b++)
    {
        setLLIt = shotSet.lower_bound( x[b] );
        if( *setLLIt == x[b] ) continue;
        setLLIt = shotSet.lower_bound( x[b] );
        setLLIt--;
        startIdx = *( setLLIt );
        endIdx = *(shotSet.upper_bound( x[b] ));
        sub = (endIdx-startIdx-1)/(a+1) + ((endIdx-startIdx-1)%(a+1))/a;
        add = (x[b]-startIdx-1)/(a+1) + ((x[b]-startIdx-1)%(a+1))/a +
                (endIdx-x[b]-1)/(a+1) + ((endIdx-x[b]-1)%(a+1))/a;
        possibleAc = possibleAc - sub + add;
        shotSet.insert( x[b] );
        if (possibleAc < k)
        {
            cout << b << endl;
            return 0;
        }
    }
    cout << -1 << endl;
    return 0;
}
