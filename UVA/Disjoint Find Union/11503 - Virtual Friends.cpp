#include <bits/stdc++.h>
using namespace std;
int testCases, F;
string n1, n2;
map<string, string> p;
map<string, int> tot;
string getParent(string s)
{
    if (p[s] == s) return s;
    p[s] = getParent( p[s] );
    return p[s];
}
void makeUnion(string s1, string s2)
{
    if ( getParent(s1)==getParent(s2) ) cout << tot[ getParent(s1) ] << endl;
    else
    {
        cout << tot[getParent(s1)]+tot[getParent(s2)] << endl;
        tot[ getParent(s2) ] = tot[getParent(s1)]+tot[getParent(s2)];
        p[ getParent(s1) ] = getParent(s2);
    }
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> testCases;
    while(testCases--)
    {
        //cout << "testCases = " << testCases+1 << endl;
        p = map<string, string>();
        tot = map<string, int>();
        cin >> F;
        while(F--)
        {
            cin >> n1 >> n2;
            if ( tot[n1]==0 )
            {
                tot[n1] = 1;
                p[n1] = n1;
            }
            if (tot[n2]==0)
            {
                tot[n2] = 1;
                p[n2] = n2;
            }
            makeUnion(n1, n2);
        }
    }
    return 0;
}
