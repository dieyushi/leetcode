/* 
* Swap Nodes in Pairs
* Given a linked list, swap every two adjacent nodes and return its head.
 
* For example,
* Given 1->2->3->4, you should return the list as 2->1->4->3.
 
* Your algorithm should use only constant space. You may not modify the
* values in the list, only nodes itself can be changed.
*/
 
#include "leetcode.h"
#include <iostream>
 
using namespace std;
 
ListNode *swapNodesinPairs(ListNode *head) {
    ListNode *curr = head, *tmp = 0, *next = 0, *pre = 0;
    if (curr && curr->next)
        head = curr->next;
    while(curr) {
        if (curr->next == 0) return head;
        next = curr->next;
        if (pre != 0) pre->next = next;
        tmp = next->next;
        next->next = curr;
        curr->next = tmp;
        pre = curr;
        curr = curr->next;
    }
    return head;
}