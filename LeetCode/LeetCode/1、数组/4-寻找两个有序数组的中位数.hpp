// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 二分
double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
    int m = (int)nums1.size();
    int n = (int)nums2.size();
    if (n < m) return findMedianSortedArrays(nums2, nums1);     // 保证m<=n
    if (m == 0) return (double)(nums2[n/2]+nums2[(n-1)/2]) / 2; // 处理m=0
    int len = m + n;
    int cut1 = 0;
    int cut2 = 0;
    int lo = 0, hi = m-1;
    int l1, r1, l2, r2;
    while (cut1 <= m-1) {
        // 二分
        cut1 = (hi-lo)/2 + lo;
        cut2 = len/2 - cut1; // 保证cut1和cut2两边的元素个数为len/2个
        
        // 处理边界
        l1 = (cut1==0) ? INT_MIN : nums1[cut1-1];
        l2 = (cut2==0) ? INT_MIN : nums2[cut2-1];
        r1 = (cut1==m) ? INT_MAX : nums1[cut1];
        r2 = (cut2==n) ? INT_MAX : nums2[cut2];
        
        // 移动lo/hi指针
        if (r2 < l1) {
            hi = cut1 - 1;
        } else if (r1 < l2) {
            lo = cut1 + 1;
        } else { // r1与r2左边共有len/2个元素
            if (len%2 != 0) return (double)min(r1, r2); // 奇数
            else { // 偶数
                return (double)(max(l1, l2)+min(r1, r2)) / 2;
            }
        }
    }
    return -1;
}

void test() {
    vector<int> nums1 = {1, 5};
    vector<int> nums2 = {2, 3};
    cout << findMedianSortedArrays(nums1, nums2) << endl;
}
