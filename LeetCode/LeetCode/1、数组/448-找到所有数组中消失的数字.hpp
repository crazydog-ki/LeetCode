// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 将数组元素对应为索引的位置取负数 => 核心是为了标记该索引下的值已经取到
vector<int> findDisappearedNumbers2(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) return nums;
    int idx = 0;
    // 1. 将数组元素对应为索引的位置取负数
    for (int i = 0; i < n; i++) {
        idx = abs(nums[i]) - 1;
        nums[idx] = (0<nums[idx]) ? -nums[idx] : nums[idx];
    }
    vector<int> res;
    // 2. 遍历取负数后的数组, 若数组元素值大于0, 则说明数组下标值不存在: 即消失的数字
    for (int j = 0; j < n; j++) {
        if (0 < nums[j]) res.push_back(j+1);
    }
    return res;
}

#pragma mark - 方法一: 将数组元素对应为索引的位置加n => 核心是为了标记该索引下的值已经取到
vector<int> findDisappearedNumbers(vector<int> &nums) {
    int n = (int)nums.size();
    if (n == 0) return nums;
    int idx = 0;
    // 1. 将数组元素对应为索引的位置加n
    for (int i = 0; i < n; i++) {
        idx = (nums[i]-1) % n;
        nums[idx] += n;
    }
    
    // 2. 遍历加n后的数组, 若数组元素值小于等于n, 则说明数组下标值不存在: 即消失的数字
    vector<int> res;
    for (int j = 0; j < n; j++) {
        if (nums[j] <= n) res.push_back(j+1);
    }
    return res;
}

void test() {
    vector<int> nums = {2, 2, 2, 3, 3};
    vector<int> res = findDisappearedNumbers2(nums);
    printVectors(res);
}
