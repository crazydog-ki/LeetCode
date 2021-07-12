// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <vector>

#pragma mark - 数组
void printVectors(vector<int> &nums) {
    for (int i = 0; i < nums.size(); i++) {
        cout << nums[i] << ", ";
    }
    cout << endl;
}

#pragma mark - 链表
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

void printNode(ListNode *head) {
    while (head) {
        cout << head->val << ", ";
        head = head->next;
    }
    cout << endl;
}

#pragma mark - 二叉树
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - tip1 => 字符串数字相互转化
/*
 字符串 => 数字
 1. string => int   : int stoi(string)
 2. string => long  : long stol(string)
 3. string => float : float stof(string)
 4. string => double: double stod(string)
 
 数字 => 字符串
 string to_string(int\long\float\double);
 
 字符转小写 tolower('A')
 字符转大写 toupper('a')
 判断字符是否为字母 isalpha('A')
 */
