#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000009
long long n, m, leftOpenMust, rightCloseMust, leftOpen, leftClose, rightOpen, rightClose;;
long long i, j, k, openCount, closeCount, available;
long long lo, lc, ro, rc, addee, leftAddee, rightAddee, ans;
long long dp[3000][3000];
long long powOf2[3000];
long long check1, check2;

long long nCr(long long n, long long r)
{
    if ( dp[n][r] != 0) return dp[n][r];
    dp[n][r] = (nCr(n-1, r) % MOD + nCr(n-1, r-1) % MOD) % MOD;
    return dp[n][r];
}

string s;
int main()
{
    cin >> n >> m;
    available = n-m;
    cin >> s;
    for (i = 0; i < 3000; i++)
    {
        dp[i][0] = 1;
    }
    for (i = 0; i < 3000; i++)
    {
        dp[i][i] = 1;
    }
    for (i = 1; i < 3000; i++)
    {
        for (j = 1; j < i; j++)
        {
            nCr(i, j);
        }
    }
    /*
    while(1)
    {
        cin >> check1 >> check2;
        cout << nCr(check1, check2) << endl;
    }
    */
    powOf2[0] = 1;
    for (i = 1; i < 3000; i++)
    {
        powOf2[i] = ( 2*powOf2[i-1] ) % MOD;
    }
    if (n%2!=0)
    {
        cout << 0;
        return 0;
    }
    for (i = 0; i < s.size(); i++)
    {
        if ( s[i] == '(' )
        {
            openCount++;
        }
        else if ( s[i] == ')' )
        {
            if (openCount > 0) openCount--;
            else leftOpenMust++;
        }
    }
    rightCloseMust = openCount;

    //cout << "leftOpenMust = " << leftOpenMust << endl;
    //cout << "rightCloseMust = " << rightCloseMust << endl;

    if ( leftOpenMust + rightCloseMust > available )
    {
        cout << 0;
        return 0;
    }

    if ( leftOpenMust + rightCloseMust == available)
    {
        cout << 1;
        return 0;
    }

    if (( available-(leftOpenMust+rightCloseMust) ) % 2  != 0)
    {
        cout << 0;
        return 0;
    }

    available = available-(leftOpenMust+rightCloseMust);

    for (leftOpen = 0; leftOpen <= available/2; leftOpen++)
    {
        for (leftClose = 0; leftClose <= available/2; leftClose++)
        {
            lo = leftOpen + leftOpenMust;
            ro = (available/2) - leftOpen;

            lc = leftClose;
            rc = (available/2) - leftClose + rightCloseMust;

            //cout << "lo = " << lo << endl;
            //cout << "lc = " << lc << endl;
            //cout << "ro = " << ro << endl;
            //cout << "rc = " << rc << endl << endl;


            if ( lc > lo || ro > rc)
            {
                //cout << "invalid" << endl;
                continue;
            }

            leftAddee = (nCr( (lc+lo), lo )%MOD + ((-powOf2[lc])%MOD+MOD)%MOD + 1%MOD)%MOD;
            //cout << "leftAddee = " << leftAddee << endl;

            rightAddee = nCr(rc+ro, rc)%MOD + (( -powOf2[ro]+1 )%MOD + MOD)%MOD;
            //cout << "rightAddee = " << rightAddee << endl;

            ans = (ans%MOD + ((leftAddee%MOD) * (rightAddee%MOD))%MOD)%MOD;
            //cout << "ans = " << ans << endl;
        }
    }
    cout << ans;
    return 0;
}
