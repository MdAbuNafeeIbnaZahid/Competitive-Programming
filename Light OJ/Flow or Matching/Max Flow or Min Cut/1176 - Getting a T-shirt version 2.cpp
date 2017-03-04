#include <bits/stdc++.h>
using namespace std;
#define SIZE 79
#define SINK 70
#define WHITE 3
#define GREY 4
#define BLACK 5
long long T, N, M, ans, addee, color[SIZE];
long long a, b, c, d, e;
string preferredSize;
map<string, long long> sizeToNum;
long long gr[SIZE][SIZE];
long long getNum(string s)
{
    return sizeToNum[s]+60;
}
long long dfs(long long u, long long minVal)
{
    long long a, b, c, d, e, posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    if ( u == SINK ) return minVal;
    for (a = 0; a < SIZE; a++)
    {
        if ( gr[u][a] > 0 )
        {
            posRet = dfs(a, min( gr[u][a], minVal ) );
            if ( posRet > 0 )
            {
                gr[u][a] -= posRet;
                gr[a][u] += posRet;
                return posRet;
            }
        }
    }
    color[u] = BLACK;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    sizeToNum["XXL"] = 1;
    sizeToNum["XL"] = 2;
    sizeToNum["L"] = 3;
    sizeToNum["M"] = 4;
    sizeToNum["S"] = 5;
    sizeToNum["XS"] = 6;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        ans = 0;
        memset(gr, 0, sizeof(gr));
        cin >> N >> M;
        for (b = 1; b <= M; b++)
        {
            gr[0][b] = 1;

            cin >> preferredSize;
            gr[b][ getNum(preferredSize) ] = 1;
            gr[ getNum(preferredSize) ][SINK] = N;

            cin >> preferredSize;
            gr[b][ getNum(preferredSize) ] = 1;
            gr[ getNum(preferredSize) ][SINK] = N;
        }
        while(1)
        {
            for (b = 0; b < SIZE; b++) color[b] = WHITE;
            addee = dfs(0, INT_MAX);
            if ( addee <= 0 ) break;
            ans += addee;
        }
        //cout << "ans = " << ans << endl;
        if ( ans >= M )
        {
            cout << "Case " << a << ": YES" << endl;
        }
        else
        {
            cout << "Case " << a << ": NO" << endl;
        }
    }
    return 0;
}
