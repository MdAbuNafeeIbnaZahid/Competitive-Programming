#include <bits/stdc++.h>
using namespace std;
long long n, ti, wi;
long long a, b, c, d, e, f, g, h;
long long myTi, myWi, lowerVal, higherVal, midVal;
struct team
{
    long long ti, wi, gap;
    team(){}
    team(long long ti, long long wi)
    {
        this->ti = ti;
        this->wi = wi;
        gap = wi-ti;
    }
    const bool operator < ( team B ) const
    {
        if ( gap == B.gap )
        {
            return ti < B.ti;
        }
        return gap < B.gap;
    }
};
vector<team> vecTeam;
bool cmp( const team A, const team B )
{
    if ( A.ti == B.ti )
    {
        return A.wi < B.wi;
    }
    return A.ti < B.ti;
}



long long ifPossible(long long pos, vector<team> givenTeams)
{
    long long a, b, c, d, e, f, g, h, balloonLeft = myTi;
    long long copMyTi = myTi;
    multiset<team> mulSetTeam;
    multiset<team>::iterator mulSetTeamIt;
    //cout << "pos = " << pos << endl;
    for (a = givenTeams.size()-1; a >= 0; a--)
    {
        if ( givenTeams[a].ti <= myTi )
        {
            break;
        }
        mulSetTeam.insert( givenTeams[a] );
        givenTeams.pop_back();
    }

    //cout << "mulSetTeam.size() = " << mulSetTeam.size() << endl;
    //cout << "givenTeams.size() = " << givenTeams.size() << endl;

    while( mulSetTeam.size()+1 > pos )
    {
        mulSetTeamIt = mulSetTeam.begin();
        //cout << "mulSetTeamIt->gap+1 = " << mulSetTeamIt->gap+1 << endl;
        //cout << "balloonLeft = " << balloonLeft << endl;
        if ( (mulSetTeamIt->gap+1) > balloonLeft )
        {
            //cout << "returning 0" << endl;
            return 0;
        }
        balloonLeft -= (mulSetTeamIt->gap+1);
        copMyTi -= (mulSetTeamIt->gap+1);
        mulSetTeam.erase( mulSetTeamIt );
        while( givenTeams.size() && givenTeams[ givenTeams.size()-1 ].ti > copMyTi )
        {
            mulSetTeam.insert( givenTeams[ givenTeams.size()-1 ] );
            givenTeams.pop_back();
        }
    }
    return 1;
}

long long bestPossible(vector<team> givenTeams)
{
    long long a, b, c, d, e, f, g, h, balloonLeft = myTi;
    long long copMyTi = myTi, ans = INT_MAX;
    multiset<team> mulSetTeam;
    multiset<team>::iterator mulSetTeamIt;
    //cout << "pos = " << pos << endl;
    for (a = givenTeams.size()-1; a >= 0; a--)
    {
        if ( givenTeams[a].ti <= myTi )
        {
            break;
        }
        mulSetTeam.insert( givenTeams[a] );
        givenTeams.pop_back();
    }

    //cout << "mulSetTeam.size() = " << mulSetTeam.size() << endl;
    //cout << "givenTeams.size() = " << givenTeams.size() << endl;

    while( mulSetTeam.size() )
    {
        ans = min(ans,  (long long)(mulSetTeam.size()+1) );
        mulSetTeamIt = mulSetTeam.begin();
        //cout << "mulSetTeamIt->gap+1 = " << mulSetTeamIt->gap+1 << endl;
        //cout << "balloonLeft = " << balloonLeft << endl;
        if ( (mulSetTeamIt->gap+1) > balloonLeft )
        {
            //cout << "returning 0" << endl;
            return ans;
        }
        balloonLeft -= (mulSetTeamIt->gap+1);
        copMyTi -= (mulSetTeamIt->gap+1);
        mulSetTeam.erase( mulSetTeamIt );
        while( givenTeams.size() && givenTeams[ givenTeams.size()-1 ].ti > copMyTi )
        {
            mulSetTeam.insert( givenTeams[ givenTeams.size()-1 ] );
            givenTeams.pop_back();
        }
    }
    return 1;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    cin >> myTi >> myWi;
    for (a = 2; a <= n; a++)
    {
        scanf("%lld %lld", &ti, &wi);
        vecTeam.push_back( team(ti, wi) );
    }
    sort( vecTeam.begin(), vecTeam.end(), cmp );
    cout << bestPossible(vecTeam);
    return 0;
}
