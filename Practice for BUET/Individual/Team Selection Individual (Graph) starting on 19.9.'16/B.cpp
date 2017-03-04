#include <bits/stdc++.h>
using namespace std;
#define SIZE 509
long long N, S, E, X, Y, Z, M, K;
long long a,b, c, d, e, f, g, h, len, minIdx, minDist, current, ifOneComplete;
long long distFromS[SIZE], distFromE[SIZE], parentFromS[SIZE], parentFromE[SIZE];
struct edge
{
    long long from, to, w;
    edge(){}
    edge(long long from, long long to, long long w)
    {
        this->from = from;
        this->to = to;
        this->w = w;
    }
};
struct node
{
    long long idx, dist;
    node(){}
    node(long long idx,long long dist)
    {
        this->idx = idx;
        this->dist = dist;
    }
    const bool operator < (node B) const
    {
        if ( dist == B.dist ) return idx < B.idx;
        return dist < B.dist;
    }
};
vector<edge> gr[SIZE];
vector<edge> com;
vector<long long> part1, part2;
void dijkstra(long long source, long long *distAr, long long *parentAr)
{
    long long a, b, c, d, e, f, g, len, current;
    set<node> setNode;
    set<node>::iterator setNodeIt;
    for (a = 1; a <= N; a++)
    {
        distAr[a] = INT_MAX;
    }
    distAr[source] = 0;
    parentAr[source] = 0;
    setNode.insert( node(source, 0) );
    while( setNode.size() )
    {

        setNodeIt = setNode.begin();
        current = setNodeIt->idx;
        setNode.erase( setNodeIt );
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            if ( distAr[current]+gr[current][a].w < distAr[ gr[current][a].to ] )
            {
                distAr[ gr[current][a].to ] = distAr[current]+gr[current][a].w;
                parentAr[gr[current][a].to] = current;
                setNode.insert( node(gr[current][a].to, distAr[ gr[current][a].to ] ) );
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("myOutput.txt", "w", stdout);
    while( scanf("%lld %lld %lld", &N, &S, &E) != EOF )
    {
        if( ifOneComplete ) cout <<  endl;
        for (a = 1; a <= N; a++)
        {
            distFromS[a] = INT_MAX;
            distFromE[a] = INT_MAX;
            gr[a] = vector<edge>();
        }
        com = vector<edge>();
        part1 = vector<long long>();
        part2 = vector<long long>();
        cin >> M;
        for (a = 1; a <= M; a++)
        {
            scanf("%lld %lld %lld", &X, &Y, &Z);
            gr[X].push_back( edge(X, Y, Z) );
            gr[Y].push_back( edge(Y, X, Z) );
        }
        cin >> K;
        for (a = 1; a <= K; a++)
        {
            scanf("%lld %lld %lld", &X, &Y, &Z);
            com.push_back( edge(X, Y, Z) );
            com.push_back( edge(Y, X, Z) );
        }
        for (a = 1; a <= N; a++)
        {
            com.push_back( edge(a, a, 0) );
        }
        dijkstra(S, distFromS, parentFromS);
        dijkstra(E, distFromE, parentFromE);
        len = com.size();
        minIdx = 0;
        minDist = INT_MAX;
        for (a = 0; a < len; a++)
        {
            if(distFromS[ com[a].from ] + com[a].w + distFromE[ com[a].to ] < minDist )
            {
                minDist = distFromS[ com[a].from ] + com[a].w + distFromE[ com[a].to ];
                minIdx = a;
            }
        }

        if ( S == E )
        {
            cout << S << endl;
            cout << "Ticket Not Used" << endl;
            cout << 0 << endl ;
            continue;
        }

        //cout << "minDist = " << minDist << endl;
        //cout << "minIdx = " << minIdx << endl;
        current = com[minIdx].from;
        while(current != S)
        {
            part1.push_back(current);
            current = parentFromS[current];
        }
        part1.push_back(S);

        len = part1.size();
        printf("%lld", part1[len-1]);
        for (a = len-2; a >= 0; a--)
        {
            printf(" %lld", part1[a]);
        }

        current = com[minIdx].to;
        while(current != E)
        {
            part2.push_back(current);
            current = parentFromE[current];
        }
        part2.push_back( E );
        len = part2.size();
        if ( part2[0] != part1[0] )
        {
            printf(" %lld",part2[0]);
        }
        for (a = 1; a < len; a++)
        {
            printf(" %lld",part2[a]);
            //if ( a < len-1 ) printf(" ");
        }
        printf("\n");
        if ( com[minIdx].w == 0 )
        {
            cout << "Ticket Not Used" << endl;
        }
        else
        {
            cout << com[minIdx].from << endl;
        }
        cout << minDist << endl ;
        //cout << endl;
        ifOneComplete = 1;
    }
    //cout << endl;
    return 0;
}
