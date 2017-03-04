#include <bits/stdc++.h>
using namespace std;
#define SIZE 25009
long long ansAr[SIZE];
long long a, b, c, d, e, f, g, j, start, span;
long long N;
int main()
{
    cin >> N;
    start = 1;
    span = 2;
    for (a = 0; ; a++)
    {
        for (j = start; j <= N; j += span)
        {
            ansAr[j] = a;
        }
        start *= 2;
        span *= 2;
        if ( start > N ) break;
    }
    if ( a <= 9 )
    {
        for (b = 1; b <= N; b++) printf("%lld", ansAr[b]);
    }
    else
    {
        for (b = 1; b <= N; b++) printf("0");
    }
    return 0;
}
