#include <bits/stdc++.h>
using namespace std;
long long S, x, y, dx, dy, curX, curY;
long long a, b, c, d, e, f, cnt = 0;
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        scanf("%lld %lld %lld %lld %lld", &S, &x, &y, &dx, &dy);
        if (S+x+y+dx+dy == 0) return 0;
        cnt = 0;
        curX = x;
        curY = y;
        if (  (curX%(2*S) > S && curX%(2*S) < 2*S && curY%(2*S) > 0 && curY%(2*S) < S)
                || (curX%(2*S) > 0 && curX%(2*S) < S && curY%(2*S) > S && curY%(2*S) < 2*S) )
        {
            cout << "After 0 jumps the flea lands at (" << x << ", " << y << ")." << endl;;
            continue;
        }
        curX = (curX + dx); //% (2*S);
        curY = (curY + dy); //% (2*S);
        cnt++;
        while( curX%(2*S) != x%(2*S) || curY%(2*S) != y%(2*S) )
        {
            //cout << "here" << endl;
            if (  (curX%(2*S) > S && curX%(2*S) < 2*S && curY%(2*S) > 0 && curY%(2*S) < S)
                || (curX%(2*S) > 0 && curX%(2*S) < S && curY%(2*S) > S && curY%(2*S) < 2*S) )
            {
                cout << "After " << cnt << " jumps the flea lands at ("
                << curX << ", " << curY << ")." << endl;
                break;
            }
            curX = (curX+dx);//%(2*S);
            curY = (curY+dy);//%(2*S);
            cnt++;

        }
        if ( curX%(2*S) != x%(2*S) || curY%(2*S) != y%(2*S) ) continue;
        cout << "The flea cannot escape from black squares." << endl;
    }
    return 0;
}
