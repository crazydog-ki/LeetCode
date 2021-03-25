// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/Irving-yjx

#include <iostream>
using namespace std;

#include <vector>
#include "tools.h"

#pragma mark - 方法一: 深搜+回溯
vector<vector<int>> res = {};
vector<int> item = {};
void dfs(vector<int> &candidates,
         int target,
         int start
         ) {
    if (target == 0) res.push_back(item);
    for (int i = start; i < candidates.size(); i++) {
        if (target < candidates[i]) continue;
        item.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i);
        item.pop_back();
    }
}
vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    dfs(candidates, target, 0);
    return res;
}

void test() {
    vector<int> candidates = {2, 3, 6, 7};
    vector<vector<int>> res = combinationSum(candidates, 7);
    for (int i = 0; i < res.size(); i++) {
        printVectors(res[i]);
    }
}
