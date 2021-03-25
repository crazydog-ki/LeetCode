// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 排序+双指针+剪枝优化
vector<vector<int>> fourSum(vector<int> &nums, int target) {
    int count = (int)nums.size();
    vector<vector<int>> res;
    if (count < 4) return res;
    // 排序
    sort(nums.begin(), nums.end());
    // 定义4个指针
    int i = 0, j = i+1, start = j+1, end = count-1;
    for (i = 0; i <= count-4; i++) {
        if (0<i && nums[i]==nums[i-1]) continue; // 去重
        //  第一重循环 => 剪枝
        if (target < nums[i]+nums[i+1]+nums[i+2]+nums[i+3]) break;
        if (nums[i]+nums[count-3]+nums[count-2]+nums[count-1] < target) continue;
        for (j = i+1; j <= count-3; j++) {
            //  第二重循环 => 剪枝
            if (target < nums[i]+nums[j]+nums[j+1]+nums[j+2]) break;
            if (nums[i]+nums[j]+nums[count-2]+nums[count-1] < target) continue;
            if (i+1<j && nums[j]==nums[j-1]) continue; // 去重
            start = j+1; end = count-1; // i, j重设后, start和end重设
            while (start < end) {
                int sum = nums[i]+nums[j]+nums[start]+nums[end];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[start], nums[end]});
                    // 防止遗漏
                    while (start<end && nums[start+1]==nums[start]) start++;
                    while (start<end && nums[end-1]==nums[end]) end--;
                    start++; end--;
                }
                else if (sum < target) start++;
                else if (target < sum) end--;
            }
        }
    }
    return res;
}

#pragma mark - 方法一: 排序+双指针
vector<vector<int>> fourSum1(vector<int> &nums, int target) {
    int count = (int)nums.size();
    vector<vector<int>> res;
    if (count < 4) return res;
    // 排序
    sort(nums.begin(), nums.end());
    // 定义4个指针
    int i = 0, j = i+1, start = j+1, end = count-1;
    for (i = 0; i <= count-4; i++) {
        if (0<i && nums[i]==nums[i-1]) continue; // 去重
        for (j = i+1; j <= count-3; j++) {
            if (i+1<j && nums[j]==nums[j-1]) continue; // 去重
            start = j+1; end = count-1; // i, j重设后, start和end重设
            while (start < end) {
                int sum = nums[i]+nums[j]+nums[start]+nums[end];
                if (sum == target) {
                    res.push_back({nums[i], nums[j], nums[start], nums[end]});
                    // 防止遗漏
                    while (start<end && nums[start+1]==nums[start]) start++;
                    while (start<end && nums[end-1]==nums[end]) end--;
                    start++; end--;
                }
                else if (sum < target) start++;
                else if (target < sum) end--;
            }
        }
    }
    return res;
}

void test() {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    // vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> res = fourSum(nums, 0);
    for (int i = 0; i < res.size(); i++) {
        printVectors(res[i]);
        cout << endl;
    }
}
