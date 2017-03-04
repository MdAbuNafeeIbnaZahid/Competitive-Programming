#include <bits/stdc++.h>
using namespace std;
int i, j, k, n;
double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}
int main()
{
    srand(time(NULL));
    freopen("dataSet.txt", "w", stdout);
    n = 200;
    for (i = 1; i <= 200; i++)
    {
        cout << fRand(0, 40000) << " " << fRand(0, 40000) << endl;
    }
    return 0;
}
