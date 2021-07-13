// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**三数之和
给你一个包含n个整数的数组nums，判断nums中是否存在三个元素a、b、c，使得a+b+c=0？请你找出所有和为0且不重复的三元组。
注意：答案中不可以包含重复的三元组。
 
提示：
1. 0 <= nums.length <= 3000
2. -105 <= nums[i] <= 105
 */

#pragma mark - 方法1-双指针+排序
vector<vector<int>> threeSum(vector<int>& nums) {
    // 排序
    sort(nums.begin(), nums.end());
    int count = (int)nums.size();
    if (count<3 || 0<nums.front() || nums.back()<0) return {}; // 提前跳出
    
    vector<vector<int>> ret = {};
    for (auto it = nums.begin(); it != nums.end(); it++) {
        if (0 < *it) break; // 提前跳出
        if (nums.begin()<it && *it==*(it-1)) continue;;
        auto l = it+1, r = nums.end()-1;
        while (l < r) {
            if (0<*it+*l || *r<0) break; // 提前跳出
            
            if (*it+*l+*r < 0) l++;
            else if (0 < *it+*l+*r) r--;
            else {
                ret.push_back({*it, *l, *r});
                // 去重
                while (l<r && *(l+1)==*l) l++;
                while (l<r && *(r-1)==*r) r--;
                l++;
                r--;
            }
        }
    }
    return ret;
}
