#include <bits/stdc++.h>
using namespace std;
#define SIZE 50
long long T, N, Si, Ei, Ci, ans;
long long i, j, k, s, put;
long long optimal[SIZE];
struct interval
{
    long long start, fin, comp;
    interval(){}
    interval(long long start, long long fin, long long comp)
    {
        this->start = start;
        this->fin = fin;
        this->comp = comp;
    }
};
bool cmp(interval a, interval b)
{
    if (a.fin==b.fin) return a.start<b.start;
    return a.fin<b.fin;
}
vector<interval> vec;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> T;
    for (i = 1; i <= T; i++)
    {
        memset(optimal, 0, sizeof(optimal) );
        vec = vector<interval>();
        cin >> N;
        for (j = 0; j < N; j++)
        {
            scanf("%lld %lld %lld", &Si, &Ei, &Ci);
            vec.push_back( interval(Si, Ei, Ci) );
        }
        sort(vec.begin(), vec.end(), cmp);
        s = vec.size();
        for (j = 0; j < s; j++)
        {
            Si = vec[j].start;
            Ei = vec[j].fin;
            Ci = vec[j].comp;
            put = max( optimal[Si]+Ci, optimal[Ei] );
            for (k = Ei; k < SIZE; k++)
            {
                optimal[k] = put;
            }
        }
        cout << optimal[48] << endl;
    }
    return 0;
}
