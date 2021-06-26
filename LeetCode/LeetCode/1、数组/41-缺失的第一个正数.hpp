// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>
#include "tools.h"

#pragma mark - 方法二: 对应位置存放对应元素(占坑)
int firstMissingPositive2(vector<int> &nums) {
    int count = (int)nums.size();
    // 1. 对应元素放到对应位置 [1, count]
    for (int i = 0; i < count; i++) {
        if (1<=nums[i] && nums[i]<=count && nums[nums[i]-1]!=nums[i]) {
            swap(nums[i], nums[nums[i]-1]);
            i--;
        }
    }
    
    // 2. 从前往后对应查找
    for (int j = 0; j < count; j++) {
        if (nums[j] != j+1) return j+1;
    }
    return count+1;
}

#pragma mark - 方法一: hash表
int firstMissingPositive(vector<int> &nums) {
    unordered_map<int, int> myMap;
    // 1. 用hash表记录数组中存在的数字
    for (int i = 0; i < nums.size(); i++) {
        myMap[nums[i]] = 1;
    }
    
    // 2. 遍历查找
    int minRes = 1;
    for (int j = 1; j < INT_MAX; j++) {
        if (myMap.find(j) == myMap.end()) {
            minRes = j;
            break;
        }
    }
    
    return minRes;
}

void test() {
    vector<int> nums = {2, 40};
    cout << firstMissingPositive2(nums) << endl;
}
