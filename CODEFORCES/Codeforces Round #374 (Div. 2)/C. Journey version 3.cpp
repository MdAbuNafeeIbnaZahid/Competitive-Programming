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
    info()
    {
        this->time = INT_MAX;
    }
    info(long long time, long long parent )
    {
        this->time = time;
        this->parent = parent;
        //this->parentIdx = parentIdx;
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
map<long long, info> vecInfo[SIZE];
map<long long, info>::iterator mapIt;
info currentInfo;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m >> T;
    for (a = 1; a <= m; a++)
    {
        scanf("%lld %lld %lld", &ui, &vi, &ti);
        gr[ ui ].push_back( edge(vi, ti) );
    }
    dfsTopSort(1);
    vecInfo[1][1] = info(0, 0) ;
    len = topSorted.size();
    for (a = len-1; a >= 0; a--)
    {
        current = topSorted[a];
        for (b = 0; b < gr[current].size(); b++)
        {
            vi = gr[current][b].to;
            ti = gr[current][b].timeNeed;
            //cout << "ti = " << ti << endl;
            //for (c = 0; c < vecInfo[current].size(); c++)
            for (mapIt = vecInfo[current].begin(); mapIt != vecInfo[current].end(); mapIt++)
            {
                c = mapIt->first;
                alreadyVis = c;
                timeSpent = vecInfo[current][c].time;
                if ( timeSpent + ti > T )
                {
                    continue;
                }
                else
                {
                    if (vecInfo[vi][alreadyVis+1].time > timeSpent + ti )
                    {
                        vecInfo[vi][alreadyVis+1].time = timeSpent + ti;
                        vecInfo[vi][alreadyVis+1].parent = current;
                        //cout << "vi = " << vi << ", alreadyVis+1 = " << alreadyVis+1;
                        //cout << ", parent = " << vecInfo[vi][alreadyVis+1].parent ;
                        //cout << ", time = " << vecInfo[vi][alreadyVis+1].time << endl;
                        //vecInfo[vi][alreadyVis+1].parentIdx = alreadyVis;
                    }
                    //vecInfo[vi].push_back( info(alreadyVis+1, timeSpent+ti, current, c) );
                }
            }
        }
    }
    len = vecInfo[n].size();
    //for (a = 0; a < len; a++)
    for (mapIt = vecInfo[n].begin(); mapIt != vecInfo[n].end(); mapIt++)
    {
        a = mapIt->first;
        //cout << "a = " << a <<  endl;
        if ( vecInfo[n][a].time <= T && a > ans )
        {
            ans = a;
        }
    }
    //cout << "ans = " << ans << endl;
    //ansVec.push_back(n);
    current = n;
    maxIdx = ans;
    while( maxIdx )
    {
        //currentInfo = vecInfo[current][maxIdx];
        //ansVec.push_back( currentInfo.parent );
        //cout << "current = " << current << endl;
        ansVec.push_back( current );
        //maxIdx--;
        current = vecInfo[current][maxIdx].parent;
        maxIdx--;
        //maxIdx = currentInfo.parentIdx;
    }
    cout << ans << endl;
    len = ansVec.size();
    for (a = len-1; a >= 0; a--)
    {
        printf("%lld ", ansVec[a]);
    }
    return 0;
}
