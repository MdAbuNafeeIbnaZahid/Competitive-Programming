#include <bits/stdc++.h>
using namespace std;
map<string,int>m;

int main()
{
    int a,b,c,d,e,i,j,k,p,q;
    string s[701],x1;
    int x[701];
    while(scanf("%d %d",&a,&b)!=EOF)
    {   m.clear();
        if(a==0 && b==0)break;
        memset(x,0,sizeof(x));
        for(i=1;i<=a;i++)
        {
            cin>>x[i]>>s[i];
        }
        p=0;
        e=0;
        for(i=1;i<=a;i++)
        {   p=0;
            q=s[i].length();
            for(j=q;j>=b;j--)
            {   if(p>=x[i])break;
                x1=s[i].substr(0,j);
                if(!m[x1] && p<x[i])
                {
                    e++;
                    p++;
                    m[x1]++;
                }

            }


        }
        cout<<e<<endl;
    }
    return 0;
}
