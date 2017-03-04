#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n, rAr[SIZE], t, R;
long long a, b, c, d, e, f, p, q, toPrint[SIZE];
long long minVal = 100;
struct party
{
    long long x, y, z;
    party(){}
    party(long long x = 0, long long y = 0, long long z = 0)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
};
vector<party> vectorParty;
struct del
{
    long long key, idx;
    del(){}
    del(long long key, long long idx)
    {
        this->key = key;
        this->idx = idx;
    }
    bool operator < (const del B) const
    {
        if ( key == B.key )
        {
            return idx < B.idx;
        }
        return key > B.key;
    }
};
long long ifPossible(long long val)
{
    vectorParty = vector<party>();
    long long a, b, c, d, e, f, g, h;
    long long workAr[SIZE];
    set<del> setDel;
    set<del>::iterator setDelIt;
    del firstTop, secondTop;
    for (a = 1; a <= n; a++)
    {
        if ( rAr[a]-val > 0 )
        {
            setDel.insert( del(rAr[a]-val, a) );
        }
    }
    while( setDel.size() >= 2 )
    {
        setDelIt = setDel.begin();
        firstTop = *setDelIt;
        secondTop = *(++setDelIt);
        setDel.erase( setDel.begin() );
        setDel.erase( setDel.begin() );
        vectorParty.push_back( party(firstTop.idx, secondTop.idx) );
        firstTop.key--;
        if ( firstTop.key > 0 )
        {
            setDel.insert( firstTop );
        }
        secondTop.key--;
        if ( secondTop.key > 0 )
        {
            setDel.insert( secondTop );
        }
    }
    if ( setDel.size()==0 )
    {
        return 1;
    }
    else if ( val == 0 )
    {
        firstTop = *setDel.begin();
        while( firstTop.key )
        {
            vectorParty.push_back( party(firstTop.idx==1?2:1, firstTop.idx) );
            firstTop.key--;
        }
        return 1;
    }
    else
    {
        firstTop = *setDel.begin();
        for (a = 0; a < vectorParty.size() && firstTop.key; a++)
        {
            if ( vectorParty[a].x!=firstTop.idx && vectorParty[a].y!=firstTop.idx && vectorParty[a].z<=0 )
            {
                vectorParty[a].z = firstTop.idx;
                firstTop.key--;
            }
        }
        if ( firstTop.key )
        {
            return 0;
        }
    }
    return 1;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n;
    //cout << "n = " << n << endl;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &rAr[a]);
        minVal = min(minVal, rAr[a]);
    }
    for (a = minVal; a >= 0; a--)
    {
//        cout << "a = " << a << endl;
        if ( ifPossible(a) )
        {
            cout << a << endl;
            cout << vectorParty.size() << endl;
            for (b = 0; b < vectorParty.size(); b++)
            {
                toPrint[ vectorParty[b].x ] = 1;
                toPrint[ vectorParty[b].y ] = 1;
                toPrint[ vectorParty[b].z ] = 1;
                for (c = 1; c <= n; c++)
                {
                    printf("%lld", toPrint[c]);
                }
                printf("\n");
                toPrint[ vectorParty[b].x ] = 0;
                toPrint[ vectorParty[b].y ] = 0;
                toPrint[ vectorParty[b].z ] = 0;
            }
            return 0;
        }
    }
    cout << 0 << endl;
    for (a = 1; a <= n; a++)
    {
        t += rAr[a];
    }
    t -= min( rAr[1], rAr[2] );
    cout << t << endl;
    for (a = 1; a <= t; a++)
    {

    }
    return 0;
}
