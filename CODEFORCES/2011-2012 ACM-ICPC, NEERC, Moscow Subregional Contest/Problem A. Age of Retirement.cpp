#include <bits/stdc++.h>
using namespace std;

int monthsNotLeap[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int monthsLeap[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int M, N, K;
int day, month, year;
int i, j, x, z, a, b, c, p, q;
int ifLeapYear(int y)
{
    if (y%400 == 0) return 1;
    if (y%100 == 0) return 0;
    if (y%4 == 0) return 1;
    return 0;
}

struct date
{
    int d, m, y;
    date(){}
    date(int d, int m, int y)
    {
        this->d = d;
        this->m = m;
        this->y = y;
    }
    int operator>(const date &b) const
    {
        if ( y > b.y ) return 1;
        if ( y == b.y && m > b.m) return 1;
        if ( y == b.y && m == b.m && d > b.d ) return 1;
        return 0;
    }
};

date addMonth( date myDate, int addee )
{
    date ret;
    ret.m = myDate.m + addee;
    ret.y = myDate.y + ceil( (double)ret.m / 12) - 1;
    ret.m %= 12;
    if (ret.m == 0) ret.m = 12;
    ret.d = myDate.d;

    if ( ifLeapYear(ret.y) && ret.d > monthsLeap[ret.m] )
    {
        ret.m++;
        ret.d = 1;
    }

    else if ( !ifLeapYear(ret.y) && ret.d > monthsNotLeap[ret.m] )
    {
        ret.m++;
        ret.d = 1;
    }
    return ret;
}

date effect[75], retire[75];

int main()
{
    cin >> M >> N >> K;
    scanf("%d.%d.%d", &day, &month, &year);
    for (i = 1; i <= K; i++)
    {
        effect[i] = addMonth( date(1, 1, 2012), (i-1)*N );
    }
    for (i = 0; i <= K; i++)
    {
        retire[i] = addMonth( date(day, month, year), 720+i*M );
    }
    for (i = 1; i <= K; i++)
    {
        if ( effect[i] > retire[i-1] ) break;
    }

    if (retire[i-1].d <= 9) cout << 0;
    cout << retire[i-1].d << ".";

    if (retire[i-1].m <= 9) cout << 0;
    cout << retire[i-1].m << ".";

    cout << retire[i-1].y ;
    return 0;
}
