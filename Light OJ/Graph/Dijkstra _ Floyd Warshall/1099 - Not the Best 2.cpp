#include <bits/stdc++.h>
using namespace std;

#define SIZE 5009


struct node
{
    int idx, dist;
    node(int idx = 0, int dist = INFINITY)
    {
        this->idx = idx;
        this->dist = dist;
    }
    bool operator<(const node &b) const
    {
        return !(dist<b.dist);
    }
};

int T, N, R, u, v, w, i, j, k, x, y, z, a, b, c, ans, minimum = INFINITY;
map<int, int> graph[SIZE];
int shortestDist[SIZE], secondShortest[SIZE];
int visited[SIZE];
map<int, int>::iterator it;
priority_queue<node> pq;
node current;
int destination;


vector<node> graph2[SIZE];
vector<node>::iterator it2;


int main()
{
    //cout << INFINITY + 1;
    freopen("input.txt", "r", stdin);

    cin >> T;
    for (i = 1; i <= T; i++)
    {
        pq = priority_queue<node>();
        cin >> N >> R;
        for (j = 1; j <= N; j++)
        {
            graph[j] = map<int, int>();
            graph2[j] = vector<node>();
            shortestDist[j] = INFINITY ;
            secondShortest[j] = INFINITY;
            visited[j] = 0;
        }
        for (j = 1; j <= R; j++)
        {
            scanf("%d %d %d", &u, &v, &w);


            graph2[u].push_back( node(v, w) );
            graph2[v].push_back( node(u, w) );

        }


        shortestDist[1] = 0;

        minimum = INFINITY;

        for (it2 = graph2[1].begin(); it2 != graph2[1].end(); it2++)
        {
            //current = (node)it2;
            if ( it2->idx == 1 && it2->dist < minimum ) minimum = it2->dist;
            else if ( it2->idx != 1 && it2->dist*2 < minimum ) minimum = it2->dist*2;
        }

        secondShortest[1] = minimum;



        //cout << "\n secondShortest[1] = " << secondShortest[1] << "\n";

        pq.push( node(1, 0) );
        while(!pq.empty())
        {
            current = (node)pq.top();
            pq.pop();

            //if (visited[current.idx] ) continue;


            for (it2 = graph2[current.idx].begin(); it2 != graph2[current.idx].end(); it2++)
            {
                if ( shortestDist[it2->idx] > shortestDist[current.idx] + it2->dist )
                {
                    secondShortest[it2->idx] = shortestDist[it2->idx];
                    shortestDist[it2->idx] = shortestDist[current.idx] + it2->dist;
                    pq.push( node(it2->idx, shortestDist[it2->idx]) );
                }

                else if ( secondShortest[it2->idx] > shortestDist[current.idx] + it2->dist )
                {
                    secondShortest[it2->idx] = shortestDist[current.idx] + it2->dist;
                    pq.push( node(it2->idx, secondShortest[it2->idx]) );

                }

                if ( //secondShortest[current.idx] + it->second > 0 &&
                     secondShortest[it2->idx] > secondShortest[current.idx] + it2->dist)
                {
                    secondShortest[it2->idx] = secondShortest[current.idx] + it2->dist;
                    pq.push( node(it2->idx, secondShortest[it2->idx]) );
                }
            }





            visited[current.idx] = 1;
        }


        for (j = 1; j <= N; j++)
        {
            //cout << "\n secondShortest[" << j << "] = " << secondShortest[j] << "\n";
        }

        ans = secondShortest[N];
        cout << "Case " << i << ": " << ans << "\n";
    }


    return 0;
}
