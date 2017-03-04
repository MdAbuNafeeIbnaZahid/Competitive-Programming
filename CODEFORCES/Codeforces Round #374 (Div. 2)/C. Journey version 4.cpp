#include <bits/stdc++.h>
using namespace std;
#define SIZE 5009
#define WHITE 0
#define GRAY 1
#define BLACK 2
long long n, m, T, ui, vi, ti;
long long a, b, c, d, e, f, g, h, len, ans, current, maxIdx;
long long alreadyVis, timeSpent;
long long color[SIZE];
struct info
{
    long long numVis, time, parent, parentIdx;
    info(){}
    info(long long numVis, long long time, long long parent, long long parentIdx)
    {
        this->numVis = numVis;
        this->time = time;
        this->parent = parent;
        this->parentIdx = parentIdx;
    }
};
struct edge
{
    long long to, timeNeed;
    edge(){}
    edge(long long to, long long timeNeed)
    {
        this->to = to;
        this->timeNeed = timeNeed;
    }
};
vector<edge> gr[SIZE];
vector<long long> topSorted;
vector<long long> ansVec;
void dfsTopSort( long long u )
{
    long long a, b, c, d, e, f, len = gr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GRAY;
    for (a = 0; a < len; a++)
    {
        if ( color[ gr[u][a].to ] == WHITE  )
        {
            dfsTopSort( gr[u][a].to );
        }
    }
    color[u] = BLACK;
    topSorted.push_back( u );
}
vector<info> vecInfo[SIZE];
info currentInfo;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> m >> T;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld %lld", &ui, &vi, &ti);
        gr[ ui ].push_back( edge(vi, ti) );
    }
    dfsTopSort(1);
    vecInfo[1].push_back( info(0, 0, 0, -1) );
    len = topSorted.size();
    for (a = len-1; a >= 0; a--)
    {
        current = topSorted[a];
        for (b = 0; b < gr[current].size(); b++)
        {
            vi = gr[current][b].to;
            ti = gr[current][b].timeNeed;
            for (c = 0; c < vecInfo[current].size(); c++)
            {
                alreadyVis = vecInfo[current][c].numVis;
                timeSpent = vecInfo[current][c].time;
                if ( timeSpent + ti > T )
                {
                    continue;
                }
                else
                {
                    vecInfo[vi].push_back( info(alreadyVis+1, timeSpent+ti, current, c) );
                }
            }
        }
        //vecInfo[current] = vector<info>();
    }
    len = vecInfo[n].size();
    for (a = 0; a < len; a++)
    {
        if ( vecInfo[n][a].time <= T && vecInfo[n][a].numVis > ans )
        {
            ans = vecInfo[n][a].numVis;
            maxIdx = a;
        }
    }
    ansVec.push_back(n);
    current = n;
    while( current != 1 )
    {
        currentInfo = vecInfo[current][maxIdx];
        ansVec.push_back( currentInfo.parent );
        current = currentInfo.parent;
        maxIdx = currentInfo.parentIdx;
    }
    cout << ans+1 << endl;
    len = ansVec.size();
    for (a = len-1; a >= 0; a--)
    {
        printf("%lld ", ansVec[a]);
    }
    return 0;
}
