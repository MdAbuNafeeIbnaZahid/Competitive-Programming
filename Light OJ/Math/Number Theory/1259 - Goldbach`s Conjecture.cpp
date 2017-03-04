#include <bits/stdc++.h>
using namespace std;
#define SIZE 10000009
int T, n, a, b, ans;
int i, j, k, x, y, z, s;
bool mark[SIZE];
vector<int> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    memset( mark, true, sizeof(mark) );
    mark[1] = false;
    for (i = 2; i <= sqrt(SIZE+1); i++)
    {
        if (mark[i])
        {
            for (j = i*i; j<SIZE; j+=i)
            {
                //cout << j << endl;
                mark[j] = false;
            }
        }
    }
    for (i = 2; i < SIZE; i++)
    {
        if (mark[i]) vec.push_back( i );
        //cout << i << endl;
    }
    s = vec.size();
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ans = 0;
        cin >> n;
        for (j = 0; j < s; j++)
        {
            a = vec[j];
            b = n-vec[j];
            if (a>b) break;
            if ( mark[b] ) ans++;
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
