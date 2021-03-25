// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 利用nums1后半部分先保存nums的所有元素
void merge2(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    for (int i = m-1; 0 <= i; i--) nums1[i+n] = nums1[i]; // nums1中的元素后移n个位置
    int idx = 0;
    int i = n; // nums1元素起始位置
    int j = 0; // nums2起始位置
    
    while (i < m+n && j < n) {
        if (nums1[i] <= nums2[j]) {
            nums1[idx] = nums1[i];
            i++;
        } else {
            nums1[idx] = nums2[j];
            j++;
        }
        idx++;
    }
    
    while (j < n) {
        nums1[idx] = nums2[j];
        idx++;
        j++;
    }
}

#pragma mark - 方法一: 借助最小堆的思想
void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
    if (n == 0) return;
    int i = 0;
    // 1. 前m个元素就位
    while (i < m) {
        if (nums1[i] <= nums2[0]) i++;
        else {
            swap(nums1[i], nums2[0]);
            sort(nums2.begin(), nums2.end()); // 维护nums2最小堆
            i++;
        }
    }
    // 2. 后n个元素就位
    for (int j = 0; j < nums2.size(); j++) {
        nums1[m+j] = nums2[j];
    }
}

void test() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};
    merge2(nums1, 3, nums2, 3);
    printVectors(nums1);
}
