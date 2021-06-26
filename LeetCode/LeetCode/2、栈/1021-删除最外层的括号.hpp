// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>
#include <stack>

#pragma mark - 方法二: 字符串模拟栈
string removeOuterParentheses2(string S) {
    string res;
    int leftCount = 0;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == '(') {
            if (leftCount != 0) res.push_back(S[i]);
            leftCount++;
        } else if (S[i] == ')') {
            leftCount--;
            if (leftCount != 0) res.push_back(S[i]);
        }
    }
    return res;
}

#pragma mark - 方法一: 栈
string removeOuterParentheses(string S) {
    string res = "";
    stack<char> myStack;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ')') myStack.pop();
        if (!myStack.empty()) res += S[i];
        if (S[i] == '(') myStack.push(S[i]);
     }
    return res;
}

void test() {
    string S = "(()())(())";
    cout << removeOuterParentheses(S) << endl;
}
