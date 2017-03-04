#include <bits/stdc++.h>
#define SIZE 9
using namespace std;
long long a, b, r, c, d, e, f, g, len, n, ifYes[SIZE];
string str;
char ch;
long long ifOk(long long r, long long c)
{
    if (r<0 || c < 0 || r >3 || c>2 ) return 0;
    if ( r==3 && c !=1 ) return 0;
    return 1;
}
string strAr[] = {"123", "456", "789", " 0 "};
long long changeR[] = {1, -1, 0, 0};
long long changeC[] = {0, 0, 1, -1};
struct coOrd
{
    long long r, c;
    coOrd(){}
    coOrd(long long r, long long c)
    {
        this->r = r;
        this->c = c;
    }
    const bool operator < (coOrd b) const
    {
        if ( r == b.r ) return c < b.c;
        return r < b.r;
    }
    coOrd operator + (coOrd b) const
    {
        coOrd ret;
        ret.r = r+b.r;
        ret.c = c+b.c;
        return ret;
    }
};
map<char, coOrd> myMap;
//map<coOrd, long long>
int main()
{
    //freopen("input.txt", "r", stdin);
    myMap['1'] = coOrd(1, 1);
    myMap['2'] = coOrd(1, 2);
    myMap['3'] = coOrd(1, 3);

    myMap['4'] = coOrd(2, 1);
    myMap['5'] = coOrd(2, 2);
    myMap['6'] = coOrd(2, 3);

    myMap['7'] = coOrd(3, 1);
    myMap['8'] = coOrd(3, 2);
    myMap['9'] = coOrd(3, 3);

    myMap['0'] = coOrd(4, 2);
    cin >> n;
    cin >> str;
    len = str.size();

    for (a = 0; a < 4; a++)
    {
        for (b = 0; b < len; b++)
        {
            ch = str[b];
            for (r = 0; r <= 3; r++)
            {
                for (c = 0; c <= 2; c++)
                {
                    if ( strAr[r][c] == ch && !ifOk(r+changeR[a], c+changeC[a]) )
                    {
                        ifYes[a] = 1;
                    }
                }
            }
        }
    }
    for (a = 0; a < 4; a++)
    {
        if ( ifYes[a] == 0 )
        {
            //cout << "a = " << a << endl;
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}
