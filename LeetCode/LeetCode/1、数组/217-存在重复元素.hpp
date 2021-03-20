// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"
#include <unordered_map>

#pragma mark - 方法二: 排序
bool containsDuplicate2(vector<int> &nums) {
    sort(nums.begin(), nums.end());
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i-1] == nums[i]) return true;
    }
    return false;
}

#pragma mark - 方法一: 哈希
bool containsDuplicate(vector<int> &nums) {
    unordered_map<int, bool> myMap;
    for (int i = 0; i < nums.size(); i++) {
        if (myMap.find(nums[i]) == myMap.end()) {
            myMap[nums[i]] = true;
        } else return true;
    }
    return false;
}
