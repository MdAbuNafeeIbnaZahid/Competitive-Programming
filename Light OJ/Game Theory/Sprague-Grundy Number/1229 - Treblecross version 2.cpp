#include <bits/stdc++.h>
using namespace std;
#define SIZE 209
long long T;
string state;
long long grundyVal[SIZE], xorVal, leftIdx, rightIdx, checkVal;
long long a, b, c, d, e, f, g, h;
vector<long long> v;
set<long long> setLL;
set<long long>::iterator setLLIt;
long long grundyF(long long n)
{
    long long a, b, c, d, e, f;
    set<long long> lowerVal;
    if (n<=0) return 0;
    if ( grundyVal[n] == -1 )
    {
        lowerVal.insert( grundyF(n-3) );
        lowerVal.insert( grundyF(n-4) );
        for (a = n-5; a >= 0; a--)
        {
            lowerVal.insert( grundyF(a) ^ grundyF(n-5-a) );
        }
        for (a = 0; ;a++)
        {
            if ( lowerVal.find(a) == lowerVal.end() ) break;
        }
        grundyVal[n] = a;
    }
    return grundyVal[n];
}
int main()
{
    freopen("input.txt", "r", stdin);
    memset(grundyVal, -1, sizeof(grundyVal) );
    grundyVal[0] = 0;

    for (a=0; a < 205; a++) grundyF(a);

    cin >> T;
    for (a = 1; a <= T; a++)
    {
        xorVal = 0;
        v = vector<long long>();
        setLL = set<long long>();
        cin >> state;
        for (b = 0; b < state.size(); b++)
        {
            if ( state[b] == 'X' )
            {
                v.push_back( b );
            }
            else
            {
                if ( b+2 < state.size() && state[b+1]=='X' && state[b+2]=='X' )
                    setLL.insert(b);
                else if ( b-1>=0 && b+1<state.size() && state[b-1]=='X' && state[b+1]=='X' )
                    setLL.insert(b);
                else if (b-2>=0 && state[b-1]=='X' && state[b-2]=='X')
                    setLL.insert(b);
            }
        }
        if ( setLL.size() )
        {
            cout << "Case " << a << ": ";
            for (setLLIt = setLL.begin(); setLLIt != setLL.end(); setLLIt++)
            {
                printf("%lld ", (*setLLIt)+1 );
            }
            cout << endl;
            continue;
        }
        else
        {
            state = "L" + state + "L";
            for (b = 0; b < state.size(); b++)
            {
                if ( state[b] == 'X' )
                {
                    if (b-1>=0 && state[b-1]=='.') state[b-1] = 'L';
                    if (b-2>=0 && state[b-2]=='.') state[b-2] = 'L';
                    if (b+1<state.size() && state[b+1]=='.') state[b+1] = 'L';
                    if (b+2<state.size() && state[b+2]=='.') state[b+2] = 'L';
                }
            }

            leftIdx = rightIdx = -1;
            for (b = 0; b < state.size(); b++)
            {
                if ( state[b] == 'L' )
                {
                    if ( leftIdx == -1 )
                    {
                        leftIdx = b;
                    }
                    else
                    {
                        rightIdx = b;
                        for (c = leftIdx+1; c < rightIdx; c++)
                        {
                            if ( state[c] != '.' ) break;
                        }
                        if ( c >= rightIdx ) xorVal ^= grundyF(rightIdx - leftIdx - 1);
                        leftIdx = rightIdx = -1;
                    }
                }
            }

            for (b = 0; b < state.size(); b++)
            {
                if ( state[b] == '.' )
                {
                    for (leftIdx = b-1; state[leftIdx]!='L';leftIdx--){}
                    for (rightIdx = b+1; state[rightIdx]!='L'; rightIdx++){}
                    checkVal = xorVal;
                    checkVal ^= grundyF(rightIdx-leftIdx-1);
                    checkVal ^= grundyF(b-2-leftIdx-1);
                    checkVal ^= grundyF(rightIdx-(b+2)-1);
                    if (checkVal == 0)
                    {
                        setLL.insert(b);
                    }
                }
            }
            if ( setLL.size() )
            {
                //cout << "Here" << endl;
                cout << "Case " << a << ": ";
                for (setLLIt = setLL.begin(); setLLIt != setLL.end(); setLLIt++)
                {
                    printf("%lld ", *setLLIt);
                }
                cout << endl;
                //continue;
            }
            else
            {
                cout << "Case " << a << ": " << 0 << endl;;
            }
        }
    }
    return 0;
}
