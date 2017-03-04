#include <bits/stdc++.h>
using namespace std;
#define SIZE 500009
int p[SIZE], total[SIZE], N, M, ans = 0, req[SIZE];
int i, j, k, ingredient, testCases, cnt;
set<int> reqSet;
set<int>::iterator it, it2;
int getParent(int u)
{
    if (p[u]==u) return u;
    p[u] = getParent(p[u]);
    return p[u];
}
void makeUnion(int u, int v)
{
    if (getParent(u)==getParent(v)) return;
    total[getParent(v)]+=total[getParent(u)];
    p[getParent(u)] = getParent(v);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //testCases = 2;
    while(scanf("%d", &N)!=EOF)
    {
        ans = 0;
        for (i = 0; i < SIZE; i++)
        {
            p[i] = i;
            total[i] = 1;
        }

        for (i = 1; i <= N; i++)
        {
            scanf("%d", &M);
            //cout << "M = " << M << endl;
            reqSet = set<int>();
            //memset(req, 0, sizeof(req));
            for (j = 1; j <= M; j++)
            {
                scanf("%d", &ingredient);
                //req[ getParent(ingredient) ]++;
                reqSet.insert( getParent(ingredient) );
            }
            cnt = 0;
            //if ( reqSet.size() < 2 ) continue;
            for (it = reqSet.begin(); it!=reqSet.end(); it++)
            {
                cnt+=total[*it];
                //cout << "cnt = " << cnt << endl;
            }
            if ( M==cnt )
            {
                ans++;
                for (it2 = reqSet.begin(); it2!=reqSet.end(); it2++)
                {
                    makeUnion(*it2, *(reqSet.begin()) );
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}
