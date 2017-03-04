#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
long long T, t, d;
double ansAr[SIZE][SIZE], ans;
long long a, b, c,  e, f, g, h;
double probF(long long t, long long d)
{
    double p1, p2, div1, div2, c1, c2, c3;
    if (t<0 || d<0) return 0;
    if ( ansAr[t][d] == -1 )
    {
        if ( t==0 ) ansAr[t][d] = 1;
        else if (t%2) ansAr[t][d] = 0;
        else
        {
            div1 = 1 - (double)(d*d)/( (t+d+1)*(t+d) );
            //cout << "div1 = " << div1 << endl;
            c1 = probF(t,d-1) * (t*d) / (double)( (t+d+1)*(t+d) );
            c3 = probF(t-2,d)*(t*t-t)/(double)( (t+d+1)*(t+d) );
            p1 = (c1+c2)/div1;

            div2 = 1-(double)(d*d-d)/( (t+d+1)*(t+d) );
            c2 = d*probF(t,d-1)/(double)( (t+d+1)*(t+d) ) ;
            p2 = (c1+c2+c3)/div2;

            ansAr[t][d] = max(p1,p2);
        }
    }
    return ansAr[t][d];
}
int main()
{
    freopen("input.txt", "r", stdin);
    for (a = 0; a < SIZE; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            ansAr[a][b] = -1;
        }
    }
    for (a=0; a < SIZE; a++)
    {
        for (b=0; b < SIZE; b++)
        {
            probF(a, b);
            //cout << "a = " << a << ", b = " << b << ", ansAr[a][b] = " << ansAr[a][b] << endl;
        }
    }
//    for (a = 0; a < SIZE; a++)
//    {
//        for (b = 0; b <= a; b++)
//        {
//            probF(a-b, b);
//        }
//    }
//    for (a = 0; a < SIZE; a++)
//    {
//        for (b = a; b < SIZE; b++)
//        {
//            probF(SIZE-1+a-b, b);
//        }
//    }
//    for (a=0; a < 10; a++)
//    {
//        for (b=0; b < 10; b++)
//        {
//            //probF(a, b);
//            cout << "a = " << a << ", b = " << b << ", ansAr[a][b] = " << ansAr[a][b] << endl;
//        }
//    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> t >> d;
        ans = ansAr[t][d];
        //cout << "Case " << a << ": " << ans << endl;
        printf("Case %lld: %0.8lf\n", a, ans);
    }
    return 0;
}

