// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "32-最长有效括号.hpp"

void test() {
    string s = "(((()))())";
    cout << longestValidParentheses(s) << endl;
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
