#include <bits/stdc++.h>
using namespace std;
char buf[300], c1, c2, c3, p[300], ci, cj;
int N, M, i, j, k, newWakeCount, ans;
vector<char> gr[300], newWakeVector;
set<char> sleepSet, wakeSet;
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
    int i, awakeNeighbor = 0;
    for (i = 0; i < gr[(int)ch].size(); i++)
    {
        if ( getParent(gr[(int)ch][i])==getParent(c1) )
        {
            awakeNeighbor++;
        }
    }
    if (awakeNeighbor >= 3) return 1;
    return 0;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    while( scanf(" %d %d ", &N, &M) != EOF )
    {
        ans = 0;
        newWakeVector = vector<char>();
        sleepSet = set<char>();
        wakeSet = set<char>();
        for (i = 0; i < 300; i++) gr[i] = vector<char>();
        for (i = 0; i < 300; i++) p[i] = (char)i;
        cin >> c1 >> c2 >> c3;
        wakeSet.insert(c1);
        wakeSet.insert(c2);
        wakeSet.insert(c3);
        for (i = 1; i <= M; i++)
        {
            cin >> ci >> cj;
            gr[(int)ci].push_back(cj);
            gr[(int)cj].push_back(ci);
            sleepSet.insert(ci);
            sleepSet.insert(cj);
        }
        sleepSet.erase(c1);
        sleepSet.erase(c2);
        sleepSet.erase(c3);
        makeUnion(c1, c2);
        makeUnion(c1, c3);
        for (ans = 0; wakeSet.size()!=N; ans++)
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
                break;
            }
            for (i = 0; i < newWakeVector.size(); i++)
            {
                sleepSet.erase( newWakeVector[i] );
                wakeSet.insert( newWakeVector[i] );
                makeUnion(c1, newWakeVector[i]);
            }
        }
        if (wakeSet.size()==N) cout << "WAKE UP IN, " << ans << ", YEARS" << endl;
        else cout << "THIS BRAIN NEVER WAKES UP" << endl;
    }
    return 0;
}
