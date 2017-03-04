#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, aAr[SIZE], workAr[SIZE];
long long a, b, c, d, e, f, g;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &aAr[a]);
        workAr[a] = aAr[a];
    }
    for (a = 1; a < n; a++)
    {
        if ( workAr[a]%2 )
        {
            workAr[a]--;
            workAr[a+1]--;
        }
    }
    for (a = 1; a <= n; a++)
    {
        //cout << "a = " << workAr[a] << endl;
        if ( workAr[a]<0 || workAr[a]%2 )
        {
            cout << "NO";
            return 0;
        }
    }
    cout << "YES";
    return 0;
    return 0;
}
