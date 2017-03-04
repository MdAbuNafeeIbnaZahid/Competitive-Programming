#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long i, L;
long long a, b, c, d, e, f, g, h, K, ansAr[SIZE], p, q, upto, N, myI, myL, startIdx;
long long endIdx, len;
struct interval
{

    long long si, ei;
    interval(){}
    interval(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
};
vector<long long> siVec, eiVec;
int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf("%lld %lld", &i, &L) == 2 )
    {
        siVec = eiVec = vector<long long>();
        memset(ansAr, 0, sizeof(ansAr) );
        for (N = 1; N <= 10000; N++)
        {
            p = 0;
            q = N-1;
            myL = 0;
            while(p <= q)
            {
                myI = (p+q)/2;
                ++myL;
                if ( i < myI  )
                {
                    q = myI - 1;
                }
                else if ( i == myI )
                {
                    break;
                }
                else if ( i > myI )
                {
                    p = myI + 1;
                }
            }
            if ( i == myI )
            {
                if ( myL == L )
                {
                    ansAr[N] = 1;
                    //cout << N << endl;
                }
            }
        }
        for (a = 1; a < SIZE; a++)
        {
            if ( ansAr[a]==1 && ansAr[a-1]==0 ) siVec.push_back(a);
        }
        for (a = SIZE-3; a >= 0; a--)
        {
            if ( ansAr[a]==1 && ansAr[a+1]==0 ) eiVec.push_back(a);
        }
        len = siVec.size();
        cout << len << endl;
        for (a = 0; a < len; a++)
        {
            printf("%lld %lld\n", siVec[a], eiVec[len-1-a]);
        }
    }
    return 0;
}
