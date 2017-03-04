#include <bits/stdc++.h>
using namespace std;
#define SIZE 10009
long long T, m;
string a, b, current;
map<string, long long> indegree, visited;
map< string, vector<string> > gr;
char input[SIZE][4][19];
long long i, j, k,  x, y, z, o, p;
queue< string > q;
map<string, long long>::iterator visitedIt, indegreeIt;
vector<string>::iterator vecStrIt;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        indegree = map<string, long long>();
        visited = map<string, long long>();
        gr = map< string, vector<string> >();
        cin >> m;
        for (j = 1; j <= m; j++)
        {
            cin >> a >> b;
            //cout << a << b;
            indegree[a]++;
            indegree[a]--;
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
        cout << "Case " << i << ": " ;
        q = queue<string>();
        //cout << " indegree.size() =  " << indegree.size() << endl;
        for ( indegreeIt = indegree.begin(); indegreeIt != indegree.end(); indegreeIt++ )
        {
            x = indegreeIt->second;
            //cout << "visitedIt->first = " << visitedIt->first << endl;
            if ( indegreeIt->second == 0 ) q.push( indegreeIt->first );
        }
        //cout << " queue is initialized " << endl;
        while( !q.empty() )
        {
            current = q.front();
            q.pop();
            for ( vecStrIt = gr[current].begin(); vecStrIt != gr[current].end(); vecStrIt++ )
            {
                indegree[*vecStrIt]--;
                if ( indegree[*vecStrIt]<= 0 )
                {
                    q.push( *vecStrIt );
                }
            }
        }
        for ( indegreeIt = indegree.begin(); indegreeIt != indegree.end(); indegreeIt++ )
        {
            if ( indegreeIt->second > 0 )
            {
                break;
                //printf("No \n");
            }
        }
        if ( indegreeIt == indegree.end() ) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
