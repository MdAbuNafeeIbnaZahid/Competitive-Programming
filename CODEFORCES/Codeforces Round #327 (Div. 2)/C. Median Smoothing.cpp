#include <bits/stdc++.h>
using namespace std;


int n, i,j, k, a, b, c, ar[500009], maxSeq = 0, totalSeq = 0, len = 0, maxLen = 0;
int seq[500009][2], first = -1, last = -1, times = 0;

bool ifToggle(int i)
{
    if (i == 1 || i == n) return false;
    return (ar[i] != ar[i-1] && ar[i]!=ar[i+1]);
}


int main()
{

    scanf("%d", &n);
    for (i = 1; i <= n; i++)
    {
        scanf("%d", &ar[i]);
    }

    for (i = 1; i <= n; i++)
    {
        if ( ifToggle(i) )
        {
            if (first == -1)
            {
                first = i;
                len = 1;
            }

            else
            {
                len++;
            }
        }

        else
        {
            if (first != -1)
            {
                if (len > maxLen) maxLen = len;
                len = 0;
                totalSeq++;
                for (k = first; k <= (first+i-1)/2; k++)
                {
                    ar[k] = ar[first-1];
                }
                for (k = i-1; k > (first+i-1)/2; k--)
                {
                    ar[k] = ar[i];
                }
                seq[totalSeq][0] = first;
                seq[totalSeq][1] = i-1;
                first = -1;
            }
        }
    }

    times = ceil(maxLen / 2.0);
    printf("%d\n", times);
    for (a = 1; a <= n; a++)
    {
        printf("%d ", ar[a]);
    }


    return 0;
}
