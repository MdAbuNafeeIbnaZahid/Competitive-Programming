#include <bits/stdc++.h>
using namespace std;
int testCases, P, T, i, j, a, b, c;
char buf[300];
set<int> tr[200];
set< set<int> > fin;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> testCases;
    while(testCases--)
    {
        for (a = 1; a<= 109; a++)
        {
            tr[a] = set<int>();
        }
        fin = set< set<int> >();
        cin >> P >> T;
        gets(buf);

        while( gets(buf) && strcmp(buf,"") )
        {
            sscanf( buf, "%d%d", &i, &j );
            tr[i].insert(j);
        }

        /*
        while(scanf("%d %d", &i, &j)==2)
        {
            tr[i].insert(j);
        }
        */
        for (a = 1; a <= P; a++)
        {
            fin.insert( tr[a] );
        }
        cout << fin.size() << endl;
        if (testCases) cout << endl;
    }
    return 0;
}
