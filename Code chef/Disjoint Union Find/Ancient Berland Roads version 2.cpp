#include <bits/stdc++.h>
using namespace std;
#define SIZE 500009
int N, M, Q, D, K, P, A, X;
int i, j, a, b, x, y, ifDestroyed[SIZE], parent[SIZE],  maxPopu = -1;
long long sum[SIZE], ans[SIZE];
int currentPopu[SIZE];
multiset<long long> popuSet;
char str[SIZE][100], ch;
struct edge
{
    int u, v;
    edge(){}
    edge(int u, int v)
    {
        this->u = u;
        this->v = v;
    }
};
stack<int> popu[SIZE];
stack<char*> query;
edge roads[SIZE];
int getParent(int a)
{
    if (parent[a] == a) return a;
    parent[a] = getParent( parent[a] );
    return parent[a];
}
void printIntMulSet(multiset<int> s)
{
    multiset<int>::iterator setIt;
    for (setIt = s.begin(); setIt!=s.end(); setIt++) cout << *setIt << " ";
    cout << endl;
}
void changeValue(int idx, int newValue)
{
    popuSet.erase( popuSet.find( sum[ getParent(idx) ] ) );
    popuSet.insert( sum[ getParent(idx) ] + newValue - currentPopu[idx] );
    sum[ getParent(idx) ] = sum[ getParent(idx) ] + newValue - currentPopu[idx];
    currentPopu[idx] = newValue;
}
void makeUnion(int a, int b)
{
    if ( getParent(a)==getParent(b) ) return;
    popuSet.erase( popuSet.find( sum[ getParent(b) ] ) );
    popuSet.erase( popuSet.find( sum[ getParent(a) ] ) );
    sum[ getParent(b) ] += sum[ getParent(a) ];
    popuSet.insert( sum[ getParent(b) ] );
    parent[ getParent(a) ] = getParent(b);
}
int main()
{
    freopen("input.txt", "r", stdin);
    for (i = 0; i < SIZE; i++) parent[i] = i;
    cin >> N >> M >> Q;
    for (i = 1; i <= N; i++)
    {
        cin >> a;
        popu[i].push(a);
    }
    for (i = 1; i <= M; i++)
    {
        cin >> x >> y;
        roads[i] = edge(x, y);
    }
    getchar();
    for (i = 1; i <= Q; i++)
    {
        gets(str[i]);
    }
    for (i = 1; i <= Q; i++)
    {
        if ( str[i][0] == 'P' )
        {
            sscanf(str[i], "%c %d %d", &ch, &A, &X);
            popu[A].push(X);
        }
        else if ( str[i][0] == 'D')
        {
            sscanf(str[i], "%c %d", &ch, &K);
            ifDestroyed[K] = 1;
        }
    }
    for (i = 1; i <= N; i++)
    {
        sum[i] = popu[i].top();
        currentPopu[i] = popu[i].top();
        popu[i].pop();
        popuSet.insert( currentPopu[i] );
    }
    for (i = 1; i <= M; i++)
    {
        if ( ifDestroyed[i]==0 )
        {
            makeUnion( roads[i].u, roads[i].v );
        }
    }
    for (i = Q; i >= 1; i--)
    {
        ans[i] = *(--popuSet.end());
        if ( str[i][0] == 'P' )
        {
            sscanf(str[i], "%c %d %d", &ch, &A, &X);
            changeValue( A, popu[A].top() );
            popu[A].pop();
        }
        else if ( str[i][0] == 'D')
        {
            sscanf(str[i], "%c %d", &ch, &K);
            makeUnion(roads[K].u, roads[K].v);
        }
    }
    for (i = 1; i <= Q; i++)
    {
        cout << ans[i] << endl;
    }
    return 0;
}
