#include <bits/stdc++.h>
using namespace std;
#define SIZE 1509
long long a, b, ans;
long long N, aAr[SIZE], bAr[SIZE], startIdx, endIdx, cntAr[SIZE][SIZE], sizeAr[SIZE];
long long color[SIZE], isCovered[SIZE], dp[SIZE];
long long c, d, e, f, g, len, maxCorrect, testCases;
struct interval
{
    long long a, b, si, ei, val;
    interval(){}
    interval(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
    const bool operator < ( interval B ) const
    {
        if ( ei == B.ei ) return si < B.si;
        return ei < B.ei;
    }
};
vector<interval> vecIn;
set<interval> setIn;
set<interval>::iterator setInIt;
vector<long long> gr[SIZE];
interval current;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        testCases++;
        maxCorrect = 0;
        vecIn = vector<interval>();
        setIn = set<interval>();
        memset(cntAr, 0, sizeof(cntAr) );
        memset(isCovered, 0, sizeof(isCovered) );
        memset(dp, 0, sizeof(dp) );
        cin >> N;
        for (c = 0; c < N+9; c++)
        {
            gr[c] = vector<long long>();
        }
        if (N==0) return 0;
        for (c = 1; c <= N; c++)
        {
            scanf("%lld %lld", &a, &b);
            if (a+b+1 <= N)
            {
                setIn.insert( interval(a+1, N-b) );
                cntAr[a+1][N-b]++;
            }
        }
        for ( setInIt = setIn.begin(); setInIt != setIn.end(); setInIt++ )
        {
            vecIn.push_back( *setInIt );
            cntAr[setInIt->si][setInIt->ei] =
                        min(cntAr[setInIt->si][setInIt->ei], setInIt->ei - setInIt->si +1 );
        }
        len = vecIn.size();
        for (c = 0; c < len; c++)
        {
            current = vecIn[c];
            dp[current.ei] = max( dp[current.ei], dp[current.si - 1] + cntAr[current.si][current.ei] );
            for (d = current.ei + 1; d < SIZE; d++)
            {
                dp[d] = max(dp[d], dp[current.ei]);
            }
        }

        ans = N - dp[SIZE-1];
        cout << "Case " << testCases << ": " << ans << endl;
    }
    return 0;
}

