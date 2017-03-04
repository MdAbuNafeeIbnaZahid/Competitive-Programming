#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define OFFSET 1009
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, n, m, members[3*SIZE], ans, addee, loopStopper;
long long mathchedMember[3*SIZE], layer[3*SIZE], color[3*SIZE];
long long a,b, c, d, e;
long long R, C, N;
long long x, y;
vector<long long> gr[3*SIZE];
set<long long> xSet, ySet;
set<long long>::iterator setLLIt, setLLIt2;
map< long long, map<long long, long long> > myMap;
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
    //cin >> T;
    while(1)
    {
        cin >> R >> C >> N;
        if ( R+C+N == 0 ) break;
        myMap = map< long long, map<long long, long long> >();
        ans = 0;
        xSet = set<long long>();
        ySet = set<long long>();
        for (a = 1; a <= N; a++)
        {
            scanf("%lld %lld", &x, &y);
            xSet.insert(x);
            ySet.insert(y);
            myMap[x][y] = 1;
        }
        n = xSet.size();
        setLLIt = xSet.begin();
        for (b = 1; b <= n; b++)
        {
            gr[getLeft(b)] = vector<long long>();
            mathchedMember[getLeft(b)] = -1;
            members[ getLeft(b) ] = *setLLIt;
            setLLIt++;
        }
        m = ySet.size();
        setLLIt = ySet.begin();
        for (b = 1; b <= m; b++)
        {
            gr[getRight(b)]= vector<long long>();
            mathchedMember[getRight(b)] = -1;
            members[ getRight(b) ] = *setLLIt;
            setLLIt++;
        }
        for (b = 1; b <= n; b++)
        {
            for (c = 1; c <= m; c++)
            {
                //if ( members[getRight(c)]%members[getLeft(b)] == 0 )
                if ( myMap[members[getLeft(b)] ][ members[ getRight(c) ] ] )
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

        cout << "Case " << a << ": " << ans << endl;

    }
//    for (a =1; a <= T; a++)
//    {
//        ans = 0;
//        cin >> n;
//        for (b = 1; b <= n; b++)
//        {
//            gr[getLeft(b)] = vector<long long>();
//            mathchedMember[getLeft(b)] = -1;
//            scanf("%lld", &members[getLeft(b)]);
//        }
//        cin >> m;
//        for (b = 1; b <= m; b++)
//        {
//            gr[getRight(b)]= vector<long long>();
//            mathchedMember[getRight(b)] = -1;
//            scanf("%lld", &members[getRight(b)]);
//        }
//        for (b = 1; b <= n; b++)
//        {
//            for (c = 1; c <= m; c++)
//            {
//                if ( members[getRight(c)]%members[getLeft(b)] == 0 )
//                {
//                    gr[getLeft(b)].push_back( getRight(c) );
//                    gr[getRight(c)].push_back( getLeft(b) );
//                }
//            }
//        }
//
//        //loopStopper = 10;
//        while( 1 )
//        {
//            addee = 0;
//            bfs();
//            for (b = 1; b <= n; b++)
//            {
//                color[ getLeft(b) ] = WHITE;
//            }
//            for (b = 1; b <= n; b++)
//            {
//                if ( layer[getLeft(b)] == 0 )
//                {
//                    //cout << "layer[" << getLeft(b) << "] = " << layer[getLeft(b)] << endl;
//                    addee += dfs1( getLeft(b) );
//                }
//            }
//            //cout << "addee = " << addee << endl;
//            if (addee <= 0)
//            {
//                break;
//            }
//            ans += addee;
//        }
//
//        cout << "Case " << a << ": " << ans << endl;
//    }
    return 0;
}
