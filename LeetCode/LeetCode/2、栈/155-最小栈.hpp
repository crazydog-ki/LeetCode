// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <stack>

#pragma mark - 方法二: 栈+优化内存
class MinStack2 {
private:
    stack<int> S;
    stack<int> minS;
public:
    MinStack2() { }
    
    void push(int x) {
        S.push(x);
        if (minS.empty() || x<=getMin()) minS.push(x);
    }
    
    void pop() {
        if (S.top() == getMin()) minS.pop();;
        S.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

#pragma mark - 方法一: 栈
class MinStack {
private:
    stack<int> S;
    stack<int> minS;
public:
    MinStack() { }
    
    void push(int x) {
        S.push(x);
        if (minS.empty() || x<=minS.top()) minS.push(x);
        else minS.push(minS.top());
    }
    
    void pop() {
        S.pop();
        minS.pop();
    }
    
    int top() {
        return S.top();
    }
    
    int getMin() {
        return minS.top();
    }
};

void test() {
    MinStack S = MinStack();
    S.push(-2);
    S.push(0);
    cout << S.getMin() << endl;
}
