#include <bits/stdc++.h>
using namespace std;
#define SIZE 39
long long t, w, n, di, vi, d[SIZE], v[SIZE];
long long ar[SIZE][1009];
long long i, j, k, flag = 0;
vector<long long> vAr[SIZE][1009];
int main()
{
    freopen("input.txt", "r", stdin);
    while(cin >> t)
    {
        if (flag) cout << endl;
        flag = 1;
        memset(ar, 0, sizeof(ar) );
        for (j = 0; j < SIZE; j++)
        {
            for (i = 0; i < 1009; i++) vAr[j][i] = vector<long long>();
        }
        cin >> w;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            scanf("%lld %lld", &d[i], &v[i]);
            d[i]*=(3*w);
        }
        for (i = 1; i <= n; i++)
        {
            for (j = 0; j <= t; j++)
            {
                if (j -d[i]>=0 && ar[i-1][j -d[i] ]+v[i] > ar[i-1][j] )
                {
                    ar[i][j] = ar[i-1][j -d[i] ]+v[i];
                    vAr[i][j] = vector<long long>(vAr[i-1][j-d[i] ]);
                    vAr[i][j].push_back(i);
                }
                else
                {
                    ar[i][j] = ar[i-1][j];
                    vAr[i][j] = vector<long long>( vAr[i-1][j] );
                }
            }
        }
        cout << ar[n][t] << endl;
        cout << vAr[n][t].size() << endl;
        for (i = 0; i < vAr[n][t].size(); i++)
        {
            printf("%lld %lld\n", d[ vAr[n][t][i] ]/(3*w), v[vAr[n][t][i] ] );
        }
        //cout << endl;
    }
    return 0;
}
