// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 双指针优化
int findPairs2(vector<int> &nums, int k) {
    if(nums.size() < 2) return 0;
    int pairCount = 0;
    int n = (int)nums.size();
    // 1. 排序
    sort(nums.begin(),nums.end());
    // 2. 一轮遍历
    for(int i = 0; i < n - 1; i++) {
        int j = i + 1; // 对每个位置i, 向后移动指针j
        while(j<n && nums[j]-nums[i]<k) j++;
        if(j<n && nums[j]-nums[i]==k) pairCount++;
        while(i<n-1 && nums[i+1]==nums[i]) i++;
    }
    return pairCount;
}

#pragma mark - 方法一: 常规方法
int findPairs(vector<int> &nums, int k) {
    // 1. 排序
    sort(nums.begin(), nums.end());
    // 2. 记录对数
    int pairCount = 0;
    // 3. 一轮遍历
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i]==nums[i-1] && k!=0) continue;
        else if (nums[i]==nums[i-1] && k==0) {
            pairCount++;
            while (i<nums.size() && nums[i] == nums[i-1]) i++;
            continue;
        }
        for (int j = i-1; 0 <= j; j--) {
            if (nums[i]-nums[j] == k) { pairCount++; break; }
            else if (k < nums[i]-nums[j]) break;
        }
    }
    return pairCount;
}

void test() {
    vector<int> nums = {1, 1, 3, 3, 5, 5};
    cout << findPairs(nums, 0) << endl;
}
