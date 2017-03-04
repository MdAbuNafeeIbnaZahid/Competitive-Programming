#include <bits/stdc++.h>
using namespace std;


int main()
{
    int a,b,c,d,e,i,j,k,p,q;
    int x[10020][3];
    int y[2000],z[2000];

    p=1;
    q=1;
    k=3;

    for(i=1;i<=10010;i=i+6)
    {
        y[p]=i;
        p++;
    }

    for(i=3;i<=10010;i=i+6)
    {
        z[q]=i;
        q++;
    }



    e=1;
    c=0;

    for(i=1;i<=41;i++)
    {




        if(i==1)
        {
            x[e][1]=0;
            x[e][2]=0;
            c--;

        }
        else
        {
            x[e][1]=c;
            x[e][2]=0;
            c--;
        }
        k++;
        e++;



        for(j=2;j<=(y[i]+1)/2;j++)
        {  if(j<=i)
             {
            x[e][1]=x[e-1][1]+0;
            x[e][2]=x[e-1][2]+2;
             }
          else

          {
            x[e][1]=x[e-1][1]+1;
            x[e][2]=x[e-1][2]+1;
          }
            e++;
        }

        k=j;

        for(j=k;j<=(y[i]-i+1);j++)
        {
            x[e][1]=x[e-1][1]+1;
            x[e][2]=x[e-1][2]-1;
            e++;
        }
        k=j;

       if(i!=1)
        {  for(j=k;j<=y[i];j++)

            {x[e][1]=x[e-1][1];

        x[e][2]=x[e-1][2]-2;
        e++;
            }

        }

        k=1;

        x[e][1]=c;
        x[e][2]=1;

        c--;

        k++;
        e++;




        for(j=2;j<=(z[i]+1)/2;j++)
        {
            if(j<=i && i!=1)
             {
            x[e][1]=x[e-1][1]+0;
            x[e][2]=x[e-1][2]+2;
             }
          else

          {
            x[e][1]=x[e-1][1]+1;
            x[e][2]=x[e-1][2]+1;
          }
            e++;
        }

        k=j;

     if(i!=1)
        {
            for(j=k;j<=(z[i]-i+1);j++)
        {
            x[e][1]=x[e-1][1]+1;
            x[e][2]=x[e-1][2]-1;
            e++;
        }
        k=j;
        for(j=k;j<=z[i];j++)

            {x[e][1]=x[e-1][1];

        x[e][2]=x[e-1][2]-2;
        e++;
            }


        }
        else
        {
            for(j=k;j<=z[i];j++)
        {
            x[e][1]=x[e-1][1]+1;
            x[e][2]=x[e-1][2]-1;
            e++;
        }
        }



    }




    while(scanf("%d %d",&a,&b)!=EOF)
    {   k=0;
        if(a==0 && b==0)break;
        c=abs(x[a][1]-x[b][1]);
        k=k+c;
        d=abs(x[a][2]-x[b][2]);
        d=d-c;

       if(d>=0)
        k=k+d/2;
        cout<<k<<endl;

    }
    return 0;
}
