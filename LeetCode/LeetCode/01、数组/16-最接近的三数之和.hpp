// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**最接近的三数之和
 给定一个包括n个整数的数组nums和一个目标值target。找出nums中的三个整数，使得它们的和与
 target最接近。返回这三个数的和。假定每组输入只存在唯一答案。
 
 提示：
 （1）3 <= nums.length <= 10^3
 （2）-10^3 <= nums[i] <= 10^3
 （3）-10^4 <= target <= 10^4
 */

#pragma mark - 方法1-双指针+排序
int threeSumClosest(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    
    int count = (int)nums.size();
    int ret = 1e4; // 10^4，三数之和不会超过10^4
    for (int i = 0; i < count; i++) {
        if (0<i && nums[i]==nums[i-1]) continue;
        int l = i+1, r = count-1;
        while (l < r) {
            int sum = nums[i]+nums[l]+nums[r];
            if (abs(sum-target) < abs(ret-target)) ret = sum;
            
            if (sum == target) return (int)sum;
            else if (target < sum) {
                while (l<r && nums[r]==nums[r-1]) r--;
                r--;
            } else if (sum < target) {
                while (l<r && nums[l]==nums[l+1]) l++;
                l++;
            }
        }
        
    }
    return (int)ret;
}

void test() {
    vector<int> nums = {-1, 2, 1, -4};
    cout << threeSumClosest(nums, 1) << endl;
}
