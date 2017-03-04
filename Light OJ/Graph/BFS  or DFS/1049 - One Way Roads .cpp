#include <bits/stdc++.h>
using namespace std;

#define SIZE 105

int t, n, a, b, c, i, j, k, ansClock, ansCounterClock, ans,  visited[SIZE], serial[SIZE], s;
int matrix[SIZE][SIZE];
class edge
{
public:
    int to, w;
    edge(int to, int w)
    {
        this->to = to;
        this->w = w;
    }
    edge(){}
};

vector<edge> v[SIZE];

void dfs(int vertex)
{
    if (visited[vertex]) return;

    visited[vertex] = 1;
    serial[s++] = vertex;

    vector<edge>::iterator it;
    for (it = v[vertex].begin(); it != v[vertex].end(); it++)
    {
        dfs( it->to );
    }
}

void dfsClock(int vertex)
{
    printf("%d ", vertex);
    if ( visited[vertex] != 0) return;
    visited[vertex] = 1;
    vector<edge>::iterator it;
    for (it = v[vertex].begin(); it != v[vertex].end(); it++)
    {
        if ( !visited[it->to] && it->to != 1)
        {
            ansClock += it->w;
            dfsClock(it->to);
        }
    }
}


void dfsCounterClock(int vertex)
{
    printf("%d ", vertex);
    if (visited[vertex] != 0) return;
    visited[vertex] = 1;
    vector<edge>::iterator it;

    if (v[vertex].empty()) return;
    for (it = v[vertex].end()-1; ; it--)
    {
        if ( visited[it->to] == 0 || it->to == 1 )
        {
            ansCounterClock += it->w;
            dfsCounterClock(it->to);
        }

        if (it == v[vertex].begin()) break;
        //printf("\n Iterating \n");
    }
}



int main()
{
    //freopen("input.txt", "r", stdin);

    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {


        ansClock = 0;
        ansCounterClock = 0;
        ans = 0;
        s = 0;

        for (j = 0; j < SIZE; j++)
        {
            v[j].clear();
            visited[j] = 0;
            for (k = 0; k < SIZE; k++)
            {
                matrix[j][k] = INT_MAX;
            }
        }


        scanf("%d", &n);
        for (j = 0; j < n; j++)
        {
            scanf("%d %d %d", &a, &b, &c);

            v[a].push_back( edge(b, 0) );
            matrix[a][b] = 0;

            v[b].push_back( edge(a, c) );
            matrix[b][a] = c;
        }
        //printf("\n Input taken \n");
        /*
        for (j = 1; j <= n; j++)
        {
            printf("\n");
            printf("%d ----- ", j);
            vector<edge>::iterator it;
            for (it = v[j].begin(); it != v[j].end(); it++)
            {
                printf("%d(%d)  ", it->to, it->w);
            }
        }
        */


        dfs(1);
        //printf("\n");
        /*
        for (j = 0; j < s; j++)
        {
            printf("%d ", serial[j]);
        }
        printf("\n");
        */


        for (j = 0; j < s; j++)
        {
            ansClock += matrix[ serial[j%s] ][ serial[(j+1)%s] ];
            ansCounterClock += matrix[ serial[(j+1)%s] ][ serial[j%s] ];
        }


        /*
        for (j = 0; j < SIZE; j++)
        {
            visited[j] = 0;
        }
        //for (j = 0; j < SIZE; j++)
        //{
            dfsClock(1);
        //}
        printf("\n Clock complete \n");
        printf("\n ansClock = %d \n", ansClock);

        for (j = 0; j < SIZE; j++)
        {
            visited[j] = 0;
        }
        //for (j = 0; j < SIZE; j++)
        //{
            dfsCounterClock(1);
        //}
        printf("\n Counter Clock complete \n");
        printf("\n ansCounterClock = %d \n", ansCounterClock);
        */

        ans = min(ansClock, ansCounterClock);
        printf("Case %d: %d\n", i, ans );
    }


    return 0;
}
