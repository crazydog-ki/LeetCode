// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 排序+双指针
vector<vector<int>> threeSum(vector<int> &nums) {
    vector<vector<int>> res;
    int size = (int)nums.size();
    // 排序
    sort(nums.begin(), nums.end());
    if (size<3 || 0<nums.front() || nums.back()<0) return {};
    int i = 0;
    int j = 0;
    // 选定cur, 对cur后面的元素实施双指针操作
    for (int cur = 0; cur < size; cur++) {
        if (0 < nums[cur]) break; // 提前跳出
        if (1<=cur && nums[cur]==nums[cur-1]) continue; // 防止重复添加
        // 对撞指针
        i = cur + 1;
        j = size - 1;
        while (i < j) {
            if (nums[cur]+nums[i]+nums[j] == 0) { // 1. 等于0
                res.push_back({nums[cur], nums[i], nums[j]});
                while (i<j && nums[i+1]==nums[i]) i++; // 去重
                while (i<j && nums[j-1]==nums[j]) j--; // 去重
                i++;
                j--;
            }
            else if (nums[cur]+nums[i]+nums[j] < 0) i++; // 2. 小于0
            else j--; // 3. 大于0
        }
    }
    return res;
}

void test() {
    // vector<int> nums = {-1, 0, 1, 2, -1, -4};
    vector<int> nums = {0, 0, 0, 0};
    vector<vector<int>> res = threeSum(nums);
}
