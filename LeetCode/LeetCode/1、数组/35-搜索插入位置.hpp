// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>

#pragma mark - 方法一: 二分查找
int searchInsert(vector<int> &nums, int target) {
    int lo = 0;
    int hi = (int)nums.size();
    int mi = 0;
    while (lo < hi) {
        mi = (lo + hi) / 2;
        if (nums[mi] == target) return mi;
        else if (nums[mi] < target) lo = mi + 1;
        else hi = mi;
    }
    return lo;
}

void test() {
    vector<int> nums = {1, 3, 5, 6};
    cout << searchInsert(nums, -1) << endl;
}
