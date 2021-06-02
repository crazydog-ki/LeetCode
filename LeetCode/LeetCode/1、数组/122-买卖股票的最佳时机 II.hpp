// Created by Irving_yjx
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法二: 贪心改进版
int maxProfit2(vector<int> &prices) {
    if (prices.size() < 2) return 0;
    int res = 0;
    for (int i = 1; i < prices.size(); i++) {
        if (prices[i-1] < prices[i]) res += (prices[i]-prices[i-1]);
    }
    return res;
}

#pragma mark - 方法一: 贪心
int maxProfit(vector<int> &prices) {
    int count = (int)prices.size();
    if (count == 0) return 0;
    int maxProfit = 0;
    int minPrice = prices[0];
    for (int i = 1; i < count; i++) {
        if (prices[i] < prices[i-1]) {
            maxProfit += (prices[i-1]-minPrice);
            minPrice = prices[i];
        }
        
    }
    if (minPrice != prices[count-1]) maxProfit += (prices[count-1]-minPrice);
    return maxProfit;
}

void test() {
    // vector<int> prices = {7, 1, 5, 8, 6, 4};
    vector<int> prices = {1, 2, 3};
    cout << maxProfit(prices) << endl;
}
