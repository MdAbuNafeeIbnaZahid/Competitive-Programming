#include <bits/stdc++.h>
using namespace std;
#define  ll  long long int
#define max3(a, b, c) max(a, b) > max(b, c) ? max(a, b) : max(b, c)
#define min3(a, b, c) min(a, b) < min(b, c) ? min(a, b) : min(b, c)
#define digit(c) (c - '0')
#define cc(c) (c - 'a')
#define pb push_back
#define mp make_pair
#define fi first+
#define se second
#define maxx 10000000000000000
#define all(X) X.begin(), X.end()
#define loop(i,n) for ( i=0; i<int(n); i++ )
#define fr(i,x,y) for ( i=x; i<=y; i++ )
#define fur(i,x,y) for ( i=x; i>=y; i-- )
#define out(x) printf("%I64d ",x);

#define in(x) scanf("%I64d",&x);
#define in2(x,y) scanf("%I64d%I64d",&x,&y);


#define REP1(i,a,b) for ( int i=(a); i<=int(b); i++ )
#define FOR(it,c) for ( auto it=(c).begin(); it!=(c).end(); it++ )
#define mp make_pair
#define ex  exit(0)
#define LSOne(S) (S & (-S))
#define INF INT_MAX //Infinity
#define cont continue
#define nl cout<<endl
#define modd 1000000007
ll dp[5000002];
ll a[5000002];
ll ans[5000002];

ll ck(ll i)
{
    return i*(i-1)/2;
}

int main()
{
    ll i,j,k,r,l,v1,v2,t,x,y,n,m,cost;
    cin>>t>>l>>r;

    for(i=1;i<=5000001;i++)
    {
        a[i]=i;
    }

    for(i=2;i<=5000001;i++)
    {
       if(a[i]!=i)
        cont;
        //x=a[i];
       for(j=1;i*j<=5000001;j++)
       {
           y=i*j;
           a[y]=a[y]/x;   // This x is not initialized. So x has garbage
           if(ans[y]==0)
            ans[y]=i;
       }
    }
    ans[1]=1;
    //cout<<"yo";

    //cout<<ans[4]<<" "<<ans[12]<<" "<<ans[35]<<" "<<ans[101];


    dp[1]=0;
    dp[2]=1;
    for(i=3;i<=5000001;i++)
    {
        //x divlen
        // y div no

        x=ans[i];
        y=i/x;
        if(x==i)
        {
            m=ck(i);
            dp[i]=m;
        }
        else
        {
            dp[i]=y*dp[x]+dp[y];
        }

    }

    //cout<<dp[1]<<" "<<dp[3]<<" "<<dp[12]<<" "<<dp[6]<<endl;


    ll p=1;
    ll sum=0;

    for(i=l;i<=r;i++)
    {
        ll temp=(p*dp[i])%modd;
        sum=(sum+temp)%modd;
        p=(p*t)%modd;
    }

    cout<<sum;
}
