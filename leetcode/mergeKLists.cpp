/*
 * Merge k Sorted Lists
 * Merge k sorted linked lists and return it as one sorted list. Analyze and
 * describe its complexity.
 */

#include <iostream>
#include "leetcode.h"

using namespace std;

ListNode *mergeKLists(vector<ListNode *> &lists) {
    if (lists.size() == 0) return 0;
    ListNode *p = lists[0];
    for (int i=1; i<lists.size(); i++) {
        p = mergeTwoLists(p, lists[i]);
    }
    return p;
}