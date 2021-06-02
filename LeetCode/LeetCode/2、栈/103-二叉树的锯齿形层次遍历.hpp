// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - 方法二: 队列
vector<vector<int>> zigzagLevelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    queue<TreeNode *> Q;
    Q.push(root);
    int count = 0;    // 记录每一层节点的个数
    vector<int> item; // 每一层的节点, 放到一个item中
    while (!Q.empty()) {
        count = (int)Q.size();
        while (count--) {
            TreeNode *t = Q.front();
            Q.pop();
            item.push_back(t->val);
            if (t->left) Q.push(t->left);
            if (t->right) Q.push(t->right);
        }
        res.push_back(item);
        item.clear();
    }
    // 反转奇数层节点
    for(int i = 1;i < res.size();i += 2){
        reverse(res[i].begin(), res[i].end());
    }
    return res;
}

#pragma mark - 方法一: 两个栈
vector<vector<int>> zigzagLevelOrder1(TreeNode *root) {
    vector<vector<int>> res;
    if (!root) return res;
    stack<TreeNode *> S1, S2;
    S1.push(root);
    TreeNode *cur = nullptr;
    vector<int> part;
    while (true) {
        while (!S1.empty()) {
            cur = S1.top();
            S1.pop();
            part.push_back(cur->val);
            if (cur->left) S2.push(cur->left);
            if (cur->right) S2.push(cur->right);
        }
        if (!part.empty()) {
            res.push_back(part);
            part.clear();
        } else break;
        
        while (!S2.empty()) {
            cur = S2.top();
            S2.pop();
            part.push_back(cur->val);
            if (cur->right) S1.push(cur->right);
            if (cur->left) S1.push(cur->left);
        }
        if (!part.empty()) {
            res.push_back(part);
            part.clear();
        } else break;
    }
    return res;
}
