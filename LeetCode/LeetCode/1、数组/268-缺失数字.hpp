// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 位运算
int missingNumber2(vector<int> &nums) {
    int missing = (int)nums.size();
    for (int i = 0; i < nums.size(); i++) {
        missing ^= (i ^ nums[i]);
    }
    return missing;
}

#pragma mark - 方法一: 数学法
int missingNumber(vector<int> &nums) {
    int count = (int)nums.size();
    int totalSum = count * (count+1) * 0.5;
    int sum = 0;
    for (auto num: nums) sum += num;
    return totalSum - sum;
}

void test() {
    vector<int> nums = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    cout << missingNumber(nums) << endl;
}
