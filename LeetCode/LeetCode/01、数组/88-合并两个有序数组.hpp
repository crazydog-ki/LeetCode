// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**合并两个有序数组
 给你两个按非递减顺序排列的整数数组nums1和nums2，另有两个整数m和n ，分别表示nums1和nums2中的元素数目。
 请你合并nums2到nums1中，使合并后的数组同样按非递减顺序排列。
 
 注意：最终，合并后数组不应由函数返回，而是存储在数组nums1中。为了应对这种情况，nums1的初始长度为m+n，其中前m个元素表示应合并的元素，后n个元素为0，应忽略。nums2的长度为n。
 */
#pragma mark - 方法1-双指针
void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int p1 = m-1, p2 = n-1;
    int target = m+n-1;
    int cur;
    while (0<=p1 || 0<=p2) {
        if (p1 == -1) {
            cur = nums2[p2--];
        } else if (p2 == -1) {
            cur = nums1[p1--];
        } else if (nums2[p2]<nums1[p1]) {
            cur = nums1[p1--];
        } else {
            cur = nums2[p2--];
        }
        nums1[target--] = cur;
    }
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m+n-1;
    m--;
    n--;
    while (0<=n) {
        while (0<=m && nums2[n]<nums1[m]) {
            swap(nums1[k--], nums1[m--]);
        }
        swap(nums1[k--], nums2[n--]);
    }
}
/*
                p1             target
 nums1: 1,2,3,4,5,-1,-1,-1,-1,-1
 nums2: 2,2,4,5,6
                p2
 */


