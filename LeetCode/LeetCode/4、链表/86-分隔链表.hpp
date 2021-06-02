// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include "tools.h"

ListNode * partition(ListNode *head, int x) {
    // 卫兵节点
    ListNode *p = new ListNode(-1);
    ListNode *m = p;
    ListNode *q = new ListNode(-1);
    ListNode *k = q;
    while (head) {
        if (head->val < x) {
            p->next = head;
            p = p->next;
        } else {
            q->next = head;
            q = q->next;
        }
        head = head->next;
    }
    q->next = nullptr;
    p->next = k->next;
    return m->next;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(2);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(2);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    
    ListNode *res = partition(l1, 3);
    printNode(res);
}
