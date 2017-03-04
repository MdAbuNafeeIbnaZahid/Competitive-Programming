#include <bits/stdc++.h>
using namespace std;
long long tot, cons, reform, ind, need;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        scanf("%lld %lld %lld", &tot, &cons, &reform);
        if ( tot+cons+reform == 0 ) break;
        ind = tot - cons - reform;
        need = (tot/2)+1-cons;
        if ( need <= 0 ) printf("0\n");
        else if ( need > ind ) printf("-1\n");
        else printf("%lld\n", need);
    }
    return 0;
}
