#include <bits/stdc++.h>
using namespace std;
#define len 1000000000
long long T, X, Y, i, j, k, diff, current, ans;
string S;
string days[] = {"SATURDAY", "SUNDAY", "MONDAY", "TUESDAY", "WEDNESDAY", "THURSDAY", "FRIDAY"};
int main()
{
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        cin >> X >> Y >> S;
        diff = (X-Y)*len;
        for (j = 0; j < 7; j++)
        {
            if ( days[j]==S ) current = j;
        }
        if (diff >= 0)
        {
            diff = ((diff%7)+7)%7;
            ans = (current + diff)%7;
        }
        else
        {
            diff = ((diff%7)+7)%7;
            ans = (current + diff)%7;
        }
        cout << "Case " << i << ": " << days[ans] << endl;
    }
    return 0;
}
