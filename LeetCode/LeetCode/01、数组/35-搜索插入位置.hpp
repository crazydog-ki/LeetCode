// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**搜索插入位置
给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。如果目标值不存在数组中，返回它将会被按顺序插入的位置。
请必须使用时间复杂度为O(logn)的算法。
 */

#pragma mark - 方法1-二分法
int searchInsert(vector<int>& nums, int target) {
    int len = (int)nums.size();
    int lo = 0, hi = len-1;
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (target == nums[mi]) return mi;
        else if (target < nums[mi]) hi = mi-1;
        else lo = mi+1;
    }
    return lo;
}
