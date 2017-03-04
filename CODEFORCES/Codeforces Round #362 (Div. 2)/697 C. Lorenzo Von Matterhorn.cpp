#include <bits/stdc++.h>
using namespace std;
struct edge
{
    long long u, v;
    edge(){}
    edge(long long u, long long v)
    {
        this->u = u;
        this->v = v;
    }
    bool const operator < (edge b) const
    {
        if ( u == b.u )
        {
            return v < b.v;
        }
        return u < b.u;
    }
};
map<edge, long long> myMap;
stack<long long> stak1, stak2;
long long q, u, v, w;
long long a, b, c, d, e, f, g, order, current, ans;
stack<long long> getStack(long long u)
{
    stack<long long> ret;
    long long a, b, c, d, e, f, g;
    while(u>0)
    {
        ret.push(u);
        u/=2;
    }
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> q;
    for (a = 1; a <= q; a++)
    {
        scanf("%lld", &order);
        if ( order == 1 )
        {
            scanf("%lld %lld %lld", &v, &u, &w);
            stak1 = getStack(v);
            stak2 = getStack(u);
            while( stak1.size() && stak2.size() && stak1.top()==stak2.top() )
            {
                stak1.pop();
                stak2.pop();
            }
            while(stak1.size())
            {
                current = stak1.top();
                stak1.pop();
                myMap[ edge(current, current/2) ] += w;
            }
            while( stak2.size() )
            {
                current = stak2.top();
                stak2.pop();
                myMap[ edge(current, current/2) ] += w;
            }
        }
        else if ( order == 2 )
        {
            ans = 0;
            scanf("%lld %lld", &v, &u);
            stak1 = getStack(v);
            stak2 = getStack(u);
            while( stak1.size() && stak2.size() && stak1.top()==stak2.top() )
            {
                stak1.pop();
                stak2.pop();
            }
            while(stak1.size())
            {
                current = stak1.top();
                stak1.pop();
                //myMap[ edge(current, current/2) ] += w;
                ans += myMap[ edge(current, current/2) ];
            }
            while( stak2.size() )
            {
                current = stak2.top();
                stak2.pop();
                ans += myMap[ edge(current, current/2) ];;
            }
            cout << ans << endl;
        }
    }
    return 0;
}
