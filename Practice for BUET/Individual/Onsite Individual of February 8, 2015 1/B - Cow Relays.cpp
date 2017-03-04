#include <iostream>
using namespace std;

#define SIZE 1000009

 int N, M, R;
 int i, j, k, x, y, z, a, b, c;

int starting, ending, eff;
struct interval
{
    int start, ending, eff;
    interval(){}
    interval(int start, int ending, int eff)
    {
        this->start  =start;
        this->ending = ending;
        this->eff = eff;
    }
    bool operator<(const interval &b) const
    {
        if (ending == b.ending)
        {
            return eff < b.eff;
        }

        return b.ending < ending;
    }
};

vector<interval> intervalVector;
int dp[SIZE];

int main()
{
   cin >> N >> M >> R;
   for (i = 1; i <= M; i++)
   {
       cin >> starting >> ending >> eff;
       intervalVector.push_back( interval(starting, ending, eff) );
   }

    sort(intervalVector.begin(), intervalVector.end());



    for (i = 0; i <= N; i++)
    {

    }

    return 0;
}
