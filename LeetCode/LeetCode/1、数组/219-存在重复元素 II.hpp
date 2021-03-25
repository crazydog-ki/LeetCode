// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"
#include <unordered_map>

#pragma mark - 方法一: 哈希
bool containsNearbyDuplicate(vector<int> &nums, int k) {
    unordered_map<int, int> myMap;
    for (int i = 0; i < nums.size(); i++) {
        if (myMap.count(nums[i]) == 0) myMap[nums[i]] = i; // 初始化key/value
        else if (i-myMap[nums[i]] <= k) return true;
        else myMap[nums[i]] = i; // 更新value
    }
    return false;
}
