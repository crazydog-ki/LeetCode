// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <string>
#include <stack>

class NestedInteger { // [123,[456,[789]]]
public:
    NestedInteger() {}
    
    NestedInteger(int value) {}
    
    bool isInteger() const;
    
    int getInteger() const;
    
    void setInteger(int value);
    
    void add(const NestedInteger &ni) {}
    
    const vector<NestedInteger> &getList() const;
};

#pragma mark - 方法二: 栈 => 优化版
NestedInteger deserialize(string s) {
    if (s.empty()) return NestedInteger();
    if (s[0] != '[') return NestedInteger(stoi(s));
    
    stack<NestedInteger> S;
    int start = 0;
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') {
            S.push(NestedInteger());
            start = i+1;
        }
        else if (s[i]==',' || s[i]==']') {
            if(start < i) S.top().add(NestedInteger(stoi(s.substr(start, i-start))));
            start = i+1;
            if (s[i] == ']') {
                if (1 < S.size()) {
                    NestedInteger t = S.top();
                    S.pop();
                    S.top().add(t);
                }
            }
        }
    }
    return S.top();
}

#pragma mark - 方法一: 栈
NestedInteger deserialize1(string s) {
    if (s.empty()) return NestedInteger();
    if (s[0] != '[') return NestedInteger(stoi(s));

    stack<NestedInteger> S;
    string curStr = "";
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '[') { // 左括号, 创建NestedInteger对象进栈
            auto ni = NestedInteger();
            S.push(ni);
        }
        else if (s[i] == ']') { // 右括号
            NestedInteger top = S.top();
            if (curStr != "") top.add(NestedInteger(stoi(curStr))); // curStr是数字
            S.pop();
            if (S.empty()) return top;
            else {
                NestedInteger &nextTop = S.top();
                nextTop.add(top);
            }
            curStr = "";
        }
        else if (s[i]=='-' || ('0'<=s[i] && s[i]<='9')) curStr += s[i]; // 数字
        else if (s[i] == ',') { // 逗号
            if (curStr != "") {
                NestedInteger &top = S.top();
                top.add(NestedInteger(stoi(curStr)));
                curStr = "";
            }
        }
    }
    return NestedInteger();
}


