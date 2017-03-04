#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
struct bp
{
    long long x, y;
    char typ;
    bp(){}
    bp(long long x, long long y, char typ)
    {
        this->x = x;
        this->y = y;
        this->typ = typ;
    }
    bool const operator < (const bp B) const
    {
        if ( x == B.x )
        {
            return y < B.y;
        }
        return x < B.x;
    }
};
typedef tree<
bp,
null_type,
less<bp>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
long long n, xo, yo, xi, yi;
map<long long, ordered_set > hor, ver, jog, biyog;
long long a, b, c, d, e, f, g, pos;
char ch;;
bp matchWith;
int main()
{
//    freopen("input.txt", "r", stdin);
    cin >> n ;
    cin >> xo >> yo;
    for (a = 1; a <= n; a++)
    {
        getchar();
        //cout << "a = " << a << endl;
        scanf("%c %lld %lld", &ch, &xi, &yi);
        //cout << "ch = " << ch << ", xi = " << xi << ", yi = " << yi << endl;
        if (xo == xi)
        {
            hor[xi].insert( bp(xi, yi, ch) );
        }
        if (yo == yi)
        {
            ver[yi].insert( bp(xi, yi, ch) );
        }
        if ( yo+xo == yi+xi )
        {
            jog[yi+xi].insert( bp(xi, yi, ch) );
        }
//        cout << "yi+xi = " << yi+xi << endl;
//        cout << "jog[yi+xi].size() = " << jog[yi+xi].size() << endl;
        if (yo-xo == yi-xi)
        {
            biyog[yi-xi].insert( bp(xi, yi, ch) );
        }
    }

    pos = hor[xo].order_of_key( bp(xo, yo, ch) );
    if ( pos >= 1 )
    {
        matchWith = *hor[xo].find_by_order(pos-1);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'R' )
        {
            cout << "YES";
            return 0;
        }
    }
    if ( pos < hor[xo].size() )
    {
        matchWith = *hor[xo].find_by_order(pos);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'R' )
        {
            cout << "YES";
            return 0;
        }
    }

    pos = ver[yo].order_of_key( bp(xo, yo, ch) );
    if ( pos >= 1 )
    {
        matchWith = *ver[yo].find_by_order(pos-1);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'R' )
        {
            cout << "YES";
            return 0;
        }
    }
    if ( pos < ver[yo].size() )
    {
        matchWith = *ver[yo].find_by_order(pos);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'R' )
        {
            cout << "YES";
            return 0;
        }
    }

//    cout << "jog = " << endl;
    pos = jog[yo+xo].order_of_key( bp(xo, yo, ch) );
//    cout << "pos = " << pos << endl;
    if ( pos >= 1 )
    {
        matchWith = *jog[yo+xo].find_by_order(pos-1);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'B' )
        {
            cout << "YES";
            return 0;
        }
    }
    if ( pos < jog[yo+xo].size() )
    {
        matchWith = *jog[yo+xo].find_by_order(pos);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'B' )
        {
            cout << "YES";
            return 0;
        }
    }



    pos = biyog[yo-xo].order_of_key( bp(xo, yo, ch) );
    if ( pos >= 1 )
    {
        matchWith = *biyog[yo-xo].find_by_order(pos-1);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'B' )
        {
            cout << "YES";
            return 0;
        }
    }
    if ( pos < biyog[yo-xo].size() )
    {
        matchWith = *biyog[yo-xo].find_by_order(pos);
        if ( matchWith.typ == 'Q' || matchWith.typ == 'B' )
        {
            cout << "YES";
            return 0;
        }
    }

    cout << "NO";
    return 0;


    return 0;
}

