#include <bits/stdc++.h>
using namespace std;
long long n, yi;
vector<long long> vecLL;
long long a, b, c, d, e, f, flag, target;
struct ele
{
    long long val;
    ele(){}
    ele(long long val)
    {
        this->val = val;
    }
    const bool operator < (ele B) const
    {
        return val > B.val;
    }
};
set<ele> s1, s2;
set<ele>::iterator setEleIt, setEleIt2;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &yi);
        s1.insert( ele(yi) );
    }
    while(1)
    {
        flag = 0;
        s2 = set<ele>(s1.begin(), s1.end());
        for ( setEleIt = s2.begin(); setEleIt != s2.end(); setEleIt++ )
        {
            target = (setEleIt->val)/2;
            if ( target == 0 ) continue;
            setEleIt2 = s1.find( ele(target) );
            if ( setEleIt2 == s1.end() )
            {
                setEleIt2 = s1.find(setEleIt->val);
                s1.erase( setEleIt2 );
                s1.insert( ele(target) );
                flag = 1;
            }
            else
            {

            }
        }
        for ( setEleIt = s2.begin(); setEleIt != s2.end(); setEleIt++ )
        {
            cout << setEleIt2->val << " ";
        }
        cout << endl;
        if ( flag == 0) break;
    }
    for (setEleIt = s1.begin(); setEleIt != s1.end(); setEleIt++)
    {
        printf("%lld ", *setEleIt);
    }
    return 0;
}
