#include <bits/stdc++.h>
using namespace std;
#define SIZE 3000009
char inp[SIZE], workStr1[SIZE], workStr2[SIZE], ans, len, lowerVal, higherVal, addee;
long long a, b, c, d, e, f, g, h;
long long T;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%s", inp);
        len = strlen(inp);
        lowerVal = 0;
        higherVal = len-1;
        addee = 0;
        while( lowerVal < higherVal )
        {
            if ( inp[lowerVal] == inp[higherVal] )
            {
                lowerVal++;
                higherVal--;
            }
            else
            {
                lowerVal++;
                addee++;
            }
        }
        cout << "Case " << a << ": " << len+addee << endl;
    }
    return 0;
}
