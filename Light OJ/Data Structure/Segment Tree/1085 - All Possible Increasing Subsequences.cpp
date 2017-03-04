#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
#define MOD 1000000007
struct item
{
    int idx, val;
    item(){}
};
bool cmp(item a, item b)
{
    if ( a.val == b.val ) return a.idx > b.idx;
    return a.val < b.val;
}
item ar[SIZE];
int T, n, BIT[SIZE], ans, val, addee;
int i, j, k, a, b, c;
int read(int idx)
{
    int ret = 0;
    while(idx > 0)
    {
        ret = (ret%MOD + BIT[idx]%MOD ) % MOD;
        idx -= (idx & -idx);
    }
    return ret;
}
void add(int idx, int val)
{
    while(idx <= n)
    {
        BIT[idx] = (BIT[idx]%MOD + val%MOD ) % MOD;
        idx += (idx & -idx);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(BIT, 0, sizeof(BIT));
        ans = 0;
        cin >> n;
        for (j = 1; j <= n; j++)
        {
            scanf("%d", &ar[j].val);
            ar[j].idx = j;
        }
        //for (j = 1; j <= n; j++)
        //{
            //add( ar[j].idx, ar[j].val );
        //}
        sort(ar+1, ar+n+1, cmp);
        for (j = 1; j <= n; j++)
        {
            //cout << "j = " << j << ", idx = " << ar[j].idx << ", val = " << ar[j].val << endl;
        }
        for (j = 1; j <= n; j++ )
        {
            addee = read( ar[j].idx-1 );
            add( ar[j].idx, 1+addee );
        }
        for (j = 1; j <= n; j++)
        {
            //cout << "BIT[" << j << "] = " << BIT[j] << endl;
            ans = read(n);
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
