#include <bits/stdc++.h>
using namespace std;
#define SIZE
int n, c, x, y, i, p[70000];
int getEn(int a)
{
    if (a < 20000) return a+20000;
    return a-20000;
}
int getHead(int a)
{
    if ( p[a]==a ) return a;
    p[a] = getHead( p[a] );
    return p[a];
}
void makeUnion(int a, int b)
{
    p[ getHead(a) ] = getHead(b);
}
int areFriends(int a, int b)
{
    if (getHead(a) == getHead(b)) return 1;
    return 0;
}
int areEnemies(int a, int b)
{
    if ( getHead(a)==getHead(getEn(b)) ) return 1;
    if ( getHead(b)==getHead(getEn(a)) ) return 1;
    return 0;
}
int setFriends(int a, int b)
{
    if ( areEnemies(a, b) ) return 0;
    makeUnion(a, b);
    makeUnion(getEn(a), getEn(b));
    return 1;
}
int setEnemies(int a, int b)
{
    if ( areFriends(a, b) ) return 0;
    makeUnion(a, getEn(b));
    makeUnion(b, getEn(a));
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for (i = 0; i < 60000; i++)
    {
        p[i] = i;
    }
    cin >> n;
    while(1)
    {
        cin >> c >> x >> y;
        if (c+x+y==0)return 0;
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
}
