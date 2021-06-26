// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include <stack>

#pragma mark - 方法三: 单调栈
int trap3(vector<int> &height) {
    stack<int> S;
    int size = (int)height.size();
    
    int sum = 0;
    for (int i = 0; i < size; i++) {
        while (!S.empty() && height[S.top()] < height[i]) {
            int cur = S.top();
            S.pop();
            if (S.empty()) break;
            int l = S.top();
            int r = i;
            int h = min(height[l], height[r]) - height[cur];
            sum += h*(r-l-1);
        }
        S.push(i);
    }
    
    return sum;
}

#pragma mark - 方法二: 动态规划(记录位置i的left_max和right_max)
int trap2(vector<int> &height) {
    int size = (int)height.size();
    if (size <= 0) return 0;
    
    vector<int> left_max(size);
    vector<int> right_max(size);
    
    // 1. 位置i左边的最大值
    left_max[0] = height[0];
    for (int i = 1; i < size; i++) left_max[i] = max(left_max[i-1], height[i]);
    
    // 2. 位置j右边的最大值
    right_max[size-1] = height[size-1];
    for (int j = size-2; 0 <= j; j--) right_max[j] = max(right_max[j+1], height[j]);
    
    // 3. 累加
    int sum = 0;
    for (int k = 0; k < size; k++) sum += min(left_max[k], right_max[k]) - height[k];
    
    return sum;
}

#pragma mark - 方法一: 暴力法(累加各位置雨水数量)
int trap(vector<int> &height) {
    int count = (int)height.size();
    int sum = 0;
    int max_left, max_right;
    for (int i = 1; i < count-1; i++) {
        max_left = 0; max_right = 0;
        for (int j = i; 0 <= j; j--) max_left = max(height[j], max_left);
        for (int k = i; k < count; k++) max_right = max(height[k], max_right);
        sum += min(max_left, max_right)-height[i];
    }
    return sum;
}

void test() {
    // vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    vector<int> height = {5, 4, 2, 1, 3, 4};
    cout << trap3(height) << endl;
}
