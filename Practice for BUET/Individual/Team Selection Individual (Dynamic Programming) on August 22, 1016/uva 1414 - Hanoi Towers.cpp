#include <bits/stdc++.h>
using namespace std;
long long idx;
long long solve(long long rem, char source, char aux, char destination)
{
    if ( rem == 1 )
    {
        cout << (++idx) << ". " << source << " to " << destination << endl;
        return 0;
    }
    solve(rem-1, source, destination, aux);
    cout << (++idx) << ". " << source << " to " << destination << endl;
    solve(rem-1, aux, source, destination);
}
int main()
{
    solve(5, 'A', 'B', 'C');
    return 0;
}
