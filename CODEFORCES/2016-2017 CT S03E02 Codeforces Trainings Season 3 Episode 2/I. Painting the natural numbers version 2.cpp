#include <bits/stdc++.h>
using namespace std;
#define SIZE 250009
long long N;
long long a, b, c, d, e, f, g, h, len, current, pow3, ansAr[SIZE];
vector<long long> ansVecAr[19];
int main()
{
    ansVecAr[1].push_back(1);
    pow3 = 1;
    for (a = 2; a <= 10; a++)
    {
        pow3 *= 3;
        for (b = 1; b < a; b++)
        {
            len = ansVecAr[b].size();
            for (c = 0; c < len; c++)
            {
                current = ansVecAr[b][c];
                ansVecAr[b].push_back(current+pow3);
            }
        }
        for (b = (pow3+1)/2; b <= pow3; b++)
        {
            ansVecAr[a].push_back(b);
        }
    }
    for (a = 1; a <= 10; a++)
    {
        len = ansVecAr[a].size();
        for (b = 0; b < len; b++)
        {
            ansAr[ ansVecAr[a][b] ] = a-1;
        }
    }
    cin >> N;
    for (a = 1; a <= N; a++)
    {
        printf("%lld", ansAr[a]);
    }
    return 0;
}
