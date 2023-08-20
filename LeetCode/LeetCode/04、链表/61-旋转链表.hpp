// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

/**旋转链表
 给你一个链表的头节点head，旋转链表，将链表每个节点向右移动k个位置。
 */

#pragma mark - 方法1-常规
ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return nullptr;
    //处理k>list.size的情况
    ListNode* tmp = head;
    ListNode* lst = nullptr;
    int size = 0;
    while (tmp) {
        lst = tmp;
        tmp = tmp->next;
        size++;
    }
    k = k % size;
    if (k==0) return head; //k为0或者size整数倍
    k = size-k;
    
    ListNode* cur = head;
    ListNode* newHead = head;
    while (--k) {
        cur = cur->next;
    }
    newHead = cur->next;
    cur->next = nullptr;
    
    lst->next = head;
    
    return newHead;
}


