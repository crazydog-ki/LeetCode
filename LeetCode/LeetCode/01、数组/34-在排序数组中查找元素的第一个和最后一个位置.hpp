// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**在排序数组中查找元素的第一个和最后一个位置
给定一个按照升序排列的整数数组nums，和一个目标值target。找出给定目标值在数组中的开始位置和结束位置。
如果数组中不存在目标值target，返回[-1,-1]。
进阶：
你可以设计并实现时间复杂度为O(logn)的算法解决此问题吗？
 
提示：
1. 0 <= nums.length <= 105
2. -109 <= nums[i] <= 109
3. nums是一个非递减数组
4. -109 <= target <= 109
 */

#pragma mark - 方法1-二分法
int binarySearch(vector<int>& nums, int lo, int hi, int target) {
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (target == nums[mi]) return mi;
        else if (target < nums[mi]) hi = mi-1;
        else lo = mi+1;
    }
    return -1;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int len = (int)nums.size();
    int minIdx = -1, maxIdx = -1;
    int lo = 0, hi = len-1;
    /// 左边界
    while (true) {
        int idx = binarySearch(nums, lo, hi, target);
        if (idx == -1) break;
        else {
            minIdx = idx;
            hi = idx-1;
        }
    }
    lo = 0; hi = len-1;
    /// 右边界
    while (true) {
        int idx = binarySearch(nums, lo, hi, target);
        if (idx == -1) break;
        else {
            maxIdx = idx;
            lo = idx+1;
        }
    }
    return {minIdx, maxIdx};
}

