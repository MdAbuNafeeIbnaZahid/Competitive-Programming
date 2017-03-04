#include <bits/stdc++.h>
using namespace std;
int N, E, K, ans, i, j;
char a, b, p[3000];
set<char>::iterator it;
set<char> used, compo;
char getParent(char ch)
{
   if (ch == p[ch]) return ch;
   p[ch] = getParent( p[ch] );
   return p[ch];
}
void makeUnion(char c1, char c2)
{
    p[ (int)getParent(c1) ] = getParent(c2);
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(scanf("%d %d", &N, &E)==2)
    {
        compo = set<char>();
        used = set<char>();
        for (i = 0; i < 3000; i++)
        {
            p[i] = i;
        }
        for (i = 1; i <= E; i++)
        {
            cin >> a >> b;
            used.insert(a);
            used.insert(b);
            makeUnion(a, b);
            //cout << a << " " << b << endl;
        }
        for (it = used.begin(); it != used.end(); it++)
        {
            compo.insert( getParent( *it ) );
        }
        //cout << "compo.size() = " << compo.size() << endl;
        K = compo.size() + (N-used.size());
        cout << 1 + K + E - N << endl;
    }
    return 0;
}
