#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
int T, n, u, v, w;
int i, j, k, ansIncr, ansDecr, ans;
int p[SIZE];
int total[SIZE];
int getParent(int u)
{
    if (p[u]==u) return u;
    p[u] = getParent(p[u]);
    return p[u];
}
void makeUnion(int u, int v)
{
    if (getParent(u)==getParent(v)) return;
    total[ getParent(v) ] += total[ getParent(u) ];
    p[ getParent(u) ] = getParent(v);
}
struct edge
{
    int from, to, weight;
    edge(int from, int to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
    edge(){}
};
bool incr(edge a, edge b)
{
    return a.weight<b.weight;
}
bool decr(edge a, edge b)
{
    return a.weight>b.weight;
}
vector<edge> vec;
vector<edge>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ansIncr = 0;
        ansDecr = 0;
        vec = vector<edge>();
        cin >> n;
        while(1)
        {
            scanf("%d %d %d", &u, &v, &w);
            if (u+v+w==0) break;
            vec.push_back( edge(u, v, w) );
        }
        sort(vec.begin(), vec.end(), incr);
        for (j = 0; j <= n; j++)
        {
            p[j] = j;
            total[j] = 1;
        }
        for (it=vec.begin(); it!=vec.end(); it++)
        {
            u = it->from;
            v = it->to;
            w = it->weight;
            if ( total[ getParent(u) ] == (n+1) ) break;
            if ( getParent(u)==getParent(v) ) continue;
            ansIncr += w;
            makeUnion(u, v);
        }
        for (j = 0; j <= n; j++)
        {
            p[j] = j;
            total[j] = 1;
        }
        for (it=vec.end(); it!=vec.begin(); it--)
        {
            u = (it-1)->from;
            v = (it-1)->to;
            w = (it-1)->weight;
            if ( total[ getParent(u) ] == (n+1) ) break;
            if ( getParent(u)==getParent(v) ) continue;
            ansDecr += w;
            makeUnion(u, v);
        }
        //cout << "i = " << i << endl;
        //cout << "ansIncr = " << ansIncr << endl;
        //cout << "ansDecr = " << ansDecr << endl;
        if ((ansIncr+ansDecr)%2==0) cout << "Case " << i << ": " << ((ansIncr+ansDecr)/2) << endl;
        else cout <<  "Case " << i << ": " << (ansIncr+ansDecr) << "/2" << endl;

    }
    return 0;
}
