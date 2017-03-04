#include <bits/stdc++.h>
using namespace std;

long long n, a, b, c, ans1 = 0, rem, ans2 = 0, adde;

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n >> a >> b >> c;

    ans1 = (n/a);
    rem = n%a;
    while(rem >= b)
    {
        adde = rem/b;
        rem %= b;
        ans1 += adde;
        rem += adde * c;
    }

//    ans1 += (rem-(b-1))/(b-c);
//    rem = rem - (ans1 - (n/a) ) * (b-c);
//
//    ans1 += rem/b;




    rem = n;
    while(rem >= b)
    {
        adde = rem/b;
        rem %= b;
        ans2 += adde;
        rem += adde * c;
    }

//    ans2 = (n-(b-1))/(b-c);
//    rem = n - ans2*(b-c);
//
//    ans2 += rem/b;
//    rem = rem % b;

    ans2 += (rem/a);

    cout << (ans1>ans2?ans1:ans2);

    return 0;
}

