#include <bits/stdc++.h>
using namespace std;
long long T;
long long a, b, c, d, e, f;
long long width, height, flag;
struct rectangle
{
    long long w, h;
    rectangle(){}
    rectangle(long long w, long long h)
    {
        this->w = w;
        this->h = h;
    }
};

vector<rectangle> joinTwoRectangle(rectangle A, rectangle B)
{
    vector<rectangle> ret;
    if ( A.w == B.w )
    {
        ret.push_back( rectangle(A.w, A.h+B.h) );
    }
    if ( A.w == B.h )
    {
        ret.push_back( rectangle(A.w, A.h+B.w) );
    }
    if ( A.h == B.w )
    {
        ret.push_back( rectangle(A.h, A.w+B.h) );
    }
    if (A.h == B.h)
    {
        ret.push_back( rectangle(A.h, A.w+B.w) );
    }
    return ret;
}

vector<rectangle> inputRectangle, doubleRectangle, tripleRectangle;
int main()
{
    //freopen("input.txt", "r", stdin);
    cin >> T;
    for (a = 1; a <= T; a++)
    {
        flag = 0;
        inputRectangle = vector<rectangle>();
        for (b = 0; b <= 3; b++)
        {
            scanf("%lld %lld", &width, &height);
            inputRectangle.push_back( rectangle(width, height) );
        }
        for (b = 0; b <= 3; b++)
        {
            for (c = b+1; c <= 3; c++)
            {
                doubleRectangle = joinTwoRectangle( inputRectangle[b], inputRectangle[c] );
                for (d = 0; d < doubleRectangle.size(); d++)
                {
                    for (e = 0; e <= 3; e++)
                    {
                        if ( e==b || e==c )
                        {
                            continue;
                        }
                        tripleRectangle = joinTwoRectangle(doubleRectangle[d], inputRectangle[e]);
                        if ( tripleRectangle.size() )
                        {
                            flag = 1;
                        }
                    }
                }
            }
        }
        if (flag)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    return 0;
}
