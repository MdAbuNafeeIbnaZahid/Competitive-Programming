#include <bits/stdc++.h>
using namespace std;

int main()
{
    map<int, int> m1;

    int i, j, k;
    for (i = 6; i >= 0; i--)
    {
        m1[i]++;
    }

    map<int, int>::iterator it;
    for (it = m1.begin(); it != m1.end(); it++)
    {
        cout << it->first << " " << it->second << "\n";
    }

    return 0;
}
