#include <bits/stdc++.h>
using namespace std;
long long U, L, copU;
vector<long long> digits;
long long dp[25][4][1L<<20];
long long recDp(long long pos, long long ifEq, long long bitMask)
{
    long long a, b, c, d, e, f, g;
    long long ret = 0, mul = 1, low = 0, high, copPos;
    //cout << "pos = " << pos << endl;
    if ( pos < 0 )
    {
        return 0;
    }
    if ( dp[pos][ifEq][bitMask] == -1 )
    {
        if ( ifEq == 0 ) // ifSmall
        {
            ret = 0;
            copPos = pos;
            for (a = 19; a >= 0 && copPos >= 0; a--)
            {
                if ( ( (bitMask>>a) & 1 ) == 0 )
                {
                    ret = ret*10 + (a/2);
                    //cout << "a = " << a << endl;
                    //cout << "ret = " << ret << endl;
                    copPos--;
                }
            }
            //dp[pos][ifEq][bitMask] = ret;
        }
        else // ifEq
        {
            ret = INT_MIN;
            for (a = 1; a <= pos; a++)
            {
                mul *= 10;
            }
            //cout << "mul = " << mul << endl;
            low = 0;
            high = digits[pos];
            //cout << "high = " << high << endl;
            for (a = low; a < high; a++)
            {
                if ( ( ( bitMask>>(2*a)) & 1 ) == 0 )
                {
                    ret = max(ret, a*mul+recDp(pos-1, 0, bitMask|(1L<<2*a) ) );
                }
                else if ( ( ( bitMask>>(2*a+1)) & 1 ) == 0 )
                {
                    ret = max(ret, a*mul+recDp(pos-1, 0, bitMask|(1L<<(2*a+1) ) ) );
                }
            }
            if ( ( ( bitMask>>(2*high)) & 1 ) == 0 )
            {
                ret = max(ret, high*mul+recDp(pos-1, 1, bitMask|(1L<<2*high) ) );
            }
            else if ( ( ( bitMask>>(2*high+1)) & 1 ) == 0 )
            {
                ret = max(ret, high*mul+recDp(pos-1, 1, bitMask|(1L<<(2*high+1) ) ) );
            }
            if ( ret == INT_MIN )
            {
                //cout << "ret == INT_MIN" << endl;
            }
        }
        dp[pos][ifEq][bitMask] = ret;
    }
    return dp[pos][ifEq][bitMask];
}
int main()
{
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    while( scanf("%lld", &U) == 1 )
    {
        memset(dp, -1, sizeof( dp ) );
        digits = vector<long long>();
        if ( U == 1000000000000000000 )
        {
            L = recDp( 17, 0, 0 );
            //cout << "*************";
            cout << L << endl;
            //cout << 998877665544332211 << endl;
        }
        else
        {
            memset(dp, -1, sizeof( dp ) );
            copU = U;
            while(copU)
            {
                digits.push_back( copU%10 );
                copU /= 10;
            }
            //cout << "digits.size()-1 = " << digits.size()-1 << endl;
            L = recDp( digits.size()-1, 1, 0 );
            //cout << "*************";
            cout << L << endl;
        }
    }
    return 0;
}
