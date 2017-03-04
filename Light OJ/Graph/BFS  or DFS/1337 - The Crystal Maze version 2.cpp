#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long T, M, N, Q, xi, yi, ansPoint[SIZE][SIZE], ansAr[SIZE*SIZE], number = 0, ans;
char grid[SIZE][SIZE];
bool visited[SIZE][SIZE];
long long a, b, c, d, e, f;
class coOrd
{
public:

    long long x, y;
    coOrd(long long x, long long y)
    {
        this->x = x;
        this->y = y;
    }
    coOrd(){}
};
coOrd current;
bool ifOk(coOrd c)
{
    long long x, y;
    x = c.x;
    y = c.y;
    if (x<0 || x>=M || y<0 || y>=N) return false;
    //cout << "inside grid" << endl;
    if ( visited[x][y] ) return false;
    //cout << "not visited " << endl;
    if ( grid[x][y] == '#' ) return false;
    //cout << ". or C " << endl;
    return true;
}
//
//void dfs(long long x, long long y)
//{
//    if ( !ifOk(x,y) ) return;
//    if ( grid[x][y]=='C' ) ans++;
//    //cout << "x = " << x << ", y = " << y << endl;
//    ansPoint[x][y] = number;
//    visited[x][y] = true;
//    dfs(x-1, y);
//    dfs(x+1, y);
//    dfs(x, y-1);
//    dfs(x, y+1);
//}
queue<coOrd> q;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        q = queue<coOrd>();
        number = 0;
        memset(ansAr, -1, sizeof(ansAr));
        memset(ansPoint, -1, sizeof(ansPoint));
        memset(visited, false, sizeof(visited));
        cin >> M >> N >> Q;
        for (b = 0; b < M; b++)
        {
            scanf("%s", grid[b]);
        }
        cout << "Case " << a << ":" << endl;
        for (b = 0; b < Q; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            if ( ansPoint[xi-1][yi-1] != -1 )
            {
                ans = ansAr[ ansPoint[xi-1][yi-1]  ];
                printf("%lld\n", ans);
                continue;
            }
            number++;
            //memset( visited, false, sizeof(visited) );
            ans = 0;

            //printf("%lld %lld\n", xi, yi);
            q = queue<coOrd>();
            q.push( coOrd(xi-1, yi-1) );
            while(!q.empty()  )
            {
                coOrd current = q.front();
                q.pop();



                if ( !ifOk(current) )
                {
                    //cout << "Not ok" << endl;
                    //cout << "x = " << current.x << ", y = " << current.y << endl;
                    continue;
                }
                visited[ current.x ][ current.y ] = true;
                ansPoint[ current.x ][ current.y ] = number;
                if ( grid[ current.x ][ current.y ] == 'C' ) ans++;
                q.push( coOrd( current.x-1, current.y ) );
                q.push( coOrd( current.x+1, current.y ) );
                q.push( coOrd( current.x, current.y-1 ) );
                q.push( coOrd( current.x, current.y+1 ) );

            }

            ansAr[number] = ans;
            printf("%lld\n", ans);
        }
    }
    return 0;
}
