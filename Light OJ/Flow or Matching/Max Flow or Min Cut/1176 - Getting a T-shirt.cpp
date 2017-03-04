#include <bits/stdc++.h>
using namespace std;
#define SIZE 8
#define WHITE 3
#define GREY 4
#define BLACK 5
long long T, N, M, ans, addee;
long long a, b, c, d, e, f;
string u, v, allSizes[] = {"source", "XXL", "XL", "L", "M", "S", "XS", "destination"};
map< string, map<string, long long> > myMap;
map<string, long long> color;
set<string> setOfSizes;
long long dfs(string u, long long minVal)
{
    long long posRet, a, b, c, d, e;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( u == "destination" ) return minVal;
    for (a = 0; a < 8; a++)
    {
        if ( myMap[u][ allSizes[a] ] > 0 )
        {
            posRet = dfs( allSizes[a], min( myMap[u][ allSizes[a] ], minVal ) );
            if ( posRet > 0 )
            {
                myMap[u][ allSizes[a] ] -= posRet;
                myMap[ allSizes[a] ][u] += posRet;
                return posRet;
            }
        }
    }
    return 0;
    color[u] = BLACK;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        setOfSizes = set<string>();
        cin >> N >> M;
        for (b = 0; b < 8; b++)
        {
            for (c = 0; c < 8; c++)
            {
                myMap[ allSizes[b] ][ allSizes[c] ] = 0;
            }
        }

        for (b = 1; b <= M; b++)
        {
            cin >> u >> v;
            setOfSizes.insert( u );
            setOfSizes.insert( v );
            myMap[u][v]++;
            myMap[v][u]++;
            myMap["source"][u] = min(N, myMap["source"][u]+1);
            myMap["source"][v] = min(N, myMap["source"][v]+1);
            myMap[u]["destination"] = min(N, myMap[u]["destination"]+1);
            myMap[v]["destination"] = min(N, myMap[v]["destination"]+1);
        }
        //for (b = 1; b <= 6; b++)
        //{
            //myMap["source"][ allSizes[b] ] = N;
            //myMap[ allSizes[b] ]["destination"] = N;
        //}
        while(1)
        {
            for (b = 0; b < 8; b++)
            {
                color[ allSizes[b] ] = WHITE;
            }
            addee = dfs("source", INT_MAX);
            //cout << "addee = " << addee << endl;
            if ( addee <= 0 ) break;
            ans += addee;
        }
        //cout << "ans = " << ans << endl;
        if ( ans >= M )
        {
            cout << "Case " << a << ": YES" << endl;
        }
        else
        {
            cout << "Case " << a << ": NO" << endl;
        }
    }
    return 0;
}
