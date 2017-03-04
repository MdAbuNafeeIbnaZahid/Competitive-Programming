#include <bits/stdc++.h>
using namespace std;
#define SIZE 20000009
long long T, Q, typ, pid, rid;
map<long long, long long> myMap;
long long a, b, c, d, e;
long long qAr[SIZE];
struct query
{
    long long typ, rid, pid;
    query(){}
    query(long long typ, long long rid, long long pid = -1)
    {
        this->typ = typ;
        this->rid = rid;
        this->pid = pid;
    }
};
vector<query> vecQ;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        vecQ = vector<query>();
        cin >> Q;
        for (b = 1; b <= Q; b++)
        {
            scanf("%lld", &typ);
            if ( typ == 1 )
            {
                scanf("%lld %lld", &pid, &rid);
                vecQ.push_back( query(typ, rid, pid) );
            }
            else if (typ == 2)
            {
                scanf("%lld", &rid);
                vecQ.push_back( query(typ, rid) );
            }
            qAr[rid] = -1;
        }
        for (b = 0; b < Q; b++)
        {
            if ( vecQ[b].typ == 1 )
            {
                if ( qAr[vecQ[b].rid ] == -1 )
                {
                    qAr[vecQ[b].rid ] = vecQ[b].pid;
                    printf("Y\n");
                }
                else
                {
                    printf("N\n");
                }
            }
            else if ( vecQ[b].typ == 2 )
            {
                if ( qAr[vecQ[b].rid ] == -1 )
                {
                    //qAr[vecQ[b].rid ] = vecQ[b].pid;
                    printf("F\n");
                }
                else
                {
                    printf("%lld\n", qAr[vecQ[b].rid ] );
                    qAr[vecQ[b].rid ] = -1;
                }
            }
        }
    }
    return 0;
}
