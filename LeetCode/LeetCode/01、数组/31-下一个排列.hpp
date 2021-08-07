// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**下一个排列
实现获取下一个排列的函数，算法需要将给定数字序列重新排列成字典序中下一个更大的排列。
如果不存在下一个更大的排列，则将数字重新排列成最小的排列（即升序排列）。
必须原地修改，只允许使用额外常数空间。
 
提示：
1. 1 <= nums.length <= 100
2. 0 <= nums[i] <= 100
 */

#pragma mark - 方法1-双指针
void nextPermutation(vector<int>& nums) {
    int len = (int)nums.size();
    if (len <= 1) return;
    
    int l = len-2;
    
    /// 优化左指针位置
    while (0<=l && nums[l+1]<=nums[l]) l--;
    
    if (0 <= l) {
        int r = len-1;
        while (0<=r && nums[r]<=nums[l]) r--;
        swap(nums[l], nums[r]);
    }
    
    /// 尾部部分按升序排列
    sort(nums.begin()+l+1, nums.end());
}
