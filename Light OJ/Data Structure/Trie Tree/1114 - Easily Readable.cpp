#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define SIZE 10009
long long T, n, m, ans;
long long a, b, c, d, e, f, g;
string strAr[SIZE], s;
map<string, long long> myMap;
string line;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        myMap = map<string, long long>();
        ans = 1;
        cin >> n;
        for (b = 1; b <= n; b++)
        {
            cin >> s;
            if (s.size()>2) sort( s.begin()+1, s.end()-1 );
            //cout << "s = " << s << endl;
            myMap[s]++;
        }
        cin >> m;
        //cout << "m = " << m << endl;
        getchar();
        printf("Case %lld:\n", a);
        for (b = 1; b <= m; b++)
        {
            ans = 1;
            getline(cin, line);
            //cout << "line = " << line << endl;
            stringstream ss(line);
            while(ss>>s)
            {
                if (s.size()>2) sort( s.begin()+1, s.end()-1 );
                //cout << "s = " << s << endl;
                ans *= myMap[s];
                //cout << "s = " << s << ", ans = " << ans << endl;
            }
            printf("%lld\n", ans);
        }
        //printf("Case %lld: %lld\n", a, ans);
    }
    return 0;
}
