#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long T, N, M, K;
long long xAr[SIZE], pos[1009], minPos, ans;
long long a, b, c, d, e, f, g, h;
struct obj
{
    long long idx, val;
    obj(){}
    obj(long long idx, long long val)
    {
        this->idx = idx;
        this->val = val;
    }
    bool const operator < (obj b) const
    {
        if ( val == b.val ) return idx < b.idx;
        return val < b.val;
    }
};
vector<obj> vecObj;
int main()
{
    //freopen("input.txt", "r", stdin);
    xAr[1] = 1;
    xAr[2] = 2;
    xAr[3] = 3;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = INT_MAX;
        memset(pos, -1, sizeof(pos) );
        cin >> N >> M >> K;

        for (b = 1; b <= N; b++)
        {
            //cout << "b = " << b << endl;
            if ( b <= 3 )
            {
                xAr[b] = b;
            }
            else xAr[b] = (xAr[b-1]+xAr[b-2]+xAr[b-3])%M + 1;
            minPos = INT_MAX;
            pos[ xAr[b] ] = b;
            for (c = 1; c <= K; c++)
            {
                minPos = min(minPos, pos[c] );
            }
            //cout << "pos[1] = " << pos[1] << endl;
            //cout << "minPos = " << minPos << endl;
            if( minPos >= 1 ) ans = min(ans, b-minPos);
        }
        if ( ans >= INT_MAX/2 ) cout << "Case " << a << ": sequence nai" ;
        else cout << "Case " << a << ": " << (ans+1) ;
        cout << endl;
    }
    return 0;
}
