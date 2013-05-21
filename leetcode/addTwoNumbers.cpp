/*
 * Add Two Numbers
 *You are given two linked lists representing two non-negative numbers. 
 *The digits are stored in reverse order and each of their nodes contain a 
 *single digit. Add the two numbers and return it as a linked list.
 *Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
 *Output: 7 -> 0 -> 8
 */
#include "leetcode.h"

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    long long sum1 = 0, sum2 = 0;
    for (int i=0; l1; l1 = l1->next) {
        sum1 = sum1 + l1->val * std::pow(10,i);
        i++;
    }

    for (int i=0; l2; l2 = l2->next) {
        sum2 = sum2 + l2->val * std::pow(10,i);
        i++;
    }

    long long sum = sum1 + sum2;
    ListNode *l3 = 0;
    ListNode *tail = 0;
    if (sum == 0){
        l3 = new ListNode(0);
        return l3;
    }
    while (sum) {
        long long rem = sum%10;
        sum = sum/10;
        ListNode *temp = new ListNode(rem);
        if (l3) {
            tail->next = temp;
            tail = temp;
        } else {
            l3 = temp;
            tail = temp;
        }
    }
    return l3;
}