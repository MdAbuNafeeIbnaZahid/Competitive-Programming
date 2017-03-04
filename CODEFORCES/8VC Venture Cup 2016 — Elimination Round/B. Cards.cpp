#include <bits/stdc++.h>
using namespace std;
char visited[350][350][350];
int i, j, k, n, b, g, r;
string str;

int bAr[] = {-1, 0, 0, 1, -1, -1};
int gAr[] = {0, -1, 0, -1, 1, -1};
int rAR[] = {0, 0, -1, -1, -1, -1};

int ifOk(int b, int g, int r)
{
    if (b < 0 || b > 320) return 0;
    if (g < 0 || g > 320) return 0;
    if (r < 0 || r > 320) return 0;
    if ( visited[b][g][r] ) return 0;
    return 1;
}

void dfs(int b, int g, int r)
{
    if (b < 0 || b > 320) return ;
    if (g < 0 || g > 320) return ;
    if (r < 0 || r > 320) return ;
    if ( visited[b][g][r] ) return ;
    int i, j;


    if (b >= 2) dfs(b-1, g, r);
    if (g >= 2) dfs(b, g-1, r);
    if (r >= 2) dfs(b, g, r-1);
    if (b>=1 && g>=1) dfs(b-1, g-1, r+1);
    if (g>=1 && r>=1) dfs(b+1, g-1, r-1);
    if (r>=1 && b>=1) dfs(b-1, g+1, r-1);



    visited[b][g][r] = 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    memset(visited, 0, sizeof(visited));
    cin >> n;
    cin >> str;
    b = g = r = 0;
    for (i = 0; i < str.size(); i++)
    {
        if (str[i] == 'B') b++;
        if (str[i] == 'G') g++;
        if (str[i] == 'R') r++;
    }
    dfs( b, g, r );

    if ( visited[1][0][0] ) cout << "B";
    if ( visited[0][1][0] ) cout << "G";
    if ( visited[0][0][1] ) cout << "R";


    return 0;
}
