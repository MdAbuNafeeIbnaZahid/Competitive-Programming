#include <bits/stdc++.h>
using namespace std;
#define SIZE 20000009
long long N;
long long a,b,c,d,e, f, g, h, semiPrime, powerCount, prevVal, numerator, denominator;
struct info
{
    long long prime, power, val, isPrime, cumAns;
    info()
    {
        val = 0;
        cumAns = 0;
        isPrime = 1;
    }
};
info infoAr[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    for (a = 2; a < SIZE; a++)
    {
        //infoAr[a].isPrime = 1;
    }
    infoAr[2].val = 3;
    for (a = 2; a < SIZE; a++)
    {
        //if ( a==2 || a==3 || a==5 || a== 7 || a== 11 || a==13 )
        //{
            //cout << "a = " << a << endl;
            //cout << "infoAr[a].isPrime = " << infoAr[a].isPrime << endl;
        //}
        if ( infoAr[a].isPrime == 0 ) continue;
        infoAr[a].val = 1+a;
        infoAr[a].prime = a;
        infoAr[a].power = 1;
        semiPrime = a*a;
        //cout << "semiPrime = " << semiPrime << endl;
        powerCount = 2;
        while(1)
        {
            if ( semiPrime >= SIZE ) break;
            //cout << "semiPrime = " << semiPrime << endl;
            infoAr[semiPrime].prime = a;
            infoAr[semiPrime].power = powerCount;
            infoAr[semiPrime].isPrime = 0;
            //infoAr[semiPrime].val = infoAr[]
            for (b = semiPrime+a; b < semiPrime*a; b+=a)
            {
                if (b>=SIZE) break;
                //cout << "b = " << b << endl;
                infoAr[b].prime = a;
                infoAr[b].power = 1;
                infoAr[b].isPrime = 0;
                if ( b == 18 )
                {
                    cout << "prime = " << infoAr[b].prime << endl;
                    cout << "power = " << infoAr[b].power << endl;
                    cout << "isPrime = " << infoAr[b].isPrime << endl;
                 }
            }
            semiPrime *= a;
            powerCount++;
        }
    }
    for (a = 2; a < SIZE; a++)
    {
        if(infoAr[a].isPrime == 1)
        {
            infoAr[a].val = 1+a;
        }
        if ( infoAr[a].isPrime == 0 )
        {
            prevVal = infoAr[a/ infoAr[a].prime ].val ;
            numerator = round( pow(infoAr[a].prime, infoAr[a].power+1) -1 );
            denominator = round( pow(infoAr[a].prime, infoAr[a].power) -1 );
            infoAr[a].val = prevVal * numerator / denominator;
        }
    }
    for (a = 2; a < 99; a++)
    {
        //cout << "a = " << a << ", ->" << infoAr[a].val << endl;
    }
    for (a = 2; a <  SIZE; a++)
    {
        infoAr[a].cumAns = infoAr[a].val + infoAr[a-1].cumAns;
    }
//    while(1)
//    {
//        cin >> N;
//        if (N==0) break;
//        cout << infoAr[N].cumAns << endl;
//    }
    return 0;
}
