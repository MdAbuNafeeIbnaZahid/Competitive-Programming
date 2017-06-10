#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including tree_order_statistics_node_update
#include <ext/pb_ds/detail/standard_policies.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
// Order Statistic Tree
/* Special functions:

		find_by_order(k) --> returns iterator to the kth largest element counting from 0
		order_of_key(val) --> returns the number of items in a set that are strictly smaller than our item
*/
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
/******   END OF HEADER *********/
#define SIZE 109
long long n, m;
char grid[SIZE][SIZE];
pair<long long, long long> finIdx, parentFin[SIZE][SIZE], parentStart[SIZE][SIZE];
long long col[SIZE][SIZE], prX = 1, prY = 1;
            //    D  U  R  L
long long dx[] = {1, -1, 0, 0};
long long dy[] = {0, 0, 1, -1};
long long charToMov[SIZE*SIZE], movToChar[SIZE*SIZE], charToButton[SIZE][SIZE];
bool ifOk(long long x, long long y)
{
    if ( x <= 0 || x > n ) return false;
    if ( y <= 0 || y > m ) return false;
    return grid[x][y] != '*';
}

bool ifUpDownKnown()
{
    return charToMov[ 'U' ] != -1;
}

bool ifLeftRightKnown()
{
    return charToMov[ 'D' ] != -1;
}

bool isSafeIdx(long long x, long long y, long long idx)
{
    long long newX = x + dx[idx];
    long long newY = y + dy[idx];
    return grid[newX][newY] != '*';
}

bool isSafeChar(char ch)
{
    long long x = prX, y = prY;
    long long mov = charToMov[ch], newX, newY;
    bool ret = true;
    if ( mov == -1 )
    {
//        cout << "mov = -1 for required char" << endl;
        if (ch == 'U' || ch == 'D')
        {
             ret = ret && isSafeIdx(x, y, 0);
             ret = ret && isSafeIdx(x, y, 1);
             return ret;
        }
        else if ( ch == 'L' || ch == 'R' )
        {
            ret = ret && isSafeIdx(x, y, 2);
//            cout << "ret = " << ret << ", for mov 2" << endl;
            ret = ret && isSafeIdx(x, y, 3);
//            cout << "ret = " << ret << ", for mov 3" << endl;
            return ret;
        }
    }
    else
    {
        newX = x + dx[mov];
        newY = y + dy[mov];
        return grid[newX][newY] != '*';
    }
}

void dfs(long long x, long long y, pair<long long, long long> parentAr[SIZE][SIZE])
{
    long long a, b, c, d, e;
    if ( ! ifOk(x, y) ) return;
    if ( col[x][y] ) return;
//    cout << "x = " << x << ", y = " << y << endl;
    col[x][y] = 1;
    for (a = 0; a < 4; a++)
    {
        long long newX = x + dx[a];
        long long newY = y + dy[a];
        if ( !ifOk(newX, newY) )
        {
            continue;
        }
        if ( col[newX][newY] )
        {
            continue;
        }
        parentAr[newX][newY] = make_pair(x, y);
        dfs(newX, newY, parentAr);
    }
}
void pressButton(char ch)
{
    cout << ch << endl;
    fflush(stdout);
    scanf("%lld %lld", &prX, &prY);
    if (prX==-1 || grid[prX][prY]=='F')
    {
        exit(0);
    }
}

void moveOneHop(long long newX, long long newY)
{
    long long a, b, c, d, e;
    for (a = 0; a < 4; a++)
    {
        if ( newX == min(max(prX + dx[a], 0LL), n) &&
            newY == min( max(prY + dy[a], 0LL), m ) )
            {
//                cout << "will press the button " << (char)movToChar[a] <<  endl;
                pressButton( movToChar[a] );
                break;
            }
    }
}

void goToFinish()
{
    long long a, b, c, d, e, nextX, nextY;
    while(1)
    {
        nextX = parentFin[prX][prY].first;
        nextY = parentFin[prX][prY].second;

//        cout << "nextX = " << nextX << endl;
//        cout << "nextY = " << nextY << endl;

        moveOneHop(nextX, nextY);
    }
}


void knowChar(char ch)
{
    long long newX, newY, a, b, c, e, f, otherIdx, idx, x = prX, y = prY;
    char otherCh;
    pressButton(ch);
    newX = prX;
    newY = prY;
//    cout << "newX = " << newX << endl;
//    cout << "newY = " << newY << endl;
    if (ch == 'U' || ch == 'D')
    {
        if ( newX <= x )
        {
            idx = 1;
        }
        else
        {
            idx = 0;
        }
        otherCh = 'U' ^ 'D' ^ ch;
        otherIdx = 0 ^ 1 ^ idx;
    }
    else
    {
        if (newY <= y)
        {
            idx = 3;
        }
        else
        {
            idx = 2;
        }
        otherCh = 'L' ^ 'R' ^ ch;
        otherIdx = 2 ^ 3 ^ idx;
    }

    charToMov[ch] = idx;
    movToChar[idx] = ch;

    charToMov[otherCh] = otherIdx;
    movToChar[otherIdx] = otherCh;


    if ( newX != x || newY != y )
    {
        pressButton(otherCh);
    }

//    for (a = 0; a < 4; a++)
//    {
//        if ( newX == min(max(x+dx[a], 0), n),  && newY==min(max(y+dy[a], 0), m ) )
//        {
//            if (ch == 'U' || ch == 'D')
//            {
//                otherCh = 'U' ^ 'D' ^ ch;
//                otherIdx = 0 ^ 1 ^ a;
//            }
//            else
//            {
//                otherCh = 'L' ^ 'R' ^ ch;
//                otherIdx = 2 ^ 3 ^ a;
//            }
//            charToMov[ch] = a;
//            movToChar[a] = ch;
//
//            charToMov[otherCh] = otherIdx;
//            movToChar[otherIdx] = otherCh;
//
//            if ( newX != x || newY != y )
//            {
//                pressButton(otherCh);
//            }
//
//            break;
//        }
//    }
}
int main()
{
//    freopen("input.txt", "r", stdin);
    memset(charToMov, -1, sizeof(charToMov));
    long long a, b, c, d, e , f;
    cin >> n >> m;
    for (a = 1; a <= n; a++)
    {
        scanf("%s", grid[a]+1);
        for (b = 1; b <= m; b++)
        {
            if ( grid[a][b] == 'F' )
            {
                finIdx = make_pair(a, b);
            }
        }
    }
    dfs(finIdx.first, finIdx.second, parentFin);
//    memset(col, 0, sizeof(col));
//    dfs(1, 1, parentStart);

    if ( isSafeChar('U') )
    {
        knowChar('U');
    }
    else
    {
        knowChar('L');
    }

//    cout << "known first char" << endl;

    if ( ifUpDownKnown() )
    {
//        cout << "up down known" << endl;
        while( !isSafeChar('L') )
        {
//            cout << "it is not safe to press L" << endl;
            pressButton( movToChar[0] );
        }
        knowChar('L');
    }
    else // left right is known
    {
//        cout << "left right known" << endl;
        while( ! isSafeChar('U') )
        {
            pressButton( movToChar[2] );
        }
        knowChar('U');
    }

//    cout << "all char known" << endl;

    goToFinish();

    return 0;
}

