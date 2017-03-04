#include <bits/stdc++.h>
using namespace std;
double a, b,  xi, yi, vi, ans, dis;
long long i, j, k, n;
int main()
{
//    freopen("input.txt", "r", stdin);
    ans = INT_MAX;
    cin >> a >> b;
    cin >> n;
    for (i = 1; i <= n; i++)
    {
        scanf("%lf %lf %lf", &xi, &yi, &vi);
        //cout << "xi = " << xi << endl;
        //cout << "yi = " << yi << endl;
        dis = sqrt( (a-xi)*(a-xi) + (b-yi)*(b-yi) );
        //cout << dis << endl;
        ans = min( ans, dis/vi );
    }
    printf("%0.11lf", ans);
    return 0;
}
