#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long a, b, c, d, e, f, g, h, n, len, leftIdx, rightIdx, ans;
char str[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    scanf("%s", str);
    len = strlen(str);
    leftIdx = INT_MAX;
    rightIdx = INT_MIN;
    for (a = 0; a < len; a++)
    {
        if ( str[a] == '>' )
        {
            leftIdx = a;
            break;
        }
    }
    for (a = len-1; a >= 0; a--)
    {
        if ( str[a] == '<' )
        {
            rightIdx = a;
            break;
        }
    }
    ans = min(len - (rightIdx-leftIdx+1), len);
    cout << ans << endl;
    return 0;
}
