#include <bits/stdc++.h>
using namespace std;
long long n[5], T;
char op[9], ops[] = {'=', '+', '-'};
long long a, b, c, d, e, f, g, done;
long long ifOk()
{
    if ( op[0]!='=' && op[1]!='=' && op[2]!='=' ) return 0;
    long long clause[5] = {0, 0, 0, 0, 0}, idx = 0;
    long long a, b, c, d, e, f;

    clause[0] = n[0];
    for (a = 0; a < 3; a++)
    {
        if ( op[a] == '=' )
        {
            idx++;
            clause[idx] = n[a+1];
        }
        else if ( op[a] == '+' )
        {
            clause[idx] += n[a+1];
        }

        else if (op[a] == '-'  )
        {
            clause[idx] -= n[a+1];
        }
    }
    //cout << "idx = " << idx << endl;
    for (a = 0; a < idx; a++)
    {
        if (clause[a] != clause[a+1]) return 0;
    }
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        done = 0;
        scanf("%lld %lld %lld %lld", &n[0], &n[1], &n[2], &n[3]);
        //cout << "input taken" << endl;
        for (b = 0; b < 3 && !done; b++)
        {
            for (c = 0; c < 3 && !done; c++)
            {
                for (d = 0; d < 3 && !done; d++)
                {
                    op[0] = ops[b];
                    op[1] = ops[c];
                    op[2] = ops[d];
                    if ( ifOk() )
                    {
                        printf("Case #%lld: %lld %c %lld %c %lld %c %lld\n", a, n[0], op[0],
                               n[1], op[1], n[2], op[2], n[3]);
                        done = 1;
                    }
                }
            }
        }
    }
    return 0;
}
