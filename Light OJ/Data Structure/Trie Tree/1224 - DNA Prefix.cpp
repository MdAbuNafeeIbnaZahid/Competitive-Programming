#include <bits/stdc++.h>
using namespace std;
//#define SIZE 3000009
#define SIZE 2500009
long long T, n, ans;
char charAr[] = {'A', 'C', 'G', 'T'}, str[59];
map<char, int> myMap;
long long a, b, c, d, e, f, g;
int children[SIZE][4], occurrence[SIZE], depth[SIZE], nodeCount;
long long insertElement(char *str)
{
    long long a, b, c, d, e, f, len = strlen(str), now = 0, idx;
    for (a = 0; a < len; a++)
    {
        idx = myMap[ str[a] ];
        if ( children[now][ idx ] == -1 )
        {
            children[now][ idx ] = ++nodeCount;
        }
        occurrence[ children[now][ idx ] ]++;
        depth[ children[now][ idx ] ] = a+1;
        now = children[now][ idx ];
    }
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    myMap['A'] = 0;
    myMap['C'] = 1;
    myMap['G'] = 2;
    myMap['T'] = 3;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        nodeCount = 0;
        memset(children, -1, sizeof(children) );
        memset(occurrence, 0, sizeof(occurrence) );
        memset(depth, 0, sizeof(depth ) );
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%s", str);
            insertElement(str);
        }
        for (b = 0; b < SIZE; b++)
        {
            ans = max((int)ans, depth[b]*occurrence[b] );
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
