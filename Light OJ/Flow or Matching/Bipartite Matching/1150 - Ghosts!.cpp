#include <bits/stdc++.h>
using namespace std;
#define SIZE 29
#define MAXN 109
#define OFFSET 52
#define WHITE 0
#define GREY 1
#define BLACK 2
long long a, b, c, d, e, f;
long long T, n;
long long maxAns, minAns, posAns, bfsDist[SIZE][SIZE][SIZE][SIZE], len, totHumFri;
long long matchedMember[MAXN], layer[MAXN], color[MAXN];
string grid[SIZE];
long long changeRow[] = {0, 1, 0, -1};
long long changeCol[] = {1, 0, -1, 0};
vector<long long> gr[MAXN];
struct cell
{
    long long row, col;
    cell(){}
    cell(long long row, long long col)
    {
        this->row = row;
        this->col = col;
    }
};
bool ifOk( cell ob )
{
    if ( ob.row < 0 || ob.row >= n || ob.col < 0 || ob.col >= n || grid[ob.row][ob.col]=='#' ) return false;
    return true;
}
bool ifHasEdge(cell A, cell B)
{
    if ( 2*bfsDist[A.row][A.col][B.row][B.col]+2 <= posAns ) return true;
    return false;
}
vector<cell> ghostVector, humanVector;
void bfs1(cell ob)
{
    long long a, b, c, d, e, f;
    cell current, nextCell;
    queue<cell> Q;
    for (a = 0; a < n; a++)
    {
        for (b = 0; b < n; b++)
        {
            bfsDist[ob.row][ob.col][a][b] = INT_MAX;
        }
    }
    bfsDist[ob.row][ob.col][ob.row][ob.col] = 0;
    Q.push(ob);
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        for (a = 0; a < 4; a++)
        {
            nextCell.row = current.row + changeRow[a];
            nextCell.col = current.col + changeCol[a];
            if ( ifOk(nextCell) && bfsDist[ob.row][ob.col][nextCell.row][nextCell.col] == INT_MAX )
            {
                bfsDist[ob.row][ob.col][nextCell.row][nextCell.col]
                    = 1 + bfsDist[ob.row][ob.col][current.row][current.col];
                Q.push( nextCell );
            }
        }
    }
}
void bfs2()
{
    long long a, b, c, d, e, f, g, current, len;
    queue<long long> Q;
    for (a = 0; a < ghostVector.size(); a++)
    {
        layer[a] = INT_MAX;
        if ( matchedMember[a] == -1 ) layer[a] = 0;
        Q.push(a);
    }
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( matchedMember[ gr[current][a] ] != -1
                && layer[ matchedMember[ gr[current][a] ] ] == INT_MAX )
            {
                layer[ matchedMember[ gr[current][a] ] ] == layer[current]+1;
            }
        }
    }
}
long long dfs2(long long u)
{
    long long a, b, c, d, e, len = gr[u].size(), posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( matchedMember[gr[u][a]] != -1 && layer[matchedMember[gr[u][a]]]==layer[u]+1 )
        {
            posRet = dfs2(matchedMember[gr[u][a]]);
            if ( posRet )
            {
                matchedMember[u] = gr[u][a];
                matchedMember[ gr[u][a] ] = u;
                return 1;
            }
        }
    }
    for (a = 0; a < len; a++)
    {
        if ( matchedMember[ gr[u][a] ] == -1 )
        {
            matchedMember[u] = gr[u][a];
            matchedMember[ gr[u][a] ] = u;
            return 1;
        }
    }
    color[u] = BLACK;
    return 0;
}
long long Hopcroft()
{
    long long a, b, c, d, e, f, g, len, addee = 0, ret = 0;
    while(1)
    {
        addee = 0;
        bfs2();
        for (a = 0; a < ghostVector.size(); a++)
        {
            color[a] = WHITE;
            //cout << "layer [" << a << "] = " << layer[a] << endl;
        }
        for (a = 0; a < ghostVector.size(); a++)
        {
            if ( layer[a] == 0 ) addee += dfs2(a);
        }
        for (a = 0; a < ghostVector.size(); a++)
        {
            //cout << "matchedMember [" << a << "] = " << matchedMember[a] << endl;
        }
        if (addee <= 0) break;
        ret += addee;
    }
    return ret;
}
void printGr()
{
    long long a, b, c, d, e, len;
    for (a = 0; a < ghostVector.size(); a++)
    {
        len = gr[a].size();
        cout << ghostVector[a].row << "," << ghostVector[a].col << " : ";
        for (b = 0; b < len; b++)
        {
            cout << "(" << humanVector[gr[a][b]-OFFSET].row << "," << humanVector[gr[a][b]-OFFSET].col << ") ";
        }
        cout << endl;
    }
    for (a = 0+OFFSET; a < humanVector.size()+OFFSET; a++)
    {
        len = gr[a].size();
        cout << a << " : ";
        for (b = 0; b < len; b++)
        {
            cout << gr[a][b] << " ";
        }
        cout << endl;
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ghostVector = vector<cell>();
        humanVector = vector<cell>();
        cin >> n;
        for (b = 0; b < n; b++)
        {
            for (c = 0; c < n; c++)
            {
                for (d = 0; d < n; d++)
                {
                    for (e = 0; e < n; e++)
                    {
                        bfsDist[b][c][d][e] = INT_MAX;
                        if (b==d && c==e) bfsDist[b][c][d][e] = 0;
                    }
                }
            }
        }
        for (b = 0; b < n; b++) cin >> grid[b];
        for (b = 0; b < n; b++)
        {
            for (c = 0; c < n; c++)
            {
                if ( grid[b][c] == 'G' ) ghostVector.push_back( cell(b, c) );
                else if ( grid[b][c] == 'H' ) humanVector.push_back( cell(b, c) );
            }
        }
        len = ghostVector.size();
        for (b = 0; b < len; b++)
        {
            bfs1( ghostVector[b] );
        }
        minAns = 1;
        maxAns = 25*25;
        while(minAns < maxAns)
        {
            posAns = (minAns + maxAns)/2;
            //cout << "minAns = " << minAns << endl;
            //cout << "maxAns = " << maxAns << endl;
            //cout << "posAns = " << posAns << endl;
            for (b = 0; b < ghostVector.size(); b++)
            {
                gr[b] = vector<long long>();
                matchedMember[b] = -1;
            }
            for (b = 0; b < humanVector.size(); b++)
            {
                gr[OFFSET+b] = vector<long long>();
                matchedMember[OFFSET+b] = -1;
            }
            for (b = 0; b < ghostVector.size(); b++)
            {
                for (c = 0; c < humanVector.size(); c++)
                {
                    if ( ifHasEdge(ghostVector[b], humanVector[c]) )
                    {
                        gr[b].push_back( OFFSET+c );
                        gr[OFFSET+c].push_back(b);
                    }
                }
            }
            //printGr();
            totHumFri = Hopcroft();
            //cout << "totHumFri = " << totHumFri << endl;
            if ( totHumFri >= humanVector.size() )
            {
                maxAns = posAns;
            }
            else minAns = posAns+1;
        }
        if (minAns < 625)cout << "Case " <<a << ": " << minAns << endl;
        else cout << "Case " << a << ": Vuter Dol Kupokat" << endl;
        //cout << endl << endl << endl << endl << endl;
    }
    return 0;
}
