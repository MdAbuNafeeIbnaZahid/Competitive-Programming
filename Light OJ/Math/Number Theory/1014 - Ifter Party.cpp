#include <bits/stdc++.h>
using namespace std;
long long T, P, L, i, j, k;
set<long long> s;
set<long long>::iterator it;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        s = set<long long>();
        cin >> P >> L;
        for (j = 1; j <= sqrt(P-L+1); j++ )
        {
            if ( (P-L) %j==0)
            {
                if (j > L)
                {
                    //cout << "inserting j = " << j << endl;
                    s.insert(j);
                }

                if ( (P-L) /j > L ) s.insert( (P-L) /j);
            }
        }
        cout << "Case " << i << ": ";
        if (s.size()<=0) cout << "impossible ";
        else for (it=s.begin(); it!=s.end(); it++)
        {
            cout << *it;
            if ( !(it== --s.end() ) ) cout << " ";
        }
        cout << endl;
    }
    return 0;
}
