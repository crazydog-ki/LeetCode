// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

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
    int pivot = nums[lo]; /// 候选轴点
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

#pragma mark - K-Selection 以选择第K小的数为例
int selectPivot(vector<int> &nums, int lo, int hi) {
    swap(nums[lo], nums[(lo+hi)/2]); /// 随机确定轴点
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
        mi = selectPivot(nums, lo, hi); /// 返回的是秩
        if (mi == k-1) return nums[mi];
        else if (k-1 < mi) hi = mi-1;
        else lo = mi+1;
    }
    return -1;
}

#pragma mark - KMP算法
int kmpMatch(string text, string pattern) {
    int tLen = (int)text.length();
    int pLen = (int)pattern.length();
    if (pLen == 0) return 0;
    
    vector<int> next(pLen, 0);
    /// 构建next表，最长公共前后缀
    for (int i = 1, j = 0; i < pLen; i++) {
        while (0<j && pattern[i]!=pattern[j]) j = next[j-1];
        if (pattern[i] == pattern[j]) j++;
        next[i] = j;
    }
    
    /// 匹配过程
    for (int i = 0, j = 0; i < tLen; i++) {
        while (0<j && text[i]!=pattern[j]) j = next[j-1];
        if (text[i] == pattern[j]) j++;
        if (j == pLen) {
            return i-pLen+1;
        }
    }
    return -1;
}

#pragma mark - 全排列
