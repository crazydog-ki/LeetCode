// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**四数之和
给定一个包含n个整数的数组nums和一个目标值target，判断nums中是否存在四个元素a，b，c和 d，使得a+b+c+d的值与target相等？找出所有满足条件且不重复的四元组。
注意：答案中不可以包含重复的四元组。
 
提示：
1. 0 <= nums.length <= 200
2. -109 <= nums[i] <= 109
3. -109 <= target <= 109
 */

#pragma mark - 方法1-双指针+排序
vector<vector<int>> fourSum1(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    vector<vector<int>> ret;
    int count = (int)nums.size();
    if (count < 4) return ret;
    
    for (int l = 0; l < count-3; l++) {
        if (0<l && nums[l]==nums[l-1]) continue;
        // 剪枝
        if (target < nums[l]+nums[l+1]+nums[l+2]+nums[l+3]) break;
        if (nums[l]+nums[count-1]+nums[count-2]+nums[count-3] < target) continue;
        
        for (int r = l+3; r < count; r++) {
            if (r+1<count && nums[r]==nums[r+1]) continue;
            
            int i = l+1, j = r-1;
            while (i < j) {
                int sum = nums[l]+nums[i]+nums[j]+nums[r];
                if (sum == target) {
                    ret.push_back({nums[l], nums[i], nums[j], nums[r]});
                    // 去重
                    while (i<j && nums[i+1]==nums[i]) i++;
                    while (i<j && nums[j-1]==nums[j]) j--;
                    i++; j--;
                }
                else if (sum < target) i++;
                else if (target < sum) j--;
            }
        }
    }
    
    return ret;
}

#pragma mark - 方法2-回溯+dfs
vector<int> myNums;
int myTarget;
int numsOfSize;
void dfs(vector<vector<int>>& ret,
         vector<int>& item,
         int start,
         int sum) {
    int itemSize = (int)item.size();
    if (sum==myTarget && itemSize==4) {
        ret.push_back(item);
        return;
    }
    
    // 四个数排列组合
    for (int i = start; i < numsOfSize; i++) {
        // 去重
        if (start<i && myNums[i]==myNums[i-1]) continue;
        
        // 剪枝
        if (numsOfSize-i < 4-itemSize) return;
        if (i+1<numsOfSize && myTarget<sum+myNums[i]+(3-itemSize)*myNums[i+1]) return;
        if (i+1<numsOfSize && sum+myNums[i]+(3-itemSize)*myNums[numsOfSize-1]<myTarget) continue;
      
        item.push_back(myNums[i]);
        dfs(ret, item, i+1, sum+myNums[i]);
        item.pop_back();
    }
}

vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    myNums = nums;
    numsOfSize = (int)nums.size();
    myTarget = target;
    
    vector<vector<int>> ret;
    int count = (int)nums.size();
    if (count < 4) return ret;
    vector<int> item;
    int sum = 0;
    dfs(ret, item, 0, sum);
    return ret;
}
