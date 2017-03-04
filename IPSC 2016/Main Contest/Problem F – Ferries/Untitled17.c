#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long t, n, x, k;
long long a, b, c, d, e, f, current;
long long layer[SIZE], step[SIZE], parent[SIZE], aArray[SIZE], totalSteps;
string ansStr;
long long leftStep(long long x)
{
    if ( x <= n )
    {
        return 2*x;
    }
    else
    {
        return 2*(x-n)-1;
    }
}
long long rightStep(long long x)
{
    if ( x <= n ) return 2*x-1;
    else return 2*(x-n);
}
void bfs(long long source)
{
    long long a, b, c, d, e , f, current;
    queue<long long> Q;
    for (a = 1; a <= 2*n; a++)
    {
        layer[a] = INT_MAX;
    }
    layer[source] = 0;
    Q.push(source);
    while( !Q.empty() )
    {
        current = Q.pop();
        if ( layer[leftStep(current)] == INT_MAX )
        {
            layer[leftStep(current)] = layer[current] + 1;
            step[leftStep(current)] = 'L';
            parent[leftStep(current)] = current;
            Q.push(leftStep(current));
        }
        if ( layer[rightStep(current)] == INT_MAX )
        {
            layer[rightStep(current)] = layer[current]+1;
            step[rightStep(current)] = 'R';
            parent[rightStep(current)] = current;
            Q.push(rightStep(current));
        }
    }
    return;
}
int main()
{
    freopen("f1.in", "r", stdin);
    freopen("f1Output.txt", "w", stdout);
    cin >> t;
    for (a = 1; a <= t; a++)
    {
        totalSteps = 0;
        ansStr = "";
        cin >> n >> x >> k;
        for (b = 1; b <= k; b++)
        {
            scanf("%lld", &aArray[b]);
        }
        bfs(x);
        current = aArray[1];
        while( layer[current] != 0 )
        {
            totalSteps++;
            if ( step[current] == 'L' )
            {
                ansStr = ansStr + 'L';
            }
            else if (step[current] == 'R')
            {
                ansStr = ansStr + 'R';
            }
            current = parent[current];
        }
        for (b = 2; b <= k; b++)
        {
            bfs( aArray[b-1] );
            current = aArray[b];
            while( layer[current ] != 0 )
            {
                totalSteps++;
                if ( step[current] == 'L' )
                {
                    ansStr = ansStr + 'L';
                }
                else if (step[current] == 'R')
                {
                    ansStr = ansStr + 'R';
                }
                current = parent[current];
                }
        }
    }
    cout << totalSteps << ":" << ansStr << endl;
    return 0;
}
