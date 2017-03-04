#include <bits/stdc++.h>
using namespace std;

char str[10009], s2[10009];

int i, j,  m, n, l, r, k;

int main()
{
    scanf("%s", str);
    scanf("%d", &m);
    for (i = 1; i <=m; i++)
    {
        scanf("%d %d %d", &l, &r, &k);
        l--;
        r--;
        char c;
        for (j = l; j <= r; j++)
        {
            s2[l+((j+k)-l)%(r-l+1)] = str[j];
        }
        for (j = l; j <= r; j++)
        {
            str[j] = s2[j];
        }
    }

    printf("%s", str);


    return 0;
}
