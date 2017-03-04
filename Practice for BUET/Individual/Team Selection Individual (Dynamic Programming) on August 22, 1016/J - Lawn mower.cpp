#include <bits/stdc++.h>
using namespace std;
long long nx, ny;
double xi, yi, w;
long long a, b, c, d, e, f, g, h;
vector<double> vecX, vecY;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> nx >> ny >> w;
        if(nx+ny+w==0) break;
        vecX = vector<double>();
        vecY = vector<double>();

        vecX.push_back(-w/2);
        vecX.push_back(75+w/2);

        vecY.push_back(-w/2);
        vecY.push_back(100+w/2);

        for (a = 1; a <= nx; a++)
        {
            scanf("%lf", &xi);
            vecX.push_back(xi);
        }
        for (a = 1; a <= ny; a++)
        {
            scanf("%lf", &yi);
            vecY.push_back(yi);
        }
        sort(vecX.begin(), vecX.end());
        sort(vecY.begin(), vecY.end());
        for (a = 1; a < nx+2; a++)
        {
            if ( vecX[a]-vecX[a-1] > w ) break;
        }
        for (b = 1; b < ny+2; b++)
        {
            if (vecY[b] - vecY[b-1] > w) break;
        }
        if (a<nx+2 || b<ny+2) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
