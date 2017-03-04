#include <bits/stdc++.h>
using namespace std;
#define SIZE 219
#define SOURCE 205
#define SINK 210
#define WHITE 3
#define GREY 4
#define BLACK 5
long long T, N, xi, yi, ni, mi;
double D;
long long maxFlow, len, totalPeng, color[SIZE], posX, posY;
long long a, b, c, d, e, f;
struct icePiece
{
    long long xi, yi, ni, mi;
    icePiece(){}
    icePiece(long long xi, long long yi, long long ni, long long mi)
    {
        this->xi = xi;
        this->yi = yi;
        this->ni = ni;
        this->mi = mi;
    }
} ;
icePiece icePieceArray[SIZE];
long long head(long long n)
{
    return n;
}
long long tail(long long n)
{
    return n+100;
}
struct edge
{
    long long from, to, cap, revIdx;
    edge(){}
    edge(long long from, long long to, long long cap, long long revIdx)
    {
        this->from = from;
        this->to = to;
        this->cap = cap;
        this->revIdx = revIdx;
    }
};
vector<edge> gr[SIZE], inputGraph[SIZE];
vector<long long> printVector;
bool isReachable(icePiece a, icePiece b)
{
    if ( (a.xi-b.xi)*(a.xi-b.xi) + (a.yi-b.yi)*(a.yi-b.yi) <= D*D ) return true;
    return false;
}
long long dfs(long long u, long long minVal, long long sink)
{
    //cout << "u = " << u << endl;
    long long a, b, c, d, posRet, len = gr[u].size();
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( u == sink ) return minVal;
    //cout << "len = " << len << endl;
    for (a = 0; a < len; a++)
    {
        if ( gr[u][a].cap <=0 || color[ gr[u][a].to ] != WHITE  ) continue;
        //cout << "now " << gr[u][a].to << " will be called for dfs" << endl;
        posRet = dfs( gr[u][a].to, min(minVal, gr[u][a].cap), sink );
        if ( posRet > 0 )
        {
            gr[u][a].cap -= posRet;
            gr[ gr[u][a].to ][ gr[u][a].revIdx ].cap += posRet;
            return posRet;
        }
    }
    color[u] = BLACK;
    return 0;
}
long long dinic(long long n)
{
    //cout << "dinic(" << n << ") is called" << endl;
    long long a, b, c, d, e, f, ret = 0, addee = 0, posX, posY;
//    if ( gr[SINK].size() )
//    {
//        gr[ gr[SINK][0].to ][ gr[SINK][0].revIdx ].cap = 0;
//        gr[SINK] = vector<edge>();
//    }
//    posX = gr[n].size();
//    posY = gr[SINK].size();
//    gr[n].push_back( edge(n, SINK, INT_MAX, posY) );
//    gr[SINK].push_back( edge(SINK, n, 0, posX ) );
    ret = 0;
    while(1)
    {
        for (a = 0; a < N; a++)
        {
            color[head(a)] = WHITE;
            color[tail(a)] = WHITE;
        }
        color[SOURCE] = WHITE;
        color[SINK] = WHITE;
        addee = dfs(SOURCE, INT_MAX, n);
        //cout << "color[SINK] = " << color[SINK] << endl;
        //cout << "addee = " << addee << endl;
        if ( addee <=0 ) break;
        ret += addee;
    }
    return ret;
}
void printGraph()
{
    long long a, b, c, d, e, len;
    for (a = 0; a < SIZE; a++)
    {
        if ( gr[a].size() <= 0 ) continue;
        cout << a << ": ";
        len = gr[a].size();
        for (b = 0; b < len; b++)
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
        totalPeng = 0;
        printVector = vector<long long>();
        cin >> N >> D;
        for (b = 0; b < N; b++)
        {
            inputGraph[ head(b) ] = vector<edge>();
            inputGraph[ tail(b) ] = vector<edge>();
        }
        inputGraph[SOURCE] = vector<edge>();

        //gr[SINK] = vector<edge>();
        for (b = 0; b < N; b++)
        {
            scanf("%lld %lld %lld %lld", &xi, &yi, &ni, &mi);
            icePieceArray[b] = icePiece(xi, yi, ni, mi);
            totalPeng += ni;
        }
        for (b = 0; b < N; b++)
        {
            posX = inputGraph[SOURCE].size();
            posY = inputGraph[tail(b)].size();
            inputGraph[SOURCE].push_back( edge(SOURCE, tail(b), icePieceArray[b].ni, posY ) );
            inputGraph[tail(b)].push_back( edge(tail(b), SOURCE, 0, posX) );

            posX = inputGraph[tail(b)].size();
            posY = inputGraph[head(b)].size();
            inputGraph[tail(b)].push_back( edge(tail(b), head(b), icePieceArray[b].mi, posY) );
            inputGraph[head(b)].push_back( edge(head(b), tail(b), 0, posX) );
        }
        for (b = 0; b < N; b++)
        {
            for (c = b+1; c < N; c++ )
            {
                if ( isReachable(icePieceArray[b], icePieceArray[c]) )
                {
                    posX = inputGraph[head(b)].size();
                    posY = inputGraph[tail(c)].size();
                    inputGraph[head(b)].push_back( edge( head(b), tail(c), INT_MAX, posY ) );
                    inputGraph[tail(c)].push_back( edge(tail(c), head(b), 0, posX ) );

                    posX = inputGraph[head(c)].size();
                    posY = inputGraph[tail(b)].size();
                    inputGraph[head(c)].push_back( edge(head(c), tail(b), INT_MAX, posY) );
                    inputGraph[tail(b)].push_back( edge(tail(b), head(c), 0, posX ) );
                }
            }
        }
        //printGraph();
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < SIZE; c++)
            {
                gr[c] = vector<edge>(inputGraph[c].begin(), inputGraph[c].end());
            }
            maxFlow = dinic(tail(b));
            //cout << "maxFlow = " << maxFlow << endl;
            if ( maxFlow >=  totalPeng ) printVector.push_back(b);
        }
        cout << "Case " << a << ":";
        if ( printVector.size() <= 0) cout << " -1" << endl;
        else
        {
            len = printVector.size();
            for (b = 0; b < len; b++) printf(" %lld", printVector[b]);
            //printf("%lld", printVector[len-1]);
            cout << endl;
        }
    }
    return 0;
}
