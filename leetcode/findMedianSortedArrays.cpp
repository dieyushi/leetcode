/*
* Median of Two Sorted Arrays
* There are two sorted arrays A and B of size m and n respectively. Find
* the median of the two sorted arrays. The overall run time complexity
* should be O(log (m+n)).
*/

#include <iostream>
#include <cassert>

using namespace std;

int findKthSmallest(int A[], int m, int B[], int n, int k) {
    if (m > n)
        return findKthSmallest(B, n, A, m, k);
    if (m == 0)
        return B[k-1];
    if (k == 1)
        return min(A[0], B[0]);

    int i = min(k/2, m), j = k - i;
    if (A[i-1] < B[j-1])
        return findKthSmallest(A+i, m-i, B, n, k-i);
    else if (A[i-1] > B[j-1])
        return findKthSmallest(A, m, B+j, n-j, k-j);
    else
        return A[i-1];
}

double findMedianSortedArrays(int A[], int m, int B[], int n) {
    int k = (m + n) /2;
    if ((m+n)%2)
        return findKthSmallest(A,m,B,n,k+1);
    else
        return (findKthSmallest(A,m,B,n,k)+findKthSmallest(A,m,B,n,k+1))/2.0;
}