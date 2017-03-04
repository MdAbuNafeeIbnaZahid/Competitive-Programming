#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, m;
string a, b;
map<string, long long> indegree, visited;
map< string, vector<string> > gr;
char input[SIZE][4][19];
long long i, j, k,  x, y, z, o, p;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> m;
        for (j = 1; j <= m; j++)
        {
            cin >> a >> b;
            cout << a << b;
            indegree[b]++;
            if ( gr.find(a)==gr.end() )
            {
                gr[a] = vector<string>();
                gr[a].push_back(b);
            }
            else
            {
                gr[a].push_back(b);
            }
        }
    }
    return 0;
}
