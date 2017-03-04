
#include <bits/stdc++.h>

using namespace std;
int i, j, k, previous, next, current, bets=0;
int myMod(int a)
{
    if (a<0) a=-a;
    return a;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    scanf("%d", &previous);
    if (previous==-1) return 0;
    while(1)
    {
        if ( scanf("%d", &current)==EOF  )
        {
            printf("%d\n", min(previous, 200-previous) );
            return 0;
        }
        if (current==-1)
        {
            printf("%d\n", min(previous, 200-previous) );
            return 0;
        }
        if (current==0)
        {
            printf("%d\n", previous);
            return 0;
        }
        printf("%d\n", min(myMod(current-previous), previous ) );
        previous = current;
    }
    return 0;
}
