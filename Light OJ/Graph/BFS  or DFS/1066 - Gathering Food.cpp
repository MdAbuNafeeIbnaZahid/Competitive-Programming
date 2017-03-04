#include <bits/stdc++.h>
using namespace std;
#define SIZE 19
long long T, N, dist[SIZE][SIZE], ans;
char grid[SIZE][SIZE], lastChar;
long long a, b, c, d, e, f, g;
struct coOrd
{
    long long r, c;
    coOrd(){}
    coOrd(long long r, long long c)
    {
        this->r = r;
        this->c = c;
    }
};
coOrd parent[SIZE][SIZE];
coOrd pos[509], current, nextPush;
queue<coOrd> q;
bool ifOk(coOrd c)
{
    if ( c.r < 0 || c.r >= N || c.c <0 || c.c >= N ) return false;
    if ( grid[c.r][c.c] == '#' ) return false;
    if ( dist[c.r][c.c] != -1 ) return false;
    if ( grid[c.r][c.c] > b+1 ) return false;
    return true;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        lastChar = 'A'-1;
        cin >> N;
        for (b = 0; b < N; b++)
        {
            scanf("%s", grid[b]);
        }
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < N; c++)
            {
                if ( grid[b][c] >= 'A' && grid[b][c] <= 'Z' )
                {
                    //cout << grid[b][c] << " " << b << " " << c << endl;
                    if (grid[b][c] > lastChar) lastChar = grid[b][c];
                    pos[ grid[b][c] ] = coOrd(b, c);
                }
            }
        }
        //cout << "lastChar = " << lastChar << endl;
        cout << "Case " << a << ": ";
        if ( lastChar <= 'A' )
        {
            cout <<  0 << endl;
            continue;
        }
        ans = 0;
        //for (b = 'A'; b <= lastChar; b++)
        //{
            //cout << b << endl;
            //cout << pos[b].r << " " << pos[b].c << endl;
        //}
        for (b = 'A'; b < lastChar; b++)
        {
            memset( dist, -1, sizeof(dist) );
            q = queue<coOrd>();
            q.push( pos[b] );
            dist[ pos[b].r ][ pos[b].c ] = 0;
            parent[ pos[b].r ][ pos[b].c ] = pos[b];
            while( !q.empty() )
            {
                current = q.front();
                q.pop();

                //cout << "current.r = " << current.r << ", current.c = " << current.c << endl;

                nextPush = coOrd( current.r+1, current.c );
                if ( ifOk(nextPush) )
                {
                    q.push( nextPush );
                    dist[ nextPush.r ][ nextPush.c ] = dist[current.r][current.c]+1;
                    parent[nextPush.r][nextPush.c] = current;
                }


                nextPush = coOrd( current.r-1, current.c );
                if ( ifOk(nextPush) )
                {
                    q.push( nextPush );
                    dist[ nextPush.r ][ nextPush.c ] = dist[current.r][current.c]+1;
                    parent[nextPush.r][nextPush.c] = current;
                }


                nextPush = coOrd( current.r, current.c+1 );
                if ( ifOk(nextPush) )
                {
                    q.push( nextPush );
                    dist[ nextPush.r ][ nextPush.c ] = dist[current.r][current.c]+1;
                    parent[nextPush.r][nextPush.c] = current;
                }


                nextPush = coOrd( current.r, current.c-1 );
                if ( ifOk(nextPush) )
                {
                    q.push( nextPush );
                    dist[ nextPush.r ][ nextPush.c ] = dist[current.r][current.c]+1;
                    parent[nextPush.r][nextPush.c] = current;
                }


            }

            if ( dist[ pos[b+1].r ][ pos[b+1].c ] == -1 )
            {
                cout << "Impossible" << endl;
                ans = -1;
                break;
            }

            ans += dist[ pos[b+1].r ][ pos[b+1].c ];
        }
        if (ans != -1) cout << ans << endl;
    }
    return 0;
}
