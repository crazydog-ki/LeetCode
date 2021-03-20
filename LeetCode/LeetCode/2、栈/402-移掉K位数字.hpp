// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <stack>
#include <string>

#pragma mark - 方法一: 单调栈
string removeKdigits(string num, int k) {
    stack<char> S;
    int i = 0;
    for (i = 0; i < num.length(); i++) {
        if (k == 0) break;
        while (!S.empty() && num[i]<S.top() && 0<k) { // 贪心原则
            S.pop();
            k--;
        }
        if (S.empty() && num[i]=='0') continue; // 处理首位为0的情况
        S.push(num[i]);
    }
    string res = "";
    if (i < num.length()) { // k==0提前成立break, i~S.length()-1的子串拼接在最后
        while (!S.empty()) {
            res = S.top() + res;
            S.pop();
        }
        res += num.substr(i, num.length()-i);
    } else { // 0<k, 栈顶直接pop
        while (!S.empty() && k--) S.pop();
        while (!S.empty()) {
            res = S.top() + res;
            S.pop();
        }
    }
    return res=="" ? "0" : res;
}

void test() {
    cout << removeKdigits("10200", 1) << endl;
    cout << removeKdigits("10", 2) << endl;
}
