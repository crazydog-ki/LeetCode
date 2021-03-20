// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#include "tools.h"

#pragma mark - 方法三: Boyer-Moore 投票算法
int majorityElement3(vector<int> &nums) {
    int count = 0;
    int candidate = 0;
    for (auto num: nums) {
        if (count == 0) candidate = num;
        count += (num == candidate) ? 1 : -1;
    }
    return candidate;
}

#pragma mark - 方法二: 快速排序
void quickSort(vector<int> &nums, int left, int right) {
    if (right < left) return;
    int i = left;
    int j = right;
    // 1. 轴点pointVal就位
    int pointVal = nums[left];
    while (i != j) {
        while (pointVal<=nums[j] && i<j) j--;
        while (nums[i]<=pointVal && i<j) i++;
        if (i < j) swap(nums[i], nums[j]);
    }
    nums[left] = nums[i];
    nums[i] = pointVal;
    // 2. 轴点左边
    quickSort(nums, left, i-1);
    // 3. 轴点右边
    quickSort(nums, i+1, right);
}

int majorityElement2(vector<int> &nums) {
    quickSort(nums, 0, (int)nums.size()-1);
    return nums[nums.size() / 2];
}

#pragma mark - 方法一: 哈希表
int majorityElement(vector<int> &nums) {
    // 1. 以数组元素作为key, 以出现次数作为value, 构建hash表
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++) {
        if (myMap.find(nums[i]) != myMap.end()) { // 存在key: nums[i]
            myMap[nums[i]]++;
        } else { // 不存在key
            myMap[nums[i]] = 1;
        }
    }
    // 2. 遍历hash表, 取出value最大对应的key
    int max = 0;
    int res = 0;
    for (auto num : myMap) {
        if (max < num.second) {
            max = num.second;
            res = num.first;
        }
    }
    return res;
}

void test() {
    vector<int> nums = {1, 7, 32, 7, 32, 22, 20};
    quickSort(nums, 0, (int)nums.size()-1);
    printVectors(nums);
}
