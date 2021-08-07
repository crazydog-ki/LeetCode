// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "30-串联所有单词的子串.hpp"

void test() {
    string s = "barfoofoobar";
    vector<string> words = {"bar", "foo"};
    vector<int> ret = findSubstring(s, words);
    printVector(ret);
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
