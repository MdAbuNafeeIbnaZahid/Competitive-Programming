#include <bits/stdc++.h>
using namespace std;
#define SIZE 319
#define OFFSET 105
#define WHITE 3
#define GREY 4
#define BLACK 5
long long T, N, D;
long long maxAns, minAns, possibleAns, source, sink, posX, posY, addee, maxFlow;
long long color[SIZE];
long long a, b, c, d, e, f;
long long tail(long long u)
{
    return u;
}
long long head(long long u)
{
    return OFFSET+u;
}
struct stone
{
    char type;
    long long dis;
    stone(){}
    stone(char type, long long dis)
    {
        this->type = type;
        this->dis = dis;
    }
};
stone stoneArray[SIZE];
struct edge
{
    long long to, cap, revIdx;
    edge(){}
    edge( long long to, long long cap, long long revIdx )
    {
        this->to = to;
        this->cap = cap;
        this->revIdx = revIdx;
    }
};
vector<edge> inputGraph[SIZE], workGraph[SIZE];
long long dfs(long long u, long long minVal)
{
    long long a, b, c, d, e, len = workGraph[u].size(), posRet;
    //cout << "u = " << u << ", minVal = " << minVal << endl;
    //cout << "sink = " << sink << endl;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( u == sink ) return minVal;
    for (a = 0; a < len; a++ )
    {
        if ( workGraph[u][a].cap <= 0 || color[workGraph[u][a].to]!=WHITE ) continue;
        posRet = dfs( workGraph[u][a].to, min(minVal, workGraph[u][a].cap) );
        if ( posRet > 0 )
        {
            workGraph[u][a].cap -= posRet;
            workGraph[ workGraph[u][a].to ][ workGraph[u][a].revIdx ].cap += posRet;
            return posRet;
        }
    }
    return 0;
}
void printGraph(vector<edge> gr[], long long len)
{
    long long a, b, c, d, e, innerLen;
    for (a = 0; a < len; a++)
    {
        innerLen = gr[a].size();
        if (innerLen <= 0) continue;
        cout << a << " : ";
        for (b = 0; b < innerLen; b++)
        {
            cout << "(" << gr[a][b].to << "," << gr[a][b].cap << ") ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> D;
        source = tail(0);
        sink = head(N+1);
        for (b = 0; b <= N+1; b++)
        {
            inputGraph[head(b)] = vector<edge>();
            inputGraph[tail(b)] = vector<edge>();
        }
        for (b = 1; b <= N; b++)
        {
            getchar();
            scanf("%c-%lld", &stoneArray[b].type, &stoneArray[b].dis);
        }
        //cout << "input taken" << endl;
        stoneArray[0] = stone('B', 0);
        stoneArray[N+1] = stone('B', D);
        for (b = 0; b <= N+1; b++)
        {
            if ( stoneArray[b].type == 'B' )
            {
                posX = inputGraph[tail(b)].size();
                posY = inputGraph[head(b)].size();
                inputGraph[tail(b)].push_back( edge(head(b), INT_MAX, posY) );
                inputGraph[head(b)].push_back( edge(tail(b), 0, posX) );
            }
            else if ( stoneArray[b].type == 'S' )
            {
                posX = inputGraph[tail(b)].size();
                posY = inputGraph[head(b)].size();
                inputGraph[tail(b)].push_back( edge(head(b), 1, posY) );
                inputGraph[head(b)].push_back( edge(tail(b), 0, posX) );
            }
        }
        minAns = 1;
        maxAns = D;
        while(minAns < maxAns)
        {
            //cout << "minAns = " << minAns << endl;
            //cout << "maxAns = " << maxAns << endl;
            maxFlow = 0;
            possibleAns = (minAns+maxAns)/2;
            for (b = 0; b <= N+1; b++)
            {
                workGraph[tail(b)] =
                    vector<edge>( inputGraph[tail(b)].begin(), inputGraph[tail(b)].end() );
                workGraph[head(b)] =
                    vector<edge>( inputGraph[head(b)].begin(), inputGraph[head(b)].end() );
            }
            for (b = 0; b <= N+1; b++)
            {
                for (c = b+1; c <= N+1; c++)
                {
                    if ( stoneArray[c].dis-stoneArray[b].dis <= possibleAns )
                    {
                        posX = workGraph[head(b)].size();
                        posY = workGraph[tail(c)].size();
                        workGraph[head(b)].push_back( edge(tail(c), INT_MAX, posY) );
                        workGraph[tail(c)].push_back( edge(head(b), 0, posX) );

                        posX = workGraph[head(c)].size();
                        posY = workGraph[tail(b)].size();
                        workGraph[head(c)].push_back( edge(tail(b), INT_MAX, posY) );
                        workGraph[tail(b)].push_back( edge(head(c), 0, posX) );
                    }
                }
            }
            //printGraph( workGraph, SIZE );
            while(1)
            {
                for (b = 0; b <= N+1; b++)
                {
                    color[tail(b)] = WHITE;
                    color[head(b)] = WHITE;
                }
                addee = dfs(tail(source), INT_MAX);
                if ( addee <= 0) break;
                maxFlow += addee;
            }
            //cout << "maxFlow = " << maxFlow << endl;
            if ( maxFlow >= 2 )
            {
                maxAns = possibleAns;
            }
            else
            {
                minAns = possibleAns+1;
            }
        }
        cout << "Case " <<a << ": " << minAns << endl;
    }
    return 0;
}
