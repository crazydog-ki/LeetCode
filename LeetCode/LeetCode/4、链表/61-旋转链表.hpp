// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

#pragma mark - 方法一: 一次遍历=>链表长度 + 两段拼接
ListNode * rotateRight(ListNode *head, int k) {
    if (!head || !head->next) return head;
    // 获得链表的长度
    int length = 0;
    ListNode *t = head;
    ListNode *m = head;
    while (t) {
        length++;
        t = t->next;
        if (t) m = t; // m指向链表尾部
    }
    
    // 重新定位k值
    if (length <= k) k = k % length;
    if (k == 0) return head;
    
    ListNode *p = head;
    ListNode *q = nullptr;
    for (int i = 0; i < length-k-1; i++) p = p->next;
    q = p->next;
    
    // 连接
    p->next = nullptr;
    m->next = head;
    
    return q;
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
    
    
    printNode(rotateRight(l1, 2));
}
