#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, a, b, k;
long long c, d, e, f, g, h, currentCap, jog, biyog, nextShot;
char grid[SIZE];
vector<long long> shotVec, ansVec;
struct strip
{
    long long si, ei, cap;
    strip(){}
    strip(long long si, long long ei)
    {
        this->si = si;
        this->ei = ei;
        cap = (ei-si+1)/b;
    }
} ;
strip pick;
vector<strip> vecStrip;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> a >> b >> k;
    scanf("%s", grid);
//    cout << "grid = " << grid << endl;
    shotVec.push_back(0);
    for (c = 0; c < n; c++)
    {
        if ( grid[c] == '1' )
        {
            shotVec.push_back( c+1 );
        }
    }
    shotVec.push_back(n+1);
    for (c = 0; c <= k; c++)
    {
//        cout << "c = " << c << endl;
//        cout << "currentCap = " << currentCap << endl;
        vecStrip.push_back( strip( shotVec[c]+1, shotVec[c+1]-1 ) );
        currentCap += vecStrip[ vecStrip.size()-1 ].cap;
//        cout << "currentCap = " << currentCap << endl;
    }
//    cout << "currentCap = " << currentCap << endl;
    while( currentCap >= a )
    {
        pick = vecStrip[ vecStrip.size()-1 ];
        vecStrip.pop_back();
        if ( pick.cap <= 0 )
        {
            continue;
        }
        biyog = pick.cap;
        nextShot = pick.si + b -1;

        ansVec.push_back( nextShot );

        vecStrip.push_back( strip(pick.si, nextShot-1) );
        vecStrip.push_back( strip(nextShot+1, pick.ei) );
        jog = vecStrip[ vecStrip.size()-1 ].cap + vecStrip[ vecStrip.size()-2 ].cap;

        currentCap = currentCap - biyog + jog;
    }
    cout << ansVec.size() << endl;
    for (c=  0; c  < ansVec.size(); c++)
    {
        printf("%lld ", ansVec[c]);
    }
    return 0;
}
