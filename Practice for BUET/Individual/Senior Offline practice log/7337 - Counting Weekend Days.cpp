#include <bits/stdc++.h>
using namespace std;
long long T, a, b, c, d, e, ans, daysLeft, current;
map<string, long long > myMap;
string month, day;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> T;

    myMap["SUN"] = 0;
    myMap["MON"] = 1;
    myMap["TUE"] = 2;
    myMap["WED"] = 3;
    myMap["THU"] = 4;
    myMap["FRI"] = 5;
    myMap["SAT"] = 6;

    myMap["JAN"] = 31;
    myMap["FEB"] = 28;
    myMap["MAR"] = 31;
    myMap["APR"] = 30;
    myMap["MAY"] = 31;
    myMap["JUN"] = 30;
    myMap["JUL"] = 31;
    myMap["AUG"] = 31;
    myMap["SEP"] = 30;
    myMap["OCT"] = 31;
    myMap["NOV"] = 30;
    myMap["DEC"] = 31;

    for (a = 1; a <= T; a++)
    {
        ans = 0;
        cin >> month >> day;
        if ( day == "FRI" || day == "SAT" ) ans++;
        current = myMap[day];
        for (b = 2; b <= myMap[month]; b++ )
        {
            current = (current+1)%7;
            if ( current == myMap["FRI"] || current == myMap["SAT"] ) ans++;
        }
        cout << ans << endl;
    }

    return 0;
}
