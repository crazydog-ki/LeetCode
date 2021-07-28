// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**
给你一个有序数组nums ，请你原地删除重复出现的元素，使每个元素只出现一次 ，返回删除后数组的新长度。
不要使用额外的数组空间，你必须在原地修改输入数组并在使用O(1)额外空间的条件下完成。
 
提示：
1. 0 <= nums.length <= 3 * 104
2. -104 <= nums[i] <= 104
3. nums 已按升序排列
 */
#pragma mark - 方法1-双指针
int removeDuplicates(vector<int>& nums) {
    int len = (int)nums.size();
    if (len < 2) return len;
    
    int cur = 0;
    for (int i = 0; i < len; i++) {
        if (nums[cur] != nums[i]) {
            nums[++cur] = nums[i];
        }
    }
    return ++cur;
}
