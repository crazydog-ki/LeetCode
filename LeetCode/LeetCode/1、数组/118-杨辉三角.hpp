// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 常规方法
vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows == 0) return res;
    res.push_back(vector<int>{1});
    if (numRows == 1) return res;
    res.push_back(vector<int>{1, 1});
    for (int i = 2; i < numRows; i++) {
        vector<int> tmp(i+1, 1); // 计算每一列
        for (int j = 1; j <= i-1; j++) {
            tmp[j] = res[i-1][j-1] + res[i-1][j];
        }
        res.push_back(tmp);
    }
    return res;
}


