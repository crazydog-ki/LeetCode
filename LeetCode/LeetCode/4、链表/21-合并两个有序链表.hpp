// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *res = nullptr;
    if (l1->val <= l2->val) {
        res = l1;
        l1 = l1->next;
    } else {
        res = l2;
        l2 = l2->next;
    }
    ListNode *cur = res; // 当前指针
    while (l1 || l2) {
        if (!l1) { // 链表l1为NULL
            cur->next = l2;
            l2 = l2->next;
        } else if (!l2) { // 链表l2为NULL
            cur->next = l1;
            l1 = l1->next;
        } else if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    return res;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(3);
    ListNode *l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(4);
    ListNode *l6 = new ListNode(6);
    l4->next = l5;
    l5->next = l6;
    
    ListNode *res = mergeTwoLists(l1, l4);
    printNode(res);
}
