// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 优化数组写入操作次数
void moveZeroes2(vector<int> &nums) {
    for (int nonZeroCount = 0, cur = 0; cur < nums.size(); cur++)
        if (nums[cur] != 0) swap(nums[nonZeroCount++], nums[cur]);
}

#pragma mark - 方法一: 双指针 => nonZeroCount和i
void moveZeroes(vector<int> &nums) {
    int nonZeroCount = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != 0) {
            nums[nonZeroCount] = nums[i];
            nonZeroCount++;
        }
    }
    for (int i = nonZeroCount; i < nums.size(); i++) {
        nums[i] = 0;
    }
}

void test() {
    // vector<int> nums = {0, 1, 0, 3, 0};
    vector<int> nums = {0, 0, 1};
    moveZeroes(nums);
    printVectors(nums);
}
