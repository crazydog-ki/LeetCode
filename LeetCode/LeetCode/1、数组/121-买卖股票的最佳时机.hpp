// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 动态规划
int maxProfit(vector<int> &prices) {
    int minPrice = INT_MAX;
    int maxProfit = 0;
    for (int i = 0; i < prices.size(); i++) {
        if (prices[i] < minPrice) minPrice = prices[i];
        else if (maxProfit < prices[i] - minPrice) maxProfit = prices[i] - minPrice;
    }
    return maxProfit;
}

void test() {
    // vector<int> price = {7, 1, 5, 3, 6, 4};
    // vector<int> price = {7, 6, 4, 3, 1};
    vector<int> price = {};
    cout << maxProfit(price) << endl;
}
