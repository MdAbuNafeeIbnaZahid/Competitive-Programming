#include <cstdio>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <string>
#include <map>
#include <list>
#include <queue>
#include <utility>
#include <vector>
#define SIZE 25
#define MOD 20071027
#define BOUNDARY(i, j) ((i >= 0 && i < row) && (j >= 0 && j < column))
using namespace std;
long long int v[300101],y[200102],z[200102];

bool x[4000001];

long long int mulmod(long long int a, long long int b, long long int mod)
{
    long long int x = 0,y = a % mod;
    while (b > 0)
    {
        if (b % 2 == 1)
        {
            x = (x + y) % mod;
        }
        y = (y * 2) % mod;
        b /= 2;
    }
    return x % mod;
}
/*
 * modular exponentiation
 */
long long int modulo(long long int base, long long int exponent, long long int mod)
{
    long long int x = 1;
    long long int y = base;
    while (exponent > 0)
    {
        if (exponent % 2 == 1)
            x = (x * y) % mod;
        y = (y * y) % mod;
        exponent = exponent / 2;
    }
    return x % mod;
}

/*
 * Miller-Rabin primality test, iteration signifies the accuracy
 */
int Miller(long long int p,long long int iteration)
{
    if (p < 2)
    {
        return 0;
    }
    if (p != 2 && p % 2==0)
    {
        return 0;
    }
    long long int s = p - 1;
    while (s % 2 == 0)
    {
        s /= 2;
    }
    for (long long int i = 0; i < iteration; i++)
    {
        long long int a = rand() % (p - 1) + 1, temp = s;
        long long int mod = modulo(a, temp, p);
        while (temp != p - 1 && mod != 1 && mod != p - 1)
        {
            mod = mulmod(mod, mod, p);
            temp *= 2;
        }
        if (mod != p - 1 && temp % 2 == 0)
        {
            return 0;
        }
    }
    return 1;
}


int main()
{    long long int a,b,c,d,i,j,p=0,q,r=1,flg,T,sum=0,fm,m,n,v1,v2,g;

     for(i=2;i<=50000;i++)
     {   if(x[i]==true)
           continue;
         v[p]=i;
         p++;
         for(j=i;j<=50000;j=j+i)
         {
             x[j]=true;
         }

     }


     cin>>T;
     for(i=1;i<=T;i++)
     {
         cin>>a>>b;
         flg=0;
         v1=0;
         v2=0;

         r=1;
         fm=1;
         d=a;
         for(j=0;j<p;j++)
         {   q=0;
             if(v[j]*v[j]*v[j]>d)
                break;

             else if(d%v[j]==0)
             {
                 while(d%v[j]==0)
                 {
                    q++;
                    d=d/v[j];
                 }

             }
             if(q>0)
                {
                    z[v1]=q;
                    v1++;
                }
         }

         g=Miller(d,20);

         if(g==1 && d!=1)
         {
             z[v1]=1;
             v1++;
         }
         else if(g==0 && d!=1)
         {
             g=sqrt(d);
             if(g*g==d)
             {
                 z[v1]=2;
                 v1++;
             }
             else
             {
                 z[v1]=1;
                 v1++;
                 z[v1]=1;
                 v1++;
             }
         }


         d=b;
         if(v1>0)
         {
             fm=z[0];
             n=v1;
             for(j=1;j<n;j++)
             {
                 if(fm!=z[j])
                 {
                     flg=1;
                     break;
                 }
             }
             if(flg==0)
             {
                 d=d*fm;
             }
         }
         for(j=0;j<p;j++)
         {   q=1;
             if(v[j]*v[j]*v[j]>d)
                break;

             else if(d%v[j]==0)
             {
                 while(d%v[j]==0)
                 {
                    q++;
                    d=d/v[j];
                 }

             }
             if(q>1)
                {
                    y[v2]=q;
                    v2++;
                }
         }


         g=Miller(d,20);


         if(g==1 && d!=1)
         {
             y[v2]=2;
             v2++;
         }
         else if(g==0 && d!=1)
         {
             g=sqrt(d);
             if(g*g==d)
             {
                 y[v2]=3;
                 v2++;
             }
             else
             {
                 y[v2]=4;
                 v2++;


             }
         }




         if(v2==0)
         {
             cout<<"Case "<<i<<": "<<b-1<<endl;
             continue;
         }
         m=v2;
         for(j=0;j<m;j++)
         {
             r=r*(y[j]);
         }
         cout<<"Case "<<i<<": "<<r-1<<endl;
     }

     return 0;
}

