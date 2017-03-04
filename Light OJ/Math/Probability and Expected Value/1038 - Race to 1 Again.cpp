#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
double ansAr[SIZE], sum;
long long N, T;
long long a, b, c, d, e, f, g, h, divCount, len, upto;
vector<long long> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    ansAr[1] = 0;
    for (a = 2; a <= 100000; a++)
    {
        divCount = 0;
        sum = 0;
        upto = sqrt(a)+1;
        for (b = 2; b < upto; b++)
        {
            if ( a%b == 0 && b!=a )
            {
                //vec.push_back(b);
                sum += ansAr[b];
                divCount++;
                if (b != a/b)
                {
                    //vec.push_back(a/b);
                    divCount++;
                    sum += ansAr[a/b];
                }
            }
        }

        //cout << "len = " << len << endl;
        sum += (divCount+2);
        //ansAr[a] = len+2;
        sum /= (divCount+1);
        ansAr[a] = sum;
    }
    for (a = 1; a <= 10; a++)
    {
        //cout << "a = " << a << ", ans = " << ansAr[a] << endl;
    }
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        scanf("%lld", &N);
        printf("Case %lld: %.6lf\n", a, ansAr[N]);
    }
    return 0;
}
