#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long m, c, n, kAr[SIZE], bij, cost;
long long a, b, d, e, f, g, current;
long long totalReq, maxK;
queue<long long> studentBookQ[SIZE], commonReq;
long long bookPosition[SIZE], pileOnDesk[SIZE];
vector<long long> firstDeskBook;
//struct bookTime
//{
//    long long bookIdx
//};
void taking(long long bookIdx)
{
    long long a, b, d, e, f, g;
    if ( bookPosition[bookIdx] == 1 )
    {
        firstDeskBook.erase( find(firstDeskBook.begin(), firstDeskBook.end(), bookIdx) );
    }
    pileOnDesk[ bookPosition[bookIdx] ]--;
    cost += bookPosition[ bookIdx ];
    bookPosition[ bookIdx ] = -1;
}
void putting(long long bookIdx)
{
    long long a, b, d, e, f, g, toRemFromFirst;
    if ( firstDeskBook.size() < c )
    {
        bookPosition[ bookIdx ] = 1;
        firstDeskBook.push_back( bookIdx );
        cost += 1;
        return;
    }
    for (a = 2; a <= m; a++)
    {
        if ( pileOnDesk[a] < c )
        {
            pileOnDesk[a]++;
            bookPosition[bookIdx] = a;
            cost += a;
            break;
        }
    }
    if ( a > m )
    {
        cost += (m+1);
        bookPosition[ bookIdx ] = m+1;
    }
    toRemFromFirst = firstDeskBook[0];
    cost += 1;
    bookPosition[ toRemFromFirst ] = -1;
    firstDeskBook.erase( firstDeskBook.begin() );
    for (a = 2; a <= m; a++)
    {
        if ( pileOnDesk[a] < c )
        {
            pileOnDesk[a]++;
            bookPosition[ toRemFromFirst ] = a;
            cost += a;
            break;
        }
    }
    if ( a>m )
    {
        cost += (m+1);
        bookPosition[ toRemFromFirst ] = m+1;
    }
    cost += bookPosition[ bookIdx ];
    pileOnDesk[ bookPosition[ bookIdx ] ]--;
    bookPosition[ bookIdx ] = -1;
    firstDeskBook.push_back( bookIdx );
    bookPosition[ bookIdx ] = 1;
    cost += 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> m >> c >> n;
        if (m+c+n==0) return 0;

        //cout << "m = " << m << ", c = " << c << ", n = " << n << endl;
        //return 0;

        maxK = 0;
        cost = 0;
        firstDeskBook = vector<long long>();
        for (a = 0; a < SIZE; a++)
        {
            bookPosition[a] = m+1;
            pileOnDesk[a] = 0;
        }
        for (a = 1; a <= n; a++)
        {
            scanf("%lld", &kAr[a] );
            maxK = max(maxK, kAr[a]);
            for (b = 1; b <= kAr[a]; b++)
            {
                scanf("%lld", &bij);
                studentBookQ[a].push( bij );
            }
        }
        //cout << "maxK = " << maxK << endl;
        for (a = 1; a <= maxK; a++)
        {
            for (b = 1; b <= n; b++)
            {
                if ( studentBookQ[b].size() )
                {
                    commonReq.push( studentBookQ[b].front() );
                    studentBookQ[b].pop();
                }
            }
        }
        while( commonReq.size() )
        {
            current = commonReq.front();
            //cout << current << " ";
            taking(current);
            //cout << "after taking " << cost << endl;
            putting(current);
            //cout << "after putting = " << cost << endl;
            commonReq.pop();
        }
        cout << cost << endl;
    }
    return 0;
}
