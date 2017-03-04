#include <bits/stdc++.h>
using namespace std;
#define SIZE 50009
int n, m, cas = 0, a, b, c, x, y, z, p[SIZE], i, j;
set<int> s;
void printAr()
{
    for (int i = 1; i <= n; i++)
    {
        cout << "p[" << i << "]=" << p[i] << " ";
    }
    cout << endl;
}
int getParent(int q)
{
    if ( p[q] == q ) return q;
    p[q] = getParent(p[q]);
    return p[q];
}
void makeUnion(int x, int y)
{
    p[ getParent(x) ] = getParent(y);
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> n >> m;
        //cout << "n = " << n << ", m = " << m << endl;
        if ( (n+m)==0) return 0;
        for (a = 1; a <= n; a++) p[a] = a;
        //cout << "parent initialized " << endl;
        s = set<int>();
        for (a = 1; a<=m; a++)
        {
            cin >> i >> j;
            //cout << "i = " << i << ", j = " << j << endl;
            makeUnion(i, j);
        }
        //cout << "unified " << endl;
        for (a = 1; a <= n; a++) s.insert( getParent(a) );
        cout << "Case " << ++cas << ": " << s.size() << endl;
    }
    return 0;
}
