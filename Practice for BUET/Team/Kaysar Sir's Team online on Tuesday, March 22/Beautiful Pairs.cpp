#include <bits/stdc++.h>
using namespace std;
#define SIZE
int N, i, j, ans = 0, ele;
vector<int> A, B;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> N;
    for (i = 0; i < N; i++)
    {
        scanf("%d", &ele);
        A.push_back(ele);
    }
    for (i = 0; i < N; i++)
    {
        scanf("%d", &ele);
        B.push_back(ele);
    }
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());

    j = 0;
    for (i = 0; i < N; i++)
    {
        if (j>=N) continue;
        while(B[j]<A[i] && j<N-1)
        {
            j++;
        }
        if (B[j]==A[i])
        {
            ans++;
            j++;
        }
    }
    //cout << ans << endl;

    ans = min(ans+1, N);
    cout << ans;
    return 0;
}
