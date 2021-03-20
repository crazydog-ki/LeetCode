// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <string>
#include <stack>
#include <vector>

#pragma mark - 方法一: 栈
int evalRPN(vector<string> &tokens) {
    stack<int> S;
    int left = 0;
    int right = 0;
    for (int i = 0; i < tokens.size(); i++) {
        if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") { // 操作数
            S.push(stoi(tokens[i]));
        } else { // 操作符
            right = S.top(); S.pop();
            left = S.top(); S.pop();
            if (tokens[i] == "+") S.push(left + right);
            else if (tokens[i] == "-") S.push(left - right);
            else if (tokens[i] == "*") S.push(left * right);
            else if (tokens[i] == "/") S.push(left / right);
        }
    }
    return S.top();
}

void test() {
    vector<string> tokens = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens) << endl;
}
