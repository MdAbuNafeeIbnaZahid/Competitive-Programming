#include <bits/stdc++.h>
using namespace std;
long long maxN, numberOfMoves, a, b, c;
int numberOfWins(int maxN, vector <int> moves)
{
    long long ret, a, b, c, d, e, f, ansAr[909], startIdx, endIdx, period, notPeriodFlag;
    long long winPerPeriod;
    ansAr[0] = 0;
    for (a = 1; a < 901; a++)
    {
        ansAr[a] = 0;
        for (b = 0; b < moves.size() && moves[b] <= a; b++)
        {
            if ( ansAr[a -moves[b] ] == 0 )
            {
                ansAr[a] = 1;
                break;
            }
        }
    }
    for (period = 1; period <= 100; period++)
    {
        notPeriodFlag = 0;
        for (a = 1; a <= 5; a++)
        {
            for (b = 1; b <= period; b++)
            {
                if ( ansAr[b] != ansAr[b+a*period  ] )
                {
                    notPeriodFlag = 1;
                }
            }
        }
        if ( notPeriodFlag == 0 ) break;
    }
    for (a = 1; a <= period; a++)
    {
        if ( ansAr[a] ) winPerPeriod++;
    }
    ret = winPerPeriod * ( maxN / period );
    for (a = 1; a <= maxN % period; a++)
    {
        if ( ansAr[a] ) ret++;
    }
    return ret;
}
int main()
{
    cin >>
    return 0;
}
