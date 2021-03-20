// Created by CoderJX
// Email  : jxyou.ki@gmail.com
// Github : https://github.com/CoderJX

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
    for (int i = start; i<candidates.size() && candidates[i]<=target; i++) {
        if (start<i && candidates[i]==candidates[i-1]) continue;
        item.push_back(candidates[i]);
        dfs(candidates, target-candidates[i], i+1);
        item.pop_back();
    }
}
vector<vector<int>> combinationSum2(vector<int> &candidates, int target) {
    sort(candidates.begin(), candidates.end()); // 排序
    dfs(candidates, target, 0);
    return res;
}

void test() {
    vector<int> candidates = {10, 1, 2, 7, 6, 1, 5};
    vector<vector<int>> res = combinationSum2(candidates, 8);
    for (int i = 0; i < res.size(); i++) {
        printVectors(res[i]);
    }
}
