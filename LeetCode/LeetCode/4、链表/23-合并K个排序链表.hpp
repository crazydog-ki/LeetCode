// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include "tools.h"
#include <queue>

ListNode * mergeTwoLists(ListNode *l1, ListNode *l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode *res = nullptr;
    if (l1->val <= l2->val) {
        res = l1;
        l1 = l1->next;
    } else {
        res = l2;
        l2 = l2->next;
    }
    ListNode *cur = res; // 当前指针
    while (l1 || l2) {
        if (!l1) { // 链表l1为NULL
            cur->next = l2;
            l2 = l2->next;
        } else if (!l2) { // 链表l2为NULL
            cur->next = l1;
            l1 = l1->next;
        } else if (l1->val <= l2->val) {
            cur->next = l1;
            l1 = l1->next;
        } else {
            cur->next = l2;
            l2 = l2->next;
        }
        cur = cur->next;
    }
    return res;
}

#pragma mark - 方法二: 队列
ListNode * mergeKLists(vector<ListNode*> &lists) {
    int size = (int)lists.size();
    if (size == 0) return nullptr;
    if (size == 1) return lists[0];
    
    queue<ListNode *> Q;
    for (int i = 0; i < size; i++) Q.push(lists[i]);
    
    ListNode *l1 = nullptr;
    ListNode *l2 = nullptr;
    while (1 < Q.size()) {
        l1 = Q.front(); Q.pop();
        l2 = Q.front(); Q.pop();
        Q.push(mergeTwoLists(l1, l2));
    }
    return Q.front();
}

#pragma mark - 方法一: 数组
ListNode * mergeKLists1(vector<ListNode*> &lists) {
    int size = (int)lists.size();
    if (size == 0) return nullptr;
    if (size == 1) return lists[0];
    if (size == 2) return mergeTwoLists(lists[0], lists[1]);
    
    int mi = size / 2;
    vector<ListNode *> sub1;
    vector<ListNode *> sub2;
    for (int i = 0; i < mi; i++) sub1.push_back(lists[i]);
    for (int j = mi; j < size; j++) sub2.push_back(lists[j]);
    
    ListNode *l1 = mergeKLists(sub1);
    ListNode *l2 = mergeKLists(sub2);
    return mergeTwoLists(l1, l2);
}
