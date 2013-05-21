/*
 * 3Sum Closest
 * Given an array S of n integers, find three integers in S such that the
 * sum is closest to a given number, target. Return the sum of the three
 * integers. You may assume that each input would have exactly one solution.

 * For example, given array S = {-1 2 1 -4}, and target = 1.

 * The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int threeSumClosest(vector<int> &num, int target) {
    sort(num.begin(), num.end());
    int mindist = INT_MAX;
    bool sign = false;
    int n = num.size();
    for (int i=0; i<n; i++) {
        int j=i+1, k=n-1;
        while (j < k) {
            int sum = num[i] + num[j] + num[k];
            int orig = mindist;
            mindist = min(mindist, abs(sum - target));
            if(sum > target) {
                if (mindist < orig)
                    sign = true;
                k--;
            } else if (sum < target) {
                if (mindist < orig)
                    sign = false;
                j++;
            } else {
                return target;
            }
        }
    }
    return (sign == true) ? (mindist + target) : (target - mindist);
}