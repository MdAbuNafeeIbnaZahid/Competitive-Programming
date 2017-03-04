#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
string A;
long long T, n;
long long a, b, c, d, e, f, g;
long long children[SIZE][19], nodeCount, isEnd[SIZE], ifNo;
long long insertElement(string str)
{
    long long a, b, c, d, e, f;
    long long len = str.size(), now = 0, newNodeCreated = 0;
    for (a = 0; a < len; a++)
    {
        if ( children[now][ str[a]-'0' ] == -1 )
        {
            children[now][ str[a]-'0' ] = ++nodeCount;
            newNodeCreated = 1;
        }
        now = children[now][ str[a]-'0' ];
        if ( isEnd[now] ) return 0;
    }
    isEnd[now] = 1;
    if ( !newNodeCreated ) return 0;
    return 1;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ifNo = 0;
        memset(children, -1, sizeof(children) );
        memset(isEnd, 0, sizeof(isEnd) );
        nodeCount = 0;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            //scanf("%lld", &A);
            cin >> A;
            if ( !insertElement(A) )
            {
                ifNo = 1;
            }
        }
        if ( ifNo ) cout << "Case " << a << ": NO" << endl;
        else cout << "Case " << a << ": YES" << endl;
    }
    return 0;
}
