// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**最大子数组和
 给你一个整数数组nums，请你找出一个具有最大和的连续子数组（子数组最少包含一个元素），返回其最大和。
 子数组是数组中的一个连续部分。
 */

#pragma mark - 方法1-动态规划
int maxSubArray(vector<int>& nums) {
    if (nums.size() <= 0) return 0;
    // dp[i]代表以nums[i]结尾的最大子数组和
    vector<int> dp(nums.size(), 0);
    dp[0] = nums[0];
    int maxSum = dp[0];
    for (int i = 1; i < nums.size(); i++) {
        dp[i] = max(dp[i-1]+nums[i], nums[i]);
        maxSum = max(maxSum, dp[i]);
    }
    return maxSum;
}

#pragma mark - 方法1-动态规划-简化
int maxSubArray2(vector<int>& nums) {
    if (nums.size() <= 0) return 0;
    int maxSum = nums[0];
    int pre = 0;
    for (int i = 0; i < nums.size(); i++) {
        pre = max(pre+nums[i], nums[i]);
        maxSum = max(maxSum, pre);
    }
    return maxSum;
}

#pragma mark - 方法2-分治
int _crossMax(vector<int>& nums, int l, int mid, int r) {
    // [xxx,mid] + [mid,xxx]
    int lMaxSum = INT_MIN;
    int sum = 0;
    for (int i = mid; l <= i; i--) {
        sum += nums[i];
        lMaxSum = max(lMaxSum, sum);
    }
    
    int rMaxSum = INT_MIN;
    sum = 0;
    for (int i = mid+1; i <= r; i++) {
        sum += nums[i];
        rMaxSum = max(rMaxSum, sum);
    }
    return lMaxSum+rMaxSum;
}

int _findMax(vector<int>& nums, int l, int r) {
    if (r == l) return nums[l];
    int mid = (r+l)/2;
    int lMax = _findMax(nums, l, mid); // 左
    int rMax = _findMax(nums, mid+1, r); // 右
    int crossMax = _crossMax(nums, l, mid, r); // 交叉
    return max(max(lMax, rMax), crossMax);
}

int maxSubArray3(vector<int>& nums) {
    return _findMax(nums, 0, (int)nums.size()-1);
}

