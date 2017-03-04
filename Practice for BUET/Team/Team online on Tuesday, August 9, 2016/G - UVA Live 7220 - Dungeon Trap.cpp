#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, N, M, ans, totalVal, disA[SIZE][SIZE], disB[SIZE][SIZE];
long long a, b, c, d, e;
long long changeR[] = {0, 0, 1, -1};
long long changeC[] = {1, -1, 0, 0};
string grid[SIZE];
struct pos
{
    long long row, col, dis;
    pos(){}
    pos(long long row, long long col, long long dis)
    {
        this->row = row;
        this->col = col;
        this->dis = dis;
    }
    bool const operator < (const pos b) const
    {
        if ( dis == b.dis )
        {
            if ( row == b.row )
            {
                return col < b.col;
            }
            return row < b.row;
        }
        return dis < b.dis;
    }
};
pos posA, posB;
bool ifOk(long long row, long long col)
{
    if ( row < 0 || row >= N ) return false;
    if ( col < 0 || col >= M ) return false;
    if ( grid[row][col] < '1' || grid[row][col] > '9' ) return false;
    return true;
}
void dijkstra(pos source, long long disAr[SIZE][SIZE])
{
    long long a, b, d, e, f, g;
    long long r, c;
    set<pos> setPos;
    pos current;
    for (a = 0; a < N; a++)
    {
        for (b = 0; b < M; b++)
        {
            disAr[a][b] = INT_MAX;
        }
    }
    disAr[source.row][source.col] = 0;
    source.dis = 0;
    setPos.insert( source );
    while( setPos.size() )
    {
        current = *setPos.begin();
        setPos.erase( setPos.begin() );
        for ( a = 0; a < 4; a++ )
        {
            r = current.row+changeR[a];
            c = current.col+changeC[a];
            if ( ifOk( r, c ) &&
                disAr[r][c] > disAr[current.row][current.col] + grid[r][c] - '0' )
            {

                disAr[r][c] = disAr[current.row][current.col] + grid[r][c] - '0';
                setPos.insert( pos(r, c, disAr[r][c]) );
            }
            //cout << "r = " << r << endl;
            //cout << "c = " << c << endl;
            //cout << "disAr[r][c] = " << disAr[r][c] << endl;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> N >> M;
        for (b = 0; b < N; b++)
        {
            cin >> grid[b];
        }
        totalVal = 0;
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < M; c++)
            {
                if ( grid[b][c] == 'A' )
                {
                    posA = pos(b, c, 0);
                }
                else if ( grid[b][c] == 'B' )
                {
                    posB = pos(b, c, 0);
                }
                else
                {
                    totalVal += ( grid[b][c] - '0' ) ;
                }
            }
        }
        dijkstra(posA, disA);
        //cout << "distance from A" << endl;
        //for (b = 0; b < N; b++)
        //{
            //for (c = 0; c < M; c++)
            //{
                //cout << disA[b][c] << " ";
            //}
            //cout << endl;
        //}
        dijkstra(posB, disB);
        ans = 0;
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < M; c++)
            {
                ans = max(ans,  totalVal + 2*( grid[b][c] - '0' ) - disA[b][c] - disB[b][c] );
            }
        }
        ans = max(ans, (long long)0 );
        printf("Case #%lld: %lld\n", a, ans);
    }
    return 0;
}
