#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long T, N;
long long a, b, c, d, e, f, g;
long long len, inDegree[SIZE], outDegree[SIZE], ifVisited[SIZE], startNode;
char str[SIZE];
struct edge
{
    long long to, idx;
    edge(){}
    edge(long long to, long long idx)
    {
        this->to = to;
        this->idx = idx;
    }
};
vector<edge> gr[SIZE];
void dfs(edge E)
{
    long long a, b, c, d, e, f, g;
    if ( ifVisited[E.idx] ) return;
    ifVisited[E.idx] = 1;
    for (a = 0; a < gr[E.to].size(); a++)
    {
        if ( !ifVisited[ gr[E.to][a].idx ] )
        {
            dfs( gr[E.to][a] );
            break;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N;
        for (b = 'a'; b <= 'z'; b++)
        {
            gr[b] = vector<edge>();
            inDegree[b] = 0;
            outDegree[b] = 0;
        }
        for (b = 1; b <= N; b++)
        {
            ifVisited[b] = 0;
        }
        startNode = -1;
        for (b = 1; b <= N; b++)
        {
            scanf("%s", str);
            len = strlen(str);
            outDegree[ str[0] ]++;
            inDegree[ str[len-1] ]++;
            gr[ str[0] ].push_back( edge(str[len-1], b) );
        }
        for (b = 'a'; b <= 'z'; b++)
        {
            if ( outDegree[b] > inDegree[b] )
            {
                startNode = b;
                break;
            }
        }
        if (startNode==-1)
        {
            for (b = 'a'; b <= 'z'; b++)
            {
                if (outDegree[b] > 0)
                {
                    startNode = b;
                    break;
                }
            }
        }
        //cout << "startNode = " << (char)startNode << endl;
        dfs(gr[startNode][0]);
        for (b = 1; b <= N; b++)
        {
            if ( !ifVisited[b] )
            {
                cout << "The door cannot be opened." << endl;
                break;
            }
        }
        if ( b > N )
        {
            cout << "Ordering is possible." << endl;
        }
    }
    return 0;
}
