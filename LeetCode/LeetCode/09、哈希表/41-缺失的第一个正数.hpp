// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <unordered_map>

/**缺失的第一个正数
给你一个未排序的整数数组nums，请你找出其中没有出现的最小的正整数。
请你实现时间复杂度为O(n)并且只使用常数级别额外空间的解决方案。

提示：
1. 1 <= nums.length <= 5*10^5
2. -2^31 <= nums[i] <= 2^31-1
 */

#pragma mark - 方法1-哈希+交换
int firstMissingPositive1(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
        if (nums[i] <= 0) { /// 防止num-1越界
            nums[i] = 0; /// 空白位置标记为0
            continue;
        }
        int pos = nums[i]-1;
        if (i == nums[i]-1) continue;
        else if (n <= pos) nums[i] = 0;
        else if (0 < nums[i]) {
            if (nums[pos] != nums[i]) {
                swap(nums[i], nums[pos]);
                if (0 < i) i--;
            }
        }
    }
    
    int ret = n+1;
    for (int j = 0; j < n; j++) {
        if (nums[j]==0 || nums[j]!=j+1) {
            ret = j+1;
            break;
        }
    }
    return ret;
}

#pragma mark - 方法2-哈希+交换+简化
int firstMissingPositive2(vector<int>& nums) {
    int n = (int)nums.size();
    for (int i = 0; i < n; i++) {
        while (0<nums[i] &&
               nums[i]<=n &&
               nums[nums[i]-1]!=nums[i]) {
            swap(nums[nums[i]-1], nums[i]);
        }
    }
    
    int ret = n+1;
    for (int j = 0; j < n; j++) {
        if (nums[j] != j+1) {
            ret = j+1;
            break;
        }
    }
    return ret;
}

#pragma mark - 方法3-哈希+正负号
int firstMissingPositive(vector<int>& nums) {
    int n = (int)nums.size();
    for (int& num: nums) {
        if (num <= 0) {
            num = n+1; /// 负数变n+1
        }
    }
    
    for (int i = 0; i < n; ++i) {
        int num = abs(nums[i]);
        if (num <= n) {
            nums[num-1] = -abs(nums[num-1]); /// 负号标记
        }
    }
    
    int ret = n+1;
    for (int i = 0; i < n; ++i) {
        if (nums[i] > 0) {
            ret = i+1;
            break;
        }
    }
    return ret;
}
