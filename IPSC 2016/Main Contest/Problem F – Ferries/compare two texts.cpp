#include <bits/stdc++.h>
using namespace std;
char chMy, chVaia;
int main()
{
    ifstream myStream("f1Output.txt");
    ifstream vaiaStream("feasyout.txt");
    while(myStream>>chMy && vaiaStream>>chVaia)
    {
        if ( chMy != chVaia )
        {
            cout << endl;
            cout << "chMy = " << chMy << endl;
            cout << "chVaia = " << chVaia << endl;
            cout << endl;
        }
    }
    return 0;
}
