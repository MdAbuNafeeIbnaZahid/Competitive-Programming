#include <bits/stdc++.h>
using namespace std;
#define SIZE 20009
#define WHITE 0
#define GREY 1
#define BLACK 2
char si;
long long T, n, m, i, j, len, SCCnum, SCCar[SIZE], u, v, assingedVal[SIZE];
long long valueToBeAssigned;
long long a, b, c, d, e, f, g, h;
vector<long long> gr[SIZE], transGr[SIZE], DAG[SIZE], topOrder, DAGtopOrder;
vector<long long> SCCvecAr[SIZE], ansVec;
long long color[SIZE];
void dfs1(long long u)
{
    long long a, b, c, d, e, f, len = gr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        dfs1( gr[u][a] );
    }
    color[u] = BLACK;
    topOrder.push_back(u);
}
void dfs2(long long u)
{
    long long a, b, c, d, e, f, len = transGr[u].size();
    if ( color[u] != WHITE ) return;
    color[u] = GREY;
    for (a = 0; a < len; a++)
    {
        dfs2( transGr[u][a] );
    }
    SCCar[u] = SCCnum;
    color[u] = BLACK;
    SCCvecAr[ SCCnum ].push_back( u );
}
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        cin >> n >> m;
        SCCnum = 0;
        memset(color, 0, sizeof(color) );
        memset(assingedVal, -1, sizeof(assingedVal) );
        for (b = 0; b <= 2*m+9; b++)
        {
            gr[b] = vector<long long>();
            transGr[b] = vector<long long>();
            DAG[b] = vector<long long>();
            SCCvecAr[b] = vector<long long>();
        }
        topOrder = vector<long long>();
        DAGtopOrder = vector<long long>();
        ansVec = vector<long long>();
        for (b = 1; b <= n; b++)
        {
            scanf("%lld %lld", &i, &j);
            gr[m-i].push_back(m+j);
            gr[m-j].push_back(m+i);
            transGr[m+j].push_back(m-i);
            transGr[m+i].push_back(m-j);
        }
        for (b = 1; b <= m; b++)
        {
            dfs1(m+b);
            dfs1(m-b);
        }
        len = topOrder.size();
        memset(color, 0, sizeof(color) );
        for (b = len-1; b >= 0; b--)
        {
            if ( color[ topOrder[b] ] == WHITE )
            {
                SCCnum++;
                dfs2( topOrder[b] );
            }
        }
        for (b = 1; b <= m; b++)
        {
            if ( SCCar[m+b] == SCCar[m-b] )
            {
                cout << "Case " << a << ": No" << endl;
                break;
            }
        }
        if ( b <= m ) continue;
        cout << "Case " << a << ": Yes" << endl;
        for (b = SCCnum; b >= 1; b--)
        {
            valueToBeAssigned = -1;
            len = SCCvecAr[b].size();
            for (c = 0; c < len; c++)
            {
                if ( assingedVal[ SCCvecAr[b][c] ] != -1 )
                {
                    valueToBeAssigned = assingedVal[ SCCvecAr[b][c] ];
                    break;
                }
            }
            if ( valueToBeAssigned == -1 ) valueToBeAssigned = 1;
            for (c = 0; c < len; c++)
            {
                v = SCCvecAr[b][c];
                assingedVal[v] = valueToBeAssigned;
                if (v > m)
                {
                    assingedVal[ v-2*(v-m) ] = !valueToBeAssigned;
                }
                else if (v<m)
                {
                    assingedVal[ v+2*(m-v) ] = !valueToBeAssigned;
                }
            }
        }
        for (b = 1; b <= m; b++)
        {
            if ( assingedVal[m+b] ) ansVec.push_back(b);
        }
        len = ansVec.size();
        cout << len << " ";
        for (b = 0; b <= len-1; b++)
        {
            printf("%lld ", ansVec[b]);
        }
        cout << endl;
    }
    return 0;
}
