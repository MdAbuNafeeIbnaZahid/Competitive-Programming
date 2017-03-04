#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long testCases, R, C;
long long a, b, d, e, f, g, h, i, j;
char maze[SIZE][SIZE], calMaze[SIZE][SIZE];
long long layerFromFire[SIZE][SIZE], layerFromJoe[SIZE][SIZE];
long long calLayerFromJoe[SIZE][SIZE];
long long movR[] = {-1, 1, 0, 0};
long long movC[] = {0, 0, -1, 1};
long long ans;
bool ifOk(long long row, long long col)
{
    if ( row <0 || row >= R || col < 0 || col >= C || maze[row][col] == '#' ) return false;
    return true;
}

bool ifEsOk(long long row, long long col)
{
    if ( row <0 || row >= R || col < 0 || col >= C || calMaze[row][col] == '#' ) return false;
    return true;
}


struct coOrd
{
    long long row, col;
    coOrd(){}
    coOrd(long long row, long long col)
    {
        this->row = row;
        this->col = col;
    }
    //const bool operator < ( coOrd B ) const
    //{
        //if ( row == B. )
    //}
};
vector<coOrd> vecFire, vecJoe;

void esBfs(vector<coOrd> vecSource, long long layer[SIZE][SIZE])
{
    long long a, b, d, e, f, g, h, i, len = vecSource.size(), nextR, nextC;
    queue<coOrd> qCo;
    coOrd current;
    for (a = 0; a < R; a++)
    {
        for (b = 0; b < C; b++)
        {
            layer[a][b] = INT_MAX;
        }
    }
    for (a = 0; a < len; a++)
    {
        layer[ vecSource[a].row ][ vecSource[a].col ] = 0;
        qCo.push( vecSource[a] );
    }
    while( qCo.size() )
    {
        current = qCo.front();
        qCo.pop();
        for (a = 0; a < 4; a++)
        {
            nextR = current.row + movR[a];
            nextC = current.col + movC[a];
            if ( !ifEsOk(nextR, nextC) )
            {
                continue;
            }
            if ( layer[nextR][nextC] < INT_MAX ) continue;
            layer[nextR][nextC] = layer[current.row][current.col] + 1;
            qCo.push( coOrd(nextR, nextC) );
        }
    }
}

void bfs(vector<coOrd> vecSource, long long layer[SIZE][SIZE])
{
    long long a, b, d, e, f, g, h, i, len = vecSource.size(), nextR, nextC;
    queue<coOrd> qCo;
    coOrd current;
    for (a = 0; a < R; a++)
    {
        for (b = 0; b < C; b++)
        {
            layer[a][b] = INT_MAX;
        }
    }
    for (a = 0; a < len; a++)
    {
        layer[ vecSource[a].row ][ vecSource[a].col ] = 0;
        qCo.push( vecSource[a] );
    }
    while( qCo.size() )
    {
        current = qCo.front();
        qCo.pop();
        for (a = 0; a < 4; a++)
        {
            nextR = current.row + movR[a];
            nextC = current.col + movC[a];
            if ( !ifOk(nextR, nextC) )
            {
                continue;
            }
            if ( layer[nextR][nextC] < INT_MAX ) continue;
            layer[nextR][nextC] = layer[current.row][current.col] + 1;
            qCo.push( coOrd(nextR, nextC) );
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        //cout << "a = " << a << endl;
        cin >> R >> C;
        vecFire = vector<coOrd>();
        vecJoe = vector<coOrd>();
        ans = INT_MAX;
        for (b = 0; b < R; b++)
        {
            scanf("%s", maze[b]);
        }
        for (b = 0; b < R; b++)
        {
            for (d = 0; d < C; d++)
            {
                if ( maze[b][d] == 'F' )
                {
                    vecFire.push_back( coOrd(b, d) );
                }
                else if ( maze[b][d] == 'J' )
                {
                    vecJoe.push_back( coOrd(b, d) );
                }
            }
        }
        bfs(vecFire, layerFromFire);
        bfs(vecJoe, layerFromJoe);
        for (b = 0; b < R; b++)
        {
            for (d = 0; d < C; d++)
            {
                calMaze[b][d] = '#';
                if ( layerFromFire[b][d] > layerFromJoe[b][d] )
                {
                    calMaze[b][d] = '.';
                }
            }
        }
        //for (b = 0; b < R; b++)
        //{
            //for (d = 0; d < C; d++)
            //{
                //cout << calMaze[b][d];
            //}
            //cout << endl;
        //}
        esBfs(vecJoe, calLayerFromJoe);
        //for (b = 0; b < R; b++)
        //{
            //for (d = 0; d < C; d++)
            //{
                //cout << calLayerFromJoe[b][d] << " ";
            //}
            //cout << endl;
        //}
        for (b = 0; b < R; b++)
        {
            ans = min(ans, calLayerFromJoe[b][0]);
            ans = min(ans, calLayerFromJoe[b][C-1]);
        }
        for (b = 0; b < C; b++)
        {
            ans = min(ans, calLayerFromJoe[0][b]);
            ans = min(ans, calLayerFromJoe[R-1][b]);
        }
        ans++;
        if ( ans < INT_MAX )
        {
            cout << ans << endl;
        }
        else
        {
            cout << "IMPOSSIBLE" << endl;
        }
    }
    return 0;
}
