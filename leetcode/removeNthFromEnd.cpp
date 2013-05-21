/* 
* Remove Nth Node From End of List
* Given a linked list, remove the nth node from the end of list and return its head.
* For example,
* Given linked list: 1->2->3->4->5, and n = 2.
* After removing the second node from the end, the linked list becomes 1->2->3->5.
* 
* Note:
* Given n will always be valid.
* Try to do this in one pass.
*/
#include "leetcode.h"
#include <iostream>

ListNode *removeNthFromEnd(ListNode *head, int n) {
    int len = 1;
    for (ListNode *iter = head; iter->next != 0; iter = iter->next) {
        len++;
    }
    if (n > len) return 0;
    if (n== len) return head->next;
    ListNode *it = head;
    for (int i=0; i!=len-n-1; i++) {
        it = it->next;
    }
    if (it->next)
        it->next = it->next->next;
    else 
        it->next = 0;
    return head;
}