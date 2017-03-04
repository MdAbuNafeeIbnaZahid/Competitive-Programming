#include <bits/stdc++.h>
using namespace std;
char buf[300], c1, c2, c3, p[300], ci, cj;
int N, M, i, j, k, newWakeCount, ans;
vector<char> gr[300], newWakeVector;
set<char> sleepSet;
set<char>::iterator setIt;
char getParent(char ch)
{
    if (ch == p[(int)ch]) return ch;
    p[(int)ch] = getParent(p[(int)ch]);
    return p[(int)ch];
}
void makeUnion(char ch1, char ch2)
{
    p[(int)getParent(ch1)] = getParent(ch2);
}
int ifWillWake(char ch)
{
    //cout << "ifWillWake is called with ch = " << ch << endl;
    int i, awakeNeighbor = 0;
    for (i = 0; i < gr[(int)ch].size(); i++)
    {
        //cout << "neighbor = " << gr[(int)ch][i] << endl;
        if ( getParent(gr[(int)ch][i])==getParent(c1) )
        {
            //cout << gr[(int)ch][i] << " is awake " << endl;
            awakeNeighbor++;
        }
    }
    //cout << "ch = " << ch <<"; awakeNeighbor = " << awakeNeighbor << endl;
    if (awakeNeighbor >= 3) return 1;
    return 0;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while( scanf(" %d %d ", &N, &M) != EOF )
    {
        //cout << "N = " << N << ", M = " << M << endl;
        ans = 0;
        newWakeVector = vector<char>();
        sleepSet = set<char>();
        for (i = 0; i < 300; i++) gr[i] = vector<char>();
        for (i = 0; i < 300; i++) p[i] = (char)i;
        cin >> c1 >> c2 >> c3;
        //cout << "c1 = " << c1 << ", c2 = " << c2 << ", c3 = " << c3 << endl;
        for (i = 1; i <= M; i++)
        {
            cin >> ci >> cj;
            //cout << ci << " " << cj << endl;
            gr[(int)ci].push_back(cj);
            gr[(int)cj].push_back(ci);
            sleepSet.insert(ci);
            sleepSet.insert(cj);
        }
        sleepSet.erase(c1);
        sleepSet.erase(c2);
        sleepSet.erase(c3);
        //cout << "getParent(" << c1 << ") = " << getParent(c1) << endl;
        //cout << "getParent(" << c2 << ") = " << getParent(c2) << endl;
        //cout << "getParent(" << c3 << ") = " << getParent(c3) << endl << endl;

        makeUnion(c1, c2);
        //cout << "getParent(" << c1 << ") = " << getParent(c1) << endl;
        //cout << "getParent(" << c2 << ") = " << getParent(c2) << endl;
        //cout << "getParent(" << c3 << ") = " << getParent(c3) << endl << endl;

        makeUnion(c1, c3);
        //cout << "getParent(" << c1 << ") = " << getParent(c1) << endl;
        //cout << "getParent(" << c2 << ") = " << getParent(c2) << endl;
        //cout << "getParent(" << c3 << ") = " << getParent(c3) << endl << endl;

        //cout << "sleepSet.size() = " << sleepSet.size() << endl;
        for (ans = 0; !sleepSet.empty(); ans++)
        {
            newWakeVector = vector<char>();
            for (setIt=sleepSet.begin(); setIt!=sleepSet.end(); setIt++)
            {
                if ( ifWillWake(*setIt) )
                {
                    newWakeVector.push_back(*setIt);
                }
            }
            if (newWakeVector.empty())
            {
                //cout << "breaking; ans = " << ans << endl;
                break;
            }
            for (i = 0; i < newWakeVector.size(); i++)
            {
                sleepSet.erase( newWakeVector[i] );
                makeUnion(c1, newWakeVector[i]);
            }
        }
        if (sleepSet.empty()) cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
        else cout << "THIS BRAIN NEVER WAKES UP" << endl;
    }
    return 0;
}
