// Created by crazydog-ki
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/crazydog-ki

#include <iostream>
using namespace std;

#include <vector>

/**盛最多水的容器
 给你n个非负整数a1，a2，...，an，每个数代表坐标中的一个点(i, ai)。在坐标内画n条垂直线，垂直线 i的两个端点分别为(i, ai) 和(i, 0) 。找出其中的两条线，得它们与x轴共同构成的容器可以容纳最多的水。
 说明：你不能倾斜容器。
 
 提示：
 (1)n = height.length
 (2)2 <= n <= 3 * 104
 (3)0 <= height[i] <= 3 * 104
 */

#pragma mark - 方法1-暴力枚举
int maxArea1(vector<int>& height) {
    int count = (int)height.size();
    int maxArea = 0;
    for (int i = 0; i < count; i++) {
        for (int j = i+1; j < count; j++) {
            int area = (j-i) * min(height[i], height[j]);
            maxArea = max(maxArea, area);
        }
    }
    return maxArea;
}

#pragma mark - 方法2-双指针+贪心
int maxArea(vector<int>& height) {
    int count = (int)height.size();
    int maxArea = 0;
    int i = 0, j = count-1;
    while (i < j) {
        int area = (j-i) * min(height[i], height[j]);
        maxArea = max(maxArea, area);
        if (height[i] < height[j]) i++;
        else j--;
    }
    return maxArea;
}

void test() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    cout << maxArea(height) << endl;
}
