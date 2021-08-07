// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"
#include <stack>

/**
给你一个链表，删除链表的倒数第n个结点，并且返回链表的头结点。
进阶：你能尝试使用一趟扫描实现吗？
 
提示：
1. 链表中结点的数目为 sz
2. 1 <= sz <= 30
3. 0 <= Node.val <= 100
4. 1 <= n <= sz
 */

#pragma mark - 方法1-两遍扫描
ListNode* removeNthFromEnd1(ListNode* head, int n) {
    ListNode* cur = head;
    int len = 0;
    while (cur != nullptr) {
        len++;
        cur = cur->next;
    }
    
    ListNode* mask = new ListNode(-1, head);
    cur = mask;
    int left = len-n;
    while (left--) cur = cur->next;
    if (cur->next) cur->next = cur->next->next;
    
    ListNode* res = mask->next;
    delete mask;
    return res;
}

#pragma mark - 方法2-双指针
ListNode* removeNthFromEnd2(ListNode* head, int n) {
    ListNode* front = head;
    ListNode* back = head;
    while (n--) front = front->next;
    /// 删除首节点的场景
    if (!front) return head->next;
    while (front->next) {
        front = front->next;
        back = back->next;
    }
    back->next = back->next->next;
    return head;
}

#pragma mark - 方法3-栈
ListNode* removeNthFromEnd3(ListNode* head, int n) {
    ListNode* mask = new ListNode(-1, head);
    stack<ListNode*> S;
    ListNode* cur = mask;
    while (cur) {
        S.push(cur);
        cur = cur->next;
    }
    
    while (n--) S.pop();
    ListNode* top = S.top();
    top->next = top->next->next;
    ListNode* res = mask->next;
    delete mask;
    return res;
}
