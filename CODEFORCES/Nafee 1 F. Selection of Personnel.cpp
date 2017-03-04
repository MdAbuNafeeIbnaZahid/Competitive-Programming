#include <bits/stdc++.h>
using namespace std;
#define SIZE 800
unsigned long long n, r, i, j, k, ans;
unsigned long long fact(unsigned long long r)
{
    unsigned long long ret = 1, i;
    for (i = 2; i <= r; i++)
    {
        ret*=i;
    }
    return  ret;
}
unsigned long long nCr(unsigned long long n, unsigned long long r)
{
    vector<unsigned long long> up;
    unsigned long long down = fact(r), i, j, k, ret = 1;;
    for (i = 0; i<r; i++) up.push_back(n-i);
    for (i = 0; i < up.size(); i++)
    {
        for (j = 2; j <= r; j++)
        {
            while( up[i]%j==0 && down%j==0 )
            {
                up[i]/=j;
                down/=j;
            }
        }
        ret*=up[i];
    }
    return ret;
}
int main()
{
    cin >> n;
    ans = nCr(n, 5)+nCr(n, 6)+nCr(n, 7);
    cout << ans ;
    return 0;
}
