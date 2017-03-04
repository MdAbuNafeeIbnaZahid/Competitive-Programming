#include <bits/stdc++.h>
using namespace std;
double myDif(double d1, double d2)
{
    double ret = d1-d2;
    if (ret < 0) ret = (-ret);
    return ret;
}
int main()
{
    double d, ans, prev, next, current;
    while(1)
    {
        cin >> d;
        current, next = d/2;
        while( current!=next )
        {
            current = next;
            next = (d + d/current)/2;
        }
        cout << prev << endl << endl;
    }
}
