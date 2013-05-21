/* 
* 4Sum
* Given an array S of n integers, are there elements a, b, c, and d in S
* such that a + b + c + d = target? Find all unique quadruplets in the
* array which gives the sum of target.

* Note:

* Elements in a quadruplet (a,b,c,d) must be in non-descending order. 
* (ie, a ? b ? c ? d)
* The solution set must not contain duplicate quadruplets.
* For example, given array S = {1 0 -1 0 -2 2}, and target = 0.

* A solution set is:
* (-1,  0, 0, 1)
* (-2, -1, 1, 2)
* (-2,  0, 0, 2)
*/
#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

vector<vector<int> > fourSum(vector<int> &num, int target) {
    set<vector<int> > ret;
    sort(num.begin(), num.end());

    int n = num.size();
    for (int i=0; i<n; i++) {
        for (int j=i+1; j<n; j++) {
            int k = j + 1, l = n-1;
            while (k < l){
                int sum = num[i] + num[j] + num[k] + num[l];
                if (sum > target)
                    --l;
                else if (sum < target)
                    ++k;
                else {
                    vector<int> tmp;
                    tmp.push_back(num[i]);
                    tmp.push_back(num[j]);
                    tmp.push_back(num[k]);
                    tmp.push_back(num[l]);
                    ret.insert(tmp);
                    k++;
                    l--;
                }
            }
        }
    }
    vector<vector<int> > ret1;
    for (auto iter = ret.begin(); iter != ret.end(); ++iter) {
        ret1.push_back(*iter);
    }
    return ret1;
}