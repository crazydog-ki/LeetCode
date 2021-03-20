// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <stack>

#pragma mark - 方法一: 两个栈, 插入元素时借助临时栈中转
class MyQueue {
private:
    stack<int> S;
    stack<int> tmpS;
public:
    /// 初始化
    MyQueue() { }
    
    /// 插入
    void push(int x) {
        while (!S.empty()) {
            tmpS.push(S.top());
            S.pop();
        }
        S.push(x);
        while (!tmpS.empty()) {
            S.push(tmpS.top());
            tmpS.pop();
        }
    }
    
    /// 删除
    int pop() {
        int top = S.top();
        S.pop();
        return top;
    }
    
    /// 访问
    int peek() {
        return S.top();
    }
    
    /// 判空
    bool empty() {
        return S.empty();
    }
};

void test() {
    MyQueue *Q = new MyQueue();
    Q->push(1);
    Q->push(2);
    Q->push(3);
    Q->push(4);
    Q->pop();
    cout << Q->peek() << endl;
}
