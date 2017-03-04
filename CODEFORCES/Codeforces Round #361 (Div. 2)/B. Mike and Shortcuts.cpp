#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
#define WHITE 0
#define GRAY 2
#define BLACK 3
long long dist[SIZE], color[SIZE];
long long n, aAr[SIZE], current;
long long a, b, c, d, e, f, g, h;
queue<long long> Q;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a  = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
    }
    for (a = 0; a <= n+3; a++)
    {
        dist[a] = INT_MAX;
    }
    //cout << "input taken" << endl;
    dist[1] = 0;
    color[0] = BLACK;
    color[n+3] = BLACK;
    Q.push(1);
    color[1] = GRAY;
    while( Q.size() )
    {
        //cout << "Q.size() = " << Q.size() << endl;
        current = Q.front();
        Q.pop();
        //cout << "current = " << current << endl;
        if( color[current+1] == WHITE )
        {
            color[current+1] = GRAY;
            dist[current+1] = 1+dist[current];
            Q.push(current+1);
        }
        if( color[current-1] == WHITE )
        {
            color[current-1] = GRAY;
            dist[current-1] = 1+dist[current];
            Q.push(current-1);
        }
        if( color[ aAr[current] ] == WHITE )
        {
            color[aAr[current]] = GRAY;
            dist[aAr[current]] = 1+dist[current];
            Q.push(aAr[current]);
        }
        color[current] = BLACK;
    }
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", dist[a]);
    }
    return 0;
}
