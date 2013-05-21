/*
 * 3Sum
 * Given an array S of n integers, are there elements a, b, c in S such that
 * a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
 * 
 * Note:

 * Elements in a triplet (a,b,c) must be in non-descending order. (ie, a ? b ? c)
 * The solution set must not contain duplicate triplets.
 * For example, given array S = {-1 0 1 2 -1 -4},

 * A solution set is:
 * (-1, 0, 1)
 * (-1, -1, 2)
*/

#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int> > threeSum(vector<int> &num) {
    sort(num.begin(), num.end());
    set<vector<int> > ret;
    vector<vector<int> > ret1;
    for (auto iter = num.begin(); iter != num.end(); ++iter) {
        auto left = iter + 1, right = num.end()-1;
        while (left < right) {
            if (*iter + *left + *right > 0)
                --right;
            else if (*iter + *left + *right < 0)
                ++left;
            else {
                vector<int> tmp;
                tmp.push_back(*iter);
                tmp.push_back(*left);
                tmp.push_back(*right);
                ret.insert(tmp);
                --right;
                ++left;
            }
        }
    }
    for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
        ret1.push_back(*iter);
    }
    return ret1;
}