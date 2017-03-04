#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, N, M, A, X, Y, C, Z;
long long i, j, k, p[SIZE], s, u, v, w;
long long getParent(long long u)
{
    if (p[(int)u]==u) return u;
    p[(int)u] = getParent(p[(int)u]);
    return p[(int)u];
}
void makeUnion(long long u, long long v)
{
    p[ (int)getParent(u) ] = getParent(v);
}
struct edge
{
    long long from, to, weight;
    edge(){}
    edge(long long from, long long to, long long weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
bool cmp(edge a, edge b)
{
    if ( a.weight==b.weight )
    {
        if ( a.from == 0 && b.from == 0) return a.to < b.to;
        if ( a.from == 0 ) return true;
        if ( b.from == 0 ) return false;
        return false;
    }
    return a.weight<b.weight;
}
vector<edge> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        vec = vector<edge>();

        for (j = 0; j < SIZE; j++)
        {
            p[(int)j] = j;
        }
        cin >> N >> M >> A;

        for (j = 1; j <= M; j++)
        {
            scanf("%lld %lld %lld", &X, &Y, &C);
            vec.push_back( edge(X, Y, C) );
        }
        for (j = 1; j <= N; j++)
        {
            vec.push_back( edge(0, j, A) );
        }
        sort(vec.begin(), vec.end(), cmp);

        Y = Z = 0;
        s = vec.size();
        for (j = 0; j < s; j++)
        {
            u = vec[(int)j].from;
            v = vec[(int)j].to;
            w = vec[(int)j].weight;
            if ( getParent(u)==getParent(v) ) continue;
            //cout << u << " " << v << " " << w << endl;
            Y += w;
            if ( (u==0) || (v==0) ) Z++;
            makeUnion(u, v);
        }
        cout << "Case " << i << ": " << Y << " " << Z << endl;
    }
    return 0;
}
