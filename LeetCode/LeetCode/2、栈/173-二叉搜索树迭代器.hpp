// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <stack>
#include <queue>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#pragma mark - 方法二: 中序遍历二叉搜索树, 容器保存
class BSTIterator2 {
private:
    queue<int> Q;
    /// 借助栈, 中序遍历
    void inorder(TreeNode *root) {
        stack<TreeNode *> S;
        while (true) {
            if (root) { // 左侧链
                S.push(root);
                root = root->left;
            } else if (!S.empty()) {
                root = S.top(); S.pop();
                Q.push(root->val);
                root = root->right;
            } else break;
        }
    }
public:
    /// 初始化
    BSTIterator2(TreeNode *root) {
        inorder(root);
    }
    
    /// 下一个最小的元素
    int next() {
        int tmp = Q.front();
        Q.pop();
        return tmp;
    }
    
    /// 是否存在下一个最小的元素
    bool hasNext() {
        return !Q.empty();
    }
};

#pragma mark - 方法一: 栈
class BSTIterator1 {
private:
    stack<TreeNode *> S;
    TreeNode *cur;
public:
    /// 初始化
    BSTIterator1(TreeNode *root) {
        cur = root;
        while (cur != nullptr) { // 左侧链入栈
            S.push(cur);
            cur = cur->left;
        }
    }
    
    /// 下一个最小的元素
    int next() {
        cur = S.top();
        S.pop();
        int res = cur->val;
        cur = cur->right;
        while (cur != nullptr) { // 左侧链入栈
            S.push(cur);
            cur = cur->left;
        }
        return res;
    }
    
    /// 是否存在下一个最小的元素
    bool hasNext() {
        return !S.empty();
    }
};
