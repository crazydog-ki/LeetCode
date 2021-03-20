// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include "tools.h"

#pragma mark - 方法二: 递归
ListNode * swapPairs(ListNode *head) {
    if (!head || !head->next) return head;
    ListNode *node = head->next;
    head->next = swapPairs(node->next);
    node->next = head;
    return node;
}

#pragma mark - 方法一: 迭代
ListNode * swapPairs1(ListNode *head) {
    ListNode *pre = new ListNode(-1); // 添加首部节点
    pre->next = head;
    ListNode *cur = pre;
    ListNode *start = nullptr;
    ListNode *end = nullptr;
    while (cur->next && cur->next->next) {
        // 初始化
        start = cur->next;
        end = cur->next->next;
        // 连接
        cur->next = end;
        start->next = end->next;
        end->next = start;
        
        cur = start;
    }
    return pre->next;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
    ListNode *l3 = new ListNode(3);
    ListNode *l4 = new ListNode(4);
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    swapPairs(l1);
}
