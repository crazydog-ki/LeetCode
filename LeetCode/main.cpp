// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;
#include "tools.h"

#include "34-在排序数组中查找元素的第一个和最后一个位置.hpp"

void test() {
    vector<int> nums = {1, 2, 2, 2, 2, 3, 4};
    int target = 2;
    vector<int> ret = searchRange(nums, target);
    printVector(ret);
}

int main(int argc, const char * argv[]) {
    test();
    return 0;
}
