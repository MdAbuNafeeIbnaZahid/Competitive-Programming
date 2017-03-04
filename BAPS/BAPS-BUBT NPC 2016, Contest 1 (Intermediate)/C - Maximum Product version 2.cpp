#include <bits/stdc++.h>
using namespace std;
long long a, b, copA, copB, ifPrinted, len, i, j, k, toPr, alreadyFlipped;
vector<long long> vecA, vecB, ansVec;
stack<long long> stakLL;
int main()
{
    cin >> a >> b;
    copA = a;
    copB = b;
    while(copA || copB)
    {
        vecA.push_back(copA%10);
        copA /= 10;
        vecB.push_back(copB%10);
        copB/=10;
    }
    while(vecA.size() && vecB.size() && vecA[ vecA.size()-1 ] == vecB[ vecB.size()-1 ])
    {
        cout << vecA[ vecA.size()-1 ];
        vecA.pop_back();
        vecB.pop_back();
        ifPrinted = 1;
    }
    cout << "first while complete" << endl;
    cout << "ifPrinted = " << ifPrinted << endl;
    if (ifPrinted)
    {
        len = vecB.size();
        for (i = len-1; i >= 0; i--)
        {
            if (alreadyFlipped)
            {
                //ansVec.push_back(9);
                cout << 9;
            }
            else if ( vecB[i] >= 2 )
            {
                //ansVec.push_back(vecB[i]-1);
                cout << vecB[i]-1;
                alreadyFlipped = 1;
            }
            else
            {
                //ansVec.push_back(vecB[i]);
                cout << vecB[i];
            }
        }
    }
    //cout << "vecB.size() = " << vecB.size()  << endl;
    else if ( !ifPrinted )
    {
        if ( vecB[vecB.size()-1]-1 != 0 )
        {
            cout << vecB[vecB.size()-1]-1;
        }
        cout << "vecB.size() = " << vecB.size()  << endl;
//        for (i = vecB.size()-2; i >= 0; i--)
//        {
//            cout << "i = " << i << endl;
//            cout << 9;
//        }
    }
    return 0;
}
