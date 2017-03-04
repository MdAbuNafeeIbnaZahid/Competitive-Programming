#include <bits/stdc++.h>
using namespace std;
int C, R, i, j, k, ans;
string name, c1, c2;
map<string, string> m;
map<string, string>::iterator ssIt;
map<string, int> ansCount;
map<string, int>::iterator siIt;
string getParent(string c)
{
    if ( m[c] == c ) return c;
    m[c] = getParent( m[c] );
    return m[c];
}
void makeUnion(string s1, string s2)
{
    m[ getParent(s1) ] = getParent(s2);
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> C >> R;
        if (C+R==0) return 0;
        m = map<string, string>();
        ansCount = map<string, int>();
        ans = -1;
        for (i = 1; i <= C; i++)
        {
            cin >> name;
            m[name] = name;
            //cout << name << endl;
        }
        for (i = 1; i <= R; i++)
        {
            cin >> c1 >> c2;
            makeUnion(c1, c2);
            //cout << c1 << " " << c2 << endl;
        }
        for (ssIt = m.begin(); ssIt!=m.end(); ssIt++)
        {
            ansCount[ getParent(ssIt->second) ]++;
        }
        for (siIt = ansCount.begin(); siIt!=ansCount.end(); siIt++)
        {
            //cout << siIt->first << " " << siIt->second << endl;
            ans = max(ans, siIt->second);
        }
        cout << ans << endl;
    }
    return 0;
}
