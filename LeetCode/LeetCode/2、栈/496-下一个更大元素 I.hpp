// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <stack>
#include "tools.h"
#include <unordered_map>

#pragma mark - 方法一: 单调栈 + 哈希表
vector<int> nextGreateElement(vector<int> &nums) {
    vector<int> res(nums.size());
    stack<int> S;
    for (int i = (int)nums.size()-1; 0 <= i; i--) {
        while (!S.empty() && S.top()<=nums[i]) S.pop();
        res[i] = S.empty() ? -1 : S.top();
        S.push(nums[i]);
    }
    return res;
}

vector<int> nextGreaterElement(vector<int> &nums1, vector<int> &nums2) {
    // 1. 遍历nums2, 用map存储每个位置对应的下一个更大元素
    unordered_map<int, int> myMap;
    stack<int> S;
    for (int i = (int)nums2.size()-1; 0 <= i; i--) {
        while (!S.empty() && S.top() <= nums2[i]) S.pop();
        myMap[nums2[i]] = S.empty() ? -1 : S.top();
        S.push(nums2[i]);
    }
    
    // 2. 遍历nums1, 存储结果
    vector<int> res(nums1.size());
    for (int i = 0; i < nums1.size(); i++) res[i] = myMap[nums1[i]];
    return res;
}

void test() {
    vector<int> nums1 = {4, 1, 2};
    vector<int> nums2 = {1, 3, 4, 2};
    vector<int> res = nextGreaterElement(nums1, nums2);
    printVectors(res);
}

