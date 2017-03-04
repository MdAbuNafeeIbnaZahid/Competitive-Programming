#include <bits/stdc++.h>
using namespace std;
int pointPlace, i, j, k, up, down, no, amb, cas = 0;
string in;

void myCount(string s, int from)
{
    int i, j, k;
    if ( s[from] > '5' )
    {
        up++;
    }
    else if ( s[from] == '5' )
    {
        for (j = from+1; j < s.size(); j++)
        {
            if ( s[j]!= '0') break;
        }
        if (j >= s.size())
        {
            amb++;
        }
        else up++;
    }
    else if ( s[from] < '5' && s[from] > '0' )
    {
        down++;
    }
    else if ( s[from]=='0' )
    {
        for (j = from+1; j < s.size(); j++)
        {
            if ( s[j]!='0' ) break;
        }
        if ( j >= s.size() )
        {
            no++;
        }
        else down++;
    }

}

int main()
{
    //freopen("input.txt", "r", stdin);
    while(1)
    {
        cas++;
        cin >> in;
        if (in == "#") return 0;
        pointPlace = -1;
        up = down = no = amb = 0;
        for (pointPlace = 0; pointPlace < in.size(); pointPlace++)
        {
            if (in[pointPlace] == '.') break;
        }
        if (pointPlace < in.size())
        {
            for (i = pointPlace+1; i < in.size(); i++)
            {
                myCount(in, i);
            }
        }
        else
        {

        }
        cout << "Case " << cas << ":" << endl;
        cout << "ROUND UP: " << up << endl;
        cout << "ROUND DOWN: " << down << endl;
        cout << "NO CHANGE: " << no << endl;
        cout << "AMBIGUOUS: " << amb << endl;
        cout << endl;
    }
    return 0;
}
