// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 二分法
vector<int> searchRange(vector<int> &nums, int target) {
    int count = (int)nums.size();
    int lo = 0, hi = count-1;
    int start = -1, end = -1;
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (nums[mi] == target) {
            start = mi; end = mi;
            while (0<=start && nums[start]==target) start--;
            while (end<=count-1 && nums[end]==target) end++;
            start++; end--;
            break;
        }
        else if (nums[mi] < target) lo = mi+1;
        else hi = mi-1;
    }
    return {start, end};
}

void test() {
    vector<int> nums = {7, 7, 8, 8, 10};
    // vector<int> nums = {1};
    vector<int> res = searchRange(nums, 7);
    printVectors(res);
}
