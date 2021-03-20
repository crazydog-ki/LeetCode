// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 改进版
void nextPermutation(vector<int> &nums) {
    int count = (int)nums.size();
    int i = count-2;
    while (0<=i && nums[i+1]<=nums[i]) i--; // 该步完成i有可能为-1(数组降序)
    if (0 <= i) {
        int j = count-1;
        while (0<=j && nums[j]<=nums[i]) j--; // 可改进用二分查找
        swap(nums[i], nums[j]);
    }
    reverse(nums.begin()+i+1, nums.end());
}

#pragma mark - 方法一: 从后往前遍历, 找到非增点
void nextPermutation1(vector<int> &nums) {
    int count = (int)nums.size();
    int i = count-1;
    while (0 < i) {
        if (nums[i] <= nums[i-1]) i--;
        else if (nums[i-1] < nums[i]) break; // 交换的时机
    }
    // 排列最大
    if (i == 0) {
        reverse(nums.begin(), nums.end());
        return;
    }
    
    // 排列不是最大, 排列nums[i-1]右边
    i--;
    int j = i+1;
    while (j <= count-1) {
        if (nums[j] <= nums[i]) {
            swap(nums[i], nums[j-1]);
            break;
        }
        else if (j == count-1) { // j到达最后, 直接交换nums[i]与nums[j]
            swap(nums[i], nums[j]);
            break;
        }
        else if (nums[i] < nums[j]) j++;
    }
    reverse(nums.begin()+i+1, nums.end()); // nums[i]右边原本已是降序
}

void test() {
    // vector<int> nums = {1, 2, 0, 4, 2, 1, 1};
    vector<int> nums = {1, 2, 3, 4, 3, 1, 0};
    // vector<int> nums = {4, 1, 1, 0};
    // vector<int> nums = {1, 2, 3};
    // vector<int> nums = {1, 3, 2};
    // vector<int> nums = {2, 3, 1};
    // vector<int> nums = {5, 4, 7, 5, 3, 2};
    nextPermutation(nums);
    printVectors(nums);
}

