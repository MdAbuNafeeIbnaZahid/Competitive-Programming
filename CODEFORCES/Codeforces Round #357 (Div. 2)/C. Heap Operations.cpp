#include <bits/stdc++.h>
using namespace std;
#define SIZE 2000009
long long n;
long long a, b, c, d, e, f, ansIdx = 0;
struct instruction
{
    string operation;
    long long val;
    instruction(){}
};
instruction inputArray[SIZE], ansArray[SIZE];
multiset<long long> heapSet;

int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        cin >> inputArray[a].operation;
        scanf("%lld", &inputArray[a].val);
    }
    for (b = 1; b <= n; b++)
    {
        if ( inputArray[b].operation == "insert" )
        {
            ansIdx++;
            ansArray[ansIdx].operation = "insert";
            ansArray[ansIdx].val = inputArray[b].val;
            heapSet.insert( inputArray[b].val );
        }
        else if ( inputArray[b].operation == "getMin" )
        {
            while(  heapSet.size() && *heapSet.begin() < inputArray[b].val )
            {
                ansIdx++;
                ansArray[ansIdx].operation = "removeMin";
                heapSet.erase( heapSet.begin() );
            }
            if ( !heapSet.size() || *heapSet.begin() > inputArray[b].val )
            {
                ansIdx++;
                ansArray[ansIdx].operation = "insert";
                ansArray[ansIdx].val = inputArray[b].val;
                heapSet.insert( inputArray[b].val );
            }
            if ( *heapSet.begin() == inputArray[b].val )
            {
                ansIdx++;
                ansArray[ansIdx].operation = "getMin";
                ansArray[ansIdx].val = inputArray[b].val;
                //heapSet.erase( heapSet.begin() );
            }
        }
        else if ( inputArray[b].operation == "removeMin" )
        {
            if ( !heapSet.size() )
            {
                ansIdx++;
                ansArray[ansIdx].operation = "insert";
                ansArray[ansIdx].val = 0;
                heapSet.insert( ansArray[ansIdx].val );
            }
            if ( heapSet.size() )
            {
                ansIdx++;
                ansArray[ansIdx].operation = "removeMin";
                heapSet.erase( heapSet.begin() );
            }
        }
    }
    cout << ansIdx << endl;
    for (b = 1; b <= ansIdx; b++)
    {
        cout << ansArray[b].operation;
        if ( ansArray[b].operation != "removeMin" )
        {
            printf(" %lld", ansArray[b].val);
        }
        printf("\n");
    }
    return 0;
}
