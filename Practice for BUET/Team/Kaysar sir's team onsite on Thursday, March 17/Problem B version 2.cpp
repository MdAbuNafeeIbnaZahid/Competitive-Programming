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
    parent[ getParent(u) ] = getParent(v);
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
    //cout << "file opened " << endl;
    long long MAX = (1<<30)-1;
    cin >> T;
    //cout << "T = " << T << endl;
    for (i = 1; i <= T; i++)
    {
        for (j = 0; j < SIZE; j++)
        {
            parent[j] = j;
            total[j] = MAX;
        }
        vecBundle = vector<bundle>();
        cin >> n >> m;
        ans = n*MAX;
        //cout << "at first ans = " << ans << endl;
        //cout << "n = " << n << ", m = " << m << endl;
        for (j = 1; j <= m; j++)
        {
            scanf("%lld %lld", &p, &s);
            vecBundle.push_back( bundle(p, s) );
            for (k = 1; k <= s; k++)
            {
                scanf("%lld", &des);
                (vecBundle[j-1].vec).push_back(des);
            }
        }
        //cout << "input taken " << endl;
        sort(vecBundle.begin(), vecBundle.end(), cmp);
        for (itBun=vecBundle.begin(); itBun!=vecBundle.end(); itBun++)
        {
            //cout << "p = " << itBun->p << ", s = " << itBun->s << endl;
        }
        for (itBun=vecBundle.begin(); itBun!=vecBundle.end(); itBun++)
        {
            //cout << "p = " << itBun->p << ", s = " << itBun->s << endl;
            previous = 0;
            parts = set<long long>();
            for (j = 0; j < itBun->s; j++)
            {
                parts.insert(   getParent ( (itBun->vec)[j] )  );
            }
            for (setLLIt = parts.begin(); setLLIt != parts.end(); setLLIt++)
            {
                previous += total[ *setLLIt ];
            }
            //cout << "previous = " << previous << endl;
            if ( itBun->p < previous )
            {
                ans -= previous;
                ans += itBun->p;
                for (setLLIt = parts.begin(); setLLIt!=parts.end(); setLLIt++)
                {
                    makeUnion(*setLLIt, *(parts.begin()) ) ;
                }
                total[ getParent(*(parts.begin())) ] = itBun->p;
            }
            //cout << "ans = " << ans << endl;
        }
        cout << ans << endl;
    }
    return 0;
}
