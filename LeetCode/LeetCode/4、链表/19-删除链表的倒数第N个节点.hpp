// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#pragma mark - 方法二: 双指针+一轮遍历
ListNode * removeNthFromEnd(ListNode *head, int n) {
    ListNode *front = head;
    ListNode *back = head;
    // front先走n步
    while (n--) front = front->next;
    if (front == NULL) return head->next; // 删除首节点的情况
    while (front->next) {
        front = front->next;
        back = back->next;
    }
    back->next = back->next->next;
    return head;
}

#pragma mark - 方法一: 链表长度+两轮遍历
ListNode * removeNthFromEnd1(ListNode *head, int n) {
    if (!head->next) return NULL;
    int length = 0;
    ListNode *cur1 = head;
    ListNode *cur2 = head;
    while (cur1) {
        cur1 = cur1->next;
        length++;
    }
    while (n+1 < length) {
        cur2 = cur2->next;
        length--;
    }
    // 删除的是首节点
    if (length == n) return head->next;
    // 删除的是非首节点 => 特点: 首节点的前驱为NULL
    else if (length != n) cur2->next = cur2->next->next;
    return head;
}

void test() {
    ListNode *l1 = new ListNode(1);
    ListNode *l2 = new ListNode(2);
//    ListNode *l3 = new ListNode(3);
    l1->next = l2;
//    l2->next = l3;
    removeNthFromEnd(l1, 2);
}
