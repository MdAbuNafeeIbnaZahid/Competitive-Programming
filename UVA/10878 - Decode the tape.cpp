#include <bits/stdc++.h>
using namespace std;
#define SIZE 999
string str;
long long cnt[SIZE], len;
char ch;
long long a,b, c, d, tot;
int main()
{
    freopen("input.txt", "r", stdin);
    //cin >> str;
    getline(cin, str);
    len = str.size();
    for (a = 0; a < len; a++)
    {
        cnt[ str[a] ]++;
    }
    for (ch = 'a'; ch <= 'z'; ch++)
    {
        cout << ch << " " << cnt[ch]+cnt[ch-'a'+'A'] << endl;
        tot += (cnt[ch]+cnt[ch-'a'+'A']);
    }
    cout << "tot = " << tot << endl;
    cout << "len = " << len << endl;
    return 0;
}
