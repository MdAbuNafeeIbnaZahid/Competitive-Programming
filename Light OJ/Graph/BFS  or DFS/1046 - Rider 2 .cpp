#include <bits/stdc++.h>
using namespace std;

#define SIZE 12
#define intMax 99999999


class coOrd
{
public:

    int row, column, k;
    coOrd(int row, int column, int k)
    {
        this->row = row;
        this->column = column;
        this->k = k;
    }
    coOrd(){}
};



int  dist[105][SIZE][SIZE], t, i, j, k, m, n, a, b, x, y, z, o, p, r, s, c;
int r2, c2, k2, stopper;
queue< coOrd > q;
string grid[SIZE];
vector< coOrd > riders;
int ans[SIZE][SIZE], ansMax, ansMin;

int dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2};
int dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};


bool ifOut(int r, int c)
{
    if (r<0 || r>=m || c<0 || c>=n) return true;
    return false;
}


int main()
{
    //freopen("input.txt", "r", stdin);


    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        riders = vector<coOrd>();

        scanf("%d %d", &m, &n);
        for (j = 0; j < m; j++)
        {
            cin >> grid[j];
        }

        for (j = 0; j < m; j++)
        {
            for (k = 0; k < n; k++)
            {
                if (grid[j][k] != '.') riders.push_back( coOrd(j, k, grid[j][k]-'0') );
            }
        }



        for (j = 0; j < riders.size() + 2; j++)
        {
            for (k = 0; k < SIZE; k++)
            {
                for (p = 0; p < SIZE; p++)
                {
                    dist[j][k][p] = intMax;
                }
            }
        }



        j = 0;
        vector<coOrd>::iterator it;
        for (it = riders.begin(); it != riders.end(); it++)
        {

            //cout << endl << "going to rider no " << j << endl;

            q = queue<coOrd>();
            q.push( coOrd(it->row, it->column, it->k) );
            dist[j][it->row][it->column] = 0;



            /*
            //stopper = 15;
            */
            while( !q.empty() )
            {


                r = q.front().row;
                c = q.front().column;
                k = q.front().k;


                /*
                //cout << "r = " << r << ", c = " << c << ", k = " << k << endl;
                */

                q.pop();

                //for (a = 1; a <= k; a++)
                //{
                    for (b = 0; b < 8; b++)
                    {
                        r2 = r + dx[b];
                        c2 = c + dy[b];
                        k2 = k;


                        if ( dist[j][r2][c2] >= intMax && !ifOut(r2, c2) )
                        {
                            q.push( coOrd(r2, c2, k2) );
                            dist[j][r2][c2] = dist[j][r][c] + 1;
                        }
                    }
                //}
            }


            for (a = 0; a <= m; a++)
            {
                for (b = 0; b <= n; b++)
                {
                    if (dist[j][a][b] != intMax )
                    {
                        dist[j][a][b] = ceil ( ( (double) dist[j][a][b] ) /  (double)(it->k ) ) ;
                    }
                }
            }



            j++;
        }


        ansMin = intMax;
        for (j = 0; j < m; j++)
        {
            for (k = 0; k < n; k++)
            {
                ans[j][k] = 0;
                for (p = 0; p < riders.size(); p++)
                {
                    ans[j][k] += dist[p][j][k];
                }
                if (ans[j][k] < ansMin) ansMin = ans[j][k];
            }
        }

        if (ansMin >= intMax) ansMin = -1;



        printf("Case %d: %d\n", i, ansMin );
    }



    return 0;
}
