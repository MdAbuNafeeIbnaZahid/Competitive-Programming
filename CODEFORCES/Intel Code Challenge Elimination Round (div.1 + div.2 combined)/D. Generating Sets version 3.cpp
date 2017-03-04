#include <bits/stdc++.h>
using namespace std;
long long n, yi;
vector<long long> vLL, cop;
long long a, b, c, d, e, flag, len, target, current, update;
map<long long, long long> occupy;
set<long long> setLL;
set<long long>::iterator setLLIt;
main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &yi);
        //vLL.push_back(yi);
        setLL.insert(yi);
        occupy[yi] = 1;
    }
    //sort(vLL.begin(), vLL.end());
    while(1)
    {
        update = 0;
        setLLIt = setLL.end();
        setLLIt--;
        current = *setLLIt;
        target = current/2;
        while( target > 0 && occupy[target] == 1 )
        {
            target /= 2;
        }
        if ( target > 0 )
        {
            occupy[target] = 1;
            occupy[current] = 0;
            setLL.insert(target);
            setLLIt = setLL.find(current);
            setLL.erase( setLLIt );
        }
        else
        {
            break;
        }
    }
    for (setLLIt = setLL.begin(); setLLIt != setLL.end(); setLLIt++)
    {
        printf("%lld ", *setLLIt);
    }
    return 0;
}
