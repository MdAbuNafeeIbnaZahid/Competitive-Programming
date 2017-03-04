#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
#define WHITE 0
#define GRAY 1
#define BLACK 2
long long n, m, k, cAr[SIZE], li, ri;
long long ans, color[SIZE], sizeOfGraph, cntAr[SIZE], maxColCnt;
long long a, b, c, d, e, f, g, h;
vector<long long> gr[SIZE], verticesPresent;
set<long long> presentInstruction;
set<long long>::iterator setLLIt;
long long dfsSize(long long u)
{
    long long a, b, c, d, e, f, ret = 0;
    if ( color[u] != WHITE )
    {
        return ret;
    }
    color[u] = GRAY;
    for (a = 0; a < gr[u].size(); )
    {
        ret += dfsSize( gr[u][a] );
    }
    return ret+1;
    color[u] = BLACK;
}
void findAllVertices(long long u)
{
    long long a, b, c, d, e, f, g;
    if ( color[u] != WHITE )
    {
        return;
    }
    color[u] = GRAY;
    verticesPresent.push_back( u );
    for (a = 0; a < gr[u].size(); a++)
    {
        if ( color[gr[u][a] ] != WHITE )
        {
            continue;
        }
        findAllVertices( gr[u][a] );
    }
    color[u] = BLACK;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &cAr[a]);
    }
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld", &li, &ri);
        gr[li].push_back(ri);
        gr[ri].push_back(li);
//        presentInstruction.insert(li);
//        presentInstruction.insert(ri);
    }
    //for (setLLIt = prese)
    for (a = 1; a <= n; a++)
    {
        if ( color[a] != WHITE )
        {
            continue;
        }
        verticesPresent = vector<long long>();
        maxColCnt = 0;
        findAllVertices( a );
        for (b = 0; b < verticesPresent.size(); b++)
        {
            cntAr[ cAr[ verticesPresent[b] ] ] = 0;
        }
        for (b = 0; b < verticesPresent.size(); b++)
        {
            cntAr[ cAr[ verticesPresent[b] ] ]++;
        }
        for (b = 0; b < verticesPresent.size(); b++)
        {
            maxColCnt = max( maxColCnt, cntAr[ cAr[ verticesPresent[b] ] ] );
        }
        ans += ( verticesPresent.size() - maxColCnt );
    }
    cout << ans;
    return 0;
}
