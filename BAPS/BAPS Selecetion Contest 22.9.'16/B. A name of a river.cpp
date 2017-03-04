#include <bits/stdc++.h>
using namespace std;
long long T, K;
long long a, b, c, d, e, f, g, h, most;
map<string, long long> myMap;
string str, ans;
map<string, long long>::iterator mapIt;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> K;
        myMap = map<string, long long>();
        for (b = 1; b <= K; b++)
        {
            cin >> str;
            myMap[str]++;
        }
        most = 0;
        for ( mapIt = myMap.begin(); mapIt != myMap.end(); mapIt++ )
        {
            if ( mapIt->second > most )
            {
                most = mapIt->second;
                ans = mapIt->first;
            }
        }
        cout << "Case " << a << ": " << ans << endl;
    }
    return 0;
}
