// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: tmpMax记录局部最大连续1的个数, max记录全局最大连续1的个数
int findMaxConsecutiveOnes(vector<int> &nums) {
    int max = 0;
    int tmpMax = 0;
    for (int i = 0; i < nums.size(); i++) {
        tmpMax = 0;
        while (i<nums.size() && nums[i]==1) {
            tmpMax++;
            i++;
        }
        if (max < tmpMax) max = tmpMax;
    }
    return max;
}

void test() {
    vector<int> nums = {1, 1, 0, 0, 1, 1, 1, 1};
    cout << findMaxConsecutiveOnes(nums) << endl;
}
