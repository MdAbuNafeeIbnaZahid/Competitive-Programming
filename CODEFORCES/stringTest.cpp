#include <bits/stdc++.h>
using namespace std;

string room[10][10];

int main()
{
    char str[10];
    string s;
    char c;

    while(1)
    {
        cin >> s;
        cin >> c;
        cout << count(s.begin(), s.end(), c) << "\n\n\n";
    }



    return 0;
}
