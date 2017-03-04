#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long N, C, hi, h[SIZE], ci, c[SIZE];
long long a, b, x, y, z, i, j, k, cumulativeColor[SIZE][35], ans, calcStart;
struct heightIdx
{
    int height;
    int idx;
    heightIdx(){}
    heightIdx(int height, int idx)
    {
        this->height = height;
        this->idx = idx;
    }
};
heightIdx current;
stack<heightIdx> stak;
int ifColorOk(int s, int e, int c)
{
    int i, j,k;
    for (i = 0; i < c; i++) if ( cumulativeColor[e][i] - cumulativeColor[s-1][i] <= 0 ) return 0;
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        stak = stack<heightIdx>();
        ans = -1;
        cin >> N >> C;
        if (N+C==0) return 0;
        for (i = 1; i <= N; i++) cin >> h[i];
        h[N+1] = 0;
        for (i = 1; i <= N; i++) cin >> c[i];
        c[N+1] = -1;
        for (j = 0; j < C; j++) cumulativeColor[0][j] = 0;
        for (i = 1; i <= N+1; i++)
        {
            for (j = 0; j < C; j++) cumulativeColor[i][j] = cumulativeColor[i-1][j] + (c[i]==j);
        }
        //cout << endl;
        //for (i = 0; i <= N+1; i++)
        //{
            //for (j = 0; j < C; j++) cout << cumulativeColor[i][j] << " ";
            //cout << endl;
        //}
        for (i = 1; i <= N+1; i++)
        {
            while( !stak.empty() && stak.top().height > h[i])
            {
                current = stak.top();
                stak.pop();
                if ( stak.empty() ) calcStart = 1;
                else calcStart = stak.top().idx+1;
                if ( ifColorOk(calcStart, i-1, C) )
                {
                    //cout << " calcStart+1= " << calcStart+1 << ", i-1 = " << i-1 << endl;
                    ans = max(ans, (i-1-calcStart+1)*current.height );
                }
            }
            stak.push( heightIdx(h[i], i) );
        }
        cout << ans << endl;
    }
    return 0;
}
