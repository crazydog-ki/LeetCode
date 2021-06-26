// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

ListNode * deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *res = new ListNode(-1);
    res->next = head;
    ListNode *header = res;
    ListNode *tailer = head->next;
    ListNode *start = head;
    ListNode *end = head;
    while (tailer) {
        if (tailer->val == start->val) end = tailer;
        else {
            if (start == end) header = start;
            else header->next = tailer;
            start = tailer;
            end = tailer;
        }
        tailer = tailer->next;
    }
    if (start != end) header->next = tailer;
    return res->next;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(6);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    
    printNode(deleteDuplicates(l1));
}
