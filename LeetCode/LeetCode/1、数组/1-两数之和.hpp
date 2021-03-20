// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#include "tools.h"

#pragma mark - 方法三: 相撞指针
vector<int> twoSum3(vector<int> &nums, int target) {
    // 1. 对未排序数组copy, 便于后续找到对应的索引
    vector<int> copyNums(nums);
    // 2. 数组排序
    sort(nums.begin(), nums.end());
    // 3. 构建相撞指针, 保存v1,v2
    int start = 0; int end = (int)nums.size() - 1;
    int v1 = 0; int v2 = 0;
    while (start < end) {
        if (nums[start] + nums[end] == target) {
            v1 = nums[start];
            v2 = nums[end];
            break;
        }
        else if (nums[start] + nums[end] < target) start++;
        else end--;
    }
    // 4. 索引结果push到结果数组中
    vector<int> res;
    for (int i = 0; i < copyNums.size(); i++) {
        if (copyNums[i] == v1 || copyNums[i] == v2) res.push_back(i);
    }
    return res;
}

#pragma mark - 方法二: 哈希+一次遍历
vector<int> twoSum2(vector<int> &nums, int target) {
    unordered_map<int, int> myMap;
    int count = (int)nums.size();
    
    vector<int> res;
    for (int i = 0; i < count; i++) {
        // 判断<i的序列中是否存在nums[j] == target-nums[i]
        if (myMap.find(target-nums[i]) != myMap.end()) {
            res.push_back(myMap[target-nums[i]]);
            res.push_back(i);
            return res;
        }
        myMap[nums[i]] = i;
    }
    return res;
}

#pragma mark - 方法一: 哈希表, 以数组元素为key, 数组索引为value => 两次遍历
vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int> myMap;
    int count = (int)nums.size();
    
    // 1. 构建map, 以数组元素为key, 数组索引为value
    for (int i = 0; i < count; i++) {
        myMap[nums[i]] = i;
    }
    // 2. 二次遍历, 需避免使用同一个元素的case(这里重点考虑key相同的情况，能否符合要求？[1, 5, 5, 7], target=10)
    vector<int> res = {};
    for (int j = 0; j < count; j++) {
        if (myMap.find(target-nums[j]) != myMap.end() && myMap[target-nums[j]] != j) {
            res.push_back(j);
            res.push_back(myMap[target-nums[j]]);
            return res;
        }
    }
    return res;
}

void test() {
    vector<int> nums = {1, 5, 5, 7};
    vector<int> res = twoSum(nums, 10);
    printVectors(res);
}
