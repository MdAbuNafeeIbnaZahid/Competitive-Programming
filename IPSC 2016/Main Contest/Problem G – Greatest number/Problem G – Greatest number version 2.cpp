#include <bits/stdc++.h>
using namespace std;
vector<char>v;


int main()
{
    freopen("g2.in", "r", stdin);
    freopen("g2Output.txt", "w", stdout);
    int a,b,c,d,e,i,j,T;
    char s[1002];
    cin>>T;
    for(i=1;i<=T;i++)
    {
        cout << "i = " << i << endl;
        v.clear();
        e=0;
        scanf("%s",&s);

        a=strlen(s);
        for(j=0;j<a;j++)
        {
            if(j==a-1 && e==0 && s[j]=='0')
            {
                v.push_back(s[j]);
            }
            else if(s[j]>'0' && s[j]<='9' && e==0)
            {   e=1;
                v.push_back(s[j]);
            }
            else if(s[j]>='0' && s[j]<='9' && e==1)
            {   e=1;
                v.push_back(s[j]);
            }
        }

    d=v.size();
    for(j=0;j<d;j++)
    {
        printf("%c",v[j]);
    }
    cout<<endl;
}
return 0;
}


