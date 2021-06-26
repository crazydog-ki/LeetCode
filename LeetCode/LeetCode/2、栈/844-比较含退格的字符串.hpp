// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <string>

#pragma mark - 方法一: 栈
bool backspaceCompare(string S, string T) {
    // 1. 处理字符串S
    string str1;
    for (int i = 0; i < S.length(); i++) {
        if (!str1.empty() && S[i] == '#') str1.pop_back();
        else if (S[i] != '#') str1 += S[i];
    }
    
    // 2. 处理字符串T
    string str2;
    for (int i = 0; i < T.length(); i++) {
        if (!str2.empty() && T[i] == '#') str2.pop_back();
        else if (T[i] != '#') str2 += T[i];
    }
    return str1 == str2;
}

void test() {
    string S = "a#b#c#";
    string T = "ad##c#";
    cout << backspaceCompare(S, T) << endl;
}
