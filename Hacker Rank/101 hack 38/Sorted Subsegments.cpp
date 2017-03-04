#include <bits/stdc++.h>
using namespace std;
#define SIZE 75009
long long n, q, k, A[SIZE], isSorted[SIZE], len;
long long a, b, c, d, e, f, g, st, en;
struct query
{
    long long startIdx, endIdx;
    query(){}
    query(long long startIdx, long long endIdx)
    {
        this->startIdx = startIdx;
        this->endIdx = endIdx;
    }
};
bool cmpFunc(const query a, const query b)
{
    if ( a.startIdx == b.startIdx ) return a.endIdx<b.endIdx;
    return a.startIdx < b.startIdx;
}
vector<query> quVec;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> q >> k;
    for (a = 0; a < n; a++)
    {
        scanf("%lld", &A[a]);
    }
    for (a = 1; a <= q; a++)
    {
        scanf("%lld %lld", &st, &en);
        quVec.push_back( query(st, en) );
    }
    sort( quVec.begin(), quVec.end(), cmpFunc );
    len = quVec.size();
    for (a = quVec[0].startIdx; a <= quVec[0].endIdx; a++)
    {
        isSorted[a] = 1;
    }
    for (a = 1; a < len; a++)
    {
        for (b = max(quVec[a-1].endIdx, quVec[a].startIdx); b <= quVec[a].endIdx; b++ )
        {
            isSorted[b] = 1;
        }
    }
    if ( isSorted[k] == 0 )
    {
        cout << A[k] ;
        return 0;
    }
    for (a = k+1; a < n; a++)
    {
        if ( isSorted[a] == 0 ) break;
    }
    en = a-1;
    for (a = k-1; a >= 0; a--)
    {
        if ( isSorted[a] == 0 ) break;
    }
    st = a+1;
    //cout << "st = " << st << endl;
    //cout << "en = " << en << endl;
    sort(A+st, A+en+1);
    for ( a = 0; a < n; a++ )
    {
        //cout << A[a] << " ";
    }
    //cout << endl;
    cout << A[k];
    return 0;
}
