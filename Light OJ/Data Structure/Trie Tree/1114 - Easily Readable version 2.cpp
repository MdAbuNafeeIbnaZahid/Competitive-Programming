#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define SIZE 10009
long long T, n, m, ans, len;
long long a, b, c, d, e, f, g;
char line[SIZE], s[SIZE], sCopy[SIZE];
struct myString
{
    char str[109];
    myString(){}
    myString(char *str)
    {
        strcpy(this->str, str);
    }
    const bool operator<(myString b) const
    {
        return strcmp( this->str, b.str ) < 0;
    }
};
map<myString, long long> myMap;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        myMap = map<myString, long long>();
        ans = 1;
        cin >> n;
        //cout << "n = " << n << endl;
        getchar();
        for (b = 1; b <= n; b++)
        {
            gets(s);
            //cout << "s = " << s << endl;
            len = strlen(s);
            if ( len > 2 ) sort(s+1, s+len-1);
            myMap[ myString(s) ]++;
        }
        cin >> m;
        //cout << "m = " << m << endl;
        getchar();
        printf("Case %lld:\n", a);
        for (b = 1; b <= m; b++)
        {
            ans = 1;
            gets(line);
            //cout << "line = " << line << endl;
            char *pch;
            pch = strtok(line, " ");
            while(pch != NULL)
            {
                //cout << "pch = " << pch << endl;
                strcpy(sCopy, pch);
                len = strlen(sCopy);
                if ( len>2 ) sort(sCopy+1, sCopy+len-1);
                ans *= myMap[ myString(sCopy) ];
                pch = strtok(NULL, " ");
            }
            printf("%lld\n", ans);
        }
    }
    return 0;
}

