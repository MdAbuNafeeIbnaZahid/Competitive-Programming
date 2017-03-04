#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
#define ROOT 0
long long ans;
int n, k, ai, aAr[SIZE], consXorAr[SIZE];
int a, b, c, d, e, f, g, h;
int children[32*SIZE][2], occurrence[32*SIZE], nodeCount = 0;
int insertElement(int num)
{
    int a, b, c, d, e, f, g, now = ROOT, level, bit;
    for (level = 31; level >= 0; level--)
    {
        bit = 1 & (num>>level);
        if ( children[now][bit] == -1 )
        {
            children[now][bit] = ++nodeCount;
        }
        occurrence[ children[now][bit] ]++;
        now = children[now][bit];
    }
}
long long query(int num)
{
    int a, b, c, d, e, f, g, h, now = ROOT, level, bitInNum, bitInK;
    long long ret = 0;
    for (level = 31; level >= 0; level--)
    {
        bitInNum = 1 & (num>>level);
        bitInK = 1 & (k>>level);

        if(level == 0)
        {
            if (bitInK == 0)
            {
                if ( children[now][1^bitInNum]!=-1 )
                {
                    ret += occurrence[ children[now][1^bitInNum] ];
                }
                if ( children[now][bitInNum] != -1 )
                {
                    ret += occurrence[ children[now][bitInNum] ];
                }
            }
            else if (bitInK == 1)
            {
                if ( children[now][1^bitInNum]!=-1 )
                {
                    ret += occurrence[ children[now][1^bitInNum] ];
                }
            }
            return ret;
        }

        if ( bitInK == 0 )
        {
            if ( children[now][1^bitInNum]!=-1 )
            {
                ret += occurrence[ children[now][1^bitInNum] ];
            }

            if ( children[now][bitInNum]!=-1 )
            {
                now = children[now][bitInNum];
            }
            else return ret;
        }
        if ( bitInK == 1 )
        {
            if ( children[now][1^bitInNum]!=-1 )
            {
                now = children[now][1^bitInNum];
            }
            else return ret;
        }
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //long long ans;
    memset(children, -1, sizeof(children) );
    cin >> n >> k;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        consXorAr[a] = consXorAr[a-1] ^ aAr[a];
    }
    insertElement(0);
    for (a = 1; a <= n; a++)
    {
        ans += query( consXorAr[a] );
        insertElement( consXorAr[a] );
    }
    cout << ans << endl;
    return 0;
}
