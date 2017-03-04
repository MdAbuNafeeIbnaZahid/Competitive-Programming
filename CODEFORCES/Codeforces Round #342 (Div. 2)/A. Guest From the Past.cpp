#include <bits/stdc++.h>
using namespace std;

long long int n, a, b, c, ans1 = 0, rem, ans2 = 0, adde = 0;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n >> a >> b >> c;

    //cout << "\n b-c = " << b-c << "\n";

    ans1 = (n/a);
    rem = n%a;

    if (rem > b-1) ans1 += (rem-(b-1))/(b-c);
    rem = rem - (ans1 - (n/a) ) * (b-c);

    ans1 += rem/b;


    if (n > b-1)
    {
        //cout << "\n (n > b-1) \n";
        //cout << "\n (n-(b-1)) = " << (n-(b-1)) << "\n";
        //cout << "\n (b-c) = " << (b-c) << "\n";
        //ans2++;
        //rem = n - b;
        ans2 += (n-(b-1))/(b-c);
    }

    //cout << "\n ans2 = " << ans2 << "\n";
    rem = n - ans2*(b-c);


    //cout << "\n rem = " << rem << "\n";

    ans2 += rem/b;
    if (rem/b) adde = c;
    rem = rem % b;
    rem += adde;


    //cout << "\n rem = " << rem << ", a = " << a << "\n";
    ans2 += (rem/a);

    cout << (ans1>ans2?ans1:ans2);

    return 0;
}
