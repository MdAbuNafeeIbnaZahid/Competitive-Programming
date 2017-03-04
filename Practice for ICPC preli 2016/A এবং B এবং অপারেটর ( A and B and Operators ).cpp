#include <iostream>
using namespace std;

int main()
{

    int t;
    cin>>t;

    int cs  = 1;

    while(t--)
    {
        ll a,b;
        cin>>a>>b;

        char p;
        cin>>p;

        if(p=='+')
        {
            ll ans = a+b;
            cout<<"Case "<<cs++<<": "<<endl;
        }
        else if(p=='-')
        {
            ll ans = a-b;
            cout<<"Case "<<cs++<<": "<<endl;
        }
        else if(p=='*')
        {
            ll ans = a*b;
            cout<<"Case "<<cs++<<": "<<endl;
        }
        else if(p=='/')
        {
            ll ans = a/b;
            cout<<"Case "<<cs++<<": "<<endl;
        }
        else if(p=='%')
        {
            ll ans = a%b;
            cout<<"Case "<<cs++<<": "<<endl;
        }



    }
    return 0;

}
