#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
int T, N, W, length, from, to, ans;
int i, j, k, a, b, c, p[SIZE], total[SIZE], u, v, w, dist[SIZE], maxLength;
int getParent(int u)
{
    if ( u==p[u] ) return u;
    p[u] = getParent(p[u]);
    return p[u];
}
void makeUnion(int u, int v)
{
    if ( getParent(u)==getParent(v) ) return;
    total[ getParent(v) ]+=total[ getParent(u) ];
    p[ getParent(u) ] = getParent(v);
}
struct fullEdge
{
    int from, to, length;
    fullEdge(){}
    fullEdge(int from, int to, int length)
    {
        this->from = from;
        this->to = to;
        this->length = length;
    }
    bool operator<(const fullEdge &b) const
    {
        if (length<b.length) return true;
        if (length==b.length && from<b.from) return true;
        if (length==b.length && from==b.from && to<b.to) return true;
        return false;
    }
};
fullEdge f;
struct halfEdge
{
    int to, length;
    halfEdge(){}
    halfEdge(int to, int length)
    {
        this->to = to;
        this->length = length;
    }
};
set<fullEdge> s;
set<fullEdge>::iterator itSet;
vector<halfEdge> MST[SIZE];
void addEdge(int u, int v, int w)
{
    MST[u].push_back( halfEdge(v, w) );
    MST[v].push_back( halfEdge(u, w) );
}
void removeEdge(int u, int v)
{
    vector<halfEdge>::iterator vecIt;
    for ( vecIt=MST[u].begin(); vecIt!=MST[u].end(); vecIt++ )
    {
        if ( vecIt->to==v ) break;
    }
    MST[u].erase( vecIt );

    for ( vecIt=MST[v].begin(); vecIt!=MST[v].end(); vecIt++ )
    {
        if ( vecIt->to==u ) break;
    }
    MST[v].erase( vecIt );
}
void bfs(int u)
{
    int current;
    memset(p, -1, sizeof(p));
    memset(dist, -1, sizeof(dist));
    queue<int> q;
    q.push( u );
    p[u] = -1;
    dist[u] = 0;
    vector<halfEdge>::iterator vecIt;
    while( !q.empty() )
    {
        current = q.front();
        q.pop();
        for (vecIt=MST[current].begin(); vecIt!=MST[current].end(); vecIt++)
        {
            if ( dist[vecIt->to]==-1 )
            {
                q.push( vecIt->to );
                p[ vecIt->to ] = current;
                dist[ vecIt->to ] = vecIt->length;
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cout << "Case " << i << ":" << endl;
        s = set<fullEdge>();
        cin >> N >> W;
        for (j = 1; j <= N; j++)
        {
            p[j] = j;
            total[j] = 1;
            MST[j] = vector<halfEdge>();
        }
        for (j = 1; j <= W; j++)
        {
            scanf("%d %d %d", &from, &to, &length);
            //cout << "from = " << from << ", to = " << to << ", lenght = " << length << endl;
            makeUnion(from, to);
            f = fullEdge(from, to, length);
            s.insert( f );
            //cout << "s.size() = " << s.size() << endl;
            if (total[ getParent(1) ]<N) printf("-1\n");
            else break;
        }
        if (j>W) continue;
        for (k = 1; k <= N; k++)
        {
            p[k] = k;
            total[k] = 1;
        }
        ans = 0;
        for (itSet=s.begin(); itSet!=s.end(); itSet++)
        {
            //cout << "u = " << u << ", v = " << v << ", w = " << w << endl;
            u = itSet->from;
            v = itSet->to;
            w = itSet->length;
            if ( getParent(u)==getParent(v) ) continue;
            //cout << "taken" << endl;
            ans += w;
            makeUnion(u, v);
            addEdge(u, v, w);
        }
        cout << ans << endl;
        for (j = j+1; j <= W; j++)
        {
            scanf("%d %d %d", &from, &to, &length);
            bfs(from);
            maxLength = from;
            k = to;
            while( p[k]!=-1 )
            {
                //cout << "k = " << k << endl;
                if ( dist[k]>dist[maxLength] )
                {
                    maxLength = k;
                }
                k = p[k];
            }
            //cout << "maxLength = " << maxLength << endl;
            if ( dist[maxLength] > length )
            {
                removeEdge(maxLength, p[maxLength]);
                addEdge(from, to, length);
                ans -= dist[maxLength];
                ans += length;
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
