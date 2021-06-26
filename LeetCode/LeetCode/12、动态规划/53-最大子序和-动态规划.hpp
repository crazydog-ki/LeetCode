// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 动态规划
int maxSubArray(vector<int> &nums) {
    int count = (int)nums.size();
    vector<int> dp(count, -1); // dp[i]: 以nums[i]结尾的最大子序和
    if (count == 0) return 0;
    dp[0] = nums[0];
    int maxVal = dp[0];
    for (int i = 1; i < count; i++) {
        dp[i] = (0<=dp[i-1]) ? dp[i-1]+nums[i] : nums[i];
        maxVal = max(maxVal, dp[i]);
    }
    return maxVal;
}
