#include <bits/stdc++.h>
using namespace std;
#define SIZE
string str;
long long n;
long long a, b, c, d, e, f, si = -1, ei = -1, len;
vector<long long> ansVec;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> str;

    for (a = 0; a < n; a++)
    {
        if ( str[a] == 'B' )
        {
            len++;
        }
        else if ( str[a] == 'W' )
        {
            if (len > 0)
            {
                ansVec.push_back(len);
            }
            len = 0;
        }
    }
    if (len > 0)
    {
        ansVec.push_back(len);
    }
    cout << ansVec.size() << endl;
    for (a = 0; a < ansVec.size(); a++)
    {
        cout << ansVec[a] << " ";
    }
    return 0;
}
