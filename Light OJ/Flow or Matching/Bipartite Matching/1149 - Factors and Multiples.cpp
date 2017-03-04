#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
#define OFFSET 101
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, n, m, members[SIZE], ans, addee, loopStopper;
long long mathchedMember[SIZE], layer[SIZE], color[SIZE];
long long a,b, c, d, e;
vector<long long> gr[SIZE];
long long getLeft(long long u)
{
    return u;
}
long long getRight(long long u)
{
    return OFFSET+u;
}
void bfs()
{
    long long a, b, c, d, e, current, len;
    queue<long long> Q;
    for (a = 1; a <= n; a++)
    {
        layer[ getLeft(a) ] = INT_MAX;
        if ( mathchedMember[getLeft(a)] == -1 )
        {
            layer[ getLeft(a) ] = 0;
            Q.push( getLeft(a) );
        }
    }
    for (a = 1; a <= m; a++)
    {
        layer[ getRight(m) ] = INT_MAX;
    }
    while( !Q.empty() )
    {
        current = Q.front();
        Q.pop();
        //cout << "current = " << current << endl;
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( mathchedMember[gr[current][a]] != -1 && layer[mathchedMember[gr[current][a]]] == INT_MAX )
            {
                layer[mathchedMember[gr[current][a]]] = layer[current]+1;
                Q.push( mathchedMember[gr[current][a]] );
            }
        }
    }
}
long long dfs1(long long u)
{
    //cout << u << endl;
    long long a, b, c, d, e, len = gr[u].size(), posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;

    for (a = 0; a < len; a++)
    {
        //cout << members[gr[u][a]] << endl;
        if ( mathchedMember[gr[u][a]] != -1 &&  layer[ mathchedMember[gr[u][a]] ] == layer[u]+1  )
        {
            posRet = dfs1( mathchedMember[gr[u][a]] );
            if (posRet)
            {
                mathchedMember[ gr[u][a] ] = u;
                mathchedMember[u] = gr[u][a];
                return 1;
            }
        }
    }
    for (a = 0; a < len; a++)
    {
         if ( mathchedMember[gr[u][a]] == -1 )
         {
            mathchedMember[ gr[u][a] ] = u;
            mathchedMember[u] = gr[u][a];
            return 1;
         }
    }
    color[u] = BLACK;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a =1; a <= T; a++)
    {
        ans = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            gr[getLeft(b)] = vector<long long>();
            mathchedMember[getLeft(b)] = -1;
            scanf("%lld", &members[getLeft(b)]);
        }
        cin >> m;
        for (b = 1; b <= m; b++)
        {
            gr[getRight(b)]= vector<long long>();
            mathchedMember[getRight(b)] = -1;
            scanf("%lld", &members[getRight(b)]);
        }
        for (b = 1; b <= n; b++)
        {
            for (c = 1; c <= m; c++)
            {
                if ( members[getRight(c)]%members[getLeft(b)] == 0 )
                {
                    gr[getLeft(b)].push_back( getRight(c) );
                    gr[getRight(c)].push_back( getLeft(b) );
                }
            }
        }

        //loopStopper = 10;
        while( 1 )
        {
            addee = 0;
            bfs();
            for (b = 1; b <= n; b++)
            {
                color[ getLeft(b) ] = WHITE;
            }
            for (b = 1; b <= n; b++)
            {
                if ( layer[getLeft(b)] == 0 )
                {
                    //cout << "layer[" << getLeft(b) << "] = " << layer[getLeft(b)] << endl;
                    addee += dfs1( getLeft(b) );
                }
            }
            //cout << "addee = " << addee << endl;
            if (addee <= 0)
            {
                break;
            }
            ans += addee;
        }
        for (b = 1; b <= n; b++)
        {
            //cout << "matchedMember[" << b << "] = " << mathchedMember[b] << endl;
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
