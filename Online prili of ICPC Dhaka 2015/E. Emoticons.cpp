#include <bits/stdc++.h>
using namespace std;

int t, i, j, first, middle, last, len, ans;
char str[100009];

int minOf3(int a, int b, int c)
{
    return 0;
}

int main()
{
    scanf("%d", &t);
    for (i = 1; i <= t; i++)
    {
        scanf("%s", str);
        len = strlen(str);
        first = 0;
        middle = 0;
        last = 0;
        ans = 0;
        for (j = 0; j < len; j++)
        {
            if (str[j] == '_')
            {
                middle++;
            }

            else if (str[j] == '^' && middle <= 0)
            {
                first++;
            }

            else if (str[j] == '^' && middle > 0)
            {
                last++;
                if (last > min(first, middle) )
                {
                    ans += min(first, middle);
                    first = 1;
                    middle = last = 0;
                }

                if (last == min(first, middle))
                {
                    ans += min(first, middle);
                    first = middle = last = 0;
                }
            }
        }
        printf("Case %d: %d\n", i, ans);
    }


    return 0;
}
