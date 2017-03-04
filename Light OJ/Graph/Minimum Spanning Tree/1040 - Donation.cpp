#include <bits/stdc++.h>
using namespace std;
#define SIZE 59
int T, n, gr[SIZE][SIZE], p[SIZE], total[SIZE], i, j;
int a, b, c, d, e, f, ans, w;
int getParent(int u)
{
    if (p[u]==u) return u;
    p[u] = getParent( p[u] );
    return p[u];
}
void makeUnion(int u, int v)
{
    total[ getParent(v) ] += total[ getParent(u) ];
    p[ getParent(u) ] = getParent(v);
}
struct edge
{
    int from, to, weight;
    edge(){}
    edge(int from, int to, int weight)
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
    for (a = 1; a <= T; a++)
    {
        vec = vector<edge>();
        ans = 0;
        cin >> n;
        for (i = 0; i < SIZE; i++)
        {
            p[i] = i;
            total[i] = 1;
        }
        for (i = 1; i <= n; i++)
        {
            //p[i] = i;
            //total[i] = 1;
            for (j = 1; j <= n; j++)
            {
                scanf("%d", &gr[i][j]);
                vec.push_back( edge(i, j, gr[i][j]) );
                //cout << gr[i][j] << " ";
            }
            //cout << endl;
        }
        sort(vec.begin(), vec.end(), cmp);
        for (it=vec.begin(); it!=vec.end(); it++)
        {
            i = it->from;
            j = it->to;
            w = it->weight;
            //cout << "i = " << i << ", j = " << j << ", w = " << w << endl;
            //cout << "total[getParent(1)] = " << total[getParent(1)] << endl;
            if (w==0) continue;
            if (getParent(i)==getParent(j)) ans+=w;
            else makeUnion(i, j);
        }
        if (total[getParent(1)]<n) ans = -1;
        cout << "Case " << a << ": " << ans << endl;
        //cout << "total[getParent(1)] = " << total[getParent(1)] << endl;
    }
    return 0;
}
