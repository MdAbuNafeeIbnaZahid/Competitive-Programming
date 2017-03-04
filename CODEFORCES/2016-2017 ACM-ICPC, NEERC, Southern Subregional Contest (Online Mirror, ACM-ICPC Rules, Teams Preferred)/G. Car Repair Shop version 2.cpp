#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
long long n, si, di;
long long a, b, c, d, e, f, g, h, len, alreadyPut, cantPut, nextIdx;
long long ansSi[SIZE], ansEi[SIZE];
vector<long long> startIdx, endIdx;
set<long long> setStart, setEnd, setCommon;
set<long long>::iterator nextEleIt;
int main()
{
    //freopen("input.txt", "r", stdin);

    cin >> n;
    cin >> si >> di;

    setStart.insert(INT_MAX);
    setEnd.insert(0);
    setCommon.insert(INT_MAX);
    setCommon.insert(0);

    setStart.insert(si);
    setEnd.insert(si+di-1);
    setCommon.insert(si);
    setCommon.insert(si+di-1);

    ansSi[1] = si;
    ansEi[1] = si+di-1;

    for (a = 2; a <= n; a++)
    {
        //cout << "a = " << a << endl;
        cantPut = 0;
        cin >> si >> di;
        //cout << "si = " << si << ", di = " << di << endl;
        nextEleIt = setCommon.lower_bound(si);
        if (  setEnd.find(*nextEleIt) != setEnd.end() )
        {
            cantPut = 1;
        }
        if ( setStart.find(*nextEleIt) != setStart.end() )
        {
            if ( si+di-1 >=  *setStart.find(*nextEleIt) )
            {
                cantPut = 1;
            }
        }
        //cout << "cantPut = " << cantPut << endl;
        if ( !cantPut )
        {
            ansSi[a] = si;
            ansEi[a] = si+di-1;
        }
        else
        {
            for ( nextEleIt = setEnd.begin(); nextEleIt != setEnd.end(); nextEleIt++ )
            {
                if ( *nextEleIt+di < *setCommon.upper_bound(*nextEleIt) )
                {
                    ansSi[a] = *nextEleIt+1;
                    ansEi[a] = *nextEleIt+di;
                    break;
                }
            }
        }
        setStart.insert(ansSi[a]);
        setEnd.insert(ansEi[a]);
        setCommon.insert(ansSi[a]);
        setCommon.insert(ansEi[a]);
    }

    for (a = 1; a <= n; a++)
    {
        cout << ansSi[a] << " " << ansEi[a] << endl;
    }
    return 0;
}
