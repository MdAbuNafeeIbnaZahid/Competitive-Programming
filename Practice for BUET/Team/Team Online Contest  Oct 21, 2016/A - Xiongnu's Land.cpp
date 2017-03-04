#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long K, R, N, L, T, W, H, n;
long long cumSum[SIZE], difArea[SIZE];
long long a, b, c, d, e, f;
long long leftIdx, rightIdx, addee, total, leftArea, rightArea;
long long probabLeftArea, probabN;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> K;
    //cout << "K = " << K << endl;
    for (a = 1; a <= K; a++)
    {
        cin >> R;
        //cout << "R = " << R << endl;
        for (b = 0; b < R+5; b++)
        {
            cumSum[b] = 0;
        }
        cin >> N;
        //cout << "N = " << N << endl;
        for (b = 1; b <= N; b++)
        {
            scanf("%lld %lld %lld %lld", &L, &T, &W, &H);
            leftIdx = L+1;
            rightIdx = min(L+1+W, R+1);
            addee = min(H, T);
            cumSum[leftIdx] += addee;
            cumSum[rightIdx] -= addee;
        }
        for (b = 1; b <= R+4; b++)
        {
            cumSum[b] += cumSum[b-1];
        }
        for (b = 1; b <= R+4; b++)
        {
            cumSum[b] += cumSum[b-1];
        }
        //for (b = 0; b <= 10; b++)
        //{
            //cout << "b = " << b << ", cumSum[b] = " << cumSum[b] << endl;
        //}
        total = cumSum[R];
        //cout << "total = " << total << endl;
        for (b = 0; b <= R; b++)
        {
            //cout << "b = " << b << endl;
            leftArea = cumSum[b];
            rightArea = total - leftArea;
            //cout << "leftArea = " << leftArea << endl;
            //cout << "rightArea = " << rightArea << endl;
            if ( leftArea >= rightArea )
            {
                probabLeftArea = leftArea;
                probabN = b;
                break;
            }
        }
        //cout << "probabN = " << probabN << endl;
        for (b = probabN+1; b <= R; b++)
        {
            if ( cumSum[b] > probabLeftArea )
            {
                break;
            }
        }
        n = b-1;
        cout << n << endl;
    }
    return 0;
}
