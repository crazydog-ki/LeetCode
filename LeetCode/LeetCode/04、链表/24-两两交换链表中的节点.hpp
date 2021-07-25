// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

/**两两交换链表中的节点
给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 
提示：
1. 链表中节点的数目在范围[0, 100]内
2. 0 <= Node.val <= 100
 */

#pragma mark - 方法1-迭代
ListNode* swapPairs1(ListNode* head) {
    ListNode* mask = new ListNode(-1);
    mask->next = head;
    ListNode* cur = mask;
    while (cur->next!=nullptr && cur->next->next!=nullptr) {
        ListNode* one = cur->next;
        ListNode* two = cur->next->next;
        cur->next = two;
        one->next = two->next;
        two->next = one;
        cur = one;
    }
    
    ListNode* ret = mask->next;
    delete mask;
    return ret;
}

#pragma mark - 方法2-递归
ListNode* swapPairs(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode* node = head->next;
    head->next = swapPairs(node->next);
    node->next = head;
    return node;
}
