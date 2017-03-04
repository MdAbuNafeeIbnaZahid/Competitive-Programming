#include <bits/stdc++.h>
using namespace std;
#define eps 0.000000000001
long long T;
long long i, j, k;
double a, b, c, d, x, y, h, lowerVal, upperVal, midVal, ans;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> a >> b >> c >> d;
        upperVal = min(b, d);
        lowerVal = 0;
        while(lowerVal+eps < upperVal)
        {
            //cout << "lowerVal = " << lowerVal << endl;
            //cout << "upperVal = " << upperVal << endl;
            midVal = (lowerVal+upperVal)/2;
            //cout << "midVal = " << midVal << endl;
            x = sqrt( abs(d*d-midVal*midVal) );
            y = sqrt( abs(b*b-midVal*midVal) );
            //cout << "x+y = " << x+y << endl;
            //cout << "a-c = " << a-c << endl;
            if ( (x+y) < abs(a-c)+eps )
            {
                upperVal = midVal;
            }
            else
            {
                lowerVal = midVal;
            }
        }
        h = (lowerVal+upperVal)/2;
        //cout << "h = " << h << endl;
        ans = 0.5 * (a+c) * h;
        printf("Case %lld: %0.12lf\n", i, ans);
    }
    return 0;
}
