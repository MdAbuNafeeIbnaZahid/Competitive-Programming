#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long N, M, u, v, w;
long long a, b, c, d, e, f, g, h;
long long parentAr[SIZE], totalAr[SIZE];
long long getParent(long long u)
{
    if ( parentAr[u] != u )
    {
        parentAr[u] = getParent( parentAr[u] );
    }
    return parentAr[u];
}
void makeUnion(long long u, long long v)
{
    if ( getParent(u) == getParent(v) )
    {

    }
}
struct edge
{
    long long u, v, w;
    edge(){}
    edge(long long u, long long v, long long w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
vector<edge> vecEdge;
bool cmp(edge A, edge B)
{
    if ( A.w == B.w )
    {
        if ( A.u == B.u )
        {
            return A.v < B.v;
        }
        return A.u < B.u;
    }
    return A.w < B.w;
}
int main()
{
    cin >> N >> M;
    for (a = 0; a < SIZE; a++)
    {
        parentAr[a] = a;
        totalAr[a] = 1;
    }
    for (a = 1; a <= M; a++)
    {
        scanf("%lld %lld %lld", &u, &v, &w);
        vecEdge.push_back( edge(u, v, w) );
    }
    sort(vecEdge.begin(), vecEdge.end(), cmp);
    for (a = vecEdge.size()-1; a >= 0; a--)
    {

    }
    return 0;
}
