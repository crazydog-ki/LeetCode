// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

ListNode * deleteDuplicates(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *start = head;
    ListNode *cur = head->next;
    while (cur) {
        if (cur->val != start->val) {
            start->next = cur;
            start = cur;
        }
        cur = cur->next;
    }
    if (start) start->next = cur;
    return head;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(2);
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(5);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    
    printNode(deleteDuplicates(l1));
}
