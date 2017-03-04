#include<bits/stdc++.h>
using namespace std;
#define SIZE 19
long long R, C;
long long a, b, d, e, f, g, h, i;
char input[SIZE][SIZE];
long long inputLL[SIZE], copyInp[SIZE];
long long ans, flipCount;
main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> R >> C;
        if ( R+C == 0 ) return 0;
        ans = INT_MAX;
        for (a = 0; a < R; a++)
        {
            scanf("%s", input[a]);
        }
        for (a = 0; a < R; a++)
        {
            inputLL[a] = 0;
            for (b = 0; b < C; b++)
            {
                if ( input[a][b] == 'X' ) inputLL[a] ^= (1<<b);
            }
        }
        //for (a = 0; a < R; a++)
        //{
            //for (b = 0; b < C; b++)
            //{
                //cout << ( (inputLL[a]>>b) & 1 ) << " ";
            //}
            //cout << endl;
        //}
        ans = INT_MAX;
        for (a = 0; a < (1<<C); a++)
        {
            flipCount = 0;
            for (b = 0; b < R; b++)
            {
                copyInp[b] = inputLL[b];
            }
            flipCount += __builtin_popcountll(a);
            copyInp[0] ^= ( (a ^ (a<<1) ^ (a>>1) ) & ((1<<C)-1) ) ;
            copyInp[1] ^= a;
            for (b = 1; b < R; b++)
            {
                flipCount += __builtin_popcountll( copyInp[b-1] );
                copyInp[b] ^= ( (copyInp[b-1] ^ (copyInp[b-1]<<1) ^ (copyInp[b-1]>>1) ) & ((1<<C)-1) );
                copyInp[b+1] ^= copyInp[b-1];
                copyInp[b-1] = 0;
            }
            if ( copyInp[R-1] & ((1<<C)-1) ) continue;
            ans = min(ans, flipCount);
        }
        if (ans < INT_MAX)
        {
            cout << "You have to tap " << ans << " tiles." << endl;
        }
        else
        {
            cout << "Damaged billboard." << endl;
        }
    }
}
