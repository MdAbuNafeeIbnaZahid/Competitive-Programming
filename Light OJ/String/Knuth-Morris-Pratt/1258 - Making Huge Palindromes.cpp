#include <bits/stdc++.h>
using namespace std;
#define SIZE 3000009
char inp[SIZE], workStr1[SIZE], workStr2[SIZE], ans, len, lowerVal, higherVal, mid;
long long a, b, c, d, e, f, g, h;
int main()
{
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%s", inp);
        len = strlen(inp);
        lowerVal = 0;
        higherVal = len-1;
        while(lowerVal < higherVal)
        {
            mid = (lower+higherVal)/2;
            for (b = 0; b < mid; b++)
            {
                workStr1[b+len] = mid-1-b;
            }
        }
    }
    return 0;
}
