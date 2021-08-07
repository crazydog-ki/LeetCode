// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "31-下一个排列.hpp"

void test() {
    vector<int> nums = {1, 3, 5, 4, 2};
    nextPermutation(nums);
    printVector(nums);
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
