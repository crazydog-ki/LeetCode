// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - QuickSort
/*
 区间L => [1, mi]
 区间R => [mi+1, k-1]
 区间U => [k, hi]
 */
int partition(vector<int> &nums, int lo, int hi) {
    int pivot = nums[lo]; // 候选轴点
    int mi = lo;
    for (int k = lo+1; k <= hi; k++)
        if (nums[k] < pivot) swap(nums[k], nums[++mi]);
    swap(nums[lo], nums[mi]);
    return mi;
}

void quickSort(vector<int> &nums, int lo, int hi) {
    if (hi-lo == 0) return;
    int mi = partition(nums, lo, hi);
    quickSort(nums, lo, mi);
    quickSort(nums, mi+1, hi);
}

#pragma mark - K-Selection, 以选择第K小的数为例
int selectPivot(vector<int> &nums, int lo, int hi) {
    swap(nums[lo], nums[(lo+hi)/2]); // 随机确定轴点
    int pivot = nums[lo];
    int mi = lo;
    for (int k = lo+1; k <= hi; k++)
        if (nums[k] < pivot) swap(nums[k], nums[++mi]);
    swap(nums[lo], nums[mi]);
    return mi;
}

int findKthSmallest(vector<int> &nums, int k) {
    int lo = 0;
    int hi = (int)nums.size()-1;
    int mi = 0;
    while (lo <= hi) {
        mi = selectPivot(nums, lo, hi); // 返回的是秩
        if (mi == k-1) return nums[mi];
        else if (k-1 < mi) hi = mi-1;
        else lo = mi+1;
    }
    return -1;
}

void test() {
    vector<int> nums = {1, 2, 2, 8, 3, 5, 9, 9, 10, 11};
    cout << findKthSmallest(nums, 4) << endl;
}
