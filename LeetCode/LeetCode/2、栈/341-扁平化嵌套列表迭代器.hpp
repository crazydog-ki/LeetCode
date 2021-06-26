// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <stack>
#include <vector>
#include <queue>

class NestedInteger { // [[1, 1], 2, [1, 1]]
public:
    bool isInteger() const;
    int getInteger() const;
    const vector<NestedInteger> &getList() const;
};

#pragma mark - 方法一: 队列
class NestedIterator {
private:
    queue<int> Q;
    /// 装填队列
    void fillQueue(const vector<NestedInteger> &nestedList) {
        for(auto &item: nestedList) {
            if (item.isInteger()) {
                Q.push(item.getInteger());
            } else {
                fillQueue(item.getList());
            }
        }
    }
public:
    /// 迭代器初始化
    NestedIterator(vector<NestedInteger> &nestedList) {
        fillQueue(nestedList);
    }
    
    /// 获取元素
    int next() {
        int cur = Q.front();
        Q.pop();
        return cur;
    }
    
    /// 存在元素与否
    bool hasNext() {
        return !Q.empty();
    }
};
