#include <bits/stdc++.h>
using namespace std;
#define SIZE 200009
long long n, aAr[SIZE], bAr[SIZE], maxVal[4*SIZE], minVal[4*SIZE], ans;
long long a, b, c, d, e, f, g, h, lowerVal, upperVal, startIdx, endIdx;
long long minVBin, maxVBin, mid;

long long sparseTableA[19][SIZE], sparseTableB[19][SIZE];
long long logAr[SIZE];
long long buildSparseTableA(long long n)
{
    long long a, b, c, d, e, f, g, h, i, j, span = 1, k, l;
    for (i = 1; i <= n; i++) sparseTableA[0][i] = aAr[i];
    for (j = 1; j < 18; j++)
    {
        span *= 2;
        for (i = 1; i <= n; i++)
        {
            sparseTableA[j][i] = max(sparseTableA[j-1][i], sparseTableA[j-1][i+span/2]);
        }
    }
    return 1;
}
long long buildSparseTableB(long long n)
{
    long long a, b, c, d, e, f, g, h, i, j, span = 1, k, l;
    for (i = 1; i <= n; i++) sparseTableB[0][i] = bAr[i];
    for (j = 1; j < 18; j++)
    {
        span *= 2;
        for (i = 1; i <= n; i++)
        {
            sparseTableB[j][i] = min(sparseTableB[j-1][i], sparseTableB[j-1][i+span/2]);
        }
    }
    return 1;
}
long long queryA(long long left, long long right)
{
    long long a, b, c, d, e, f, l = right-left+1, k, ret, upto, rem ;
    k = logAr[l];
    ret = sparseTableA[k][left];
    upto = left + (1<<k) - 1;
    rem = right - upto;
    ret = max(ret, sparseTableA[k][left+rem]);
    return ret;
}
long long queryB(long long left, long long right)
{
    long long a, b, c, d, e, f, l = right-left+1, k, ret, upto, rem ;
    k = logAr[l];
    ret = sparseTableB[k][left];
    upto = left + (1<<k) - 1;
    rem = right - upto;
    ret = min(ret, sparseTableB[k][left+rem]);
    return ret;
}
long long buildSeg(long long idx, long long L, long long R)
{
    long long mid = (L+R)/2;
    if ( L == R )
    {
        maxVal[idx] = aAr[L];
        minVal[idx] = bAr[L];
        return 0;
    }
    buildSeg(2*idx, L, mid);
    buildSeg(2*idx+1, mid+1, R);
    maxVal[idx] = max(maxVal[2*idx], maxVal[2*idx+1]);
    minVal[idx] = min(minVal[2*idx], minVal[2*idx+1]);
    return 1;
}
long long query(long long idx, long long L, long long R, long long left, long long right,
                long long &minV, long long &maxV)
{
    long long mid = (L+R)/2, minVL, minVR, maxVL, maxVR;
    if ( right < left )
    {
        minV = INT_MAX;
        maxV = INT_MIN;
        return 0;
    }
    if ( right < L || R < left )
    {
        minV = INT_MAX;
        maxV = INT_MIN;
        return 0;
    }
    if ( left <= L && R <= right )
    {
        minV = minVal[idx];
        maxV = maxVal[idx];
        return 0;
    }
    query(2*idx, L, mid, left, right, minVL, maxVL);
    query(2*idx+1, mid+1, R, left, right, minVR, maxVR);
    minV = min(minVL, minVR);
    maxV = max(maxVL, maxVR);
    return 1;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    for (a = 0; a < 19; a++)
    {
        for (b = 0; b < SIZE; b++)
        {
            sparseTableA[a][b] = INT_MIN;
            sparseTableB[a][b] = INT_MAX;
        }
    }
    logAr[0] = -1;
    cin >> n;
    for (a = 1; a <= n; a++)
    {
        logAr[a] = logAr[a/2]+1;
        //cout << "a = " << a << " log = " << logAr[a] << endl;
        scanf("%lld", &aAr[a]);
    }
    for (a = 1; a <= n; a++)
    {
        scanf("%lld", &bAr[a]);
    }
    //buildSeg(1, 1, n);
    buildSparseTableA(n);
//    for (a = 0; a < 5; a++)
//    {
//        for (b = 0; b <= n; b++)
//        {
//            cout << sparseTableA[a][b] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl << endl;
    buildSparseTableB(n);
//    for (a = 0; a < 5; a++)
//    {
//        for (b = 0; b <= n; b++)
//        {
//            cout << sparseTableB[a][b] << " ";
//        }
//        cout << endl;
//    }
    for (a = 1; a <= n; a++)
    {
        // startIdx find
        lowerVal = a;
        upperVal = n;
        while(upperVal - lowerVal > 1)
        {
            mid = (lowerVal+upperVal)/2;
            //query(1, 1, n, a, mid, minVBin, maxVBin);
            maxVBin = queryA(a, mid);
            minVBin = queryB(a, mid);
            if ( maxVBin-minVBin >= 0 )
            {
                upperVal = mid;
            }
            else if ( maxVBin-minVBin < 0 )
            {
                lowerVal = mid+1;
            }
        }
        //query(1, 1, n, a, lowerVal, minVBin, maxVBin);
        maxVBin = queryA(a, lowerVal);
        minVBin = queryB(a, lowerVal);
        if ( maxVBin-  minVBin == 0 ) startIdx = lowerVal;
        else startIdx = upperVal;

        //query(1, 1, n, a, startIdx, minVBin, maxVBin);
        maxVBin = queryA(a, startIdx);
        minVBin = queryB(a, startIdx);
        if ( maxVBin - minVBin != 0 ) continue;

        //endIdx find
        lowerVal = a;
        upperVal = n;
        while(upperVal - lowerVal > 1)
        {
            mid = ceil((lowerVal+upperVal)/2.0);
            //query(1, 1, n, a, mid, minVBin, maxVBin);
            maxVBin = queryA(a, mid);
            minVBin = queryB(a, mid);
            if ( maxVBin-minVBin > 0 )
            {
                upperVal = mid-1;
            }
            else if ( maxVBin-minVBin <= 0 )
            {
                lowerVal = mid;
            }
        }
        //query(1, 1, n, a, upperVal, minVBin, maxVBin);
        maxVBin = queryA(a, upperVal);
        minVBin = queryB(a, upperVal);
        if ( maxVBin-  minVBin == 0 ) endIdx = upperVal;
        else endIdx = lowerVal;




        //query(1, 1, n, a, endIdx, minVBin, maxVBin);
        maxVBin = queryA(a, endIdx);
        minVBin = queryB(a, endIdx);
        if ( maxVBin - minVBin != 0 ) continue;

//        cout << "a = " << a << endl;
//        cout << "startIdx = " << startIdx << endl;
//        cout << "endIdx = " << endIdx << endl;
        ans += (endIdx - startIdx+1);
    }
    cout << ans << endl;
    return 0;
}

