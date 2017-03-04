#include <bits/stdc++.h>
using namespace std;
long long T, Q, di, si;
char ri;
long long a, b, c,  d, e, f, g;
long long incorrect[19], correct[19], ans;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> Q;
        ans = 0;
        memset(incorrect, 0, sizeof(incorrect));
        memset(correct, 0, sizeof(correct));
        for (b = 1; b <= Q; b++)
        {
            scanf("%lld %lld %c", &di, &si, &ri);
            //cout << "di = " << di << endl;
            //cout << "si = " << si << endl;
            //cout << "ri = " << ri << endl << endl;
            if ( si==1 && ri=='c' )
            {
                correct[di]++;
            }
            else if ( si==0 && ri=='i' )
            {
                incorrect[di]++;
            }
        }
        for (c = 1; c <= 10; c++)
        {
            incorrect[c] += incorrect[c-1];
        }
        for (c = 2; c <= 10; c++)
        {
            ans += (correct[c]*incorrect[c-1]);
        }
        cout << ans << endl;
    }
    return 0;
}
