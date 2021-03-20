// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 使用反转
void rotate2(vector<int> &nums, int k) {
    int count = (int)nums.size();
    k = k % count;
    reverse(nums.begin(), nums.end());
    reverse(nums.begin(), nums.begin()+k);
    reverse(nums.begin()+k, nums.end());
}

#pragma mark - 方法一: 常规方法 => 超出时间限制
void rotate(vector<int> &nums, int k) {
    if (k < 0 || nums.size() == 0) return;
    int count = (int)nums.size();
    k = k % count;
    int i = count-k;
    int j = count-1;
    while (i < j) {
        swap(nums[i], nums[j]);
        i++;
        j--;
    }
    for (int i = count-k; i < count; i++) {
        int tmp = nums[i];
        for (int j = i; 0 < j; j--) {
            nums[j] = nums[j-1];
        }
        nums[0] = tmp;
    }
}

void test() {
    vector<int> nums = {1, 2, 3, 4, 5};
    rotate2(nums, 2);
    printVectors(nums);
}
