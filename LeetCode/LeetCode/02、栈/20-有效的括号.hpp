// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include <string>
#include <stack>

/**有效的括号
给定一个只包括'('、')'、'{'、'}'、'['、']'的字符串s，判断字符串是否有效。
有效字符串需满足：
1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
 
提示：
1. 1 <= s.length <= 104
2. s 仅由括号 '()[]{}' 组成
 */

#pragma mark - 方法1-栈
bool isValid(string s) {
    int len = (int)s.length();
    if (len%2 == 1) return false;
    stack<char> S;
    S.push('#');
    for (int i = 0; i < len; i++) {
        char ch = S.top();
        if ((ch=='(' && s[i]==')') ||
            (ch=='[' && s[i]==']') ||
            (ch=='{' && s[i]=='}')) {
            S.pop();
            continue;
        }
        S.push(s[i]);
    }
    return S.top()=='#';
}
