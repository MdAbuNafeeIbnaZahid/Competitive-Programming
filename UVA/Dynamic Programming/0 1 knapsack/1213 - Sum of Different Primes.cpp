#include <bits/stdc++.h>
using namespace std;
#define SIZE 1129
vector<int> primes;
bool mark[SIZE];
int n, k, ans;
int i, j, a, b, c, d, e, f, g;
int ar[200][SIZE][19];
int main()
{
    freopen("input.txt", "r", stdin);
    memset(mark, true, sizeof(mark));
    memset(ar, 0, sizeof(ar));
    mark[1] = false;
    for (i = 4; i < SIZE; i+=2)
    {
        mark[i] = false;
    }
    for (i = 3; i <= sqrt(SIZE+1); i++)
    {
        if ( mark[i] )
        {
            for (j = i*i; j < SIZE; j+=(2*i)) mark[j] = false;
        }
    }
    for (i = 2; i < SIZE; i++)
    {
        if (mark[i]) primes.push_back(i);
    }
    for (a = 0; a < primes.size(); a++)
    {
        //cout << primes[a] << " ";
        b = 0;
        c = 0;
        ar[a][b][c] = 1;
    }
    //cout << endl;
    ar[0][2][1] = 1;
    for (a = 1; a < primes.size(); a++)
    {
        for (b = 0; b <= SIZE; b++)
        {
            for (c = 1; c <= 14; c++)
            {
                if ( b-primes[a] >= 0 )
                {
                    ar[a][b][c] = ar[a-1][ b-primes[a] ][c-1] + ar[a-1][b][c];
                }
                else
                {
                    ar[a][b][c] = ar[a-1][b][c];
                }
            }
        }
    }
    while(1)
    {
        ans = 0;
        scanf("%d %d", &n, &k);
        if (n+k==0) return 0;
        ans = ar[ primes.size()-1 ][n][k];
        printf("%d\n", ans);
    }
    return 0;
}
