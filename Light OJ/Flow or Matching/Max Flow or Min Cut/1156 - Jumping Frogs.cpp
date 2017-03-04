#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
#define WHITE 3
#define GREY 4
#define BLACK 5
#define OFFSET 250
long long T, N, D;
long long possibleAns, maxAns, minAns, addee, color[SIZE], posX, posY;
long long a, b, c, d, e, f;
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
long long head(long long u)
{
    return OFFSET+u;
}
long long tail(long long u)
{
    return u;
}
vector<edge> inputGraph[SIZE], workGraph[SIZE];
long long dfs(long long u)
{
    long long a, b, c, d, e, posRet;
    if ( u == 2*N+2 ) return 1;
    if ( color[u] == GREY ) return 0;
    color[u] = GREY;
    if ( stoneArray[u].type == 'S' && u <= N+1)
    {
        color[2*N+2-u] = GREY;
    }
    for (a = u+1; a <= 2*N+2 && stoneArray[a].dis-stoneArray[u].dis<=possibleAns; a++)
    {
        posRet = dfs(a);
        if ( posRet ) return posRet;
    }
    color[u] = BLACK;
    if ( stoneArray[u].type == 'S' && u <= N+1)
    {
        color[2*N+2-u] = BLACK;
    }
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> D;
        for (b = 0; b < 2*N+5; b++)
        {
            inputGraph[b] = vector<edge>();
        }
        stoneArray[0].type = 'B';
        stoneArray[0].dis = 0;
        for (b = 1; b <= N; b++)
        {
            getchar();
            scanf("%c-%lld", &stoneArray[b].type, &stoneArray[b].dis);
            //cout << "b = " << b << endl;
            //cout << "type = " << stoneArray[b].type << endl;
            //cout << "dis = " << stoneArray[b].dis << endl;
        }
        for (b = 1; b <= N; b++)
        {
            //cout << stoneArray[b].type << "-" << stoneArray[b].dis << endl;
        }
        stoneArray[N+1].type = 'B';
        stoneArray[N+1].dis = D;
        for (b = N, c = N+2; b >= 1; b--, c++)
        {
            stoneArray[c].type = stoneArray[b].type;
            stoneArray[c].dis = 2*D - stoneArray[b].dis;
        }
        stoneArray[2*N+2].type = 'B';
        stoneArray[2*N+2].dis = 2*D;
        for (b = 0; b <= 2*N+2; b++)
        {
            if ( stoneArray[b].type == 'S' )
            {
                posX = inputGraph[tail(b)].size();
                posY = inputGraph[head(b)].size();
                inputGraph[tail(b)].push_back( edge(tail(b), head(b), 1, posY) );
                inputGraph[head(b)].push_back( edge(head(b), tail(b), 0, posX) );
            }
        }
        minAns = 1;
        maxAns = D;
        while(minAns < maxAns)
        {
            //cout << "minAns = " << minAns << endl;
            //cout << "maxAns = " << maxAns << endl;
            for (b = 0; b <= 2*N+2; b++)
            {
                color[b] = WHITE;
            }
            possibleAns = (minAns+maxAns)/2;
            addee = dfs(0);
            if ( addee )
            {
                maxAns = possibleAns;
            }
            else
            {
                minAns = possibleAns+1;
            }
        }
        cout << "Case " << a << ": " << minAns << endl;
    }
    return 0;
}
