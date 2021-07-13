// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

/**寻找两个正序数组的中位数
给定两个大小分别为m和n的正序（从小到大）数组nums1和nums2。请你找出并返回这两个正序数组的中位数。
 
提示：
1. nums1.length == m
2. nums2.length == n
3. 0 <= m <= 1000
4. 0 <= n <= 1000
5. 1 <= m + n <= 2000
6. -106 <= nums1[i], nums2[i] <= 106
 */
#pragma mark - 方法1-数组合并
double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    int i = 0, j = 0;
    
    // 归并排序合并数组
    vector<int> mergedNums;
    while (i < m || j < n) {
        if (i<m && (n<=j || nums1[i]<=nums2[j])) {
            mergedNums.push_back(nums1[i]);
            i++;
        } else {
            mergedNums.push_back(nums2[j]);
            j++;
        }
    }

    // 找到中位数
    int count = (int)mergedNums.size();
    return count%2 ? mergedNums[(count-1)/2] :                                     (mergedNums[count/2-1]+mergedNums[count/2])/2.0;
}

#pragma mark - 方法2-归并排序优化版
double findMedianSortedArrays2(vector<int>& nums1, vector<int>& nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    int totalLen = m + n;
    int i = 0, j = 0, k = 0;
    int left = -1, right = -1;
    
    while (k++ <= totalLen/2) {
        left = right;
        if (i<m && (n<=j || nums1[i]<nums2[j])) {
            right = nums1[i++];
        } else {
            right = nums2[j++];
        }
    }
    
    return totalLen%2 ? right : (left+right)/2.0;
}

#pragma mark - 方法3-二分法
int getKth(vector<int>& nums1,
           int start1,
           int end1,
           vector<int>& nums2,
           int start2,
           int end2,
           int k) {
    int len1 = end1 - start1 + 1;
    int len2 = end2 - start2 + 1;
    // 保证len1 < len2
    if (len2 < len1) return getKth(nums2, start2, end2, nums1, start1, end1, k);
    
    // 处理边界问题
    if (0 == len1) return nums2[start2+k-1];
    if (1 == k) return min(nums1[start1], nums2[start2]);
    
    // 考虑数组越界问题
    int i = start1 + min(len1, k/2) - 1;
    int j = start2 + min(len2, k/2) - 1;
    if (nums1[i] < nums2[j]) {
        return getKth(nums1, i+1, end1, nums2, start2, end2, k-(i-start1+1));
    } else {
        return getKth(nums1, start1, end1, nums2, j+1, end2, k-(j-start2+1));
    }
}

double findMedianSortedArrays3(vector<int>& nums1, vector<int>& nums2) {
    int len1 = (int)nums1.size();
    int len2 = (int)nums2.size();
    int left = (len1+len2+1) / 2;
    int right = (len1+len2+2) / 2;
    return (getKth(nums1, 0, len1-1, nums2, 0, len2-1, left) + getKth(nums1, 0, len1-1, nums2, 0, len2-1, right)) * 0.5;
}

#pragma mark - 方法4-二分法优化
double findMedianSortedArrays4(vector<int>& nums1, vector<int>& nums2) {
    int len1 = (int)nums1.size();
    int len2 = (int)nums2.size();
    // 保证nums1为短数组
    if (len2 < len1) return findMedianSortedArrays4(nums2, nums1);
    bool isOu = (len1+len2)%2 == 0;
    
    // 针对nums1采用二分
    int left = 0, right = len1;
    while (left <= right) {
        // i+j = (len1-i)+(len2-j)+1，兼顾奇偶
        int i = (left + right) / 2;
        int j = (len1+len2+1)/2 - i;
        
        if (i!=len1 && j!=0 && nums1[i]<nums2[j-1]) left = i+1;
        else if (i!=0 && j!=len2 && nums2[j]<nums1[i-1]) right = i-1;
        else { // 找到中位数
            int maxLeft = 0;
            if (i==0) maxLeft = nums2[j-1];
            else if (j==0) maxLeft = nums1[i-1];
            else maxLeft = max(nums1[i-1], nums2[j-1]);
            if (!isOu) return maxLeft;
            
            int minRight = 0;
            if (i==len1) minRight = nums2[j];
            else if (j==len2) minRight = nums1[i];
            else minRight = min(nums1[i], nums2[j]);
            return (maxLeft+minRight) / 2.0f;
        }
    }
    return 0.0f;
}
