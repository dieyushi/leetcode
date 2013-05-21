/* 
 * Container With Most Water
 * 
 * Given n non-negative integers a1, a2, ..., an, where each represents a point
 * at coordinate (i, ai). n vertical lines are drawn such that the two endpoints
 * of line i is at (i, ai) and (i, 0). Find two lines, which together with x-axis
 * forms a container, such that the container contains the most water.

 * Note: You may not slant the container.
 */

#include <iostream>
#include <vector>

using namespace std;

//int maxArea(vector<int> &height){
//    int maxcap = 0;
//    size_t left = 0, right = height.size()-1;
//
//    for (auto ileft = height.begin(); ileft < height.end(); ++ileft) {
//        for (auto irighr = ileft; irighr < height.end(); ++irighr) {
//            int cap = min(*ileft, *irighr) * (irighr - ileft);
//            maxcap = max(maxcap, cap);
//        }
//    }
//
//    return maxcap;
//}

int maxArea(vector<int> &height) {
    int maxcap = 0;
    size_t left = 0, right = height.size() - 1;

    while (left < right) {
        int cap = (right - left) * min(height[left], height[right]);
        maxcap = max(cap, maxcap);

        if (height[left] < height[right])
            ++left;
        else 
            --right;
    }
    return maxcap;
}