#include <bits/stdc++.h>
using namespace std;

#define SIZE 550


int T, n,m, u, v, w, t;
int i, j, k , a, b, c, x, y, z;

int INFIN;;

int dist[SIZE], visited[SIZE];

struct node
{
    int idx;
    int dis;

    node(int idx = 0, int dis = (int)INFINITY)
    {
        this->idx = idx;
        this->dis = dis;
    }
    bool operator<(const node &n) const
    {
        return !(dis < n.dis);
    }
};

map<int, int> graph[SIZE];
priority_queue<node> pq;


int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

//    string s;
//    cin >> s;
//    cout << s;

    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> n >> m;

        for (j = 0; j < n; j++)
        {
            dist[j] = (int)INFINITY;
            visited[j] = 0;
            pq.push(node(j));
            graph[j] = map<int, int>();
        }


        for (j = 1; j <= m; j++)
        {
            scanf("%d %d %d", &u, &v, &w);

            if (graph[u][v] == 0 || graph[u][v] > w)
            {
                graph[u][v] = w;
                graph[v][u] = w;
            }
        }

        scanf("%d", &t);
        dist[t] = 0;

        pq.push(node(t, 0));
        while(!pq.empty())
        {
            node current = (node)pq.top();
            pq.pop();

            if ( visited[current.idx] ) continue;

            map<int, int>::iterator it;
            for (it = graph[current.idx].begin(); it != graph[current.idx].end(); it++)
            {
                if ( dist[it->first] > (dist[current.idx] > it->second ? dist[current.idx] : it->second) )
                {
                    dist[it->first] = (dist[current.idx] > it->second ? dist[current.idx] : it->second);
                    pq.push( node(it->first, dist[it->first]) );
                }
            }



            visited[current.idx] = 1;
        }


        cout << "Case " << i << ":\n";
        for (j = 0; j < n; j++)
        {
            if (dist[j] >= (int)INFINITY-10) printf("Impossible\n");
            else printf("%d\n", dist[j]);
        }

    }


    //cout << "gcdshbvchdbshjdb";


    return 0;
}
