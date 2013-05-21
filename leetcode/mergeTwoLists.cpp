/*
 * Merge Two Sorted Lists
 * Merge two sorted linked lists and return it as a new list. The new list
 * should be made by splicing together the nodes of the first two lists.
 */

#include <iostream>
#include "leetcode.h"

using namespace std;

ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
    ListNode *ret = new ListNode(0);
    ListNode *tmp = ret;
    while (l1 != 0 && l2 != 0) {
        if (l1->val < l2->val) {
            tmp->next = l1;
            l1 = l1->next;
        } else {
            tmp->next = l2;
            l2 = l2->next;
        }
        tmp = tmp->next;
    }
    if (l1) {
        tmp->next = l1;
    }
    if (l2) {
        tmp->next = l2;
    }
    ret = ret->next;
    return ret;
}