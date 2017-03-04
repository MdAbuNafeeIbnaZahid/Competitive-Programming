#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
long long n;
long long a,b, c, d, e;
struct cont
{
    string handle;
    long long bef, aft;
};
cont contArray[SIZE];
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> contArray[a].handle;
        cin >> contArray[a].bef >> contArray[a].aft;
    }
    for (a = 1; a <= n; a++)
    {
        if ( contArray[a].bef >= 2400 )
        {
            if ( contArray[a].aft > contArray[a].bef )
            {
                cout << "YES";
                return 0;
            }
        }
    }
    cout << "NO";
    return 0;
}
