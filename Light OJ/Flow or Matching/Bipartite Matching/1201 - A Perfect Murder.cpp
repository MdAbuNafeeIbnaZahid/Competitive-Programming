#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define LEFT 1
#define RIGHT 2
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, N, M, a, b;
long long side[SIZE], matchedMember[SIZE], layer[SIZE], maxMatch, addee, color[SIZE], ans;
long long c, d, e, f, g, h, i, j;
vector<long long> gr[SIZE];
void dfs1(long long u, long long leftOrRight)
{
    long long a, b, c, d, len = gr[u].size();
    if ( side[u] != 0 ) return;
    side[u] = leftOrRight;
    for (a = 0; a < len; a++)
    {
        if ( leftOrRight == LEFT ) dfs1( gr[u][a], RIGHT );
        else dfs1( gr[u][a], LEFT );
    }
}
void bfs1()
{
    long long a, b, c, d, e, current, len;
    queue<long long> Q;
    for (a = 1; a <= N; a++)
    {
        layer[a] = INT_MAX;
        if ( matchedMember[a] == -1 && side[a] == LEFT )
        {
            layer[a] = 0;
            Q.push(a);
        }
    }
    while( !Q.empty() )
    {
        current = Q.front();
        Q.pop();
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( matchedMember[ gr[current][a] ] != -1 && layer[ matchedMember[ gr[current][a] ] ] == INT_MAX )
            {
                layer[ matchedMember[ gr[current][a] ] ] = layer[current]+1;
                Q.push( matchedMember[ gr[current][a] ] );
            }
        }
    }
}
long long dfs2(long long u)
{
    long long a, b, c, d, e, f, g, len = gr[u].size(), posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( matchedMember[ gr[u][a] ] != -1 && layer[ matchedMember[ gr[u][a] ] ]==layer[u]+1 )
        {
            posRet = dfs2(matchedMember[ gr[u][a] ]);
            if (posRet)
            {
                matchedMember[u] = gr[u][a];
                matchedMember[ gr[u][a] ] = u;
                return 1;
            }
        }
    }
    for (a = 0; a < len; a++)
    {
        if ( matchedMember[ gr[u][a] ] == -1 )
        {
            matchedMember[u] = gr[u][a];
            matchedMember[ gr[u][a] ] = u;
            return 1;
        }
    }
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (c = 1; c <= T; c++)
    {
        cin >> N >> M;
        for (d = 1; d <= N; d++)
        {
            gr[d] = vector<long long>();
            side[d] = 0;
            matchedMember[d] = -1;
        }
        maxMatch = 0;
        for (d = 1; d <= M; d++)
        {
            scanf("%lld %lld", &a, &b);
            gr[a].push_back(b);
            gr[b].push_back(a);
        }
        for (d = 1; d <= N; d++)
        {
            if ( side[d] == 0 ) dfs1(d, LEFT);
        }
        while(1)
        {
            addee = 0;
            bfs1();
            for (d = 1; d <= N; d++)
            {
                color[d] = WHITE;
            }
            for (d = 1; d <= N; d++)
            {
                if ( layer[d] == 0 ) addee += dfs2(d);
            }
            if (addee <= 0) break;
            maxMatch += addee;
        }
        ans = N - maxMatch;
        cout << "Case " << c << ": " << ans << endl;
    }
    return 0;
}
