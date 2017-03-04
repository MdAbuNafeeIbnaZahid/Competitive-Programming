#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
int T, N, Si, Fi, S[SIZE], F[SIZE];
int i, j, k, s, upto;
struct slot
{
    int start, fin, idx;
    slot(){};
    slot(int start, int fin, int idx)
    {
        this->start = start;
        this->fin = fin;
        this->idx = idx;
    }
};
bool cmp(slot a, slot b)
{
    if ( a.fin==b.fin ) return a.idx<b.idx;
    return a.fin<b.fin;
}
vector<slot> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        vec = vector<slot>();
        cin >> N;
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &S[j]);
        }
        for (j = 1; j <= N; j++)
        {
            scanf("%d", &F[j]);
        }
        for (j = 1; j <= N; j++)
        {
            vec.push_back( slot(S[j], F[j], j) );
        }
        sort(vec.begin(), vec.end(), cmp);
        s = vec.size();
        for (j = 0; j <s; j++)
        {
            cout << "j = " << j << ", start = " << vec[j].start << ", fin = " << vec[j].fin;
            cout << ", idx = " << vec[j].idx << endl;
        }
        cout << vec[0].idx << " ";
        upto = vec[0].fin;
        for (j = 1; j < s; j++)
        {
            if (vec[j].start > upto)
            {
                cout << vec[j].idx << " ";
                upto = vec[j].fin;
            }
        }
        cout << endl;
    }
    return 0;
}
