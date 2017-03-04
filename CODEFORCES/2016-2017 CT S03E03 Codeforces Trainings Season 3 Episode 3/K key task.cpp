#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define BLUE 0
#define YELLOW 1
#define RED 2
#define GREEN 3
long long R, C;
char input[SIZE][SIZE];
long long a, b, c, d, e, f, g, h, nextR, nextC, nextTy, ans, len;
long long dist[29][SIZE][SIZE];
long long sr, sc, er, ec;
long long movR[] = {1, 0, -1, 0};
long long movC[] = {0, 1, 0, -1};
bool ifOk(long long ty, long long row, long long col)
{
    if ( row < 0 || row >= R || col < 0 || col >= C || input[row][col] == '#'  )
    {
        return false;
    }
    else if ( input[row][col] == 'B' )
    {
        if ( (ty & (1<<BLUE) )== 0 ) return false;
    }
    else if ( input[row][col] == 'Y' )
    {
        if ( (ty & (1<<YELLOW) )== 0 ) return false;
    }
    else if ( input[row][col] == 'R' )
    {
        if ( (ty & (1<<RED) )== 0 ) return false;
    }
    else if ( input[row][col] == 'G' )
    {
        if ( (ty & (1<<GREEN) )== 0 ) return false;
    }
    return true;
}
struct pos
{
    long long ty, row, col;
    pos(){}
    pos(long long ty, long long row, long long col)
    {
        this->ty = ty;
        this->row = row;
        this->col = col;
    }
};
void bfs(long long ty, long long row, long long col)
{
    long long a, b, c, d, e, f, g;
    pos current;
    for (a = 0; a < 19; a++)
    {
        for (b = 0; b < R+3; b++)
        {
            for (c = 0; c < C+3; c++)
            {
                dist[a][b][c] = INT_MAX;
            }
        }
    }
    dist[ty][row][col] = 0;
    queue<pos> qPos;
    qPos.push( pos(ty, row, col) );
    while( qPos.size() )
    {
        current = qPos.front();
        qPos.pop();
//        cout << "current.row = " << current.row << endl;
//        cout << "current.col = " << current.col << endl;
//        cout << "current.ty = " << current.ty << endl;
        nextR = current.row;
        nextC = current.col;
        nextTy = current.ty;
        if ( input[current.row][current.col] == 'b' )
        {
            nextTy = current.ty | (1<<BLUE);
        }
        else if ( input[current.row][current.col] == 'y' )
        {
            nextTy = current.ty | (1<<YELLOW);
        }
        else if ( input[current.row][current.col] == 'r' )
        {
            nextTy = current.ty | (1<<RED);
        }
        else if ( input[current.row][current.col] == 'g' )
        {
            nextTy = current.ty | (1<<GREEN);
        }

        if ( dist[nextTy][nextR][nextC] == INT_MAX )
        {
            dist[nextTy][nextR][nextC] = dist[current.ty][current.row][current.col];
            qPos.push( pos(nextTy, nextR, nextC) );
        }
        for (a = 0; a <= 3; a++)
        {
            nextR = current.row + movR[a];
            nextC = current.col + movC[a];
            if ( !ifOk(nextTy, nextR, nextC) )
            {
                continue;
            }
            else if ( dist[nextTy][nextR][nextC] == INT_MAX )
            {
                dist[nextTy][nextR][nextC] = dist[current.ty][current.row][current.col] + 1;
                qPos.push( pos(nextTy, nextR, nextC) );
            }
        }
    }
}
vector<long long> erVec, ecVec;
int main()
{
//    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> R >> C;
        if (R+C == 0) return 0;
        ans = INT_MAX;
        erVec = vector<long long>();
        ecVec = vector<long long>();
        for (a = 0; a < R; a++)
        {
            scanf("%s", input[a]);
        }

        for (a = 0; a < R; a++)
        {
            for (b = 0; b < C; b++)
            {
                if ( input[a][b] == '*' )
                {
                    sr = a;
                    sc = b;
                }
                else if ( input[a][b] == 'X' )
                {
                    //er = a;
                    //ec = b;
                    erVec.push_back(a);
                    ecVec.push_back(b);
                }
            }
        }
        bfs(0, sr, sc);
//        cout << "er = " << er << endl;
//        cout << "ec = " <<ec << endl;
        for (a = 0; a < 19; a++)
        {
//            cout << "a = " << a << ", dist[0][0][a] = " << dist[0][0][a] << endl;
        }
        len = erVec.size();
        for (a = 0; a < 19; a++)
        {
//            cout << "a = " << a << ", dist[a][er][ec] = " << dist[a][er][ec] << endl;
            for (b = 0; b < len; b++)
            {
                ans = min(ans, dist[a][erVec[b] ][ecVec[b] ]);
            }
        }
        if ( ans == INT_MAX )
        {
            cout << "The poor student is trapped!" << endl;
        }
        else
        {
            cout << "Escape possible in " << ans <<  " steps." << endl;
        }
    }
    return 0;
}
