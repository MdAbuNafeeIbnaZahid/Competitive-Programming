#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, m, pi, si;
long long c, u;
long long aAr[SIZE], bAr[SIZE];
long long a, b, d, e, f, g, h;
long long current, adNeed, isUsed[SIZE], len;
struct computer
{
    long long idx, power;
    computer(){}
    computer(long long idx, long long power)
    {
        this->idx = idx;
        this->power = power;
    }
    const bool operator < (computer B) const
    {
        if ( power == B.power )
        {
            return idx < B.idx;
        }
        return power < B.power;
    }
};
struct socket
{
    long long idx, power;
    socket(){}
    socket(long long idx, long long power)
    {
        this->idx = idx;
        this->power = power;
    }
    const bool operator < (socket B) const
    {
        if ( power == B.power )
        {
            return idx < B.idx;
        }
        return power < B.power;
    }
};
struct connection
{
    long long socketIdx, adaptersNeeded;
    connection(){}
    connection(long long socketIdx, long long adaptersNeeded)
    {
        this->socketIdx = socketIdx;
        this->adaptersNeeded = adaptersNeeded;
    }
    const bool operator < (connection B) const
    {
        if ( adaptersNeeded == B.adaptersNeeded )
        {
            return socketIdx < B.socketIdx;
        }
        return adaptersNeeded < B.adaptersNeeded;
    }
};
vector<computer> vecComputer;
vector<socket> vecSocket;
map<long long, set<connection> > myMap;
set<connection>::iterator setConIt;
set<long long> powerSet;
map<long long, vector<long long> > mapLLvecLL;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &pi);
        vecComputer.push_back( computer(a, pi) );
        mapLLvecLL[ pi ].push_back( a );
        powerSet.insert( pi );
    }
    for (a = 1; a <= m; a++)
    {
        scanf("%lld", &si);
        vecSocket.push_back( socket(a, si) );
    }
    sort( vecComputer.begin(), vecComputer.end() );
    sort( vecSocket.begin(), vecSocket.end() );

    for (a = 0; a <= 34; a++)
    {
        for (b = 0; b < vecSocket.size(); b++)
        {
            if (  !isUsed[vecSocket[b].idx] && mapLLvecLL[vecSocket[b].power ].size() )
            {
                c++;
                u+=a;
                aAr[ vecSocket[b].idx ] = a;
                len = mapLLvecLL[vecSocket[b].power ].size();
                bAr[ mapLLvecLL[vecSocket[b].power ][ len-1 ] ] = vecSocket[b].idx;
                isUsed[vecSocket[b].idx] = 1;
                mapLLvecLL[vecSocket[b].power ].pop_back();
            }
        }
        for (b = 0; b < vecSocket.size(); b++)
        {
            vecSocket[b].power = ( vecSocket[b].power+1 )/2;
        }
    }

    cout << c << " " << u << endl;
    for (a = 1; a <= m; a++)
    {
        printf("%lld ", aAr[a]);
    }
    cout << endl;
    for (a = 1; a <= n; a++)
    {
        printf("%lld ", bAr[a]);
    }
    return 0;
}
