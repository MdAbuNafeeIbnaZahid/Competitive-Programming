#include <bits/stdc++.h>
using namespace std;
#define SIZE 100009
long long n, aAr[SIZE];
long long a, b, c, d, e, f, g, h, mySum, calAr[9], idx;
set<long long> setL;
set<long long>::iterator setLLit;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 0; a < n; a++)
    {
        scanf("%lld", &aAr[a]);
        setL.insert( aAr[a] );
        mySum += aAr[a];
    }
    if (  setL.size() == 1 || setL.size() == 2 )
    {
        cout << "YES";
        return 0;
    }
    else if ( setL.size() == 3   )
    {
        for (setLLit = setL.begin(); setLLit != setL.end(); setLLit++)
        {
            calAr[idx] = *setLLit;
            idx++;
        }
        if ( calAr[1]-calAr[0] == calAr[2]-calAr[1] )
        {
            cout << "YES";
            return 0;
        }
        else
        {
            cout << "NO";
            return 0;
        }
    }
    else
    {
        cout << "NO";
        return 0;
    }
    cout << "NO";
        return 0;
    return 0;
}
