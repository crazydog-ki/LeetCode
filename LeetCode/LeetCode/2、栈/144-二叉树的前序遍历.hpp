// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <stack>
#include "tools.h"

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - 方法一: 栈
vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) return res;
    stack<TreeNode *> S;
    S.push(root);
    TreeNode *cur = nullptr;
    while (!S.empty()) {
        cur = S.top();
        S.pop();
        res.push_back(cur->val);
        if (cur->right) S.push(cur->right);
        if (cur->left) S.push(cur->left);
    }
    return res;
}

void test() {
    TreeNode *root = new TreeNode(1);
    TreeNode *second = new TreeNode(2);
    TreeNode *third = new TreeNode(3);
    TreeNode *fourth = new TreeNode(4);
    TreeNode *fifth = new TreeNode(5);
    root->left = second; root->right = third;
    second->left = fourth; third->right = fifth;
    vector<int> res = preorderTraversal(root);
    printVectors(res);
}
