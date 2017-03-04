#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, n, u, k, vi;
vector<long long> gr[SIZE];
long long a, b, c, d, e, f, g;
set< pair<long long, long long> > bridgeSet;
set< pair<long long, long long> >::iterator setPairIt;
long long tim, discoverTime[SIZE], lowTime[SIZE], parentAr[SIZE], isVisited[SIZE];
void dfsFindBridge(long long u)
{
    long long a, b, c, d, e, v, childrenCount = 0;
    if ( isVisited[u] )
    {
        return;
    }
    tim++;
    lowTime[u] = discoverTime[u] = tim;
    isVisited[u] = 1;
    for (a = 0; a < gr[u].size(); a++)
    {
        v = gr[u][a];
        if ( parentAr[u] == v )
        {
            continue;
        }
        if ( isVisited[v] )
        {
            lowTime[u] = min(lowTime[u], discoverTime[v]);
        }
        else
        {
            parentAr[v] = u;
            dfsFindBridge(v);
            lowTime[u] = min(lowTime[u], lowTime[v]);
            if ( discoverTime[u] < lowTime[v] /* && parentAr[u] != -1 */ )
            {
               bridgeSet.insert( { min(u,v), max(u,v) } );
            }
            childrenCount++;
        }
//        if ( childrenCount > 1 && parentAr[u]== -1 )
//        {
//
//        }
    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
//        cout << endl << endl << endl;
//        cout << "a = " << a << endl;
        cin >> n;
        for (b = 0; b < n; b++)
        {
            gr[b] = vector<long long>();
            lowTime[b] = INT_MAX;
            parentAr[b] = -1;
            isVisited[b] = 0;
        }
        bridgeSet = set< pair<long long, long long> >();
        for (b = 0; b < n; b++)
        {
            scanf("%lld ", &u);
            scanf("(%lld)", &k);
            for (c = 1; c <= k; c++)
            {
                scanf("%lld", &vi);
                gr[ u ].push_back( vi );
            }
        }
//        for (b = 0; b < n; b++)
//        {
//            cout << b << " (" << gr[b].size() << ") ";
//            for (c = 0; c < gr[b].size(); c++)
//            {
//                cout << gr[b][c] << " ";
//            }
//            cout << endl;
//        }
        for (b = 0; b < n; b++)
        {
            dfsFindBridge(b);
        }
        cout << "Case " << a << ":" << endl;
        cout << bridgeSet.size() << " critical links" << endl;
        for ( setPairIt = bridgeSet.begin(); setPairIt != bridgeSet.end(); setPairIt++ )
        {
            printf("%lld - %lld\n", setPairIt->first, setPairIt->second);
        }
    }
    return 0;
}
