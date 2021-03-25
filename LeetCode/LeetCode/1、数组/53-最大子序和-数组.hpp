// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 动态规划
int maxSubArray(vector<int> &nums) {
    int count = (int)nums.size();
    vector<int> dp(count, 0); // dp[i]代表以nums[i]结尾的连续子序和
    dp[0] = nums[0];
    for (int i = 1; i < count; i++) {
        if (dp[i-1] < 0) dp[i] = nums[i];
        else dp[i] = dp[i-1] + nums[i];
    }
    return *max_element(dp.begin(), dp.end()); // max_element函数返回的是向量最大元素的位置
}
