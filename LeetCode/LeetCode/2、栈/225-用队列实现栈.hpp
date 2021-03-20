// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <queue>

#pragma mark - 方法一: 两个队列, 插入元素时借助临时队列中转
class MyStack {
private:
    queue<int> Q;
    queue<int> tmpQ;
public:
    /// 初始化
    MyStack() { }
    
    /// 插入
    void push(int x) {
        while (!Q.empty()) { // 队列中元素进入临时队列
            tmpQ.push(Q.front());
            Q.pop();
        }
        Q.push(x);
        while (!tmpQ.empty()) { // 临时队列中元素进入队列
            Q.push(tmpQ.front());
            tmpQ.pop();
        }
    }
    
    /// 删除
    int pop() {
        int top = Q.front();
        Q.pop();
        return top;
    }
    
    /// 访问
    int top() {
        return Q.front();
    }
    
    /// 判空
    bool empty() {
        return Q.empty();
    }
};

void test() {
    MyStack *S = new MyStack();
    S->push(1);
    S->push(2);
    S->push(3);
    S->push(4);
    cout << S->top() << endl;
    S->pop();
    cout << S->top() << endl;
}
