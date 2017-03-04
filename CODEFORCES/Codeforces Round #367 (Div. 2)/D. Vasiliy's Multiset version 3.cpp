#include <bits/stdc++.h>
using namespace std;
#define SIZE 8000009
int q, children[SIZE][2], xi, occurrence[SIZE], nodeCount, ans, current;
int a, b, c, d, e, f, g;
char ch;
int insertElement(int num, int level, int nodeIdx)
{
    int a, b, c, d, e, f, current = nodeIdx;
    occurrence[current]++;
    for (a = level; a >= 0; a--)
    {
        if ( children[current][ (num>>a) &1] == -1 )
        {
            children[current][(num>>a)&1] = ++nodeCount;
            occurrence[nodeCount]++;
        }
        else
        {
            occurrence[ children[current][ (num>>a)&1] ]++;
        }
        current = children[current][(num>>a)&1];
    }
    return 1;
}

int deleteElement(int num, int level, int nodeIdx)
{
     int a, b, c, d, e, f, whatToDo, current = nodeIdx;
     occurrence[current]--;
     for (a = level; a >= 0; a--)
     {
         current = children[ current ][ (num>>a) & 1 ];
         occurrence[ current ]--;
     }
}

int main()
{
//    freopen("input.txt", "r", stdin);
    memset(children, -1, sizeof(children) );
    insertElement(0, 30, 0);
    cin >> q;
    for (a = 1; a <= q; a++)
    {
        getchar();
        scanf("%c %d", &ch, &xi);
        if ( ch == '+' )
        {
            insertElement(xi, 30, 0);
        }
        else if (ch == '-')
        {
            deleteElement(xi, 30, 0);
        }
        else if (ch == '?')
        {
            ans = 0;
            current = 0;
            for (b = 30; b >= 0; b--)
            {
                if ( ( (xi>>b) & 1 )==1 && children[current][0]!=-1
                    && occurrence[ children[current][0] ] >0 )
                {
                    current = children[current][0];
                    ans ^= (1<<b);
                }
                else if ( ( (xi>>b) & 1 )== 0 && children[current][1]!=-1
                         && occurrence[ children[current][1] ] > 0 )
                {
                    current = children[current][1];
                    ans ^= (1<<b);
                }
                else if ( children[current][0]!=-1 && occurrence[ children[current][0] ] > 0 )
                {
                    current = children[current][0];
                }
                else if ( children[current][1]!=-1 && occurrence[ children[current][1] ] > 0 )
                {
                    current = children[current][1];
                }
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}
