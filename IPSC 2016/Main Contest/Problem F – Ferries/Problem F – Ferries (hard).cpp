//#include <bits/stdc++.h>
#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long t, n, x, k;
long long a, b, c, d, e, f, current;
long long layer[SIZE], step[SIZE], parent[SIZE], aArray[SIZE], totalSteps;
string ansStr, thisMove;
long long leftStep(long long x)
{
    if ( x <= n )
    {
        return 2*x;
    }
    else
    {
        return 2*(x-n)-1;
    }
}
long long rightStep(long long x)
{
    if ( x <= n ) return 2*x-1;
    else return 2*(x-n);
}
struct position
{
    long long idx, layer, step, parent;
    position(){}
    position(long long idx, long long layer, long long step, long long parent)
    {
        this->idx = idx;
        this->layer = layer;
        this->step = step;
        this->parent = parent;
    }
};
map<long long, position> myMap;
void printMapLLPos(map<long long, position> givenMap)
{
    map<long long, position>::iterator mapLLPosIt;
    for (mapLLPosIt = givenMap.begin(); mapLLPosIt != givenMap.end(); mapLLPosIt++)
    {
        cout << "idx = " << mapLLPosIt->first << endl;
        cout << "layer = " << mapLLPosIt->second.layer << endl;
        cout << "parent = " << mapLLPosIt->second.parent << endl;
        cout << endl;
    }
}
void bfs(long long source, long long dest)
{
    long long a, b, c, d, e , f, current;
    queue<long long> Q;
    myMap = map<long long, position>();
    map<long long, position>::iterator mapLLPosIt;
    //cout << "source = " << source << endl;
    //cout << "dest = " << dest << endl;
    myMap[source] = position(source, 0, NULL, NULL);
    if ( dest == source ) return;
    Q.push(source);
    while( !Q.empty() )
    {
        current = Q.front();
        Q.pop();
        //cout << "current = " << current << endl;
        if ( myMap.find( leftStep(current) ) == myMap.end() )
        {
            myMap[leftStep(current)] = position(leftStep(current), myMap[current].layer+1,
                                                'L', current);
            Q.push(leftStep(current));
        }
        if ( myMap.find( rightStep(current) ) == myMap.end() )
        {
            myMap[rightStep(current)] = position(rightStep(current), myMap[current].layer+1,
                                                'R', current);
            Q.push(rightStep(current));
        }
        if ( myMap.find(dest) != myMap.end() )
        {
            break;
        }
    }
    return;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    freopen("f2.in", "r", stdin);
    //freopen("f2Output.txt", "w", stdout);
    cin >> t;
    cout << "total cases = " << t << endl;
    for (a = 1; a <= t; a++)
    {
        cout << "Case " << a << endl;
        totalSteps = 0;
        ansStr = "";
        cin >> n >> x >> k;
        aArray[0] = x;
        for (b = 1; b <= k; b++)
        {
            scanf("%lld", &aArray[b]);
        }
        for (b = 1; b <= k; b++)
        {
            thisMove = "";
            bfs( aArray[b-1], aArray[b] );
            //printMapLLPos(myMap);
            current = aArray[b];
            while( myMap[current].layer != 0 )
            {
                totalSteps++;
                if ( myMap[current].step == 'L' )
                {
                    thisMove='L'+thisMove;
                }
                else if (myMap[current].step == 'R')
                {
                    thisMove='R'+thisMove;
                }
                current = myMap[current].parent;
            }
            ansStr+=thisMove;
        }
        cout << totalSteps << ":" << ansStr << endl;
    }

    return 0;
}
