// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "28-实现strStr().hpp"

void test() {
    string text = "ABABCABAA";
    string pattren = "BA";
    cout << strStr(text, pattren) << endl;
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
