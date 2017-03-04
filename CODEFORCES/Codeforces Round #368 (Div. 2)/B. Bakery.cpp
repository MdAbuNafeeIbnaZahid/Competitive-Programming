#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, m, u, v, l, k, ui[SIZE], vi[SIZE], li[SIZE], ai, isStore[SIZE];
set<long long> setL;
long long a,b, c, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld %lld", &ui[a], &vi[a], &li[a]);
    }
    for (a = 1; a <= k; a++)
    {
        scanf("%lld", &ai);
        isStore[ai] = 1;
    }
    for (a = 1; a <= m; a++)
    {
        if ( isStore[ui[a] ]  ^ isStore[ vi[a] ] )
        {
            setL.insert( li[a] );
        }
    }
    if ( setL.size() ) cout << (*setL.begin() );
    else cout << -1;
    return 0;
}
