#include <bits/stdc++.h>
using namespace std;
vector<string>v;
int main()
{
    freopen("input.txt", "r", stdin);
    int a,b,c,d,e,i,j,p=-1,q;
    string s[1005];

    while(scanf("%d",&a)!=EOF)
    {   if(a<=0)break;
         v.clear();
        for(i=1;i<=a;i++)
    {
        cin>>s[i];
    }
    for(i=1;i<=a;i++)
    {   p=-1;
        b=s[i].length();
        if(b!=8)continue;
        for(j=0;j<8;j++)
        {
            if(j==1)
            {
                if(s[i][j]!=s[i][j-1])
                {
                    p=0;
                    break;
                }
                else if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p = 0;
                    break;
                }
            }
            else if(j==2)
            {
                if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p=0;
                    break;
                }
            }
            else if(j==3)
            {
                if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p=0;
                    break;
                }
            }
            else if(j==4)
            {
                if(!(s[i][j]>='A' && s[i][j]<='Z'))
                {
                    p=0;
                    break;
                }
            }
            else if(j==5)
            {
                if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p=0;
                    break;
                }
            }
            else if(j==6)
            {
                if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p=0;
                    break;
                }
            }
            else if(j==7)
            {
                if(!(s[i][j]>='1' && s[i][j]<='9'))
                {
                    p=0;
                    break;
                }
            }

        }
        if(p==-1)
        {
            v.push_back(s[i]);
        }
    }
    d=v.size();
    for(i=0;i<d;i++)
    {
        cout<<v[i]<<endl;
    }
    }
    return 0;

}
