
/******** Nafee's common starting *******/
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
#define SIZE 109
#define eps (1e-9)
long long n,k, x0, Ai, Li, Pi;
long long a, b, c, d, e, f, g;
double ans, dpAr[SIZE][SIZE], prevMoney, ifWin, ifLose;
struct game
{
    double moneyGain, newMoneyIfLoss, probWin, probLoss;
    game(){}
    game( double Ai, double Li, double Pi )
    {
        moneyGain = Ai;
        newMoneyIfLoss = (100 - Li)/100;
        probWin = Pi/100;
        probLoss = (100 - Pi)/100;
    }
};
bool cmpGame(const game A, const game B)
{
    double AB, BA;
    //01 + 10
    AB = (1-A.probWin) * B.probWin * B.moneyGain
        + A.probWin * (1-B.probWin) * A.moneyGain * B.newMoneyIfLoss;
    BA = (1-B.probWin) * A.probWin * A.moneyGain
        + B.probWin * (1-A.probWin) * B.moneyGain * A.newMoneyIfLoss;
    return AB > BA;
}
vector<game> vecGame;
int main()
{
    //freopen("input.txt", "r", stdin);
    //memset(dpAr, -1, sizeof(dpAr) );

//    cout << "while loop start" << endl;
    while(1)
    {
        cin >> n >> k >> x0;
//        cout << "n = " << n << ", k = " << k << ", x0 = " << x0 << endl;
        if ( n+k+x0 == 0 )
        {
            return 0;
        }
        vecGame = vector<game>();
        //memset(dpAr, -1, sizeof(dpAr) );
        for (a = 0; a < SIZE; a++)
        {
            for (b = 0; b < SIZE; b++)
            {
                dpAr[a][b] = 0;
            }
        }
        for (a = 1; a <= n; a++)
        {
            scanf("%lld %lld %lld", &Ai, &Li, &Pi);
            vecGame.push_back( game(Ai, Li, Pi) );
        }
        sort(vecGame.begin(), vecGame.end(), cmpGame);
//        for (a =0; a < n; a++)
//        {
//            cout << "a = " << a << endl;
//            cout << vecGame[a].moneyGain << " " << vecGame[a].newMoneyIfLoss << " "
//                << vecGame[a].probWin << " " << vecGame[a].probLoss << endl;
//        }
        //dpAr[0][0] = x0;
        for (a = 0; a <= n; a++)
        {
            dpAr[0][a] = x0;
        }
        for (a = 1; a <= k; a++)
        {
//            prevMoney = dpAr[a-1][a-1];
//            ifWin = prevMoney + vecGame[a-1].moneyGain;
//            ifLose = prevMoney * vecGame[a-1].newMoneyIfLoss;
//            dpAr[a][a] = ifWin * vecGame[a-1].probWin + ifLose * vecGame[a-1].probLoss;
            for (b = a; b <= n; b++)
            {
                prevMoney = dpAr[a-1][b-1];
                ifWin = prevMoney + vecGame[b-1].moneyGain;
                ifLose = prevMoney * vecGame[b-1].newMoneyIfLoss;
                dpAr[a][b] = max(dpAr[a][b-1], ifWin * vecGame[b-1].probWin + ifLose * vecGame[b-1].probLoss);
            }
        }
//        for (a = 1; a <= k; a++)
//        {
//            for (b = 1; b <= n; b++)
//            {
//                cout << dpAr[a][b] << " ";
//            }
//            cout << endl;
//        }
        //cout << dpAr[k][n] << endl;
        printf("%0.2lf\n", dpAr[k][n]);
    }
    return 0;
}
