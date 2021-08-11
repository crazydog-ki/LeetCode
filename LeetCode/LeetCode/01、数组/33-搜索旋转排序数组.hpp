// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**搜索旋转排序数组
整数数组nums按升序排列，数组中的值互不相同。
在传递给函数之前，nums在预先未知的某个下标k（0 <= k < nums.length）上进行了旋转，使数组变为 [nums[k]、nums[k+1]、nums[n-1], nums[0], nums[1], ...,nums[k-1]]（下标从0 开始计数）。例如，[0, 1, 2, 4, 5, 6, 7]在下标3处经旋转后可能变为[4, 5, 6, 7, 0, 1, 2]。
给你旋转后的数组nums和一个整数target，如果nums中存在这个目标值target，则返回它的下标，否则返回-1。

提示：
1. 1 <= nums.length <= 5000
2. -10^4 <= nums[i] <= 10^4
3. nums中的每个值都独一无二
4. 题目数据保证nums在预先未知的某个下标上进行了旋转
5. -10^4 <= target <= 10^4
 */
#pragma mark - 方法1-二分法
int search(vector<int>& nums, int target) {
    int size = (int)nums.size();
    
    int lo = 0, hi = size-1;
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (nums[mi] == target) return mi;
        
        /// mi在前半段
        if (nums[lo] <= nums[mi]) {
            if (nums[mi] < target) lo = mi+1;
            else if (target<nums[mi] && nums[lo]<=target) hi = mi-1;
            else if (target<nums[mi] && target<nums[lo]) lo = mi+1;
        }
        /// mi在后半段
        else if (nums[mi] < nums[lo]) {
            if (target < nums[mi]) hi = mi-1;
            else if (nums[mi]<target && nums[lo]<=target) hi = mi-1;
            else if (nums[mi]<target && target<nums[lo]) lo = mi+1;
        }
     }
    return -1;
}
