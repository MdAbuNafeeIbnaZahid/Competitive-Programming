#include <bits/stdc++.h>
using namespace std;

#define WHITE 0
#define GREY 1
#define BLACK 2


class coOrd
{
public:

    int r, c;
    coOrd(int r, int c)
    {
        this->r = r;
        this->c = c;
    }
    coOrd(){};
};

int t, a, b, c, m, n, i, j, k, hr, hc, ra, ca, rb, cb, rc, cc, rh, ch;
char ara[25][25];
char arb[25][25];
char arc[25][25];
int dis[25][25], color[25][25];
coOrd parent[25][25];

queue<coOrd> q;


int ar[25][25];



void BFS(int r, int c)
{
    if (r < 0 || r >= m || c < 0 || c >= n) return;
    if (color[r][c] == BLACK) return;

    if (color[r+1][c] == WHITE)
    {
        color[r+1][c] == BLACK;
        q.push(coOrd(r+1, c));
        dis[r+1][c] = dis[r][c]+1;
    }
    if (color[r-1][c] == WHITE)
    {
        q.push(coOrd(r-1, c));
        color[r-1][c] == BLACK;
        dis[r-1][c] = dis[r][c]+1;
    }
    if (color[r][c+1] == WHITE)
    {
        q.push(coOrd(r, c+1));
        color[r][c+1] == BLACK;
        dis[r][c+1] = dis[r][c]+1;
    }
    if (color[r][c-1] == WHITE)
    {
        q.push(coOrd(r, c-1));
        color[r][c-1] == BLACK;
        dis[r][c-1] = dis[r][c]+1;
    }

    color[r][c] = BLACK;
}



int main()
{
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%d %d", &m, &n);
        for (j = 0; j < m; j++)
        {
            scanf("%s", ara[j]);
        }


        for (j = 0; j < m; j++)
        {
            for (k = 0; k < n; k++)
            {
                ar[j][k] = -1;
                color[j][k] = WHITE;
                if (ara[j][k] == 'm' || ara[j][k] == '#') color[j][k] = BLACK;
                else if (ara[j][k] == 'h')
                {
                    rh = j;
                    ch = k;
                }
                else if (ara[j][k] == 'a')
                {
                    ra = j;
                    ca = k;
                }
                else if (ara[j][k] == 'b')
                {
                    rb = j;
                    cb = k;
                }
                else if (ara[j][k] == 'c')
                {
                    rc = j;
                    cc = k;
                }
            }
        }


        q.push(coOrd(rh, ch));
        color[rh][ch] = GREY;
        dis[rh][ch] = 0;

        while(q.size())
        {
            coOrd ob = q.front();
            q.pop();
            BFS(ob.r, ob.c);
        }

        printf("Case %d: %d\n", i, max(dis[ra][ca], max(dis[rb][cb], dis[rc][cc])));


    }



    return 0;
}
