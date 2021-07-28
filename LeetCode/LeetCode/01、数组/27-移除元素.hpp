// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**移除元素
给你一个数组nums和一个值val，你需要原地移除所有数值等于val的元素，并返回移除后数组的新长度。
不要使用额外的数组空间，你必须仅使用O(1)额外空间并原地修改输入数组。
元素的顺序可以改变。你不需要考虑数组中超出新长度后面的元素。

提示：
1. 0 <= nums.length <= 100
2. 0 <= nums[i] <= 50
3. 0 <= val <= 100
 */
#pragma mark - 方法1-双指针
int removeElement(vector<int>& nums, int val) {
    int len = (int)nums.size();
    int cur = 0;
    for (int i = 0; i < len; i++) {
        if (nums[i] != val) {
            nums[cur++] = nums[i];
        }
    }
    return cur;
}
