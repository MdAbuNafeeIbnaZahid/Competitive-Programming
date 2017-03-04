#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long T, N, w, k, xi, yi, thisSwipe, ans, len;
long long startIdx, endIdx, posSwipe, dp[SIZE][SIZE];
long long a, b, c, d, e, f;
map<long long, long long> dustInHeight;
map<long long, long long>::iterator mapLLIt, mapLLItInside;
struct dust
{
    long long startH, endH, quantity;
    dust(){}
    dust(long long startH, long long endH, long long quantity)
    {
        this->startH = startH;
        this->endH = endH;
        this->quantity = quantity;
    }
};
vector<dust> dustVector;
long long recDp(long long sweep, long long idx)
{
    long long a, b, c, d, e, f, prevIdx;
    if ( sweep <= 0 || idx <= 0 ) return 0;
    if ( dp[sweep][idx] == -1 )
    {
        for (prevIdx = idx-1; prevIdx >= 1; prevIdx-- )
        {
            if ( dustVector[prevIdx-1].endH < dustVector[idx-1].startH ) break;
        }
        dp[sweep][idx] = max(recDp(sweep-1, prevIdx)+dustVector[idx-1].quantity,
                             recDp(sweep, idx-1));
    }
    return dp[sweep][idx];
}
dust newDust;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(dp, -1, sizeof(dp));
        ans = 0;
        dustInHeight = map<long long, long long>();
        dustVector = vector<dust>();
        cin >> N >> w >> k;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lld", &xi, &yi);
            dustInHeight[yi]++;
        }
        for (mapLLIt = dustInHeight.begin(); mapLLIt != dustInHeight.end(); mapLLIt++)
        {
            newDust = dust();
            newDust.startH = mapLLIt->first;
            newDust.endH = mapLLIt->first+w;
            newDust.quantity = 0;
            for (mapLLItInside = mapLLIt; mapLLItInside != dustInHeight.end(); mapLLItInside++)
            {
                if ( mapLLItInside->first <= newDust.endH ) newDust.quantity += mapLLItInside->second;
                else break;
            }
            dustVector.push_back( newDust );
        }
        len = dustVector.size();
        for (b = 0; b < len; b++)
        {
            //cout << "b = " << b << endl;
            //cout << "startH = " << dustVector[b].startH << endl;
            //cout << "endH = " << dustVector[b].endH << endl;
            //cout << "quantity = " << dustVector[b].quantity << endl;
        }
        for (b = 0; b <= k; b++)
        {
            for (c = 0; c <= len; c++)
            {
                dp[b][c] = recDp(b, c);
            }
        }
        for (b = 0; b <= k; b++)
        {
            for (c = 0; c <= len; c++)
            {
                //cout << dp[b][c] << " ";
            }
            //cout << endl;
        }
        ans = recDp(k, len);
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
