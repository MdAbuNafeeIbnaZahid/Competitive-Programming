#include <bits/stdc++.h>
using namespace std;
#define SIZE 49
long long N, Q;
long long a, b, c, d, e, f, g, h, cnt, len;
string descriptionOrder;
long long track[SIZE][SIZE][1009], ansAr[1009];
char grid[SIZE][SIZE], query[SIZE], found;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N >> Q;
    cin >> descriptionOrder;
    for (a = 0; a < N; a++)
    {
        for (b = 0; b < 17; b++)
        {
            scanf("%s", grid[b]);
        }
        for ( b = 0; b < 17; b++)
        {
            for (c = 0; c < 43; c++)
            {
                if ( grid[b][c] == '*' )
                {
                    track[b][c][ descriptionOrder[a] ] = 1;
                }
            }
        }
    }
    for (a = 1; a <= Q; a++)
    {
        scanf("%s", query);
        len = strlen( query );
        for (b = 0; b < len; b++)
        {
            ansAr[ query[b] ] = 0;
        }
        for (b = 0; b < 17; b++)
        {
            for (c = 0; c < 43; c++)
            {
                cnt = 0;
                for (d = 0; d < len; d++)
                {
                     cnt += track[b][c][ query[d] ];
                     if ( track[b][c][ query[d] ] )
                     {
                         found = query[d];
                     }
                }
                if ( cnt == 1 )
                {
                    ansAr[ found ] = 1;
                }
            }
        }
        printf("Query %lld: ", a);
        for (b = 0; b < len; b++)
        {
            if ( ansAr[ query[b] ] )
            {
                printf("Y");
            }
            else
            {
                printf("N");
            }
        }
        printf("\n");
    }
    return 0;
}
