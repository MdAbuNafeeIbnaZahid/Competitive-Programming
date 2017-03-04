#include <bits/stdc++.h>
using namespace std;
#define SIZE 1009
#define UP 1
#define LEFT 2
#define CORNER 3
long long testCases, n, dp[SIZE][SIZE], pi, ji, pAns, jAns, len, tot, ifJan[SIZE];
long long solution[SIZE][SIZE];
string str;
long long a, b, c, d, e, f, g, h;
struct choice
{
    long long p, j, idx;
    choice(){}
    choice(long long p, long long j, long long idx)
    {
        this->p = p;
        this->j = j;
        this->idx = idx;
    }
    const bool operator < (choice b)
    {
        if (p == b.p)
        {
            if ( j == b.j )
            {
                return idx > b.idx;
            }
            return j < b.j;
        }
        return p > b.p;
    }
};
vector<choice> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    for (a = 1; a <= testCases; a++)
    {
        memset(dp, 0, sizeof(dp) );
        memset(ifJan, 0, sizeof(ifJan) );
        memset(solution, -1, sizeof(solution) );
        vec = vector<choice>();
        pAns = jAns = tot = 0;
        cin >> n;
        cin >> str;
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld", &pi, &ji);
            vec.push_back( choice(pi, ji, b) );
        }
        sort(vec.begin(), vec.end());
        if ( str[0] == 'P' )
        {
            pAns += vec[0].p;
            vec.erase( vec.begin() );
        }
        len = vec.size();
        for (b = 1; b <= (int)ceil(len/2.0); b++)
        {
            for (c = 1; c <= 2*b-2; c++)
            {
                dp[b][c] = max(dp[b-1][c], dp[b][c-1]);
                if ( dp[b][c] ==  dp[b-1][c])
                {
                    solution[b][c] = UP;
                }
                else if ( dp[b][c] ==  dp[b][c-1])
                {
                    solution[b][c] = LEFT;
                }
            }
            for (c = 2*b-1; c <= len; c++)
            {
                dp[b][c] = max(dp[b-1][c], dp[b][c-1]);
                dp[b][c] = max(dp[b][c], vec[c-1].j+dp[b-1][c-1]);
                if ( dp[b][c] == vec[c-1].j+dp[b-1][c-1] )
                {
                    solution[b][c] = CORNER;
                }
                else if ( dp[b][c] ==  dp[b-1][c])
                {
                    solution[b][c] = UP;
                }
                else if ( dp[b][c] ==  dp[b][c-1])
                {
                    solution[b][c] = LEFT;
                }
            }
        }
        for (b = 0; b <= (int)ceil(len/2.0); b++)
        {
            for (c = 0; c <= len; c++)
            {
                cout << dp[b][c] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (b = 0; b <= (int)ceil(len/2.0); b++)
        {
            for (c = 0; c <= len; c++)
            {
                cout << solution[b][c] << " ";
            }
            cout << endl;
        }
        jAns = dp[ (int)( ceil(len/2.0) ) ][ len ];
        b = (int)( ceil(len/2.0) );
        c = len;
        while(b>0 && c>0)
        {
            if ( solution[b][c] == UP ) b--;
            else if ( solution[b][c] == LEFT ) c--;
            else if ( solution[b][c] == CORNER )
            {
                cout << "b = " << b << ", c = " << c << endl;
                ifJan[c-1] = 1;
                b--;
                c--;
            }
        }
        for (b = 0; b < len; b++)
        {
            if ( !ifJan[b] ) pAns += vec[b].p;
        }

//        for (b = 0; b < len; b++)
//        {
//            tot += vec[b].
//        }
        //cout << "Case " << a << " " << jAns << endl;
        cout << pAns << " " << jAns << endl;
    }
    return 0;
}
