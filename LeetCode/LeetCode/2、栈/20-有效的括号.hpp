// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <stack>
#include <string>

#pragma mark - 方法一: 栈
bool isValid(string s) {
    stack<char> S;
    for (int i = 0; i < s.length(); i++) {
        if (s[i]=='(' || s[i]=='[' || s[i]=='{') S.push(s[i]);
        else if (!S.empty()) {
            switch (s[i]) {
                case ')':
                    if (S.top() != '(') return false;
                    break;
                case ']':
                    if (S.top() != '[') return false;
                    break;
                case '}':
                    if (S.top() != '{') return false;
                    break;
                default:
                    break;
            }
            S.pop();
        }
        else return false;
    }
    return S.empty();
}

void test() {
    // string str = "(){}{}[]";
    string str = "()]";
    cout << isValid(str) << endl;
}
