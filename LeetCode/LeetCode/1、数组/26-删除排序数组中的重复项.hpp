// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 双指针, 大步前行
int removeDuplicates(vector<int> &nums) {
    if (nums.size() == 0) return 0;
    int len = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] != nums[i-1]) nums[++len] = nums[i];
    }
    return ++len;
}

void test() {
    vector<int> nums = {0, 0, 1, 2, 2, 3, 3, 4};
    cout << removeDuplicates(nums) << endl;
    printVectors(nums);
}
