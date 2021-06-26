// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 双指针
int threeSumClosest(vector<int> &nums, int target) {
    // 1. 排序
    sort(nums.begin(), nums.end());
    
    // 2. 选取指针
    int count = (int)nums.size();
    int i = 0, start = 1, end = count-1;
    int res = nums[i]+nums[start]+nums[end];
    
    // 3. 移动指针
    for (int i = 0; i < count-2; i++) {
        start = i+1; end = count-1;
        while (start < end) {
            int sum = nums[i]+nums[start]+nums[end];
            if (abs(sum-target) < abs(res-target)) res = sum; // 更接近, res重新赋值
            if (sum < target) start++;
            else if (target < sum) end--;
            else return res;
        }
    }
    return res;
}

void test() {
    vector<int> nums = {-4, -1, 1, 4, 9, 11};
    cout << threeSumClosest(nums, 7) << endl;
}
