#include <bits/stdc++.h>
using namespace std;



#define SIZE 30009


class edge
{
public:

    int to, weight;
    edge(int to = -1, int weight = -1)
    {
        this->to = to;
        this->weight = weight;
    }
};

long long t, n, u, v, w, i, j, k, a, b, c, x, y, z, dist[SIZE], ans, maxDist, furthestNode;
vector<edge> g[SIZE];
queue<int> q;
//vector<int> weight[SIZE];

void bfs(int u)
{
    q = queue<int>();

    int current, i, j, k;

    for (j = 0; j < SIZE; j++)
    {
        //g[j].clear();
        dist[j] = (unsigned)(~0)>>1;
    }

    dist[u] = 0;
    q.push(u);

    while( !q.empty() )
    {

        current = q.front();
        q.pop();

        vector<edge>::iterator  it;
        for (it = g[current].begin(); it != g[current].end(); it++)
        {
            if ( dist[it->to] ==  (unsigned)(~0)>>1 )
            {
                q.push(it->to);
                dist[it->to] = dist[current] + it->weight;
            }
        }
    }
}


int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%lld", &t);
    for (i = 1; i <= t; i++)
    {
        q = queue<int>();
        for (j = 0; j < SIZE; j++)
        {
            g[j].clear();
            //dist[j] = (unsigned)(~0)>>1;
        }
        scanf("%lld", &n);
        for (j = 1; j < n; j++)
        {
            scanf("%lld %lld %lld", &u, &v, &w);
            g[u].push_back( edge(v, w) );
            g[v].push_back( edge(u, w) );
        }

        ans = 0;
        bfs(0);

        maxDist = 0;
        for (j = 0; j < n; j++)
        {
            if (dist[j] > maxDist)
            {
                maxDist = dist[j];
                furthestNode = j;
            }
        }

        bfs(furthestNode);

        for (j = 0; j < n; j++)
        {
            if (dist[j] > maxDist)
            {
                maxDist = dist[j];
                furthestNode = j;
            }
        }

        /*
        for (j = 0; j < n; j++)
        {
            if ( g[j].size() > 1 ) continue;

            for (a = 0; a < SIZE; a++)
            {
                dist[a] = (unsigned)(~0) >> 1;
            }

            bfs(j);

            sort(dist, dist+SIZE);
            if (dist[n-1] > ans) ans = dist[n-1];
        }
        */

        //Case 1: 100
        printf("Case %lld: %lld\n", i, maxDist);
        //cout << "Case " << i <<": " << ans << "\n";
    }


    return 0;
}
