#include <bits/stdc++.h>
using namespace std;
#define WHITE 0
#define GREY 1
#define BLACK 2
#define SIZE 200009
long long n, ai[SIZE], color[SIZE], head[SIZE], ans, root;
long long a, b, c, d, e, f, g;
set<long long> cycle, nonCycle;
set<long long>::iterator setIt;
long long dfs1(long long u)
{
    if (head[u] != 0) return head[u];
    if ( head[ ai[u] ] != 0 )
    {
        head[u] = head[ ai[u] ];
        return head[u];
    }
    if ( color[ ai[u] ] == GREY )
    {
        head[u] = u;
        return head[u];
    }
    color[u] = GREY;
    head[u] = dfs1( ai[u] );
    color[u] = BLACK;
    return head[u];
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &ai[a]);
    }
    for (a = 1; a <= n; a++)
    {
//        cout << "a = " << a << endl;
        dfs1( a );
    }
    for (a = 1; a <= n; a++)
    {
        if ( ai[ head[a] ] == head[a] )
        {
            nonCycle.insert( head[a] );
        }
        else
        {
            cycle.insert( head[a] );
        }
    }

//    cout << "nonCycle" << endl;
//    for (setIt = nonCycle.begin(); setIt != nonCycle.end(); setIt++)
//    {
//        //ai[ *setIt ] = root;
//        cout << *setIt << endl;
//    }
//    cout << "cycle" << endl;
//    for (setIt = cycle.begin(); setIt != cycle.end(); setIt++)
//    {
//        //ai[ *setIt ] = root;
//        cout << *setIt << endl;
//    }

    ans = cycle.size() + nonCycle.size();
    if ( nonCycle.size() )
    {
        ans--;
        root = *(nonCycle.begin());
    }
    else
    {
        root = *(cycle.begin());
    }
    for (setIt = nonCycle.begin(); setIt != nonCycle.end(); setIt++)
    {
        ai[ *setIt ] = root;
    }
    for (setIt = cycle.begin(); setIt != cycle.end(); setIt++)
    {
        ai[ *setIt ] = root;
    }
    printf("%lld\n", ans);
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", ai[a]);
    }
    return 0;
}
