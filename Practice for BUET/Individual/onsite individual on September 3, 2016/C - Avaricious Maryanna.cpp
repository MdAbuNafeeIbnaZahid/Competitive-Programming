#include <bits/stdc++.h>
using namespace std;
#define SIZE 250009
char cAns5[SIZE], cAns6[SIZE];
long long sq5[SIZE], sq6[SIZE], ans5[SIZE], ans6[SIZE], sol5[SIZE], sol6[SIZE];
long long T, N;
long long a, b, c, d, e, f, g;
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ans5[1] = 5;
    ans6[1] = 6;
    for (a = 2; a <= 500; a++)
    {
        for (b = 0; b < a+9; b++)
        {
            sq6[b] = 0;
            sq5[b] = 0;
        }
        for (b = 1; b <= a-1; b++)
        {
            for (c = 1; c <= a-1; c++)
            {
                if (b+c>a+9)  continue;

                sq6[b+c-1] += ans6[b]*ans6[c];
                sq6[b+c] += sq6[b+c-1]/10;
                sq6[b+c-1] %= 10;

                sq5[b+c-1] += ans5[b]*ans5[c];
                sq5[b+c] += sq5[b+c-1]/10;
                sq5[b+c-1] %= 10;
            }
        }
        ans6[a] = (10-sq6[a])%10;
        ans5[a] = sq5[a];
    }
    cAns5[500] = cAns6[500] = 0;
    for (a = 1; a <= 500; a++)
    {
        cAns5[500-a] = '0' + ans5[a];
        cAns6[500-a] = '0' + ans6[a];
    }
    cin >> T;
    for (a = 1; a <=T; a++)
    {
        scanf("%lld", &N);
        printf("Case #%lld: ", a);
        if (N == 0)
        {
            printf("Impossible");
        }
        else if (N == 1)
        {
            printf("0 1 5 6");
        }
        else
        {
            if ( ans5[N]==0 && ans6[N]==0 )
            {
                printf("Impossible");
            }
            else if ( ans5[N]==0 && ans6[N]!=0 )
            {
                printf("%s", cAns6+500-N);
            }
            else if ( ans5[N]!=0 && ans6[N]==0 )
            {
                printf("%s", cAns5+500-N);
            }
            else
            {
                if ( strcmp(cAns5+500-N, cAns6+500-N) <= 0 )
                {
                    printf("%s %s", cAns5+500-N, cAns6+500-N);
                }
                else printf("%s %s", cAns6+500-N, cAns5+500-N);
            }
        }
        printf("\n");
    }
    return 0;
}
