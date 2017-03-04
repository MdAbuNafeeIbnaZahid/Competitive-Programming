#include <bits/stdc++.h>
using namespace std;
int T, m;
int i, j, k, w, ans;
string u, v;
map<string, string> p;
map<string, int> total;
string getParent(string u)
{
    if (p[u]==u) return u;
    p[u] = getParent( p[u] );
    return p[u];
}
void makeUnion(string u, string v)
{
    total[ getParent(v) ]+=total[getParent(u)];
    p[ getParent(u) ] = p[getParent(v)];
}
struct edge
{
    string from, to;
    int weight;
    edge(){}
    edge(string from, string to, int weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};
vector<edge> vec;
vector<edge>::iterator it;
bool cmp(edge a, edge b)
{
    return a.weight<b.weight;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        vec = vector<edge>();
        ans = 0;
        p = map<string, string>();
        total = map<string, int>();
        cin >> m;
        for (j = 1; j <= m; j++)
        {
            cin >> u >> v >> w;
            p[u] = u;
            total[u] = 1;
            p[v] = v;
            total[v] = 1;
            vec.push_back( edge(u, v, w) );
        }
        sort(vec.begin(), vec.end(), cmp);
        for (it=vec.begin(); it!=vec.end(); it++)
        {
            u = it->from;
            v = it->to;
            w = it->weight;
            if ( getParent(u)==getParent(v) ) continue;
            ans+=w;
            makeUnion(u, v);
        }
        if (total[ getParent(u) ]!=p.size()) cout << "Case " << i << ": Impossible" << endl;
        else cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
