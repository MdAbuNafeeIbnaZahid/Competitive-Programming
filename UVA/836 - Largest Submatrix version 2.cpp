#include <bits/stdc++.h>
using namespace std;
char line[1000];
string input[30];
int testCases, i, j, k, m, myMatrix[30][30], ans, height, row;
stack<int> stak;
int main()
{
    freopen("input.txt", "r", stdin);
    cin >> testCases;
    while(testCases--)
    {
        ans = -1;
        memset(myMatrix, 0, sizeof(myMatrix));
        i = 0;
        while(gets(line))
        {
            stringstream ss(line);
            while( ss >> input[i] ) i++;
        }

        row = i;
        //cin >> input[0];
        //for (i = 1; i < input[0].size(); i++)
        //{
            //cin >> input[i];
        //}
        for (j = 0; j < input[0].size(); j++)
        {
            if ( input[0][j] == '0' ) myMatrix[0][j] = 0;
            else if ( input[0][j] == '1' ) myMatrix[0][j] = 1;
        }
        for (i = 1; i < row; i++)
        {
            for (j = 0; j < input[0].size(); j++)
            {
                if ( input[i][j] == '0' ) myMatrix[i][j] = 0;
                else if ( input[i][j] == '1' ) myMatrix[i][j] = myMatrix[i-1][j] + 1;
            }
        }
        //for (i = 0; i < input[0].size(); i++)
        //{
            //for (j = 0; j < input[0].size(); j++)
            //{
                //cout << myMatrix[i][j] << " ";
            //}
            //cout << endl;
        //}
        for (i = 0; i < row; i++)
        {
            stak = stack<int>();

            for (j = 0; j < input[0].size(); j++)
            {
                while( !stak.empty() && myMatrix[i][stak.top()] > myMatrix[i][j] )
                {
                    height = myMatrix[i][stak.top()];
                    stak.pop();
                    if (stak.empty()) ans = max(ans,  j*height );
                    else ans = max(ans, (j-stak.top()-1)*height );
                }
                stak.push(j);
            }
            while( !stak.empty()  )
            {
                height = myMatrix[i][stak.top()];
                stak.pop();
                if (stak.empty()) ans = max(ans,  j*height );
                else ans = max(ans, (j-stak.top()-1)*height );
            }
        }
        cout << ans << endl << endl;
    }
    return 0;
}
