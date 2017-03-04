#include <bits/stdc++.h>
using namespace std;
#define SIZE 109
int M, n, m;
int i, j, k, aCount, cCount, gCount, tCount;
string input;
struct DNA
{
    string str;
    int inversions;
    int idx;
    DNA(){}
    DNA(string str, int idx, int inversions = 0)
    {
        this->str = str;
        this->idx = idx;
        this->inversions = inversions;
    }
};
DNA dnaAr[SIZE];
bool cmp(const DNA &a, const DNA &b)
{
    if (a.inversions == b.inversions) return a.idx<b.idx;
    return a.inversions<b.inversions;
}
int countInversions(string str)
{
    int aCount = cCount = gCount = tCount = 0, len = str.size();
    int i, j, k, m, ret = 0;
    for (i = 0; i < len; i++)
    {
        if ( str[i]=='A' )
        {
            aCount++;
            ret += cCount;
            ret += gCount;
            ret += tCount;
        }
        else if (str[i] == 'C')
        {
            cCount++;
            ret += gCount;
            ret += tCount;
        }
        else if (str[i] == 'G')
        {
            gCount++;
            ret += tCount;
        }
        else if (str[i] == 'T')
        {
            tCount++;
        }
    }
    return  ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> M;
    //cout << "M = " << M << endl;
    for (i = 1; i <= M; i++)
    {
        cin >> n >> m;
        for (j = 0; j < m; j++)
        {
            cin >> input;
            dnaAr[j] = DNA(input, j);
        }
        for (j = 0; j<m; j++)
        {
            dnaAr[j].inversions = countInversions( dnaAr[j].str );
        }
        stable_sort(dnaAr, dnaAr+m, cmp);
        for (j = 0; j < m; j++)
        {
            cout << dnaAr[j].str << endl;
        }
        if (i<M)cout << endl;
    }
    return 0;
}
