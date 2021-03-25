// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include "tools.h"
#include <vector>

#pragma mark - 方法四: 中序遍历模拟
class Solution {
private:
    ListNode *head;
public:
    TreeNode * helper(int left, int right) {
        if (right < left) return nullptr;
        int mid = (left+right) / 2;
        // 左
        TreeNode *lc = helper(left, mid-1);
        // 根 => 中序遍历的反过程
        TreeNode *root = new TreeNode(this->head->val);
        root->left = lc;
        this->head = this->head->next;
        // 右
        root->right = helper(mid+1, right);
        return root;
    }
    TreeNode * sortedListToBST(ListNode *head) {
        // 链表大小
        ListNode *t = head;
        int size = 0;
        while (t) {
            size++;
            t = t->next;
        }
        
        this->head = head;
        return helper(0, size-1);
    }
};

#pragma mark - 方法三: 递归3 => 链表转数组, 空间换时间
class Solution1 {
private:
    vector<int> nums;
public:
    /// 构建数组
    void constructNums(ListNode *head) {
        while (head) {
            nums.push_back(head->val);
            head = head->next;
        }
    }
    
    TreeNode * helper(int left, int right) {
        if (right < left) return nullptr;
        if (left == right) return new TreeNode(nums[left]);
        
        int mid = (left+right) / 2;
        TreeNode *node = new TreeNode(nums[mid]);
        
        node->left = helper(left, mid-1);
        node->right = helper(mid+1, right);
        return node;
    }

    TreeNode * sortedListToBST3(ListNode *head) {
        constructNums(head);
        return helper(0, (int)nums.size()-1);
    }
};

#pragma mark - 方法二: 递归2
TreeNode * helper(ListNode *head, ListNode *tail) { // tail是哨兵节点
    if (!head || head == tail) return nullptr;
    ListNode *slow = head, *fast = head;
    while (fast->next!=tail && fast->next->next!=tail) {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *cur = new TreeNode(slow->val);
    cur->left = helper(head, slow);
    cur->right = helper(slow->next, tail);
    return cur;
}

TreeNode * sortedListToBST2(ListNode *head) {
    if (!head) return nullptr;
    return helper(head, nullptr);
}

#pragma mark - 方法一: 递归1
TreeNode * sortedListToBST1(ListNode *head) {
    if (!head) return nullptr;
    if (!head->next) return new TreeNode(head->val);
    // 哨兵节点, 保证slowPre不为空
    ListNode *start = new ListNode(-1);
    start->next = head;
    
    ListNode *slow = start, *fast = start, *slowPre = nullptr;
    while (fast && fast->next) { // 找中点
        slowPre = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    slowPre->next = nullptr;
    root->left = sortedListToBST1(start->next);
    root->right = sortedListToBST1(slow->next);
    return root;
}

void test() {
    ListNode *l1 = new ListNode(-10);
    ListNode *l2 = new ListNode(-3);
    ListNode *l3 = new ListNode(0);
    ListNode *l4 = new ListNode(5);
    ListNode *l5 = new ListNode(9);
    
    l1->next = l2;
    l2->next = l3;
    l3->next = l4;
    l4->next = l5;
    
    Solution *s = new Solution();
    s->sortedListToBST(l1);
}
