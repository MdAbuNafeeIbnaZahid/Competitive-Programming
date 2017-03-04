#include <bits/stdc++.h>
using namespace std;

#define SIZE 200


struct node
{
    int idx, dis;
    node(int idx = 0, int dis = INFINITY)
    {
        this->idx = idx;
        this->dis = dis;
    }
    bool operator<(const node &b) const
    {
        return !(dis<b.dis);
    }
};


int N, M, T, u, v, w;
int i, j, k, a, b, c, x, y, z;

map<int, int> graph[SIZE];
int dist[SIZE], visited[SIZE];

priority_queue<node> pq;


int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> N >> M;

        for (j = 1; j <= N; j++)
        {
            graph[j] = map<int, int>();
            dist[j] = INFINITY;
            visited[j] = 0;
            pq.push( node(j) );
        }
        pq = priority_queue<node>();

        for (j = 1; j <= M; j++)
        {
            scanf("%d %d %d", &u, &v, &w);
            if ( graph[u].find(v) != graph[u].end() && graph[u][v] < w ) continue;
            graph[u][v] = w;
            graph[v][u] = w;
        }



        dist[1] = 0;
        pq.push( node(1, 0) );


        while(!pq.empty())
        {
            node current = (node)pq.top();
            pq.pop();


            if (visited[current.idx]) continue;

            map<int,int>::iterator it;
            for (it = graph[current.idx].begin(); it != graph[current.idx].end(); it++)
            {
                if ( dist[it->first] > (dist[current.idx] + it->second) )
                {
                    //cout << "\n it->second = " << it->second  << "\n";
                    dist[it->first] = dist[current.idx] + it->second;

                    //cout << "\n dist[" << it->first << "] = " << dist[it->first] << "\n";

                    pq.push( node(it->first, dist[it->first]) );
                }
            }



            visited[current.idx] = 1;
        }


        cout << "Case " << i << ": ";
        if (dist[N] < (int)INFINITY) cout << dist[N] << "\n";
        else   cout << "Impossible" << "\n";
    }



    return 0;
}
