#include <bits/stdc++.h>
using namespace  std;
#define SIZE 100009
long long n, m, q, grid[1009][1009], input[100009][9], order, ansAr[100009], isFullToggled[SIZE];
long long a, b, c, d, e, f, g, h,  bookCount[SIZE];
long long i, j, k;
vector<long long> gr[100009];
long long dfs(long long u)
{
    long long a, b, c, d, e, f, g, len = gr[u].size(), current, order;
    long long i, k, j, ifChanged;
    for (a = 0; a < len; a++)
    {
        ifChanged = 0;
        current = gr[u][a];
        order = input[current][1];
        if (order == 1)
        {
            //scanf("%lld %lld", &i, &j);
            i = input[current][2] ;
            j = input[current][3] ;
            //gr[a-1].push_back( a );
            if ( isFullToggled[i]^grid[i][j] == 0 )
            {
                ansAr[current] = ansAr[u]+1;
                bookCount[i]++;
                grid[i][j] ^= 1;
                ifChanged = 1;
            }
            else
            {
                ansAr[current] = ansAr[u];
            }
            dfs(current);
            if ( ifChanged )
            {
                grid[i][j] ^= 1;
                bookCount[i]--;
            }
        }
        else if (order == 2)
        {
            //scanf("%lld %lld", &i, &j);
            i = input[current][2] ;
            j = input[current][3] ;
            //gr[a-1].push_back( a );
            if ( isFullToggled[i]^grid[i][j] == 1 )
            {
                ansAr[current] = ansAr[u]-1;
                bookCount[i]--;
                grid[i][j] ^= 1;
                ifChanged = 1;
            }
            else
            {
                ansAr[current] = ansAr[u];
            }
            dfs(current);
            if ( ifChanged )
            {
                grid[i][j] ^= 1;
                bookCount[i]++;
            }
        }
        else if (order == 3)
        {
            //scanf("%lld", &i);
            i = input[current][2] ;
            //gr[a-1].push_back( a );
            ansAr[current] = ansAr[u] - bookCount[i] + (m - bookCount[i]);
            bookCount[i] = m-bookCount[i];
            isFullToggled[i] ^= 1;
            dfs(current);
            bookCount[i] = m-bookCount[i];
            isFullToggled[i] ^= 1;
        }
        else if (order == 4)
        {
            //scanf("%lld", &k);
            k = input[current][2] ;
            //isSaved[k] = 1;
            //gr[k].push_back( a );
            ansAr[current] = ansAr[u];
            dfs(current);
        }
    }
    return 1;
}
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n >> m >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &order);
        input[a][1] = order;
        if (order == 1)
        {
            scanf("%lld %lld", &i, &j);
            input[a][2] = i;
            input[a][3] = j;
            gr[a-1].push_back( a );
        }
        else if (order == 2)
        {
            scanf("%lld %lld", &i, &j);
            input[a][2] = i;
            input[a][3] = j;
            gr[a-1].push_back( a );
        }
        else if (order == 3)
        {
            scanf("%lld", &i);
            input[a][2] = i;
            gr[a-1].push_back( a );
        }
        else if (order == 4)
        {
            scanf("%lld", &k);
            input[a][2] = k;
            //isSaved[k] = 1;
            gr[k].push_back( a );
        }
    }
    dfs(0);
    for (a = 1; a <= q; a++)
    {
        printf("%lld\n", ansAr[a]);
    }
    return 0;
}
