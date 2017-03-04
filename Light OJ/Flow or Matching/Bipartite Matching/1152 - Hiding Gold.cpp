#include <bits/stdc++.h>
using namespace std;
#define SIZE 29
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, m, n;
long long a, b, c, d, e, f, color[SIZE][SIZE], layer[SIZE][SIZE], addee, maxMatch;
long long totalGoldCell, ans, loopCount;
string grid[SIZE];
struct cell
{
    long long row, col;
    cell()
    {
        row = -1;
        col = -1;
    }
    cell(long long row, long long col)
    {
        this->row = row;
        this->col = col;
    }
};
cell matchedMember[SIZE][SIZE];
long long changeRow[] = {0, 1, 0, -1};
long long changeCol[] = {1, 0, -1, 0};
bool ifOk(cell ob)
{
    if ( ob.row < 0 || ob.row >= m || ob.col < 0 || ob.col >= n  || grid[ob.row][ob.col] == 'o' )
    {
        return false;
    }
    return true;
}
void bfs1()
{
    long long a, b, c, d, e, f, len;
    cell current, nextCell;
    queue<cell> Q;
    for (a = 0; a < m; a++)
    {
        for (b = 0; b < n; b++)
        {
            layer[a][b] = INT_MAX;
            if ( grid[a][b]=='*' && (a+b)%2==0 && matchedMember[a][b].row == -1 )
            {
                layer[a][b] = 0;
                Q.push(cell(a, b));
            }
        }
    }
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        for (a = 0; a < 4; a++)
        {
            nextCell = cell(current.row+changeRow[a], current.col+changeCol[a] );
            if ( ifOk(nextCell) && ifOk( matchedMember[nextCell.row][nextCell.col] ) )
            {
                nextCell = matchedMember[nextCell.row][nextCell.col];
                if ( layer[nextCell.row][nextCell.col] == INT_MAX )
                {
                    layer[nextCell.row][nextCell.col] = layer[current.row][current.col]+1;
                    Q.push( nextCell );
                }
            }
        }
    }
}
long long dfs1(long long u, long long v)
{
    long long a, b, c, d, e, f, len, posRet;
    if ( !ifOk(cell(u, v)) ) return 0;
    if ( color[u][v] != WHITE ) return 0;
    color[u][v] = GREY;
    for (a = 0; a < 4; a++)
    {
        if ( ifOk(cell(u+changeRow[a], v+changeCol[a]))
            && ifOk(matchedMember[ u+changeRow[a] ][ v+changeCol[a] ] ) )
        {
            posRet = dfs1( matchedMember[ u+changeRow[a] ][ v+changeCol[a] ].row,
                          matchedMember[ u+changeRow[a] ][ v+changeCol[a] ].col  );
            if (posRet)
            {
                matchedMember[u][v] = cell(u+changeRow[a], v+changeCol[a]);
                matchedMember[u+changeRow[a]][v+changeCol[a]] = cell(u, v);
                return 1;
            }
        }
    }
    for (a = 0; a < 4; a++)
    {
        if ( ifOk(cell(u+changeRow[a], v+changeCol[a]))
            && !ifOk(matchedMember[ u+changeRow[a] ][ v+changeCol[a] ] ) )
        {
            matchedMember[u][v] = cell(u+changeRow[a], v+changeCol[a]);
            matchedMember[u+changeRow[a]][v+changeCol[a]] = cell(u, v);
            return 1;
        }
    }
    color[u][v] = BLACK;
    return 0;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        maxMatch = 0;
        totalGoldCell = 0;
        cin >> m >> n;
        for (b = 0; b < m; b++) cin >> grid[b];
        for (b = 0; b < m; b++)
        {
            for (c = 0; c < n; c++)
            {
                matchedMember[b][c] = cell();
                layer[b][c] = -1;
                if ( grid[b][c] == '*' ) totalGoldCell++;
            }
        }
        loopCount = 0;
        while(++loopCount)
        {
            addee = 0;
            bfs1();
            for (b = 0; b < m; b++)
            {
                for (c = 0; c < n; c++)
                {
                    if ( ifOk(cell(b, c)) )
                    {
                        //cout << "b = " << b << ", c = " << c  << ", leyer = " << layer[b][c];
                        //cout << endl;
                    }
                }
            }
            for (b = 0; b < m; b++)
            {
                for (c = 0; c < n; c++)
                {
                    color[b][c] = WHITE;
                }
            }
            for (b = 0; b < m; b++)
            {
                for (c= 0; c < n; c++)
                {
                    if ( (b+c)%2==0 && layer[b][c] == 0 )
                    {
                        addee += dfs1(b, c);
                    }
                }
            }
            if (addee <= 0) break;
            maxMatch += addee;
        }
        ans = totalGoldCell - maxMatch;
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
