// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <string>
#include <stack>

#pragma mark - 方法一: 栈
string removeDuplicates(string S) {
    string myStack;
    for (int i = 0; i < S.length(); i++) {
        if (myStack.empty() || S[i]!=myStack.back()) myStack.push_back(S[i]);
        else if (myStack.back() == S[i]) myStack.pop_back();
    }
    return myStack;
}

void test() {
    cout << removeDuplicates("accab") << endl;
}
