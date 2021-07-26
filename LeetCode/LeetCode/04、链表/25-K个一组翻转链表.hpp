// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

/**K个一组翻转链表
给你一个链表，每k个节点一组进行翻转，请你返回翻转后的链表。
k是一个正整数，它的值小于或等于链表的长度。
如果节点总数不是k的整数倍，那么请将最后剩余的节点保持原有顺序。

进阶：
1. 你可以设计一个只使用常数额外空间的算法来解决此问题吗？
2. 你不能只是单纯的改变节点内部的值，而是需要实际进行节点交换。
 
提示：
1. 列表中节点的数量在范围sz内
2. 1 <= sz <= 5000
3. 0 <= Node.val <= 1000
4. 1 <= k <= sz
 */

#pragma mark - 方法1-递归
ListNode* reverseOneList(ListNode* head) {
    ListNode *guard = nullptr;
    while (head) {
        ListNode* next = head->next;
        head->next = guard;
        guard = head;
        head = next;
    }
    return guard;
}

ListNode* reverseKGroup1(ListNode* head, int k) {
    if (!head) return nullptr;
    ListNode* guard = new ListNode(-1);
    ListNode* tail = head;
    
    int count = k;
    while (--k) {
        if (tail->next) tail = tail->next;
        else return head;
    }
    
    ListNode* next = tail->next;
    tail->next = nullptr;
    guard->next = reverseOneList(head);
    head->next = reverseKGroup1(next, count);
    ListNode* ret = guard->next;
    delete guard;
    return ret;
}

#pragma mark - 方法2-迭代
ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* guard = new ListNode(-1);
    ListNode* ret = guard;
    
    ListNode* cur = head;
    ListNode* tail = head;
    while (cur) {
        int count = k;
        while (--count) {
            if (tail->next) tail = tail->next;
            else {
                guard->next = cur;
                return ret->next;
            }
        }
        
        ListNode* nex = nullptr;
        if (tail) {
            nex = tail->next;
            tail->next = nullptr; // 置为空，才能反转链表
        }
        
        guard->next = reverseOneList(cur);
        guard = cur;
        cur = nex;
        tail = nex;
    }
    // delete guard;
    return ret->next;
}
