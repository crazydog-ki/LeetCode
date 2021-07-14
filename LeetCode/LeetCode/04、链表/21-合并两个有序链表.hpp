// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"

/**合并两个有序链表
将两个升序链表合并为一个新的升序链表并返回。新链表是通过拼接给定的两个链表的所有节点组成的。
 
提示：
1. 两个链表的节点数目范围是[0, 50]
2. -100 <= Node.val <= 100
3. l1和l2均按非递减顺序排列
 */

#pragma mark - 方法1-迭代
ListNode* mergeTwoLists1(ListNode* l1, ListNode* l2) {
    ListNode *head = new ListNode(-1);
    ListNode *cur = head;
    while (l1 || l2) {
        if (!l1) {
            cur->next = l2;
            break;
        }
        
        if (!l2) {
            cur->next = l1;
            break;
        }
        
        if (l1->val < l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    return head->next;
}

#pragma mark - 方法2-递归
ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (l1 == nullptr) {
        return l2;
    } else if (l2 == nullptr) {
        return l1;
    } else if (l1->val < l2->val) {
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    } else {
        l2->next = mergeTwoLists(l1, l2->next);
        return l2;
    }
}
