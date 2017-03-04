#include <bits/stdc++.h>
using namespace std;
long long a, b;
long long dp[39][19][4][4];
vector<long long> vecA, vecB;
long long copA, copB, len, ans, ansStart;
long long c, d, e, f, g, h, i;
struct idx
{
    long long pos, dig, ifLowBound, ifHighBound;
    idx(){}
    idx(long long pos, long long dig, long long ifLowBound, long long ifHighBound)
    {
        this->pos = pos;
        this->dig = dig;
        this->ifLowBound = ifLowBound;
        this->ifHighBound = ifHighBound;
    }
};
idx solution[39][19][4][4], myIdx;
long long recDp(long long pos, long long dig, long long ifLowBound, long long ifHighBound)
{
    long long a, b, c, d, e, f, low, high;
    if ( dp[pos][dig][ifLowBound][ifHighBound] == -1 )
    {
        if ( pos == 0 )
        {
            dp[pos][dig][ifLowBound][ifHighBound] = dig;
            return dp[pos][dig][ifLowBound][ifHighBound];
        }
        low = (ifLowBound ? vecA[pos]: 0);
        high = (ifHighBound ? vecB[pos] : 9);
        for (a = low; a <= high; a++)
        {
            if ( dig*recDp(pos-1, a, (a<=low?ifLowBound:0), (a>=high?ifHighBound:0) )
                > dp[pos][dig][ifLowBound][ifHighBound] )
            {
                dp[pos][dig][ifLowBound][ifHighBound] = dig*recDp(pos-1, a, 0, 0);
                solution[pos][dig][ifLowBound][ifHighBound].pos = pos-1;
                solution[pos][dig][ifLowBound][ifHighBound].dig = a;
                solution[pos][dig][ifLowBound][ifHighBound].ifLowBound = (a<=low?ifLowBound:0);
                solution[pos][dig][ifLowBound][ifHighBound].ifHighBound = (a>=high?ifHighBound:0);
            }
        }
    }
    return dp[pos][dig][ifLowBound][ifHighBound];
}
int main()
{
    memset(dp, -1, sizeof(dp));
    ans = -1;
    cin >> a >> b;
    copA = a;
    copB = b;
    while(copA || copB)
    {
        vecA.push_back( copA%10 );
        copA /= 10;
        vecB.push_back( copB%10 );
        copB /= 10;
    }
    len = vecA.size();
    cout << "len = " << len << endl;
    for (c = vecA[len-1]; c <= vecB[len-1]; c++)
    {
        cout << "c = " << c << endl;
        cout << "recDp(len-1, c, (c<=vecA[len-1]), (c>=vecB[len-1]) ) = "
            << recDp(len-1, c, (c<=vecA[len-1]), (c>=vecB[len-1]) ) << endl;
        if ( recDp(len-1, c, (c<=vecA[len-1]), (c>=vecB[len-1]) ) > ans )
        {
            ans = recDp(len-1, c, (c<=vecA[len-1]), (c>=vecB[len-1]) );
            ansStart = c;
            myIdx = solution[len-1][c][(c<=vecA[len-1])][(c>=vecB[len-1])];
        }
    }
    cout << ans;
    return 0;
}
