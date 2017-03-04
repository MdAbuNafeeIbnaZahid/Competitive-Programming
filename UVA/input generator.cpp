#include <bits/stdc++.h>
using namespace std;
long long testCases = 100, N, W, H, xi, yi;
long long a, b, c, d, e, f, g;
int main()
{
    freopen("input.txt", "w", stdout);
    srand( time(NULL) );
    cout << testCases << endl << endl;
    for (a = 1; a <= testCases; a++)
    {
        N = rand() % 101;
        W = rand() % 10000;
        H = rand() % 10000;
        cout << N << " " << W << " " << H << endl;
        for (b = 1; b <= N; b++)
        {
            xi = rand() % (W+1);
            yi = rand() % (H+1);
            cout << xi << " " << yi << endl;
        }
        cout << endl;
    }
    return 0;
}
