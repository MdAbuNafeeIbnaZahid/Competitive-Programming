#include <bits/stdc++.h>
using namespace std;
#define SIZE 1600099
int T, n, ar[SIZE], consXorAr[SIZE], maxAns, minAns;
long long a, b, c, d, e, f, g;
int children[SIZE][3], nodeCount;
long long insertElement(long long num)
{
    long long a, b, c, d, e, f, now = 0, level, bit;
    for (level = 31; level >= 0; level--)
    {
        bit = 1 & (num>>level);
        if ( children[now][bit] == -1 )
        {
            children[now][bit] = ++nodeCount;
        }
        now = children[now][bit];
    }
    return 1;
}
long long queryMax(long long num)
{
    long long a, b, c, d, e, f, now = 0, level, bit, ret = 0;
    for (level = 31; level >= 0; level--)
    {
        //cout << "level = " << level<< " ";
        bit = 1 & (num>>level);
        //cout << "bit = " << bit << endl;
        if ( children[now][1^bit] != -1 )
        {
            ret ^= (1<<level);
            now = children[now][1^bit];
        }
        else
        {
            now = children[now][bit];
        }
    }
    return ret;
}

long long queryMin(long long num)
{
    long long a, b, c, d, e, f, now = 0, level, bit, ret = 0;
    for (level = 31; level >= 0; level--)
    {
        bit = 1 & (num>>level);
        if ( children[now][bit] != -1 )
        {
            //ret ^= (1<<level);
            now = children[now][bit];
        }
        else
        {
            now = children[now][1^bit];
            ret ^= (1<<level);
        }
    }
    return ret;
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        memset(children, -1, sizeof(children) );
        nodeCount = 0;
        maxAns = INT_MIN;
        minAns = INT_MAX;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld", &ar[b]);
        }
        insertElement(0);
        for (b = 1; b <= n; b++)
        {
            //cout << "b = " << b << endl;
            consXorAr[b] = consXorAr[b-1] ^ ar[b];
            //cout << "xor = " << consXorAr[b] << endl;
            minAns = min( minAns, (int)queryMin(consXorAr[b]) );
            //cout << "minAns = " << minAns << endl;
            maxAns = max( maxAns, (int)queryMax(consXorAr[b]) );
            //cout << "maxAns = " << maxAns << endl;
            insertElement( consXorAr[b] );
            //cout << ", nodeCount = " << nodeCount << endl;
        }
        cout << "Case " << a << ": " << maxAns << " " << minAns << endl;
    }
    return 0;
}
