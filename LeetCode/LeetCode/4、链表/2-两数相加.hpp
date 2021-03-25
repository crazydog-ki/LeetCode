// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**两数相加
 1. 两个非空的链表，表示两个非负整数。它们每位数字都是按照逆序方式存储的，并且每个节点只能存储一位数字。
 2. 请你将两个数相加，并以相同形式返回一个表示和的链表。
 3. 你可以假设除了数字0之外，这两个数都不会以0开头。
 */
#pragma mark - 方法1-短链对齐补零
ListNode* addTwoNumbers1(ListNode* l1, ListNode* l2) {
    int len1 = 1, len2 = 1;
    ListNode *ptr1 = l1, *ptr2 = l2;
    
    // 获取链表长度
    while (ptr1->next) {
        len1++;
        ptr1 = ptr1->next;
    }
    while (ptr2->next) {
        len2++;
        ptr2 = ptr2->next;
    }
    
    // 短链末尾补零
    int delta = (len1 <= len2) ? len2-len1 : len1-len2;
    ListNode *tmpPtr = (len1 <= len2) ? ptr1 : ptr2;
    while (delta--) {
        tmpPtr->next = new ListNode(0);
        tmpPtr = tmpPtr->next;
    }
    
    // 指针复位
    ptr1 = l1;
    ptr2 = l2;
    
    ListNode *resPtr = new ListNode(-1);
    ListNode *curPtr = resPtr;
    int count = 0; // 记录进位, 1代表进位, 0代表不进位
    int sum = 0; // 记录相加结果
    while (ptr1 && ptr2) {
        sum = count + ptr1->val + ptr2->val;
        curPtr->next = new ListNode(sum % 10);
        curPtr = curPtr->next;
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
        count = (9<sum) ? 1 : 0;
    }
    
    if (count) { // 最后还有进位
        curPtr->next = new ListNode(1);
        curPtr = curPtr->next;
    }
    
    return resPtr->next;
}

#pragma mark - 方法2-短链不对齐补零
ListNode* addTwoNumbers2(ListNode* l1, ListNode* l2) {
    ListNode *resPtr = new ListNode(-1);
    ListNode *curPtr = resPtr;
    int carry = 0;
    while (l1 || l2 || carry) {
        if (l1) {carry += l1->val; l1 = l1->next;}
        if (l2) {carry += l2->val; l2 = l2->next;}
        curPtr = curPtr->next = new ListNode(carry % 10);
        carry /= 10; // 记录进位
    }
    
    return resPtr->next;
}

void test() {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
    l1->next = l2;
    l2->next = l3;
    
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(6);
    ListNode *l6 = new ListNode(9);
    l4->next = l5;
    l5->next = l6;
    
    ListNode *resPtr = addTwoNumbers2(l1, l4);
    printNode(resPtr);
}
