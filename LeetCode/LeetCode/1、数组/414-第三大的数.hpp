// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 维护first, second, third
int thirdMax(vector<int> &nums) {
    int first = INT_MIN;
    int second = INT_MIN;
    int third = INT_MIN;
    int flag = INT_MAX;
    for (int i = 0; i < nums.size(); i++) {
        flag = min(flag, nums[i]); // 记录数组最小值, 处理第三大的数的确为INT_MIN的情况
        if (first < nums[i]) {
            third = second;
            second = first;
            first = nums[i];
        } else if (second < nums[i] && nums[i] < first) {
            third = second;
            second = nums[i];
        } else if (third < nums[i] && nums[i] < second) {
            third = nums[i];
        }
    }
    return (third<second && flag<=third) ? third : first;
}

void test() {
    vector<int> nums = {1, 2, 2, 5, 3, 5};
    cout << thirdMax(nums) << endl;
}
