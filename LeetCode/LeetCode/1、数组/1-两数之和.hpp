// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <map>
#include "tools.h"

/**两数之和
 1. 给定一个整数数组nums和一个整数目标值target，请你在该数组中找出和为目标值的那两个整数，并返回它们的数组下标。

 2. 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素不能使用两遍。
 
 3. 你可以按任意顺序返回答案。
 */
#pragma mark - 方法1-两次遍历+哈希
vector<int> twoSum1(vector<int>& nums, int target) {
    int count = (int)nums.size();
    if (count < 2) return {};
    
    vector<int> res(2, -1); // 只有两个元素
    // 1、构造 myMap[value]=index
    map<int, int> myMap;
    for (int i = 0; i < count; i++) {
        myMap[nums[i]] = i;
    }
    
    // 2、遍历数组，找到结果提前跳出
    for (int i = 0; i < count; i++) {
        int key = target - nums[i];
        if (myMap.count(key) && myMap[key]!=i) { // 元素重复
            res[0] = myMap[key];
            res[1] = i;
            break;
        }
    }
    return res;
}

#pragma mark - 方法2-一次遍历+哈希
vector<int> twoSum2(vector<int>& nums, int target) {
    int count = (int)nums.size();
    if (count < 2) return {};
    
    vector<int> res(2, -1);
    map<int, int> myMap;
    for (int i = 0; i < count; i++) {
        int key = target - nums[i];
        if (myMap.count(key)) {
            res[0] = myMap[key];
            res[1] = i;
            break;
        }
        myMap[nums[i]] = i;
    }
    return res;
}

void test() {
    vector<int> nums = {3, 2, 4};
    vector<int> res = twoSum2(nums, 6);
    printVectors(res);
}
