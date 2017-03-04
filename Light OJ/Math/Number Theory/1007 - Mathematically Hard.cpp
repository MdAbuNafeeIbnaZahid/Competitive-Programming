#include <bits/stdc++.h>
using namespace std;
#define SIZE 5000009
bool mark[SIZE];
unsigned long long int rpn[SIZE], i, j, k, a, b, T;
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    for (i = 0; i < SIZE; i++) rpn[i] = i*i;
    mark[1] = 0;
    rpn[1] = 0;
    for (i = 2; i < SIZE; i++)
    {
        if (mark[i])
        {
            for (j = i; j < SIZE; j+=i)
            {
                mark[j] = false;
                rpn[j] = (rpn[j] / (i*i))*(i-1)*(i-1);
            }
        }
    }
    for (i = 2; i < SIZE; i++)
    {
        rpn[i] += rpn[i-1];
    }
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        //cin >> a >> b;
        //cout << "Case " << i << ": " << rpn[b]-rpn[a-1] << endl;
        scanf("%lld %lld", &a, &b);
        printf("Case %lld: %llu\n", i, (rpn[b]-rpn[a-1]) );
    }
    return 0;
}
