// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

#pragma mark - 方法二: 改进版
ListNode * addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode *head = new ListNode(0);
    ListNode *cur = head;
    int upNum = 0, sum = 0;
    while (l1 || l2) {
        sum = (l1?l1->val:0) + (l2?l2->val:0) + upNum;
        cur->val = sum % 10;
        upNum = sum / 10;
        l1 = l1 ? l1->next : NULL;
        l2 = l2 ? l2->next : NULL;
        if (l1 || l2) {
            cur->next = new ListNode(0);
            cur = cur->next;
        }
    }
    if (upNum) cur->next = new ListNode(1);
    return head;
}

#pragma mark - 方法一: 数组存储 => 构造链表
ListNode * addTwoNumbers1(ListNode *l1, ListNode *l2) {
    bool isUpBit = false;
    int tmpNum = 0;
    vector<int> nums;
    while (l1!=NULL || l2!=NULL) {
        if (l1 == NULL) l1 = new ListNode(0);
        if (l2 == NULL) l2 = new ListNode(0);
        tmpNum = l1->val+l2->val;
        if (tmpNum<10 && !isUpBit) nums.push_back(tmpNum); // 小于10不进位
        else if (10<=tmpNum && !isUpBit) { // 大于10不进位
            nums.push_back(tmpNum-10);
            isUpBit = true;
        } else if (tmpNum<9 && isUpBit) { // 小于9进位
            nums.push_back(tmpNum+1);
            isUpBit = false;
        } else if (9<=tmpNum && isUpBit) { // 大于9进位
            nums.push_back(tmpNum-9);
        }
        l1 = l1->next;
        l2 = l2->next;
    }
    if (isUpBit) nums.push_back(1);
    ListNode *head = new ListNode(nums[0]);
    ListNode *cur = head;
    for (int i = 1; i < nums.size(); i++) {
        cur->next = new ListNode(nums[i]);
        cur = cur->next;
    }
    return head;
}

void test() {
    ListNode *l1 = new ListNode(2);
    ListNode *l2 = new ListNode(4);
    ListNode *l3 = new ListNode(3);
//    ListNode *l1 = new ListNode(5);
//    ListNode *l2 = new ListNode(4);
//    ListNode *l3 = new ListNode(5);
    l1->next = l2;
    l2->next = l3;
    
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(6);
    ListNode *l6 = new ListNode(4);
//    ListNode *l4 = new ListNode(6);
//    ListNode *l5 = new ListNode(7);
//    ListNode *l6 = new ListNode(8);
//    ListNode *l7 = new ListNode(1);
    l4->next = l5;
    l5->next = l6;
//    l6->next = l7;
    addTwoNumbers(l1, l4);
}
