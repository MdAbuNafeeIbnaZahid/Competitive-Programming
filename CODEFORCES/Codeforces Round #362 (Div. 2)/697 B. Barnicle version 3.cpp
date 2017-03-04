#include <bits/stdc++.h>
using namespace std;
string str, a = "", d = "", p, q;
long long b, len;
long long i, j, k, m, n;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> str;
    len = str.size();
    for (i = 0; i < len; i++)
    {
        if ( str[i] == '.' ) break;
        a = a+str[i];
    }
    //i++;
    for (i=i+1 ;i<len; i++)
    {
        if ( str[i] == 'e' ) break;
        d = d + str[i];
    }
    for (i = i+1; i < len; i++)
    {
        b = b*10 + (str[i]-'0');
    }
    //cout << "a = " << a << ", d = " << d << ", b = " << b << endl;
    p = a;
    q = d;
//    if ( b==0 )
//    {
//        cout << p << "." << q;
//        return 0;
//    }
    for (i = 1; i <= b; i++)
    {
        if ( q.size() )
        {
            p = p + q[0];
            q.erase( q.begin() );
        }
        else p = p+'0';
    }
    if ( p.size()>1 && p[0]=='0' ) p.erase( p.begin() );
    cout << p;
    //len = q.size();
    if ( q.size() == 1 &&  q[ 0 ]=='0' ) q.erase( q.begin() );
    if ( q.size() )
    {
        cout << "." << q;
    }
    return 0;
}
