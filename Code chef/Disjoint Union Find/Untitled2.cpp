#include <bits/stdc++.h>
using namespace std;
char ar[10][100];
multiset<int> mulSet;
void printIntMulSet(multiset<int> s)
{
    multiset<int>::iterator setIt;
    for (setIt = s.begin(); setIt!=s.end(); setIt++) cout << *setIt << " ";
    cout << endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for (int i = 0; i < 15; i++)
    {
        mulSet.insert(i/2);
    }
    mulSet.erase( mulSet.find(5) );
    printIntMulSet(mulSet);
    return 0;
}
