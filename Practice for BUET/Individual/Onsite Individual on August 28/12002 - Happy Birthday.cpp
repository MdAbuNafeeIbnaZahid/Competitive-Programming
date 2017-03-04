#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long N, kAr[SIZE], nonDec[SIZE], nonInc[SIZE], nonDecGr[SIZE], nonIncSm[SIZE];
long long a, b, c, d, e, f, g, h, ans, len;
vector<long long> dishVec[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        for (a = 0; a < SIZE; a++)
        {
            dishVec[a] = vector<long long>();
            nonDecGr[a] = nonIncSm[a] = 0;
        }
        ans = 0;
        cin >> N;
        //cout << "N = " << N << endl;
        if (N==0) return 0;
        for (a = 1; a <= N; a++)
        {
            scanf("%lld", &kAr[a]);
        }
        //cout << "kAr" << endl;
        for (a = 1; a <= N; a++)
        {
            //cout << kAr[a] << " ";
        }
        //cout << endl;
        nonDec[N] = nonInc[N] = 1;
        for (a = N-1; a >= 1; a--)
        {
            nonDec[a] = nonInc[a] = 1;
            for (b = a+1; b <= N; b++)
            {
                if ( kAr[b] >= kAr[a] )
                {
                    nonDec[a] = max( nonDec[a], 1+nonDec[b] );
                }
                if ( kAr[b] <= kAr[a] )
                {
                    nonInc[a] = max( nonInc[a], 1+nonInc[b] );
                }
            }
        }
        //cout << "nonDec" << endl;
        for (a = 1; a <= N; a++)
        {
            //cout << nonDec[a] << " ";
        }
        //cout << endl;
        //cout << "nonInc" << endl;
        for (a = 1; a <= N; a++)
        {
            //cout << nonInc[a] << " ";
        }
        //cout << endl;
        for (a = 1; a <= N; a++)
        {
            for (b = a+1; b <= N; b++)
            {
                if ( kAr[b] > kAr[a] )
                {
                    nonDecGr[a] = max(nonDecGr[a], nonDec[b]);
                }
                else if ( kAr[b] < kAr[a] )
                {
                    nonIncSm[a] = max(nonIncSm[a], nonInc[b] );
                }
            }
        }
        for (a = 1; a <= N; a++)
        {
            dishVec[ kAr[a] ].push_back(a);
        }
        for (a = 0; a < SIZE; a++)
        {
            len = dishVec[a].size();
            for (b = 0; b < len; b++)
            {
                for (c = 0; c < len; c++)
                {
                    ans = max(ans, 1+max(b,c)+nonDecGr[ dishVec[a][b] ] + nonIncSm[ dishVec[a][c] ] );
                    ans = max(ans, 1+max(b,c)+ nonDecGr[ dishVec[a][c] ] + nonIncSm[ dishVec[a][b] ] );
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
