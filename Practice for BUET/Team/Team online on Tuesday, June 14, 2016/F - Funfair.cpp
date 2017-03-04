#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
double n, k, x0, x, possibleX, bestIdx, bestXSoFar;
struct game
{
    double Ai, Li, Pi, playedFlag;
    game(){}
    game(double Ai, double Li, double Pi, double playedFlag)
    {
        this->Ai = Ai;
        this->Li = Li;
        this->Pi = Pi;
        this->playedFlag = playedFlag;
    }
};
game gameArray[SIZE];
long long a, b, c, d, e;
int main()
{
    freopen("input.txt", "r", stdin);
    while(1)
    {
        cin >> n >> k >> x0;
        if (n+k+x0==0) break;
        for (a = 1; a <= n; a++)
        {
            scanf("%lf %lf %lf", &gameArray[a].Ai, &gameArray[a].Li, &gameArray[a].Pi);
            gameArray[a].playedFlag = 0;
        }
        x = x0;
        for (a = 1; a <= k; a++)
        {
            bestXSoFar = INT_MIN;
            for (b = 1; b <= n; b++)
            {
               if ( !gameArray[b].playedFlag )
               {
                   possibleX = x + (gameArray[b].Ai * gameArray[b].Pi/100)
                                - ((100-gameArray[b].Pi)/100) * (x*gameArray[b].Li/100);
                    if ( possibleX > bestXSoFar )
                    {
                        bestIdx = b;
                        bestXSoFar = possibleX;
                    }
               }
            }
            x = bestXSoFar;
            gameArray[(int)bestIdx].playedFlag = 1;
        }
        printf("%0.2lf\n", x);
    }
    return 0;
}
