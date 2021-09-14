// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <stack>

/**接雨水
给定n个非负整数表示每个宽度为1的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水。
提示：
1. n == height.length
2. 0 <= n <= 3 * 104
3. 0 <= height[i] <= 105
 */

#pragma mark - 方法1-暴力法
int trap1(vector<int>& height) {
    int size = (int)height.size();
    int ret = 0;
    for (int i = 0; i < size; i++) {
        int maxL = 0, maxR = 0;
        for (int j = 0; j <= i; j++) maxL = max(maxL, height[j]);
        for (int k = i; k < size; k++) maxR = max(maxR, height[k]);
        ret += min(maxL, maxR)-height[i];
    }
    return ret;
};

#pragma mark - 方法2-动态规划
int trap2(vector<int>& height) {
    int size = (int)height.size();
    vector<int> maxL(size), maxR(size);
    maxL[0] = height[0];
    for (int i = 1; i < size; i++) maxL[i] = max(maxL[i-1], height[i]);
    
    maxR[size-1] = height[size-1];
    for (int j = size-2; 0 <= j; j--) maxR[j] = max(maxR[j+1], height[j]);
    
    int ret = 0;
    for (int k = 1; k <= size-2; k++) ret += min(maxL[k], maxR[k])-height[k];
    return ret;
}

#pragma mark - 方法3-单调栈
int trap3(vector<int>& height) {
    int size = (int)height.size();
    stack<int> S;
    int ret = 0;
    for (int i = 0; i < size; i++) {
        while (!S.empty() && height[S.top()]<height[i]) {
            int t = S.top();
            S.pop();
            if (S.empty()) break;
            int l = S.top();
            int r = i;
            int dis = r-l-1;
            int delta = min(height[l], height[r])-height[t];
            ret += dis*delta;
        }
        S.push(i);
    }
    return ret;
}

#pragma mark - 方法4-双指针
int trap4(vector<int>& height) {
    int size = (int)height.size();
    int maxL = 0, maxR = 0;
    int l = 0, r = size-1;
    int ret = 0;
    while (l < r) {
        if (height[l] <= height[r]) {
            if (maxL < height[l]) maxL = height[l];
            else ret += maxL-height[l];
            l++;
        } else {
            if (maxR < height[r]) maxR = height[r];
            else ret += maxR-height[r];
            r--;
        }
    }
    return ret;
}

