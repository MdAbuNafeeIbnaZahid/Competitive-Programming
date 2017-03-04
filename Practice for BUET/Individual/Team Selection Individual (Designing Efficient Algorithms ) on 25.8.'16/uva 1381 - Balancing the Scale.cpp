#include <bits/stdc++.h>
using namespace std;
#define SIZE 70009
long long input[19], idx, sum, testCases, nums[9], cnt, len, ansAr[SIZE], ans;
long long a, b, c, d, e, f, g, h;
vector<long long> sumToBits[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        ans = 0;
        memset(ansAr, 0, sizeof(ansAr) );
        testCases++;
        for (a = 0;a < SIZE; a++)
        {
            sumToBits[a] = vector<long long>();
        }
        scanf("%lld", &input[0] );
        if ( input[0] == 0 ) return 0;
        for (a = 1; a <= 15; a++)
        {
            scanf("%lld", &input[a]);
        }
        //sort(input, input+16);
        for (b = 0; b < (1<<16); b++)
        {
            if ( __builtin_popcountll(b) == 4 )
            {
                cnt = 0;
                for (c = 0; c < 19; c++)
                {
                    if ( 1 & (b>>c) ) nums[++cnt] = input[c];
                }
                if ( cnt != 4 ) cout << "cnt is not 4" << endl;
                sort(nums+1, nums+5);
                sum = 1*nums[1] + 2*nums[2] + 3*nums[3] + 4*nums[4];
                sumToBits[sum].push_back(b);
                len = sumToBits[sum].size();
                for (c = 0; c < len; c++)
                {
                    if ( sumToBits[sum][c] & b ) continue;
                    ansAr[b | sumToBits[sum][c] ]++;
                }
                while( next_permutation(nums+1, nums+5) )
                {
                    sum = 1*nums[1] + 2*nums[2] + 3*nums[3] + 4*nums[4];
                    sumToBits[sum].push_back(b);
                    len = sumToBits[sum].size();
                    for (c = 0; c < len; c++)
                    {
                        if ( sumToBits[sum][c] & b ) continue;
                        ansAr[b | sumToBits[sum][c] ]++;
                    }
                }
            }
        }
        for (b = 0; b < (1<<16); b++)
        {
            if ( __builtin_popcountll(b) == 8 )
            {
                ans += ansAr[b]*ansAr[ ((1<<16)-1) ^ b ];
            }
        }
        //cout << "ans = " << ans << endl;
        ans /= 2;
        cout << "Case " << testCases << ": " << ans << endl;
    }
    return 0;
}
