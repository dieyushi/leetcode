/*
* Remove Duplicates from Sorted Array
* Given a sorted array, remove the duplicates in place such that each element
* appear only once and return the new length.
 
* Do not allocate extra space for another array, you must do this in place
* with constant memory.
 
* For example,
* Given input array A = [1,1,2],
 
* Your function should return length = 2, and A is now [1,2].
*/
#include <iostream>
 
int removeDuplicates(int A[], int n) {
    if (n == 0) return 0;
    int start = 0;
    int curr = A[0];
 
    for (int i=0;i<n;i++){
        if (A[i] != curr) {
            A[start++] = curr;
            curr = A[i];
        }
    }
    A[start++] = curr;
    return start;
}