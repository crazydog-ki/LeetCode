// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 双指针
int removeElement(vector<int> &nums, int val) {
    int k = 0;
    for(int i = 0; i < nums.size(); ++i) {
        if(nums[i] != val) {
            nums[k] = nums[i];
            ++k;
        }
    }
    return k;
}

void test() {
    vector<int> nums = {0, 1, 2, 2, 3, 0, 4, 2};
    // vector<int> nums = {3, 3};
    // vector<int> nums = {1};
    printVectors(nums);
    cout << removeElement(nums, 2) << endl;
    printVectors(nums);
}
