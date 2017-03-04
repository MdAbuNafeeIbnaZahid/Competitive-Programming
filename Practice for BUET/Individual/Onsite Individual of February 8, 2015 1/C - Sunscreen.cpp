#include <iostream>
#include <set>
using namespace std;

#define SIZE 2510

int C, L;
int minn[SIZE];
int maxx[SIZE];
int SPFtoCover[1005];
int SPF, cover;
int demandAr[1005];
int i, j, k, a, b, c, x, y, z, ans = 0;



struct lotion
{
    int SPF, cover, demand;
    lotion(int demand = 0, int cover = 0, int SPF = 0)
    {
        this->demand = demand;
        this->cover = cover;
        this->SPF = SPF;
    }

    bool operator<(const lotion &b) const
    {
        //if ( SPFtoCover[b.SPF] <= 0) return false;
        return !(demand < b.demand);
    }
};

set<lotion> lotionSet;

int main()
{
    //freopen()
    cin >> C >> L;

    for (i = 1; i <= C; i++)
    {
        cin >> minn[i];
        cin >> maxx[i];
    }

    for (i = 1; i <= L; i++)
    {
        cin >> SPF >> cover;
        SPFtoCover[SPF] += cover;
        //cout << "\n SPFtoCover[SPF] = " << SPFtoCover[SPF] << "\n";
        demandAr[SPF] = 1;
    }

    for (i = 1; i <= C; i++)
    {
        for (j = minn[i]; j <= maxx[i]; j++)
        {
            if (demandAr[j] > 0) demandAr[j]++;
        }
    }

    for (i  = 1; i <= 1000; i++)
    {
        if (SPFtoCover[i] > 0)
        {
            //cout << "\n SPFtoCover[i] > 0 \n";
            lotionSet.insert( lotion(demandAr[i], SPFtoCover[i], i) );
        }
    }


    //cout << "\n" << lotionSet.size() << "\n";

    set<lotion>::iterator it;
    for (i = 1; i <= C; i++)
    {
        for (it = lotionSet.begin(); it != lotionSet.end(); it++)
        {
            if (it->SPF >= minn[i] && it->SPF <= maxx[i])
            {
                if ( SPFtoCover[it->SPF] > 0 )
                {
                    SPFtoCover[it->SPF]--;
                    ans++;
                }

                else
                {
                    //lotionSet.erase(it);
                }
            }
        }
    }


    cout << ans;
    return 0;
}
