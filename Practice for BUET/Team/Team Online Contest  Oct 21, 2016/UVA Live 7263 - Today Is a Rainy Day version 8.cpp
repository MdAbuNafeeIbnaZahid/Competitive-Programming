#include <bits/stdc++.h>
using namespace std;
#define SIZE 666669
long long a, b, c, d, e, f, g, h, len, ans, toPut, diffCount;
long long layer[SIZE], myPow10[SIZE];
vector<long long> posState;
char givenStr[119], desStr[119];
long long givenAr[SIZE], desAr[SIZE], interAr[SIZE], pos[9];
void bfs(long long root, long long *layer)
{
    long long a, b, c, d, e, f, g, h, current, nextNum, toPut;
    queue<long long> q;
    for (a = 0; a < SIZE; a++)
    {
        layer[a] = INT_MAX;
    }
    layer[root] = 0;
    q.push(root);
    posState.push_back(root);
    while( q.size() )
    {
        current = q.front();
        q.pop();
        for (a = 1; a <= 6; a++)
        {
            for (b = 1; b <= 6; b++)
            {
                if (a==b) continue;
                nextNum = 0;
                for (c = 0; c <= 5; c++)
                {
                    toPut = (current/myPow10[c])%10;
                    if (toPut == a)
                    {
                        toPut = b;
                    }
                    nextNum += (toPut*myPow10[c] );
                }
                if ( layer[nextNum ] >= INT_MAX )
                {
                    layer[ nextNum ] = 1 + layer[current];
                    q.push( nextNum );
                    posState.push_back( nextNum );
                }
            }
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    myPow10[0] = 1;
    for (a = 1; a <= 10; a++)
    {
        myPow10[a] = 10 * myPow10[a-1];
    }
    bfs(654321, layer);
    while( gets(desStr)   )
    {
        gets(givenStr);
        len = strlen(givenStr);
        ans = INT_MAX;
        for (a = 0; a < posState.size(); a++)
        {
            for (b = 1; b <= 6; b++)
            {
                pos[b] = (posState[a]/myPow10[b-1])%10;
            }
            diffCount = 0;
            for (b = 0; b < len; b++)
            {
                //toPut = (posState[a]/ myPow10[ givenStr[b]-'0'-1 ] )%10;
                toPut = pos[ givenStr[b]-'0' ];
                diffCount += (toPut != desStr[b]-'0');
            }
            ans = min(ans, diffCount+layer[ posState[a] ] );
        }
        printf("%lld\n", ans);
    }
    return 0;
}
