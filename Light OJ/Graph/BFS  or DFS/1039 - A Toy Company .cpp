#include <bits/stdc++.h>
using namespace std;


int visited[50][50][50], dist[50][50][50], t, n, a, b, c, d, e, f, x, y, z, ans, i, j, k, m;
string start, finish, res[60][4];

int X[] = {-1, 1, 0, 0, 0, 0};
int Y[] = {0, 0, -1, 1, 0, 0};
int Z[] = {0, 0, 0, 0, -1, 1};

class word
{
public:

    int x, y, z;
    word(int x, int y, int z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    word(){}
};


bool ifOk(word ob)
{
    if (ob.x < 0 || ob.x > 'z'-'a') return false;
    if (ob.y < 0 || ob.y > 'z'-'a') return false;
    if (ob.z < 0 || ob.z > 'z'-'a') return false;

    return true;
}

bool ifOk(int x, int y, int z)
{
    if (x < 0 || x > 'z'-'a') return false;
    if (y < 0 || y > 'z'-'a') return false;
    if (z < 0 || z > 'z'-'a') return false;

    return true;
}

queue<word> q;


int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        memset(visited, 0, sizeof(visited));

        //printf("\n Before fill \n");
        fill( &dist[0][0][0], &dist[49][49][49] , INT_MAX );
        //printf("\n After fill \n");

        cin >> start >> finish >> n;
        for (j = 0; j < n; j++)
        {
            cin >> res[j][0] >> res[j][1] >> res[j][2];
        }

        for (j = 0; j < n; j++)
        {
            for (a = 0; a < res[j][0].size(); a++)
            {
                for (b = 0; b < res[j][1].size(); b++)
                {
                    for (c = 0; c < res[j][2].size(); c++)
                    {
                        visited[ res[j][0][a]-'a' ][ res[j][1][b]-'a' ][ res[j][2][c]-'a' ] = 1;
                    }
                }
            }
        }

        if ( visited[ start[0]-'a' ][ start[1]-'a' ][ start[2]-'a' ] == 1 )
        {
            ans = -1;
        }

        else
        {
            q = queue<word>();

            dist[ start[0]-'a' ][ start[1]-'a' ][ start[2]-'a' ] = 0;
            q.push( word(start[0]-'a', start[1]-'a', start[2]-'a') );
            visited[ start[0]-'a' ][ start[1]-'a' ][ start[2]-'a' ] = 1;

            while( !q.empty() )
            {
                word ob = q.front();


                q.pop();


                for (j = 0; j < 6; j++)
                {
                    x = ( ob.x + X[j] + 'z' - 'a' + 1 ) % ('z' - 'a' + 1);
                    y = ( ob.y + Y[j] + 'z' - 'a' + 1 ) % ('z' - 'a' + 1);
                    z = ( ob.z + Z[j] + 'z' - 'a' + 1 ) % ('z' - 'a' + 1);


                    if ( ifOk(x, y, z) && !visited[x][y][z] )
                    {
                        q.push( word(x, y, z) );
                        dist[x][y][z] = dist[ob.x][ob.y][ob.z] + 1;
                        visited[x][y][z] = 1;
                    }
                }
            }

            if ( dist[ finish[0]-'a' ][ finish[1]-'a' ][ finish[2]-'a' ] >= INT_MAX ) ans = -1;
            else ans = dist[ finish[0]-'a' ][ finish[1]-'a' ][ finish[2]-'a' ];
        }




        //printf( "\n %d \n",  dist[ finish[0]-'a' ][ finish[1]-'a' ][ finish[2]-'a' ]);
        printf("Case %d: %d\n", i, ans);
    }

    return 0;
}
