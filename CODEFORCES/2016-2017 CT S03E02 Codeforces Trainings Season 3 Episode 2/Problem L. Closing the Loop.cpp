#include <bits/stdc++.h>
using namespace std;
long long S, len, num, subtract, ans;
vector<long long> bl, re;
char str[99];
long long a, b, c, d, e, f, g, h;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> S;
    for ( a = 1; a <= S; a++ )
    {
        num = 0;
        scanf("%s", str);
        len = strlen(str);
        for (b = 0; b < len-1; b++)
        {
            num = num*10 + str[b]-'0';
        }
        if ( str[len-1] == 'R' )
        {
            re.push_back(num);
        }
        else
        {
            bl.push_back(num);
        }
    }
    sort(re.begin(), re.end());
    sort(bl.begin(), bl.end());
    while( re.size() && bl.size() )
    {
        len = re.size();
        ans += re[len-1];
        re.pop_back();

        len = bl.size();
        ans += bl[len-1];
        bl.pop_back();

        subtract += 2;
    }
    ans -= subtract;
    cout << ans;
    return 0;
}
