#include <bits/stdc++.h>
using namespace std;
int T;
#define SIZE 100
int ifUsed[SIZE], N, K;
char prin[SIZE];
int cur;
int i, j, a, b, c;
char output[SIZE][SIZE];
int fact[SIZE];
void printAllOrderedPerm(int pos)
{
    //cout << "pos = " << pos << endl;// ", rem = " << rem << endl;
    int a, b, c, d, e;
    if (cur > K) return;
    if ( pos >= N )
    {
        if ( cur < K+10 )
        {
            for (a = 0; a < N; a++)
            {
                //printf("%c", prin[a]);
                output[cur][a] = prin[a];
            }
            //printf("\n");
            output[cur][a] = 0;
            cur++;
        }
        return;
    }
    for (a = 0; a < N; a++)
    {
        if ( !ifUsed[a] )
        {
            ifUsed[a] = 1;
            prin[pos] = 'A'+a;
            printAllOrderedPerm(pos+1);
            ifUsed[a] = 0;
        }
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    cur = 0;
    N = 26;
    K = 30;
    fact[1] = 1;
    fact[2] = 2;
    fact[3] = 6;
    fact[4] = 24;
    for (a = 5; a < SIZE; a++) fact[a] = SIZE;
    printAllOrderedPerm(0);
    //cout << "done" << endl;
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        //cur = 0;
        //memset(ifUsed, 0, sizeof(ifUsed));
        cin >> N >> K;
        //cout << "Case " << i << ":" << endl;
        printf("Case %d:\n", i);
        //printAllOrderedPerm(0);
        for (a = 0; a < K && a < fact[N]; a++)
        {
            for (b = 0; b < N; b++)
            {
                printf("%c", output[a][26-N+b]+N-26);
            }
            printf("\n");
        }
    }
    return 0;
}
