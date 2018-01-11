#include <bits/stdc++.h>
using namespace std;

int ar[99][99];

int main()
{

    int &i = ar[5][5];

    i = 9;

    cout << ar[5][5];

    return 0;
}
