#include <iostream>
#include <stack>
#include <cstdio>
using namespace std;
#define SIZE 30009
stack<int> stak;
int T, N, ans, heightAr[SIZE], i, j, k, height;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        ans = -1;
        stak = stack<int>();
        cin >> N;
        for (j = 1; j <= N; j++) cin >> heightAr[j];
        for (j = 1; j <= N; j++)
        {
            while( !stak.empty() && heightAr[stak.top()] > heightAr[j] )
            {
                height = heightAr[stak.top()];
                stak.pop();

                if (stak.empty()) ans = max(ans, (j-1)*height );
                else if ( !stak.empty() ) ans = max(ans, (j-stak.top()-1 )*height );
            }
            stak.push(j);
        }
        while( !stak.empty() )
        {
            height = heightAr[stak.top()];
            stak.pop();

            if (stak.empty()) ans = max(ans, (j-1)*height );
            else if ( !stak.empty() ) ans = max(ans, (j-stak.top()-1 )*height );
        }
        cout << "Case " << i << ": " << ans << endl;
    }
    return 0;
}
