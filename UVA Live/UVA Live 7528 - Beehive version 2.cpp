#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long i, j;
long long a, b, c, d, e, f, g, layer[SIZE][SIZE];
vector<long long> gr[SIZE+9], bfsStart;
map< pair<long long, long long>, long long > twoDToOneD;
vector< pair<long long, long long> > vecPair;
long long dx[] = {-1, -1, 0, 1, 1, 0};
long long dy[] = {-1, 1, 2, 1, -1, -2};
void buildBeeHive()
{
    long long a, b, c, d, e, f, x = 0, y = 0, nx, ny;
    queue< pair<long long, long long> > Q;
    pair<long long, long long> current;
    Q.push( {x, y} );
    vecPair.push_back( {x,y} );
    twoDToOneD[ {0, 0} ] = 1;
    while( Q.size() && vecPair.size() < SIZE )
    {
        current = Q.front();
        Q.pop();
        x = current.first;
        y = current.second;
        for ( a = 0; a < 5; a++ )
        {
            nx = x + dx[a];
            ny = y + dy[a];
            if ( ny < 0 )
            {
                continue;
            }
            if ( twoDToOneD[ {nx, ny} ]== 0 )
            {
                vecPair.push_back( {nx, ny} );
                Q.push( {nx, ny} );
                twoDToOneD[ {nx, ny} ] = vecPair.size();
            }
        }
    }
}
void buildGraph()
{
    long long a, b, c, d, e, f, g, x, y, nx, ny;
    for (a = 0; a < vecPair.size(); a++)
    {
        x = vecPair[a].first;
        y = vecPair[a].second;
        for (b = 0; b < 6; b++)
        {
            nx = x + dx[b];
            ny = y + dy[b];
            if ( twoDToOneD[{nx,ny}] == 0 )
            {
                continue;
            }
            gr[a+1].push_back( twoDToOneD[{nx,ny}] );
        }
    }
}
void bfs( vector<long long> rootVec, long long *layerAr)
{
    long long a, b, c, d, e, f, g, current;
    queue<long long> Q;
    for (a = 0; a < SIZE; a++)
    {
        layerAr[a] = INT_MAX;
    }
    for (a = 0; a < rootVec.size(); a++)
    {
        Q.push( rootVec[a] );
        layerAr[ rootVec[a] ] = 0;
    }
    while( Q.size() )
    {
        current = Q.front();
        Q.pop();
        for (a = 0; a < gr[current].size(); a++)
        {
            if ( layerAr[ gr[current][a] ] >= INT_MAX )
            {
                layerAr[ gr[current][a] ] = layerAr[current] + 1;
                Q.push( gr[current][a] );
            }
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    buildBeeHive();
    buildGraph();
    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            layer[a][b] = INT_MAX;
        }
    }
    while(1)
    {
        scanf("%lld %lld", &i, &j);
        if (i+j==0)
        {
            return 0;
        }
        bfsStart = vector<long long>();
        bfsStart.push_back(i);
        bfs( bfsStart, layer[i] );
        printf("%lld\n", layer[i][j]);
    }
    return 0;
}
