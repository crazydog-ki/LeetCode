// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include "tools.h"

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

ListNode * reverseBetween(ListNode *head, int m, int n) {
    if (!head || !head->next || m==n) return head;
    // 4个指针
    ListNode *pre = new ListNode(-1); // 卫兵节点
    ListNode *start = nullptr;
    ListNode *end = nullptr;
    ListNode *las = nullptr;
    
    pre->next = head;
    ListNode *res = pre;  // 结果节点
    
    ListNode *cur = head; // 当前节点
    n = n - m;
    while (--m) {
        pre = cur;
        cur = cur->next;
    }
    start = cur;
    while (n--) cur = cur->next;
    end = cur;
    las = end->next;
    end->next = nullptr; // 便于反转
    
    // 反转链表+连接链表
    pre->next = reverseList(start);
    start->next = las;
    
    return res->next;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    ListNode *l5 = new ListNode(5);
    ListNode *l6 = new ListNode(6);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    l5->next = l6;
    
    printNode(reverseBetween(l1, 2, 4));
}
