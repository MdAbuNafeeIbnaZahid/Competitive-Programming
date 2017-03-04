#include <bits/stdc++.h>
using namespace std;


#define INFINITY 9999999
#define SIZE 109

//const int INFINITY = (unsigned)(~0) >> 1;
int t, n, r, u, v, s, d, a, b, c, i, j, k,x, y, z, maxD, maxS, maxDist;
vector<int> g[SIZE];
int distD[SIZE], distS[SIZE];
queue<int> q;

void bfs(int source, int *ar)
{
    q = queue<int>();
    int current, i, j, k;
    ar[source] = 0;
    q.push(source);

    while(!q.empty())
    {
        current = q.front();
        q.pop();

        for (i = 0; i < g[current].size(); i++)
        {
            if (ar[ g[current][i] ] == INFINITY)
            {
                ar[ g[current][i] ] = ar[current] + 1;
                q.push( g[current][i] );
            }
        }
    }
}



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> t;
    for (i = 1; i <= t; i++)
    {
        maxD = maxS = maxDist = 0;
        for (j = 0; j < SIZE; j++)
        {
            distD[j] = INFINITY;
            distS[j] = INFINITY;
            g[j].clear();
        }

        cin >> n >> r;

        for (j = 0; j < r; j++)
        {
            cin >> u >> v;
            g[u].push_back(v);
            g[v].push_back(u);
        }

        cin >> s >> d;

        //cout << "Just before bfs \n";


        bfs(s, distS);
        bfs(d, distD);

        for (j = 0; j < n; j++)
        {
            if (distD[j] + distS[j] > maxDist)
            {
                maxDist = distD[j] + distS[j];
            }
        }

        cout << "Case " << i <<": "<< maxDist << "\n";
    }


    return 0;
}
