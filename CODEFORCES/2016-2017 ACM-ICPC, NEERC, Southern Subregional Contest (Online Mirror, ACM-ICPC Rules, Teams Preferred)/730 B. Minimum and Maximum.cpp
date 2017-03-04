#include <bits/stdc++.h>
using namespace std;
long long T, n;
long long a, b, c, d, e, f, g, low, high, probLow, probHigh;
char response;
int main()
{
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%lld", &n);
        if ( n <= 1 )
        {
            //cout << "! " << 1 << " " << 1 << endl;
            printf("! 1 1\n");
            fflush(stdout);
            continue;
        }
        else
        {
            printf("? 1 2\n");
            fflush(stdout);
            low = 1;
            high = 2;
            cin >> response;
            if ( response == '>' )
            {
                low = 2;
                high = 1;
            }
            for (b = 3; b <= n; b+=2)
            {
                probLow = b;
                probHigh = b;
                if ( b+1 <= n )
                {
                    printf("? %lld %lld\n", b, b+1);
                    fflush(stdout);
                    cin >> response;
                    if ( response == '<' )
                    {
                        probLow = b;
                        probHigh = b+1;
                    }
                    else if ( response == '=' )
                    {
                        probLow = b;
                        probHigh = b+1;
                    }
                    else if ( response == '>' )
                    {
                        probLow = b+1;
                        probHigh = b;
                    }

                }

                printf("? %lld %lld\n", probLow, low);
                fflush(stdout);
                cin >> response;
                if ( response == '<' )
                {
                    low = probLow;
                }
                printf("? %lld %lld\n", probHigh, high);
                fflush(stdout);
                cin >> response;
                if ( response == '>' )
                {
                    high = probHigh;
                }
            }
            printf("! %lld %lld\n", low, high);
            fflush(stdout);
        }
    }
    return 0;
}
