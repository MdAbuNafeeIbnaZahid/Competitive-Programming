#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long testCases, N, height[SIZE], width[SIZE], auxIncr[SIZE], auxDecr[SIZE], ar[SIZE];
long long incr, decr, idx, len, put;
long long a, b, c, d, e, f;
long long binSearchSmallestThatGraterThan(long long ar[], long long s, long long e, long long key)
{
    long long mid;
    while(e-s>1)
    {
        mid = (s+e)/2;
        if (ar[mid] <= key) s = mid+1;
        else e = mid;
    }
    if ( ar[s] > key ) return s;
    return e;
}
long long binSearchBiggestThatSmallerThan(long long ar[], long long s, long long e, long long key)
{
    long long mid;
    while(e-s>1)
    {
        mid = (s+e)/2;
        //if ( ar[s] == key ) return s;
        //if (ar[e] == key) return e;
        //if (ar[mid] == key) return mid;
        if ( key >= ar[mid] ) s = mid+1;
        else e = mid;
    }
    return s;
}
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        incr = decr = 0;
        cin >> N;
        for (b = 0; b < N; b++)
        {
            scanf("%lld", &height[b]);
        }
        for (b = 0; b < N; b++)
        {
            scanf("%lld", &width[b]);
        }
        idx = -1;
        for (b = 0; b < N; b++)
        {
            for (c = 0; c < width[b]; c++)
            {
                ar[++idx] = height[b];
                //cout << "idx = " << idx << endl;
            }
        }
        //cout << "idx = " << idx << endl;
        incr = 0;
        decr = 0;
        auxIncr[incr] = ar[0];
        auxDecr[decr] = ar[0];
        for (b = 1; b <= idx; b++)
        {
            //cout << "b = " << b << ", ar[b] = " << ar[b] << endl;
            //cout << "auxIncr[0] = " << auxIncr[0] << endl;
            if (ar[b] >= auxIncr[incr] )
            {
                auxIncr[++incr] = ar[b];
                //cout << "incr = " << incr << endl;
            }
            else if ( ar[b] < auxIncr[0] )
            {
                auxIncr[0] = ar[b];
                //cout << "auxIncr[0] = " << auxIncr[0] << endl;
            }
            else
            {
                put = binSearchSmallestThatGraterThan(auxIncr, 0, incr, ar[b]);
                //cout << "put = " << put << endl;
                auxIncr[ put ] = ar[b];
            }


            if( ar[b] <= auxDecr[decr] )
            {
                auxDecr[++decr] = ar[b];
            }
            else if ( ar[b] > auxDecr[0] )
            {
                auxDecr[0] = ar[b];
            }
            else
            {
                //put = binSearchSmall(auxDecr, 0, decr, ar[b]);
                auxDecr[ put ] = ar[b];
            }
        }
        for (b = 0; b <= incr; b++)
        {
            //cout << "b = " << b << ", val = " << auxIncr[b] << endl;
        }
        cout << a << endl;
        cout << "incr = " << (incr+1) << endl;
        cout << "decr = " << (decr+1) << endl;
    }
    return 0;
}
