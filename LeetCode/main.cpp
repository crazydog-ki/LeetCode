// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "41-缺失的第一个正数.hpp"

void test() {
    vector<int> nums = {2147483647, 2147483646, 2147483645, 3, 2, 1, -1, 0, -2147483648};
    cout << firstMissingPositive(nums) << endl;
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
