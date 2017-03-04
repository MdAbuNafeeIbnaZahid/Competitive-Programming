#include <bits/stdc++.h>
using namespace std;
long long T, N;
long long orientate(long long n, long long si, long long ei)
{
    long long ret = n, a, b, c, d, e, cap;
    if ( si > ei )
    {
        return 0;
    }
//    for (a = 1; a <= si; a++ )
//    {
//        ret >>= 1LL;
//    }
    ret >>= si;
    cap = (1LL << (ei-si+1) ) - 1;
    ret = cap & ret;
    return ret;
}
long long countAdjBit(long long n)
{
    long long a, b, c, d, e, f, ret = 0;
    for ( a = 0; a < 50; a++ )
    {
        if ( ( (n>>a)&1LL) && ( (n>> (a+1LL) )&1) )
        {
            ret++;
        }
    }
    return ret;
}
long long countAdjBitUpto( long long n )
{
    long long a, b, c, d, ret = 0;
    for ( a = 1; a <= n; a++ )
    {
        ret += countAdjBit(a);
    }
    return ret;
}
long long solve( long long n )
{
    long long a, b, c, d, e, ret = 0, twoBits, left, right, addee;
    for ( a = 0; a < 50; a++ )
    {
        twoBits = orientate(n, a, a+1);
        left = orientate(n, a+2, 50);
        right = orientate(n, 0, a-1);
        if ( twoBits == 3 ) // tick
        {
            //addee = left * (1LL << a);
            addee = left * (1LL << a) + right+1;;
        }
        else // cross
        {
//            if (!left)
//            {
//                addee = 0;
//            }
//            else
//            {
                //addee = (left-1) * (1LL << a) + right+1;
                addee = left * (1LL<<a);
//            }
        }
        ret += addee;
    }
    return ret;
}
int main()
{
//    freopen("input.txt", "r", stdin);
//    while( 1 )
//    {
//        long long num;
//        cin >> num;
//        cout << countAdjBitUpto(num) << endl << endl;
//    }
    long long a, b, c, d, e;
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        long long ans;
        scanf("%lld", &N);
        ans = solve(N);
        printf("Case %lld: %lld\n", a, ans);
    }
    return 0;
}
