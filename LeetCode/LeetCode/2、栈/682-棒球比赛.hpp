// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include <string>
#include <stack>

#pragma mark - 方法一: 栈
int calPoints(vector<string> &ops) {
    // 1. 每轮积分入栈
    stack<int> S;
    for (int i = 0; i < ops.size(); i++) {
        if (ops[i] == "+") { // 本轮积分值是前两轮之和
            int current = S.top();
            S.pop();
            current += S.top();
            S.push(current-S.top());
            S.push(current);
        } else if (ops[i] == "D") { // 本轮积分值是前一轮的两倍
            S.push(S.top()*2);
        } else if (ops[i] == "C") { // 最后一个回合的分数是无效的, 移除
            S.pop();
        } else {   // 本轮获得的积分值
            S.push(stoi(ops[i]));
        }
    }
    
    // 2. 计算总积分值
    int totalPoints = 0;
    while (!S.empty()) {
        totalPoints += S.top();
        S.pop();
    }
    
    return totalPoints;
}

void test() {
    // vector<string> ops = {"5", "2", "C", "D", "+"};
    vector<string> ops = {"-21", "-66", "39", "+", "+"};
    cout << calPoints(ops) << endl;
}
