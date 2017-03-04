#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
#define WHITE 0
#define GREY 1
#define BLACK 2
long long T, m, n;
long long layer[SIZE], matchedMember[SIZE], color[SIZE], addee, maxMatch, loopCount;
long long a, b, c, d, e, f;
struct person
{
    long long height, age, ifDivorced, ifMan;
};
vector<long long> gr[SIZE];
person personArray[SIZE];
void bfs1()
{
    long long a, b, c, d, e, len, current;
    queue<long long > Q;
    for (a = 1; a <= m; a++)
    {
        layer[a] = INT_MAX;
        if ( matchedMember[a]== -1 )
        {
            layer[a] = 0;
            Q.push(a);
        }
    }
    while(!Q.empty())
    {
        current = Q.front();
        Q.pop();
        //cout << "current = " << current << endl;
        len = gr[current].size();
        for (a = 0; a < len; a++)
        {
            //cout << "matchedMember[ gr[current][a] ] = " << matchedMember[ gr[current][a] ] << endl;
            if ( matchedMember[ gr[current][a] ] != -1 && layer[ matchedMember[ gr[current][a] ] ] == INT_MAX  )
            {
                //cout << matchedMember[ gr[current][a] ] << " will be pushed " << endl;
                layer[ matchedMember[ gr[current][a] ] ] = layer[current]+1;
                Q.push( matchedMember[ gr[current][a] ] );
            }
        }
    }
}
long long dfs1(long long u)
{
    long long a, b, c, d, e, len = gr[u].size(), posRet;
    if ( color[u] != WHITE ) return 0;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        if ( matchedMember[gr[u][a]]!=-1 && layer[matchedMember[gr[u][a]]]==layer[u]+1 )
        {
            posRet = dfs1(matchedMember[gr[u][a]]);
            if ( posRet  )
            {
                matchedMember[u] = gr[u][a];
                matchedMember[gr[u][a]] = u;
                return 1;
            }
        }
    }
    for (a =0; a < len; a++)
    {
        if ( matchedMember[ gr[u][a] ] == -1 )
        {
            matchedMember[u] = gr[u][a];
            matchedMember[gr[u][a]] = u;
            return 1;
        }
    }
    color[u] = BLACK;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        maxMatch = 0;
        cin >> m >> n;

        for (b = 1; b <= m; b++)
        {
            scanf("%lld %lld %lld", &personArray[b].height, &personArray[b].age, &personArray[b].ifDivorced);
            matchedMember[b] = -1;
        }
        for (b = 1, c = m+1; b <= n; b++, c++)
        {
            scanf("%lld %lld %lld", &personArray[c].height, &personArray[c].age, &personArray[c].ifDivorced);
            matchedMember[c] = -1;
        }
        for (b = 1; b <= m+n; b++)
        {
            gr[b] = vector<long long>();
        }
        //cout << "m = " << m << endl;
        //cout << "n = " << n << endl;
        for (b = 1; b <= m; b++)
        {
            for (c = m+1; c <= m+n; c++)
            {
                //cout << "(" << b << "," << c << ")" << endl;

                if ( abs(personArray[b].height-personArray[c].height) <= 12 &&
                    abs(personArray[b].age-personArray[c].age) <= 5
                    && personArray[b].ifDivorced==personArray[c].ifDivorced )
                {
                    //cout << "(" << b << "," << c << ")" << endl;
                    gr[b].push_back(c);
                    gr[c].push_back(b);
                }
            }
        }
        loopCount = 0;
        while(++loopCount)
        {
            //cout << "loopCount = " << loopCount << endl;
            for (b = 1; b <= m+n; b++)
            {
                //cout << "matchedMember[" << b << "] = " << matchedMember[b] << endl;
            }
            addee = 0;
            bfs1();
            for (b = 1; b <= n+m; b++)
            {
                color[b] = WHITE;
            }
            for (b = 1; b <= m; b++)
            {
                //cout << "layer[" << b << "] = " << layer[b] << endl;
                if (layer[b] == 0)
                {
                    addee += dfs1(b);
                }
            }
            if (addee <= 0) break;
            maxMatch += addee;
        }
        cout << "Case " << a << ": " << maxMatch << endl;
    }
    return 0;
}
