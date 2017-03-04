#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000009
long long T, M, A, B, mi;
long long len, ans, current, myNext, addee;
vector<long long> mAr, track[9];
long long a, b, c, d, e, f, g;
struct myPair
{
    long long a, b;
    myPair(){}
    myPair(long long a, long long b)
    {
        this->a = a;
        this->b = b;
    }
    const bool operator < (myPair B) const
    {
        if ( a == B.a )
        {
            return b < B.b;
        }
        return a < B.a;
    }
};
map<myPair, long long> myMap;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        for (b = 0; b < 7; b++)
        {
            track[b] = vector<long long>();
        }
        ans = 0;
        mAr = vector<long long>();
        myMap = map<myPair, long long>();
        myMap[ myPair(0, 0) ] = 1;
        track[0].push_back(0);
        cin >> M;
        for (b = 0; b < M; b++)
        {
            scanf("%lld", &mi);
            mAr.push_back( mi );
        }
        cin >> A >> B;
        sort( mAr.begin(), mAr.end() );
        for (b = 0; b < M; b++) // taking mAr values one by one
        {
            //cout << "b = " << b << ", mAr[b] = " << mAr[b] << endl;
            //if ( 4 * mAr[b] > B ) continue;

            for (c = 3; c >= 0; c--) // already taking c members
            {
                //cout << "c = " << c << endl;
                len = track[c].size();
                //cout << "len = " << len << endl;
                for (d = 0; d < len; d++)
                {
                    current =  track[c][d] ;
                    //cout << "current = " << current << endl;
                    if ( current + mAr[b] * (4-c) > B ) continue;
                    if (current + mAr[M-1]*(4-c)<A)
                    for (e = 1; e+c <= 4; e++ )
                    {
                        myNext = current + mAr[b] * e;
                        //cout << "next = " << next << endl;
                        if (myNext > B) continue;

                        if ( c+e == 4  && myNext >= A && myNext <= B )
                        {
                            //cout << myMap[ myPair(c, current) ] << " added" << endl;
                            ans += myMap[ myPair(c, current) ];
                            continue;
                        }

                        if ( myMap[ myPair(c+e, myNext) ] == 0 )
                        {
                            track[c+e].push_back( myNext );
                            //cout << "pushed " << next << " in track" << "[" << c+e << endl;
                        }
                        myMap[ myPair(c+e, myNext) ] += myMap[ myPair(c, current) ];

                    }
                }
            }
        }
//        len = track[4].size();
//        //cout << "track[4].size() = " << track[4].size() << endl;
//        for (b = 0; b < len; b++)
//        {
//            //cout << "track[4][" << b << "] = " << track[4][b] << endl;
//            if ( track[4][b] < A || track[4][b] > B ) continue;
//            //cout << "came" << endl;
//            ans += myMap[ myPair(4, track[4][b]) ];
//        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
