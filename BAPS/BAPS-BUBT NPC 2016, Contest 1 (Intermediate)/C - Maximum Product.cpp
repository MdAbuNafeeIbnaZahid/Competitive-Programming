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
    cout << "first while complete" << endl;
    while(vecA.size() && vecB.size() && vecA[ vecA.size()-1 ] == vecB[ vecB.size()-1 ])
    {
        cout << vecA[ vecA.size()-1 ];
        vecA.pop_back();
        vecB.pop_back();
        ifPrinted = 1;
    }
    len = vecB.size();
    for (i = len-1; i >= 0; i--)
    {
        if (alreadyFlipped)
        {
            ansVec.push_back(9);
        }
        else if ( vecB[i] >= 2 )
        {
            ansVec.push_back(vecB[i]-1);
            alreadyFlipped = 1;
        }
        else
        {
            ansVec.push_back(vecB[i]);
        }
//        cout << "i = " << i << endl;
//        cout << "vecB[i] = " << vecB[i] << endl;
//        if ( i == len-1 )
//        {
//            toPr = vecB[i]-1;
//            stakLL.push(vecB[i]-1);
//            ansVec.push_back(vecB[i]-1);
//        }
//        else
//        {
//            toPr = toPr * 10 + 9;
//            stakLL.push(9);
//            ansVec.push_back(9);
//        }
    }
    if ( !ifPrinted )
    {
        while( ansVec[0] == 0 )
        {
            ansVec.erase( ansVec.begin() );
        }
    }
    while(ansVec.size())
    {
        //cout << stakLL.top();
        //stakLL.pop();
        cout << ansVec[0];
        ansVec.erase( ansVec.begin() );
    }
//    while(vecB.size() && (vecB[ vecB.size()-1 ] == 1 || vecB[ vecB.size()-1 ] == 0) )
//    {
//        cout << vecB[ vecB.size()-1 ];
//        vecB.pop_back();
//    }
//    if ( vecB.size()  )
//    {
//        cout << vecB[ vecB.size()-1 ]-1;
//        vecB.pop_back();
//    }
//    while(vecB.size())
//    {
//        cout << 9;
//        vecB.pop_back();
//    }
    return 0;
}
