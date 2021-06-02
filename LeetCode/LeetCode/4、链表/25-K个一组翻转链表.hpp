// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include "tools.h"

/// 单链表翻转
ListNode * reverseList(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *p = head;
    ListNode *q = head->next;
    ListNode *tmp = nullptr;
    while (q) {
        tmp = q->next;
        q->next = p;
        p = q;
        q = tmp;
    }
    return p;
}

ListNode * reverseKGroup(ListNode *head, int k) {
    // 卫兵指针
    ListNode *t = new ListNode(-1);
    t->next = head;
    
    // 维护4个指针
    ListNode *header = t;
    ListNode *tailer = nullptr;
    ListNode *start = nullptr;
    ListNode *end = t;
    
    while (end->next) {
        for (int i = 0; i<k && end; i++) end = end->next;
        if (!end) break; // 不够k
        // 就位
        start = header->next;
        tailer = end->next;
        end->next = nullptr;
        // 连接
        header->next = reverseList(start);
        start->next = tailer;
        // 重置
        header = start;
        end = start;
    }
    return t->next;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    ListNode *res = reverseKGroup(l1, 2);
    printNode(res);
}

