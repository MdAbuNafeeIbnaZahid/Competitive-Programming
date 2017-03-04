#include <bits/stdc++.h>
using namespace std;
#define SIZE 200
long long T, n, m, des, ans, p, s, previous;
long long i, j, k;
long long parent[SIZE], total[SIZE];
long long getParent(long long u)
{
    if (parent[u]==u) return u;
    parent[(int)u] = getParent( parent[u] );
    return parent[u];
}
void makeUnion(long long u, long long v)
{
    if ( getParent(u)==getParent(v) ) return;
}
struct bundle
{
    long long p, s;
    vector<long long> vec;
    bundle(){}
    bundle(long long p, long long s)
    {
        this->p = p;
        this->s = s;
    }
};
bool cmp(bundle a, bundle b)
{
    if ( a.s==b.s ) return a.p<b.p;
    return a.s<b.s;
}
vector<bundle> vecBundle;
vector<bundle>::iterator itBun;
set<long long> parts;
set<long long>::iterator setLLIt;;
int main()
{
    freopen("input.txt", "r", stdin);
    long long MAX = (1<<30)-1;
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            parent[j] = j;
            total[j] = MAX;
        }
        ans = 0;
        vecBundle = vector<bundle>();
        cin >> n >> m;
        for (j = 1; j <= m; j++)
        {
            scanf("%lf %lf", &p, &s);
            vecBundle.push_back( bundle(p, s) );
            for (k = 1; k <= s; k++)
            {
                scanf("%d", &des);
                (vecBundle[j-1].vec).push_back(des);
            }
        }
        sort(vecBundle.begin(), vecBundle.end(), cmp);
        for (itBun=vecBundle.begin(); itBun!=vecBundle.end(); itBun++)
        {
            previous = 0;
            parts = set<long long>();
            for (j = 0; j < itBun->s; j++)
            {
                parts.insert( (itBun->vec)[j] );
            }
            for (setLLIt = parts.begin(); setLLIt != parts.end(); setLLIt++)
            {
                previous += total[ *setLLIt ];
            }
            if ( itBun->p < previous )
            {
                ans -= previous;
                ans += p;
                for (setLLIt = parts.begin(); setLLIt!=parts.end(); setLLIt++)
                {
                    makeUnion(*setLLIt, *(parts.begin()) ) ;
                }
                total[ *(parts.begin()) ] = p;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
