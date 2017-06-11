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
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
#define SIZE 300009
char fStr[SIZE], lStr[SIZE];
long long len;
deque<char> fd, ld;
vector<char> fvc, lvc;
int main()
{
//    freopen("input.txt", "r", stdin);



    long long a, b, c, d, e, f;
    scanf("%s", fStr+1);
    scanf("%s", lStr+1);
    len = strlen( fStr+1 );

    sort(fStr+1, fStr+len+1);
    sort(lStr+1, lStr+1+len);

//    cout << "fd " << endl;
    for (a = 1; a <= (len+1)/2; a++)
    {
//        cout << fStr[a];
        fd.push_back( fStr[a] );
//        ld.push_back( lStr[a] );
    }
//    cout << endl << "ld" << endl;;
    for (a = len - len/2 + 1; a <= len; a++)
    {
//        cout << lStr[a] ;
        ld.push_back( lStr[a] );
    }
//    cout << endl;

//    cout << fd.front() << endl;




    while( fvc.size() + lvc.size() < len-1 )
    {
        char ch;
        long long done = fvc.size() + lvc.size();
        if ( done & 1 ) // even turn
        {
            if ( ld.back() > fd.front() )
            {
                ch = ld.back();
                fvc.push_back( ch );
                ld.pop_back();
            }
            else
            {
                ch = ld.front();
                lvc.push_back( ch );
                ld.pop_front();
            }
        }
        else // odd turn
        {
            if ( fd.front() < ld.back() )
            {
                ch = fd.front();
                fvc.push_back( ch );
                fd.pop_front();
            }
            else
            {
                ch = fd.back();
                lvc.push_back( ch );
                fd.pop_back();
            }
        }
    }




    if ( fd.size() )
    {
        char ch = fd.front();
        fvc.push_back( ch );
        fd.pop_front();
    }
    if ( ld.size() )
    {
        char ch = ld.front();
        fvc.push_back( ch );
    }



    for ( a= 0; a < fvc.size(); a++)
    {
        printf("%c", fvc[a]);
    }


    if ( lvc.size() )
    {
        for (a = lvc.size()-1; a >= 0; a--)
        {
            printf("%c", lvc[a]);
        }
    }





    return 0;
}

