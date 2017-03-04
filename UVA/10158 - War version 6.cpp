#include <bits/stdc++.h>
using namespace std;
int n, fr[10009], en[10009], i, j, k, c, x, y;
int getIdentity(int a)
{
    if (a==-1) return -1;
    if ( fr[a] == a) return a;
    fr[a] = getIdentity( fr[a] );
    return fr[a];
}

int makeUnion(int a, int b)
{
    if (a==-1 || b==-1) return 0;
    fr[ getIdentity(a) ] = getIdentity(b);
    return 1;
}

int areFriends(int a, int b)
{
    return getIdentity(a)==getIdentity(b);
}

int areEnemies(int a, int b)
{
    return getIdentity(en[getIdentity(a)])==getIdentity(b);
}

int setFriends(int a, int b)
{
    if ( areEnemies(a, b) ) return 0;
    makeUnion( getIdentity(en[getIdentity(a)]), getIdentity(en[getIdentity(b)]) );
    makeUnion(a, b);
    en[getIdentity(b)] = getIdentity(en[getIdentity(b)]);
    en[en[getIdentity(b)]] = getIdentity(b);
    return 1;
}

int setEnemies(int a, int b)
{
    if ( areFriends(a, b) ) return 0;
    makeUnion( getIdentity(a), getIdentity(en[getIdentity(b)]) );
    makeUnion( getIdentity(b), getIdentity(en[getIdentity(a)]) );
    en[getIdentity(a)] = getIdentity(b);
    en[getIdentity(b)] = getIdentity(a);
    return 1;
}

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (i = 0; i < n; i++)
    {
        fr[i] = i;
        en[i] = -1;
    }
    while(1)
    {
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
