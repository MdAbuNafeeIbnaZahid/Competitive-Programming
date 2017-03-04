#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long testCases, N;
long long a, b, c, d,e , f, g, toProp;
long long girlPref[SIZE][SIZE], boyPref[SIZE][SIZE], boyMatch[SIZE], ifOffered[SIZE][SIZE];
long long girlMatch[SIZE], boyPrefWork[SIZE][SIZE];
void offer(long long g, long long b)
{
    if ( boyMatch[b] == 0 )
    {
        boyMatch[b] = g;
        girlMatch[g] = b;
    }
    else
    {
        if ( boyPrefWork[b][g] < boyPrefWork[b][ boyMatch[b] ] )
        {
            girlMatch[ boyMatch[b] ] = 0;
            boyMatch[b] = g;
            girlMatch[g] = b;
        }
        else
        {
            // do nothing
        }
    }
}
queue<long long> boysToProp[SIZE];
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        //cout << "a = " << a << endl;
        if ( a > 1 ) cout << endl;
        cin >> N;
        for (b = 1; b <= N; b++)
        {
            boysToProp[b] = queue<long long>();
        }
        memset(boyMatch, 0, sizeof(boyMatch));
        memset(girlMatch, 0, sizeof(girlMatch));
        memset(ifOffered, 0, sizeof(ifOffered));
        for (b = 1; b <= N; b++)
        {
            for (c = 1; c <= N; c++)
            {
                scanf("%lld", &girlPref[b][c]);
                boysToProp[b].push( c );
            }
        }
        for (b = 1; b <= N; b++)
        {
            for (c = 1; c <= N; c++)
            {
                scanf("%lld", &boyPref[b][c]);
                boyPrefWork[b][ boyPref[b][c] ] = c;
            }
        }
        while(1)
        {
            //cout << "in while" << endl;
            for (b = 1; b <= N; b++)
            {
                //cout << "b = " << b << ", girlMatch[b] = " << girlMatch[b] <<  endl;
                if ( girlMatch[b] == 0 ) break;
            }
            if ( b > N )
            {
                //cout << "all girls are engaged" << endl;
                break;
            }
            for (b = 1; b <= N; b++)
            {
                if ( girlMatch[b] == 0 )
                {
                    c = boysToProp[b].front();
                    boysToProp[b].pop();
                    //if ( !ifOffered[b][ girlPref[b][c] ] )
                    //{
                    offer(b, girlPref[b][c]);
                    ifOffered[b][ girlPref[b][c] ] = 1;
                        //break;
                    //}
                }
            }

        }
        for (b = 1; b <= N; b++)
        {
            printf("%lld\n", girlMatch[b]);
        }
    }
    return 0;
}
