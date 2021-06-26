// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 双指针
int maxArea(vector<int> &height) {
    int i = 0;
    int j = (int)height.size()-1;
    int maxArea = 0;
    int tmpArea = 0;
    while (i <= j) {
        tmpArea = min(height[i], height[j])*(j-i);
        if (maxArea < tmpArea) maxArea = tmpArea;
        if (height[i] < height[j]) i++;
        else j--;
    }
    return maxArea;
}

#pragma mark - 方法一: 暴力
int maxArea1(vector<int> &height) {
    int size = (int)height.size();
    int maxArea = 0;
    int tmpArea = 0;
    for (int i = 0; i < size; i++) {
        for (int j = i+1; j < size; j++) {
            tmpArea = (j-i) * min(height[i], height[j]);
            if (maxArea < tmpArea) maxArea = tmpArea;
        }
    }
    return maxArea;
}

void test() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
}
