#include <bits/stdc++.h>
using namespace std;
long long n, m;
long long a, b, c, d, e, f, g, h;
long long ans, leftPlace, rightPlace, cmp, checkLeft, checkRight;
long long used[10], usedRight[10];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> m;;
    leftPlace = 1;
    cmp = 7;
    while(n > cmp)
    {
        leftPlace++;
        cmp *= 7;
    }
    //cout << "leftPlace = " << leftPlace << endl;
    rightPlace = 1;
    cmp = 7;
    while( m > cmp )
    {
        rightPlace++;
        cmp*=7;
    }
    //cout << "rightPlace = " << rightPlace << endl;
    if (leftPlace+rightPlace > 7)
    {
        cout << 0;
        return 0;
    }
    for (a = 0; a < n; a++)
    {
        memset(used, 0, sizeof(used));
        checkLeft = a;
        for (c = 1; c <= leftPlace; c++)
        {
            used[(checkLeft%7)]++;
            checkLeft/=7;
        }
        for (c = 0; c < 7; c++)
        {
            if ( used[c] > 1 ) break;
        }
        if ( c<7 ) continue;
        for (b = 0; b < m; b++)
        {
            memset(usedRight, 0, sizeof(usedRight));
            checkRight = b;
            for (c = 1; c <= rightPlace; c++)
            {
                usedRight[checkRight%7]++;
                checkRight/=7;
            }
            for (c = 0; c < 7;c++)
            {
                if( used[c] + usedRight[c] > 1 ) break;
            }
            if ( c<7 ) continue;
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
