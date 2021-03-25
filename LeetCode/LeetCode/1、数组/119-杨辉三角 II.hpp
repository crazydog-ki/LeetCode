// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 常规方法
vector<int> getRow(int rowIndex) {
    vector<vector<int>> res;
    for (int i = 0; i <= rowIndex; i++) {
        res.push_back(vector<int>(i+1, 1)); // 计算每一列
        if (0 < i) {
            for (int j = 1; j <= i-1; j++) {
                res[i][j] = res[i-1][j-1] + res[i-1][j];
            }
        }
    }
    return res[rowIndex];
}
