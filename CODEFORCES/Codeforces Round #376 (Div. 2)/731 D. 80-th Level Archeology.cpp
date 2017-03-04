#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long n, c, li, wij;
vector<long long> word[SIZE];
long long a, b, d, e, f, g, h, doneUpto, ifInv[SIZE];
struct invalidInterval
{
    long long si, ei;
    invalidInterval(){}
    invalidInterval(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
    }
};
bool cmpInvalidInterval(invalidInterval A, invalidInterval B)
{
    if ( A.si == B.si )
    {
        return A.ei < B.ei;
    }
    return A.si < B.si;
}
vector<invalidInterval> changeVec;

void findInvInt(  long long startIdx, long long endIdx)
{
    long long minIdx = min(startIdx, endIdx), maxIdx = max(startIdx, endIdx);
    if ( startIdx < endIdx )
    {
        changeVec.push_back( invalidInterval(c-maxIdx+1, c-minIdx) );
    }
    else if ( startIdx > endIdx )
    {
        changeVec.push_back( invalidInterval(1, c-maxIdx) );
        changeVec.push_back( invalidInterval(c-minIdx+1, c) );
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> c;
    //cout << "n = " << n << ", c = " << c << endl;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &li);
        for (b = 1; b <= li; b++)
        {
            scanf("%lld", &wij);
            word[a].push_back( wij );
        }
    }
    for (a = 1; a < n; a++)
    {
        for (b = 0; b < min( word[a].size(), word[a+1].size() ); b++ )
        {
            if ( word[a][b] != word[a+1][b] )
            {
                findInvInt( word[a][b], word[a+1][b]);
                break;
            }
        }
        if ( b >= min( word[a].size(), word[a+1].size() ) )
        {
            if ( word[a].size() > word[a+1].size() )
            {
                cout << -1;
                return 0;
            }
        }
    }
    //cout << "vecInvInt.size() = " << vecInvInt.size() << endl;
    sort(changeVec.begin(), changeVec.end(), cmpInvalidInterval);
    for (a = 0; a < changeVec.size(); a++)
    {
        //cout << "a = " << a << endl;
        if ( changeVec[a].si > changeVec[a].ei )
        {
            continue;
        }
        for (b = max(doneUpto, changeVec[a].si); b <= changeVec[a].ei; b++)
        {
            ifInv[b] = 1;
        }
        doneUpto = max(doneUpto, changeVec[a].ei);
    }
    for (a = 1; a <= c; a++)
    {
        if ( !ifInv[a] )
        {
            cout << a%c;
            return 0;
        }
    }
    cout << -1;
    return 0;
}
