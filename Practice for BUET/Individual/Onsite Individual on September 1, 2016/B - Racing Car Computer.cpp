#include <bits/stdc++.h>
using namespace std;
#define SIZE 1509
long long N, aAr[SIZE], bAr[SIZE], startIdx, endIdx, cntAr[SIZE], sizeAr[SIZE];
long long color[SIZE], isCovered[SIZE];
long long c, d, e, f, g, len, maxCorrect;
struct interval
{
    long long a, b, si, ei;
    interval(){}
    interval(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
    const bool operator < ( interval B )
    {
        if ( si == B.si ) return ei < B.ei;
        return si < B.si;
    }
};
vector<interval> vecIn;
set<interval> setIn;
set<interval>::iterator setInIt;
vector<long long> gr[SIZE];
int main()
{
    while(1)
    {
        maxCorrect = 0;
        vecIn = vector<interval>();
        setIn = set<interval>();
        memset(cntAr, 0, sizeof(cntAr) );
        memset(isCovered, 0, sizeof(isCovered) );
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
                setIn.push_back( interval(a+1, N-b) );
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
            for (d = 0; d < len; d++)
            {
                if ( c == d ) continue;
                if ( vecIn[c].si <= vecIn[d].si && vecIn[d].si <= vecIn[c].ei  ) continue;
                if ( vecIn[c].si <= vecIn[d].ei && vecIn[d].ei <= vecIn[c].ei  ) continue;
                if ( vecIn[d].si <= vecIn[c].si && vecIn[c].si <= vecIn[d].ei  ) continue;
                if ( vecIn[d].si <= vecIn[c].ei && vecIn[c].ei <= vecIn[d].ei  ) continue;
                gr[c].push_back(d);
                gr[d].push_back(c);
            }
        }
        for (c = 0; c < N; c++)
        {
            if ( isCovered[c] ) continue;
            bfs(c);
        }
    }
    return 0;
}
