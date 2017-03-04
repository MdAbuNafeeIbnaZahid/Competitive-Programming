#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long n, x;
long long a, b, c, d, e, f, g, len, counter, lastX;
vector<char*> toPrint[SIZE];
char sArray[SIZE][19];
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n;
    for (a = 1; a <= n/2; a++)
    {
        scanf("%lld %s", &x, sArray[a]);
        strcpy(sArray[a], "-");
        toPrint[x].push_back( sArray[a] );
    }
    for (a = (n/2)+1; a <= n; a++)
    {
        scanf("%lld %s", &x, sArray[a]);
        toPrint[x].push_back( sArray[a] );
    }
    for (a = 0; a <= 100; a++)
    {
        len = toPrint[a].size();
        for (b = 0; b < len; b++)
        {
            printf("%s ", toPrint[a][b]);
        }
    }
    return 0;
}
