#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long T, N;
long long a, b, c, d, e, f, g;
long long len, inDegree[SIZE], outDegree[SIZE], ifVisited[SIZE], startNode, notPossible;
long long inDegreeBig, outDegreeBig;
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
void dfs(long long u)
{
    //cout << "u = " << (char)u << endl;
    long long a, b, c, d, e, f, g;
    if ( ifVisited[u] ) return;
    ifVisited[u] = 1;
    for (a = 0; a < gr[u].size(); a++)
    {
        //cout << "gr[u][a].to = " << (char)gr[u][a].to << endl;
        if ( !ifVisited[ gr[u][a].to ] )
        {
            dfs( gr[u][a].to );
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
            ifVisited[b] = 0;
        }
        for (b = 1; b <= N; b++)
        {
            ifVisited[b] = 0;
        }
        startNode = -1;
        notPossible = 0;
        inDegreeBig = 0;
        outDegreeBig = 0;
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
            //cout << "b = " << (char)b << endl;
            if ( outDegree[b] > inDegree[b] )
            {
                startNode = b;
            }
            if ( abs(inDegree[b]-outDegree[b]) > 1 ) notPossible = 1;
            if ( inDegree[b] > outDegree[b] )
            {
                if(inDegreeBig)
                {
                    //cout << "inDegreeBig = " << inDegreeBig << endl;
                    notPossible = 1;
                }
                inDegreeBig = b;
            }
            if( outDegree[b] > inDegree[b] )
            {
                //cout << "outDegreeBig = " << outDegreeBig << endl;
                if(outDegreeBig)
                {
                    //cout << "outDegreeBig = " << outDegreeBig << endl;
                    notPossible = 1;
                }
                outDegreeBig = b;
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
        dfs(startNode);
        for (b = 'a'; b <= 'z'; b++)
        {
            if ( !ifVisited[b] && (inDegree[b]>0 || outDegree[b]>0 ) )
            {
                //cout << "b = " << (char)b << " is not visited " << endl;
                notPossible = 1;
            }
        }
        if (notPossible)
        {
            cout << "The door cannot be opened." << endl;
        }
        else
        {
            cout << "Ordering is possible." << endl;
        }
    }
    return 0;
}
