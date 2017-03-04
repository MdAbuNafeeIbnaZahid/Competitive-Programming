#include <bits/stdc++.h>
using namespace std;
#define SIZE 1000009
long long n, ar[SIZE], forMerge[SIZE], ans = 0, i, j, k, a, b, c;
long long insertionSort(long long *ar, long long start, long long fin)
{
    long long i, j, k, ret = 0, temp, pivot;
    for (i = start; i <= fin; i++)
    {
        pivot = ar[i];
        for (j = i-1; j>=start; j--)
        {
            if (ar[j]>pivot)
            {
                ret++;
                ar[j+1] = ar[j];
            }
        }
        ar[j+1] = pivot;
    }
    return ret;
}
long long mergeTwo(long long *ar, long long s1, long long e1, long long s2, long long e2)
{
    long long i, j, k, m, n, ret = 0, idx1 = s1, idx2 = s2;
//    cout << "sorted array 1 : ";
//    for (i = s1; i <= e1; i++)
//    {
//        cout << ar[i] << " ";
//    }
//    cout << endl;
//    cout << "sorted array 2 : ";
//    for (i = s2; i <= e2; i++)
//    {
//        cout << ar[i] << " ";
//    }
//    cout << endl;
    for (i = s1; i<=e2; i++)
    {
        if ( idx1>e1 )
        {
            forMerge[i] = ar[idx2];
            idx2++;
        }
        else if (idx2>e2)
        {
            forMerge[i] = ar[idx1];
            idx1++;
        }
        else if ( ar[idx1]<ar[idx2] )
        {
            forMerge[i] = ar[idx1];
            idx1++;
        }
        else if ( ar[idx2]<ar[idx1] )
        {
            forMerge[i] = ar[idx2];
            idx2++;
            ret += (e1-idx1+1);
        }
    }
    for (i = s1; i<=e2; i++)
    {
        ar[i] = forMerge[i];
    }
//    cout << "merged sorted array : ";
//    for (i = s1; i <= e2; i++)
//    {
//        cout << ar[i] << " ";
//    }
//    cout << endl;

    return ret;
}
long long mergeSort(long long *ar, long long start, long long fin)
{
    long long i, j, k;
//    cout << "mergeSort is called for the array ";
//    for (i = start; i <= fin; i++)
//    {
//        cout << ar[i] << " ";
//    }
//    cout << endl;
    if (start>=fin) return 0;
    long long ret = 0;
    ret += mergeSort(ar, start, (start+fin)/2);
    ret += mergeSort(ar, (start+fin)/2+1, fin);
    ret += mergeTwo(ar, start, (start+fin)/2, (start+fin)/2+1, fin);
//    cout << "sorted array is ";
//    for (i = start; i <= fin; i++)
//    {
//        cout << ar[i] << " ";
//    }
//    cout << endl;
    return ret;
}
long long mySort(long long *ar, long long start, long long fin)
{
    long long ret = 0;
    if (fin-start+1<=14)
    {
        ret = insertionSort(ar, start, fin);
    }
    else ret = mergeSort(ar, start, fin);
    return ret;
}
int main()
{
    freopen("input.txt", "r", stdin);
    while(cin >> n)
    {
        for (i = 0; i < n; i++)
        {
            scanf("%lld", &ar[i]);
        }
        cout << mySort(ar, 0, n-1) << endl;
    }
    return 0;
}
