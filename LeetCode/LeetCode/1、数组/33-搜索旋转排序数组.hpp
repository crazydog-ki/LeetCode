// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 二分法
int search(vector<int> &nums, int target) {
    int count = (int)nums.size();
    int lo = 0, hi = count-1;
    while (lo <= hi) {
        int mi = (lo+hi)/2;
        if (nums[mi] == target) return mi; // 提前退出
        if (nums[mi] < nums[lo]) { // 后一半 {6, 7, 1, 2, 3, 4, 5}
            if (nums[mi]<target && target<=nums[hi]) lo = mi+1;
            else hi = mi-1;
        }
        else { // 前一半 {3, 4, 5, 6, 7, 1, 2}
            if (nums[lo]<=target && target<nums[mi]) hi = mi-1;
            else lo = mi+1;
        }
    }
    return -1;
}

void test() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << search(nums, 2) << endl;
}
