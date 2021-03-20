// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <stack>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - 方法一: 栈
vector<int> inorderTraversal(TreeNode *root) {
    stack<TreeNode *> S;
    vector<int> res;
    while (true) {
        if (root) {
            S.push(root);
            root = root->left; // 深入遍历左子树
        } else if (!S.empty()) {
            root = S.top(); S.pop();
            res.push_back(root->val); // 访问节点
            root = root->right; // 深入遍历右子树
        } else break;
    }
    return res;
}
