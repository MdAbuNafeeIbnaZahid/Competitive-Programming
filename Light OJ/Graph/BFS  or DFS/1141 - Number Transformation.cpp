#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, s, t, ans, current, dist[SIZE], parent[SIZE];
bool mark[SIZE];
vector<long long> gr[SIZE];
long long a, b, c, d, e, f;
queue<long long> q;
vector<long long>::iterator itVec;
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    mark[1] = false;
    for (a = 2; a < SIZE; a++)
    {
        if (mark[a])
        {
            for (b = 2*a; b < SIZE; b+=a)
            {
                mark[b] = false;
                gr[b].push_back( b+a );
            }
        }
    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%lld %lld", &s, &t);
        //cout << "s = " <<s << ", t = " << t << endl;
        q = queue<long long>();
        q.push( s );
        memset(dist, -1, sizeof(dist));
        memset(parent, -1, sizeof(parent));
        dist[s] = 0;
        parent[s] = s;
        while( !q.empty() )
        {
            current = q.front();
            q.pop();
            if ( current>t ) continue;
            //cout << "current = " << current << endl;
            //cout << "gr[current].begin()-gr[current].end() = " << gr[current].begin()-gr[current].end() << endl;
            for ( itVec = gr[current].begin(); itVec != gr[current].end(); itVec++ )
            {
                //cout << "*itVec = " << (*itVec) << endl;
                if( dist[ *itVec ] == -1 )
                {
                    parent[ *itVec ] = current;
                    dist[ *itVec ] = dist[current]+1;
                    q.push(*itVec);
                }
            }
        }
        printf("Case %lld: %lld\n", a, dist[t]);
    }
    return 0;
}
