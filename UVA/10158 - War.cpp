#include <bits/stdc++.h>
using namespace std;
int n, c, x, y,  fr[10009], en[10009], i, j, k;
char line[1009];
set<int> enSet[10009];

int getFriend(int a)
{
    if ( fr[a]==a ) return a;
    fr[a] = getFriend( fr[a] );
    return fr[a];
}

/*
int getEnemy(int a)
{
    en[a] = en[ getFriend(a) ];
    return en[a];
}
*/

int setFriends(int a, int b)
{
    getFriend(a);
    getFriend(b);
    getEnemy(a);
    getEnemy(b);
    if ( en[a]==fr[b] || en[b]==fr[a] ) return 0;
    fr[ getFriend(a) ] = getFriend(b);
    return 1;
}

int setEnemies(int a, int b)
{
    getFriend( a );
    getFriend( b );
    if ( fr[a] == fr[b] ) return 0;
    en[ a ] = en[ getFriend(a) ] = getFriend(b);
    return 0;
}

int areFriends(int a, int b)
{
    return (getFriend(a) == getFriend(b) );
}

int areEnemies(int a, int b)
{
    return (getEnemy(a) == getFriend(b));
}

int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        fr[i] = i;
        en[i] = -1;
    }
    while( 1 )
    {
        //if ( strcmp(line, "") == 0 || feof(stdin) ) break;
        //sscanf(line, "%d %d %d", &c, &x, &y);
        cin >> c >> x >> y;
        if (c+x+y==0) return 0;
        if (c == 1)
        {
            if ( !setFriends(x, y) ) cout << -1 << endl;
        }
        else if (c == 2)
        {
            if ( !setEnemies(x, y) ) cout << -1 << endl;
        }
        else if (c == 3)
        {
            if ( areFriends(x, y) ) cout << 1 << endl;
            else cout << 0 << endl;
        }
        else if (c == 4)
        {
            if (areEnemies(x, y)) cout << 1 << endl;
            else cout << 0 << endl;
        }
    }
    return 0;
}
