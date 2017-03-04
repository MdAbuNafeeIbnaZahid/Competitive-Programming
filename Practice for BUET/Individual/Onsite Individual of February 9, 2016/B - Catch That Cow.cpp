#include <iostream>
using namespace std;

#define SIZE 100009
#define INF 999999999


int i, j, k;
int dist[SIZE];
int N, K;

int minOfThree(int a, int b, int c)
{
    return ( a<b ? (a<c?a:c) : (b<c?b:c));
}

int getDist(int n)
{
    if (n < 0 || n > 100000) return INF;


    if (dist[n] == INF)
        dist[n] = minOfThree( getDist(n-1), getDist(n+1), n%2==0?getDist(n/2):INF ) + 1;


    return dist[n];
}



int main()
{
    cin >> N >> K;

    for (i = 0; i <= 100000; i++)
    {
        dist[i] = INF;
    }

    dist[N] = 0;

    cout << getDist(K);

    return 0;
}
