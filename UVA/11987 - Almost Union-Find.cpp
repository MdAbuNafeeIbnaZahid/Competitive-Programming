#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
#define SIZE 100009
long long n, m, input[SIZE], parent[SIZE], i, j, k, a, b, c, x, y, z;
long long order, p, q, sum[SIZE], total[SIZE];
vector<int> childs[SIZE];
int myFindParent(int a)
{
    int i;
    if ( parent[a] == a) return a;
    //childs[ parent[a] ].erase( find(childs[parent[a]].begin(), childs[parent[a]].end(), ) );
    parent[a] = myFindParent( parent[a] );
    //if ( find(childs[ parent[a] ].begin(), childs[ parent[a] ].end(), a) != childs[ parent[a] ].end() )
    for (i = 0; i<childs[parent[a]].size(); i++) if ( childs[parent[a]][i] == a ) break;
    if (i >= childs[parent[a]].size()) childs[ parent[a] ].push_back( a );
    return parent[a];
}

int f1(int p, int q)
{
    if (myFindParent(p) == myFindParent(q) ) return 0;

    int tot = total[ myFindParent(p) ] + total[ myFindParent(q) ];
    total[ myFindParent(p) ] = total[ myFindParent(q) ] = tot;

    int s = sum[myFindParent(p)] + sum[myFindParent(q)];
    sum[myFindParent(p)] = sum[myFindParent(q)] = s;

    childs[ myFindParent(q) ].push_back( myFindParent(p) );
    parent[ myFindParent(p) ] = myFindParent(q);
}

int f2(int p, int q)
{
    int i, j;
    if (myFindParent(p) == myFindParent(q) ) return 0;

    total[ myFindParent(p) ]--;
    sum[ myFindParent(p) ] -= p;

    total[myFindParent(q)]++;
    sum[myFindParent(q)] += p;

    cout << "before the for loop in f2" << endl;
    for (i = 0; i < childs[ parent[p] ].size(); i++)
    {
        cout << " childs[ parent[p] ].size() = " << childs[ parent[p] ].size() << endl;
        cout << "childs[ parent[p] ][i] = " << childs[ parent[p] ][i] << endl;
        myFindParent( childs[ parent[p] ][i] );
    }
    cout << "after the for loop in f2" << endl;

    parent[p] = myFindParent(q);
}

void printVector( vector<int> v)
{
    int i;
    for (i = 0; i < v.size(); i++) cout << v[i] << " ";
    cout << endl;
}

int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf("%lld %lld", &n, &m) != EOF )
    {
        for (i = 1; i <= n; i++)
        {
            parent[i] = i;
            sum[i] = i;
            total[i] = 1;
            childs[i] = vector<int>();
            //childs[i].push_back(i);
        }
        for (i = 1; i <= m; i++)
        {
            cin >> order;
            if (order == 1)
            {
                cin >> p >> q;
                cout << "order = " << order << ", p = " << p << ", q = " << q << endl;
                f1(p, q);
            }
            else if (order == 2)
            {
                cin >> p >> q;
                cout << "order = " << order << ", p = " << p << ", q = " << q << endl;
                f2(p, q);
            }
            else if (order == 3)
            {
                cin >> p;
                cout << "order = " << order << ", p = " << p << endl;
                cout << total[ myFindParent(p) ] << " " << sum[ myFindParent(p) ] << endl;
            }
            for (j = 1; j <= n; j++) cout << parent[j] << " ";
            cout << endl;
            for (j = 1; j <= n; j++) cout << sum[j] << " ";
            cout << endl;
            for (j = 1; j <= n; j++) cout << total[j] << " ";
            cout << endl;
            for (j = 1; j <= n; j++)
            {
                cout << "childs of " << j <<"= ";
                printVector( childs[j] );
            }
        }
    }
    return 0;
}
