#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long testCases, N, height[SIZE], width[SIZE], ansInc[SIZE], ansDec[SIZE];
long long incAns, decAns;
long long a, b, c, d, e;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        cin >> N;
        for (b = 1; b <= N; b++) ansInc[b] = ansDec[b] = INT_MIN;
        for (b = 1; b <= N; b++) scanf("%lld", &height[b]);
        for (b = 1; b <= N; b++) scanf("%lld", &width[b]);
        for (b = 1; b <= N; b++)
        {
            ansInc[b] = ansDec[b] = width[b];
        }
        incAns = decAns = width[1];
        for (b = 2; b <= N; b++)
        {
            for (c = b-1; c >= 1; c--)
            {
                if ( height[b] > height[c] )
                {
                    ansInc[b] = max( ansInc[b], ansInc[c] + width[b] );
                }
                incAns = max(incAns, ansInc[b]);
                //cout << "ansInc[" << b << "] = " << ansInc[b] << endl;
                //cout << "incAns = " << incAns << endl;
                if (height[b] < height[c] )
                {
                    ansDec[b] = max( ansDec[b], ansDec[c] + width[b] );
                }
                decAns = max(decAns, ansDec[b]);
                //cout << "ansDec[" << b << "] = " << ansDec[b] << endl;
                //cout << "decAns = " << decAns << endl;
            }
        }
        if ( incAns >= decAns ) printf("Case %lld. Increasing (%lld). Decreasing (%lld).\n", a, incAns, decAns);
        else printf("Case %lld. Decreasing (%lld). Increasing (%lld).\n", a, decAns, incAns);
    }
    return 0;
}
