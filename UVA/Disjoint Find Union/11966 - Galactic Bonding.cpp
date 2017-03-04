#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
int T, N, p[SIZE], i, j, k;
double D, X, Y;
int getParent(int a)
{
    if (p[a] == a) return a;
    p[a] = getParent( p[a] );
    return p[a];
}
void makeUnion(int a, int b)
{
    p[ getParent(a) ] = getParent(b);
}
struct coOrd
{
    double x, y;
    coOrd(){}
    coOrd(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
};
coOrd co[SIZE];
set<int> s;
double getDist(coOrd c1, coOrd c2)
{
    return sqrt( (c1.x-c2.x)*(c1.x-c2.x) + (c1.y-c2.y)*(c1.y-c2.y) );
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        s = set<int>();
        cin >> N >> D;
        for (j = 1; j <= N; j++)
        {
            cin >> X >> Y;
            co[j] = coOrd(X, Y);
        }
        for (j = 1; j <= N; j++)
        {
            p[j] = j;
        }
        for (j = 1; j < N; j++)
        {
            for (k = j+1; k <= N; k++)
            {
                //cout << "dist between " << j << "& " << k << " = " << getDist( co[j], co[k] ) << endl;
                if ( getDist( co[j], co[k] ) <= D )
                {
                    makeUnion(j, k);
                }
            }
        }
        for (j = 1; j <= N; j++)
        {
            s.insert( getParent(j) );
        }
        cout << "Case " << i << ": " << s.size() << endl;
    }
    return 0;
}
